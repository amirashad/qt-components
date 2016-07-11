/* 
 * File:   qNaturalSort.h
 * Author: amirjanov
 *
 * Created on June 17, 2012, 7:20 PM
 */

#ifndef QNATURALSORT_H
#define	QNATURALSORT_H

#include <QString>
#include <QStringList>

class qNaturalSort {
public:

    inline bool operator()(const QString &t1, const QString &t2) const {
        QStringList list1;
        QStringList list2;
        int length1 = t1.length();
        int length2 = t2.length();

        QString tmp1;
        QChar lastLetter1;
        for (int i = 0; i < length1; i++) {
            QChar a1 = t1.at(i).toLower();

            if ((lastLetter1.isDigit() && !a1.isDigit()) || (!lastLetter1.isDigit() && a1.isDigit())) {
                list1 << tmp1;
                tmp1 = "";
            }

            tmp1 += a1;
            lastLetter1 = a1;

            if (i == length1 - 1) {
                list1 << tmp1;
                tmp1 = "";
            }

        }

        QString tmp2;
        QChar lastLetter2;
        for (int i = 0; i < length2; i++) {
            QChar a2 = t2.at(i).toLower();

            if ((lastLetter2.isDigit() && !a2.isDigit()) || (!lastLetter2.isDigit() && a2.isDigit())) {
                list2 << tmp2;
                tmp2 = "";
            }

            tmp2 += a2;
            lastLetter2 = a2;

            if (i == length2 - 1) {
                list2 << tmp2;
                tmp2 = "";
            }

        }

        int length = qMin(list1.size(), list2.size());

        for (int i = 0; i < length; i++) {
            if (list1.at(i) == list2.at(i))
                continue;

            int i1 = list1.at(i).toInt();
            int i2 = list2.at(i).toInt();

            if (i1 != 0 || i2 != 0)
                return i1 < i2;

            return list1.at(i).toLower() < list2.at(i).toLower();
        }

        return length1 < length2;
    }
};

#endif	/* QNATURALSORT_H */

