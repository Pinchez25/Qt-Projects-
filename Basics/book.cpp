#include<QString>
#include "Custom_Class_Sorting_Containers.h"

Book::Book(QString auth, QString tit){
    author = auth;
    title = tit;
}
QString Book::getAuthor() const{
    return author;

}
QString Book::getTitle() const{
    return title;
}
