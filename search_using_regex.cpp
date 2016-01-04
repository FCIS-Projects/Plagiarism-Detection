#include "search_using_regex.h"
#include <QDebug>
#include <QRegularExpression>

Search_Using_RegEx::Search_Using_RegEx()
{

}

Search_Using_RegEx::Search_Using_RegEx( QString *regular_expression, QString *str )
{

}

Search_Using_RegEx::Search_Using_RegEx( QString *regular_expression, QFile *file )
{
    this->file = file;
    this->regular_expression = regular_expression;
    prepare();
}

void Search_Using_RegEx::prepare()
{
//    QFile file("in.txt");
//    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
//        return;
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in( file );
    QString line;
    int comment_index;
    QRegularExpression *regex = new QRegularExpression("\\|/*");

    while ( !in.atEnd() )
    {
        line = in.readLine();



        if( comment_index = line.indexOf("\\") -1 )
        {

        }
    }
}
