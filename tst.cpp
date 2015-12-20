#include "tst.h"

using namespace tries;

TST::TST()
{
}

int TST::get(QString key)
{
    Node *node = get(root, key, 0);

    if( node == NULL )
        return (int)NULL;

    return node->value;
}

Node* TST::get(Node* node, QString key, int char_index)
{
    if( node == NULL )
        return NULL;

    QChar character = key.at(char_index);

    if( character < node->character )
        return get(node->left, key, char_index);

    else if( character > node->character )
        return get(node->right, key, char_index);

    else if(character < key.length() - 1)
        return get(node->middle, key, char_index + 1);

    else
        return node;
}

void TST::insert(QString key, int value)
{
    root = insert(root, key, value, 0);
}

Node* TST::insert(Node* node, QString key, int value, int char_index)
{
    QChar character = key.at(char_index);

    if( node == NULL )
    {
        node = new Node;
        node->character = character;
    }

    if( character < node->character )
        return insert(node->left, key, value, char_index);

    else if( character > node->character )
        return insert(node->right, key, value, char_index);

    else if(character < key.length() - 1)
        return insert(node->middle, key, value, char_index + 1);

    else node->value = value;

    return node;
}

QString TST::match(QString str)
{
    QString key("");
    search(root, 0, key, str);
    return key;
}

void TST::search(Node *node, int index, QString str, QString match)
{
    if(node == NULL)
        return;
    QChar character = match[index];
    if(character < node->character)
    {
        search(node->left, index, str, match);
    }

    else if(character > node->character)
    {
        search(node->right, index, str, match);
    }

    else
    {
        if(index < str.length()-1)
        {
            match.operator +=(character);
            search(node->middle, index+1, str, match);
        }
        else if (index == str.length()-1 && node->value != NULL)
        {
            match.operator +=(character);
            return;
        }
    }
}
