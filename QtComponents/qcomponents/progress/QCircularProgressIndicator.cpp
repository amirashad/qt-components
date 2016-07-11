/*
 * File:   QCircularProgressIndicator.h
 * Author: Rashad Amirjanov
 *
 * Created on April 12, 2010, 11:53 AM
 */


#include "QCircularProgressIndicator.h"

#include <QPainter>
#include <QApplication>

QCircularProgressIndicator::QCircularProgressIndicator(QWidget* parent)
: QWidget(parent),
m_angle(0),
m_timerId(-1),
m_delay(40),
m_displayedWhenStopped(false),
m_color(Qt::black) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFocusPolicy(Qt::NoFocus);
}

bool QCircularProgressIndicator::isAnimated() const {
    return (m_timerId != -1);
}

void QCircularProgressIndicator::setDisplayedWhenStopped(bool state) {
    m_displayedWhenStopped = state;

    update();
}

bool QCircularProgressIndicator::isDisplayedWhenStopped() const {
    return m_displayedWhenStopped;
}

void QCircularProgressIndicator::startAnimation() {
    m_angle = 0;

    if (m_timerId == -1)
        m_timerId = startTimer(m_delay);
}

void QCircularProgressIndicator::stopAnimation() {
    if (m_timerId != -1)
        killTimer(m_timerId);

    m_timerId = -1;

    update();
}

void QCircularProgressIndicator::setAnimationDelay(int delay) {
    if (m_timerId != -1)
        killTimer(m_timerId);

    m_delay = delay;

    if (m_timerId != -1)
        m_timerId = startTimer(m_delay);
}

void QCircularProgressIndicator::setColor(const QColor & color) {
    m_color = color;

    update();
}

QSize QCircularProgressIndicator::sizeHint() const {
    return QSize(20, 20);
}

int QCircularProgressIndicator::heightForWidth(int w) const {
    return w;
}

void QCircularProgressIndicator::timerEvent(QTimerEvent * /*event*/) {
    m_angle = (m_angle + 30) % 360;

    update();
    QApplication::processEvents();
}

void QCircularProgressIndicator::paintEvent(QPaintEvent * /*event*/) {
    if (!m_displayedWhenStopped && !isAnimated())
        return;

    int width = qMin(this->width(), this->height());

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int outerRadius = (width - 1)*0.5;
    int innerRadius = (width - 1)*0.5 * 0.38;

    int capsuleHeight = outerRadius - innerRadius;
    int capsuleWidth = (width > 32) ? capsuleHeight * .23 : capsuleHeight * .35;
    int capsuleRadius = capsuleWidth / 2;

    for (int i = 0; i < 12; i++) {
        QColor color = m_color;
        color.setAlphaF(1.0f - (i / 12.0f));
        p.setPen(Qt::NoPen);
        p.setBrush(color);
        p.save();
        p.translate(rect().center());
        p.rotate(m_angle - i * 30.0f);
        p.drawRoundedRect(-capsuleWidth * 0.5, -(innerRadius + capsuleHeight), capsuleWidth, capsuleHeight, capsuleRadius, capsuleRadius);
        p.restore();
    }
}
