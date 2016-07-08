#ifndef MD_COMMON_IPCTRL_H
#define MD_COMMON_IPCTRL_H

#include <QFrame>
#include <QLineEdit>
#include <QIntValidator>
#include "stdint.h"
#include <QHBoxLayout>
#include <QFont>
#include <QLabel>
#include <QKeyEvent>
#include "../qcomps_global.h"

class QCOMPS_EXPORT IPCtrl : public QFrame {

    Q_OBJECT

        enum
        {
            QTUTL_IP_SIZE   = 4,// число октетов IP адресе
            MAX_DIGITS      = 3 // число символов в LineEdit
        };

public:

    explicit IPCtrl (QWidget *parent = 0);
    ~IPCtrl();

    virtual bool eventFilter( QObject *obj, QEvent *event );
    QLineEdit *(m_pLineEdit[QTUTL_IP_SIZE]);

    QString text();
    void setText(QString text);
    QLineEdit* pEdit;

public slots:
    void slotTextChanged( QLineEdit* pEdit );

signals:
    void signalTextChanged( QLineEdit* pEdit );

private:
    void MoveNextLineEdit (int i);
    void MovePrevLineEdit (int i);
};

#endif // MD_COMMON_IPCTRL_H
