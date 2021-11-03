#include <QCoreApplication>

#include<QDebug>
#include "Qt_Strings.h"
#include "DateTime.h"
#include "Containers.h"
#include "algorithm"
#include "Custom_Class_Sorting_Containers.h"
#include<QVector>
#include "Files_and_Directories.h"

bool compareByTitle(const Book &b1, const Book &b2){
    return b1.getTitle() < b2.getTitle();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
     * For debugging purposes, we use the qDebug(), qWarning(),
     * qCritical() and qFatal() fucntions.

*/
    // ####################### Qt Strings ################################

//    QString sf = "Peter has a car";
//    //NOTE: The two strings have different cases for has
//    QString sf2 = "Peter HAS a car";
//    QString sf3 = "Play footbal";
//    WorkWithString s;
//    s.initialiseString();
//    qDebug() << "Size of the string: " + s.getSize(sf);
//    qDebug() <<s.modifyString(sf);
//    s.accessString(sf);
//    s.validateString(sf);
//    s.buildString();
//    qDebug()<<"\nLooping through a string";
//    s.iterateString(sf);
//    // all lowercase xters are > uppercase counterparts
//    s.stringComparison(sf, sf2);
//    s.stringComparison(sf,sf3);
//    s.stringConversion();
//    s.Letters();



   // ######################  Qt Date and Time ############################

//    WorkWithDateTime dt;

//    dt.setDateTime();
//    dt.getDateTime();
//    dt.dateCompare();
//    dt.dateFormats();
//    dt.getWeekDay();
//    dt.timeFormats();
//    dt.ifLeapYear({2021,4,23});
//    dt.validateDate();
//    dt.add_determine_days();
//    dt.dateTime();
//    dt.utcTime();



    // #############################   Qt Containers ##############################
//    Containers c;
//    c.Vectors();
//    c.List();
//    c.StringList();
//    c.Sets();
//    c.Maps();



    //#############################  Custom sorting class ##########################



//    QVector<Book> books = {
//      Book("Jack London","The call of the wind"),
//      Book("Honoré de Balzac", "Father Goriot"),
//      Book("Leo Tolstoy", "War and Peace"),
//      Book("Gustave Flaubert", "Sentimental education"),
//      Book("Guy de Maupassant", "Une vie"),
//      Book("William Shakespeare", "Hamlet")
//    };



//    std::sort(books.begin(), books.end(),compareByTitle);

//    for(Book& bk: books){
//        qDebug() <<bk.getAuthor()<<": "<<bk.getTitle();
//    }


    // ##############################  Qt FIles and Directories ##############################

    FileDirectories fd;
    fd.fileSize();
    fd.writeToFile();
    fd.readFile();
    fd.copyFile();
    fd.fileOwner();
    fd.fileInfo();
    fd.workWithDirectories();
    fd.specialPaths();
    fd.filePaths();
    fd.filePermissions();
    fd.directoryContents();




    return a.exec();
}
