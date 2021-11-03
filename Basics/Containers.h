#ifndef CONTAINERS_H
#define CONTAINERS_H

#endif // CONTAINERS_H
#include<QDebug>
#include<algorithm>

using namespace std;
class Containers
{
public:
    Containers() {
        qDebug() <<"\n======================================== ";
        qDebug() <<"Containers in qt c+++ ";
        qDebug() <<"========================================== ";
    }
    void Vectors();
    void List();
    void StringList();
    void Sets();
    void Maps();
};

void Containers::Vectors(){
    qDebug()<<"QVector template class provides dynamic array\n ";

    // int vector
    QVector<int> vals = {1,2,3,4,5};

    // Size of the vector
    qDebug()<<"The size of the vector is: "<<vals.size();
    qDebug()<<"The first item is: "<<vals.first();
    qDebug()<<"The last item is: "<<vals.last();


    // Add items to the vector at the end of the vector
    vals.append(6);
    vals.append(0);
    qDebug()<<"Elements: ";

    // Loop through the vector
    for(int val: vals){
        qDebug()<<val;
    }



}
void  Containers::List(){
    QList<QString> authors = {
      "Balzac","Tolstoy","Gulbranssen","London"
    };


    // loop through the list
    for (int i=0;i<authors.size() ;i++ ) {
        qDebug()<<authors.at(i);

    }
    // << operator inserts new elements to the container
    authors<<"Galsworthy"<<"Sienkiewicz";

    // Sort the list
    sort(authors.begin(), authors.end());


    //output the sorted list
    qDebug()<<" ";
    qDebug()<<"Sorted: ";
    qDebug()<<" ";

    for(QString author: authors){
        qDebug()<<author;
    }

}
void Containers::StringList(){
    qDebug()<<" ";
    // QStringList() is a convinience container that provides a list of strings
    // Has fast index-based accesss as well as fast insertions and removals
    QString string = "coin, book, cup, pencil, clock, bookmark";

    // split cuts the string into substrings according to the provided separator,
    // and returns them in a list
    QStringList items = string.split(",");

    // provides a const iteartor
    QStringListIterator it(items);

    while(it.hasNext()){
        qDebug()<<it.next().trimmed();
    }

//    for(QString item: items){
//        qDebug()<<item;
//    }

}
void Containers::Sets(){
    // QSet provide a single valued mathematical set with fast lookups
    // The values are sorted in an unspecified order
    QSet<QString> cols1 = {"yellow","red","blue"};
    QSet<QString> cols2 = {"blue","pink","orange"};

    qDebug()<<"There are "<<cols1.size()<<" values in the set";

    // Add a new value to the set
    cols1.insert("brown");
    qDebug()<<"There are "<<cols1.size()<<" values in the set";
    // unite the 2 sets . cols1 set will have all items inserted from cols2
    // set that are not already present
    cols1.unite(cols2);

    qDebug()<<"There are "<<cols1.size()<<" values in the set";

    qDebug()<<" ";
    for(QString val: cols1){
        qDebug()<<val;
    }

    // sorting of a set is not supported
    // To sort a set we create a list out of it and sort it.
    // values() method returns a new QList containing the elements in the set.

    QList<QString> lcols = cols1.values();

    sort(lcols.begin(), lcols.end());

    qDebug()<<" ";
    qDebug()<<"************************************* ";
    qDebug()<<"Sorted Set: ";
    for(QString val: lcols){
        qDebug()<<val;
    }

}
void Containers::Maps(){
    // A map is an associative array(dictionary) that stores key-value pairs.
    // It provides fast lookup of the value associated with a key.
    QMap<QString, int> items = {
        {"Coins",5},
        {"books",3}
    };

    // Add a new item to the map
    items.insert("bottles",7);

    QList<int> values = items.values();

    qDebug()<<"Values: ";
    for(int val: values){
        qDebug()<<val;
    }
    qDebug()<<" ";
    QList<QString> keys = items.keys();
    qDebug()<<"Keys: ";
    for(QString key: keys){
        qDebug()<<key;
    }

    QMapIterator<QString, int> it(items);

    qDebug()<<" ";
    qDebug()<<"Key-Value pairs: ";

    while(it.hasNext()){
        it.next();
        qDebug()<<it.key()<<":"<<it.value();
    }
    for(auto pair: items){
        qDebug()<<pair;
    }


}


























