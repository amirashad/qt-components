/* 
 * File:   QQTouchScreenKeyboard.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on May 7, 2009, 4:43 PM
 */

#include "QTouchScreenKeyboard.h"
#include <QDesktopWidget>

QTouchScreenKeyboard *QTouchScreenKeyboard::keyboard;

QTouchScreenKeyboard::QTouchScreenKeyboard(QWidget *parent) : QDialog(parent) {
    setModal(false);
    setAttribute(Qt::WA_ShowWithoutActivating, true);
    for (int i = 0; i < MAX_LETTER_KEYS; i++) {
        keyLetters[i] = NULL;
    }
    for (int i = 0; i < MAX_NUMBER_KEYS; i++) {
        keyNumbers[i] = NULL;
    }

    initKeyboardLettersRu();
    //    initKeyboardLettersEng();
    initKeyboardNumbers();
    initKeyboardButtons();

    setWindowFlags(Qt::Dialog);
    setWindowTitle(trUtf8("On-Screen Keyboard"));//"Клавиатура"
}

QTouchScreenKeyboard::~QTouchScreenKeyboard() {
}

void QTouchScreenKeyboard::initKeyboardLettersRu() {
    chars.append("й");
    chars.append("ц");
    chars.append("у");
    chars.append("к");
    chars.append("е");
    chars.append("н");
    chars.append("г");
    chars.append("ш");
    chars.append("щ");
    chars.append("з");
    chars.append("х");
    //    chars.append("ъ");

    chars.append(KY_LINE);

    chars.append("ф");
    chars.append("ы");
    chars.append("в");
    chars.append("а");
    chars.append("п");
    chars.append("р");
    chars.append("о");
    chars.append("л");
    chars.append("д");
    chars.append("ж");
    chars.append("э");

    chars.append(KY_LINE);

    chars.append("я");
    chars.append("ч");
    chars.append("с");
    chars.append("м");
    chars.append("и");
    chars.append("т");
    chars.append("ь");
    chars.append("б");
    chars.append("ю");
    chars.append("ъ");
    chars.append("ё");
    //    chars.append(",");
}

void QTouchScreenKeyboard::initKeyboardLettersEng() {
    chars.append("q");
    chars.append("w");
    chars.append("e");
    chars.append("r");
    chars.append("t");
    chars.append("y");
    chars.append("u");
    chars.append("i");
    chars.append("o");
    //    chars.append("p");
    //    chars.append("[");
    //    chars.append("]");

    chars.append(KY_LINE);

    chars.append("a");
    chars.append("s");
    chars.append("d");
    chars.append("f");
    chars.append("g");
    chars.append("h");
    chars.append("j");
    chars.append("k");
    chars.append("l");
    //    chars.append(";");
    //    chars.append("'");

    chars.append(KY_LINE);

    chars.append("z");
    chars.append("x");
    chars.append("c");
    chars.append("v");
    chars.append("b");
    chars.append("n");
    chars.append("m");
    chars.append("p");
    chars.append(",");
    //    chars.append(".");
    //    chars.append("/");
}

void QTouchScreenKeyboard::initKeyboardNumbers() {
    numbers.append("1");
    numbers.append("2");
    numbers.append("3");

    numbers.append(KY_LINE);

    numbers.append("4");
    numbers.append("5");
    numbers.append("6");

    numbers.append(KY_LINE);

    numbers.append("7");
    numbers.append("8");
    numbers.append("9");

    numbers.append(KY_LINE);

    numbers.append("0");
    numbers.append(".");
        numbers.append("Ok");
}

void QTouchScreenKeyboard::initKeyboardButtons() {
    QSize size = QSize(40, 40);
    QFont font = QFont(this->font().family(), 13);
    QGridLayout *gridButtons = new QGridLayout();
    gridButtons->setHorizontalSpacing(5);
    gridButtons->setVerticalSpacing(5);

    QGridLayout *gridNumbers = new QGridLayout();
    gridNumbers->setHorizontalSpacing(5);
    gridNumbers->setVerticalSpacing(5);

    int gridRow = 0;
    int gridColumn = 0;
    for (int i = 0; i < chars.size(); i++) {
        if (chars[i] == KY_LINE) {
            gridRow = 0;
            gridColumn += 1;
        } else {
            keyLetters[i] = new QPushButton(trUtf8(chars[i].toUtf8()), this);
            keyLetters[i]->setFixedSize(size);
            keyLetters[i]->setFont(font);
            gridButtons->addWidget(keyLetters[i], gridColumn, gridRow);
            connect(keyLetters[i], SIGNAL(clicked()), this, SLOT(keysClicked()));
            gridRow += 1;
        }
    }

    gridRow = 0;
    gridColumn = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == KY_LINE) {
            gridRow = 0;
            gridColumn += 1;
        } else {
            keyNumbers[i] = new QPushButton(trUtf8(numbers[i].toUtf8()), this);
            keyNumbers[i]->setFixedSize(size);
            keyNumbers[i]->setFont(font);
            //            keyNumbers[i]->setVisible(false);
            gridNumbers->addWidget(keyNumbers[i], gridColumn, gridRow);
            connect(keyNumbers[i], SIGNAL(clicked()), this, SLOT(keysClicked()));
            gridRow += 1;
        }
    }

    keyCapsLock = new QPushButton("Caps Lock", this);
    keyCapsLock->setCheckable(true);

    keySpace = new QPushButton(" ", this);
    keyBackSpace = new QPushButton("<--", this);
    //    btnLanguage = new QPushButton("RU");

    //    connect(btnLanguage, SIGNAL(clicked()), this, SLOT(btnLanguageClicked()));
    connect(keySpace, SIGNAL(clicked()), this, SLOT(keysClicked()));
    connect(keyCapsLock, SIGNAL(clicked()), this, SLOT(keyCapsLockClicked()));
    connect(keyBackSpace, SIGNAL(clicked()), this, SLOT(keysClicked()));

    keyCapsLock->setFixedSize(size.width()*2 + gridButtons->horizontalSpacing(), size.height());
    keySpace->setFixedHeight(size.height());
    keyBackSpace->setFixedSize(size.width()*2 + gridButtons->horizontalSpacing(), size.height());
    //    btnLanguage->setFixedSize(size);

    QHBoxLayout *specKeysLayout = new QHBoxLayout();
    specKeysLayout->setSpacing(5);
    specKeysLayout->setContentsMargins(0, 0, 0, 0);
    specKeysLayout->addWidget(keyCapsLock);
    specKeysLayout->addWidget(keySpace);
    specKeysLayout->addWidget(keyBackSpace);
    //    specKeysLayout->addWidget(btnLanguage);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(gridButtons);
    layout->addLayout(specKeysLayout);

    QHBoxLayout *layoutAllKeys = new QHBoxLayout();
    layoutAllKeys->addLayout(layout);
    layoutAllKeys->addLayout(gridNumbers);

    setLayout(layoutAllKeys);
}

void QTouchScreenKeyboard::keysClicked() {
    if (sender() == 0) {
        return;
    }

    if (typeid (QPushButton) != typeid (*sender())) {
        return;
    }

    QPushButton* key = (QPushButton*) sender();

    QWidget * component = parentWidget()->focusWidget();
    if (component == NULL) {
        return;
    }
    //    parentWidget()->focusWidget()->activateWindow();
    QLineEdit * edit = NULL;
    QComboBox * combo = NULL;
    if (typeid (QLineEdit) == typeid (*component)) {
        edit = (QLineEdit *) component;
    } else if (typeid (QComboBox) == typeid (*component)) {
        combo = (QComboBox *) component;
    }

    int keyCode = Qt::Key_unknown;
    if (key->text() == "<--") {
        keyCode = Qt::Key_Backspace;
    }else if(key->text() == "Ok"){
        keyCode = Qt::Key_Return;
    }
    QKeyEvent evt(QKeyEvent::KeyPress, keyCode, Qt::NoModifier, key->text());

    if (edit != NULL) {
        edit->event(&evt);
    } else if (combo != NULL) {
        combo->activateWindow();
        combo->event(&evt);
    }
}

void QTouchScreenKeyboard::btnLanguageClicked() {
    for (int i = 0; i < MAX_LETTER_KEYS; i++) {
        if (keyLetters[i] != NULL) {
            delete keyLetters[i];
            keyLetters[i] = NULL;
        }
    }
    for (int i = 0; i < MAX_NUMBER_KEYS; i++) {
        if (keyNumbers[i] != NULL) {
            delete keyNumbers[i];
            keyNumbers[i] = NULL;
        }
    }

    if (btnLanguage->text() == "RU") {
        initKeyboardLettersRu();
        initKeyboardNumbers();
        initKeyboardButtons();
        btnLanguage->setText("EN");
    } else if (btnLanguage->text() == "EN") {
        initKeyboardLettersEng();
        initKeyboardNumbers();
        initKeyboardButtons();
        btnLanguage->setText("RU");
    }
}

void QTouchScreenKeyboard::keyCapsLockClicked() {
    for (int i = 0; i < MAX_LETTER_KEYS; i++) {
        if (keyLetters[i] != NULL) {
            if (((QPushButton*) sender())->isChecked()) {
                keyLetters[i]->setText(keyLetters[i]->text().toUpper());
            } else {
                keyLetters[i]->setText(keyLetters[i]->text().toLower());
            }
        }
    }
}

void QTouchScreenKeyboard::showEvent(QShowEvent*) {
    QDesktopWidget desktop;
    //    QMessageBox::information(this, "", QString("%1, %2").arg(this->geometry().width()).arg(this->geometry().height()));
    int x = (desktop.width() - this->geometry().width()) / 2;
    int y = (desktop.height() - this->geometry().height() - 120);
    move(x, y);
}

void QTouchScreenKeyboard::initKeyboard() {
    keyboard = new QTouchScreenKeyboard();
}

void QTouchScreenKeyboard::showKeyboard(QWidget* parent) {
    Q_UNUSED(parent)
//    keyboard->setParent(parent, Qt::Dialog);
//    keyboard->setModal(false);
//    keyboard->show();
}

void QTouchScreenKeyboard::hideKeyboard() {
//    keyboard->hide();
}
