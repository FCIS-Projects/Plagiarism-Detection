#ifndef TST_H
#define TST_H

#include <QString>
#include <QList>
#include <QChar>

namespace tries
{
    struct Node
    {
        int value;
        QChar character;

        Node* left;
        Node* middle;
        Node* right;
    };

    class TST
    {
    private:
        Node* root;

    public:
        TST();
        ~TST();

        int get(QString key);
        void insert(QString key, int value);
        Node* insert(Node* node, QString key, int value, int char_index);
        QString match(QString str);

    private:
        Node* get(Node* node, QString key, int char_index);
        void search(Node* node, int index, QString str, QString match);
    };
}

#endif // TST_H
