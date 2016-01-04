#include "lcs.h"

LCS::LCS()
{
}

LCS::LCS(QString str1, QString str2)
{
    int length1 = str1.length();
    int length2 = str2.length();
    int result;

    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
                if(str1[i-1] == str2[j-1])
                {
                    memo[i][j] = 1+ memo[i-1][j-1];
                }


                else
                {
                    memo[i][j] = qMax(memo[i-1][j], memo[i][j-1]);
                }
        }
    }
    qDebug()<<"the lcs: ";
    print_lcs(str1, str2, length1, length2);
//    qDebug()<<"the diff : ";
//    print_diff(str1, str2, length1, length2);
    result = memo[length1][length2];
//    return result;

}

void LCS::print_diff(QString str1, QString str2, int length1, int length2)
{

    if (length1 > 0 && length2 > 0 && str1[length1] == str2[length2])
    {
        print_diff(str1, str2, length1-1, length2-1);
        qDebug()<< str1[length1]<< " ";
    }
    else if(length2 > 0 && (length1 == 0 ||
            memo[length1][length2-1] > memo[length1-1][length2]))
    {
        print_diff(str1, str2, length1, length2-1);
        qDebug()<< "+"<< str2[length2];
    }
    else if(length1 > 0 && (length2=0 ||
            memo[length1][length2-1] <= memo[length1-1][length2]))
    {
        print_diff(str1, str2, length1-1, length2);
        qDebug()<< "-"<< str1[length1];
    }
}

void LCS::print_lcs(QString str1, QString str2, int length1, int length2)
{
    if (length1 == 0 && length2 == 0)
        return;

    else if (length1 == 0 && length2 > 0)
    {
        print_lcs(str1, str2, length1, length2-1);
        qDebug()<<"+"<< str2[length2-1];
    }

    else if (length1 > 0 && length2 == 0)
    {
        print_lcs(str1, str2, length1-1, length2);
        qDebug()<< "-"<< str1[length1-1];
    }

    else if (memo[length1][length2] == memo [length1-1][length2])
    {
        print_lcs(str1, str2, length1-1, length2);
        qDebug()<<"-"<< str1[length1-1];
    }
    else if(memo[length1][length2] == memo[length1][length2-1])
    {
        print_lcs(str1, str2, length1, length2-1);
        qDebug()<< "+"<< str2[length2-1];
    }
    else
    {
        print_lcs(str1, str2, length1-1, length2-1);
        qDebug() << str1[length1-1];
    }
}
