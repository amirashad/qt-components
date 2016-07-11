/* 
 * File:   QTouchScreenKeyboard.h
 * Author: Rashad Amirjanov
 *
 * Created on May 7, 2009, 4:43 PM
 */

#ifndef _QTOUCHSCREENKEYBOARD_H
#define	_QTOUCHSCREENKEYBOARD_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QKeyEvent>
#include <QString>

#include "../qcomps_global.h"

#define MAX_LETTER_KEYS   40
#define MAX_NUMBER_KEYS   15

#define KY_LINE         "[newline]"
#define KY_CAPS_LOCK    "[capslock]"
#define KY_SHIFT        "[shift]"

class QCOMPS_EXPORT QTouchScreenKeyboard : public QDialog {
    Q_OBJECT
public:
    QTouchScreenKeyboard(QWidget *parent = 0);
    ~QTouchScreenKeyboard();

    static void initKeyboard();
    static void showKeyboard(QWidget *parent);
    static void hideKeyboard();
public slots:
    void keysClicked();
    void btnLanguageClicked();
    void keyCapsLockClicked();
private:
    void initKeyboardButtons();
    void initKeyboardLettersRu();
    void initKeyboardLettersEng();
    void initKeyboardNumbers();
    void showEvent(QShowEvent *);
    QPushButton *keyLetters[MAX_LETTER_KEYS];
    QPushButton *keyNumbers[MAX_NUMBER_KEYS];
    QVector<QString> chars;
    QVector<QString> numbers;
    QPushButton *keyCapsLock, *keySpace, *keyBackSpace, *btnLanguage;
    static QTouchScreenKeyboard *keyboard;
};

#endif	/* _QTOUCHSCREENKEYBOARD_H */

