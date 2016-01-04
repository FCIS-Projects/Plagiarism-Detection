#ifndef LCS_H
#define LCS_H
#include <QDebug>
#include <QString>
#include <algorithm>
#include <QVector>


class LCS
{
private:
    int memo[100][100];
public:
    LCS();
    LCS(QString str1, QString str2);
    void print_diff(QString str1, QString str2, int length1, int length2);
    void print_lcs(QString str1, QString str2, int length1, int length2);
};

#endif // LCS_H
