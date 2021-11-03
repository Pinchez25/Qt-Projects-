#ifndef CUSTOM_CLASS_SORTING_CONTAINERS_H
#define CUSTOM_CLASS_SORTING_CONTAINERS_H

#endif // CUSTOM_CLASS_SORTING_CONTAINERS_H
#include<QString>
class Book
{
public:
    Book(QString, QString);
    QString getAuthor() const;
    QString getTitle() const;

private:
    QString author, title;
};
