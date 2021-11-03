#ifndef QT_STRINGS_H
#define QT_STRINGS_H
#include<QString>
#include<qstring.h>
#include<QDebug>
#define STR_EQUAL 0


#endif // QT_STRINGS_H

// QString - class for working with qt strings
// Stores 16-bit QChars

class WorkWithString{
private:
    //QString *str, str2, str3, str4;

public:

    void initialiseString();
    // The lenght of the string is returned by length(),size() and count() methods
    QString getSize(QString str);

    QString modifyString(QString st);

    void accessString(QString st);
    void validateString(QString st);
    void buildString();
    void iterateString(QString st);
    void stringComparison(QString s1, QString s2);
    void stringConversion();
    void Letters();


};
void WorkWithString::initialiseString(){
    QString st = "Peter";
    QString st2{"Thua"};
    QString st3("Mwangi");
    // As an array of characters
    QChar st4[3] = {'1','2','3'};
    QString st5(st4, 3);

    QString str3;

    // set the size of the string
    str3.resize(3);
    // initialize the string per character
    str3[0] = QChar('P');
    str3[1] = QChar('e');
    str3[2] = QChar('t');

    qWarning() <<"=========== Initialising a string =============\n";
    qDebug() <<st+" "+st2+" "+st3+" "+st5+"  "+str3;



}
QString WorkWithString::getSize(QString str){
    QString d{};
    QString s = d.setNum(str.size()) + " "+d.setNum(str.length()) +" "+d.setNum(str.count());
    return s;
}
QString WorkWithString::modifyString(QString st){
    //Convert string to uppercase
    QString upper = st.toUpper();

    //convert to lowercase
    QString lower = st.toLower();

    //append a string
    QString appended = st.append(" this is appended");

    // prepend a string
    QString prepend = st.prepend("Prepended string ");

     st.replace(0,3,"Girl");
     st.remove(4,5);


    return "UPPER: "+upper+" ,LOWER: "+lower+" ,APPENDED: "+appended+" ,PREPENDED: "+prepend+" \nRemove and replace "+st;
}

void WorkWithString::accessString(QString st){
    QChar first = st[0];

    QChar third = st.at(2);

     //               substrings

    // return the n rightmost characters of the string

    QString right = st.right(4);

    // Return a string of certain width with a fill charcter followed by the string
    QString right2 = st.rightJustified(20,'#');

    //return the leftmost n characters
    QString left = st.left(4);

    //Get a number of characters starting from a certain position
    QString mid = st.mid(3,4);

//    QStringRef sub(&st, 0, 5);





    qDebug()<<"The first character is "<<first;
    qDebug() <<" The 3rd character is "<<third;
    qDebug()<<" Last 4 characters: "<<right;
    qDebug()<<" "<<right2;
    qDebug()<<"First 4 characters"<<left;
    qDebug()<<"4 xters from the 3rd position: "<<mid;

}

void WorkWithString::validateString(QString st){
    bool endString = st.endsWith("car");
    bool startsWith = st.startsWith("Bilingual");

    if(endString){
        qDebug()<<" The string doesn't end with car";
    }
    if(!startsWith){
        qDebug()<<" The string does not start with bilingual";
    }
    if(!st.isEmpty()){
        qDebug() <<"The string is not empty";
    }

    // clear the string - makes it null
    st.clear();
   if(st.isNull()){
        qDebug()<<" The string is null";
    }

/*
 * NOTE: All null strings are empty but an empty string are not necessarily null;
 * An empty string has a size==0

*/
}
void WorkWithString::buildString(){
    // Allows us to replace specific control characters with actual values.
    // We use the arg method to do the interpolation.

    QString s1 = "There are %1 white roses";
    int n = 12;

    //replace the marker with n
    qDebug() << s1.arg(n)<<"";

    /*
     * The markers to be replaced begin with the % character. The following xter is
     * a number specifying the argument. There can be multiple arguments for a string.
     * NB: arg method is overloaded,it can take integers, long numbers, chars and QChars etc.
*/
    QString s2 = "We have %1 lemons and %2 oranges";
    int ln = 12;
    int on = 4;
    // multiple args called in a chain
    qDebug()<<s2.arg(ln).arg(on)<<"";
}
void WorkWithString::iterateString(QString st){

    qDebug() << "Using for in loop";
    for(QChar qc: st){
        qDebug()<<qc<<" ";
    }
    qDebug()<<"\n";

    qDebug()<<"Using pointers, begin() and end() functions";
    for(QChar *it = st.begin(); it!=st.end();++it){
        qDebug()<<*it<<" ";
    }
    qDebug()<<"\n ";

    qDebug()<<"Using for loop";
    for(int i=0;i<st.size();i++){
        qDebug()<<st.at(i)<<" ";
    }


}
void WorkWithString::stringComparison(QString s1, QString s2){
    // compare() method - compares 2 strings and returns an integer:
    // if returned int<0, str1<str2, else if int> 0, str1>str2, if int==0, str1==str2
    int compare = s1.compare(s2);

    if(compare == STR_EQUAL){
        qDebug()<<" Both strings are equal [compared with CaseSensitive]";
    }else if(compare > STR_EQUAL){
        qDebug()<<" s1 > s2";
    }else{
        qDebug()<<"S1< S2";
    }

    // case insensitive compare
    int compare2 = s1.compare(s2, Qt::CaseInsensitive);

    if(compare2 == STR_EQUAL){
        qDebug()<<" Both strings are equal [Case insensitive comparison]";
    }else if(compare2 > STR_EQUAL){
        qDebug()<<" s1 > s2";
    }else{
        qDebug()<<"S1< S2";
    }


}
void WorkWithString::stringConversion(){
    QString s1{"12"}, s2{"15"},s3,s4;
    int n=12,n2=87;

    qDebug()<<"String to integer "<<s1.toInt();
    qDebug()<<"String to double "<<s2.toDouble();
    qDebug()<<"Number to string "<<s3.setNum(n) + s4.setNum(n2);


}
void WorkWithString::Letters(){
     int digits  = 0;
     int letters = 0;
     int spaces  = 0;
     int puncts  = 0;

     QString str { "7 white, 3 red roses." };

     for (QChar s : str) {

       if (s.isDigit()) {
         digits++;
       } else if (s.isLetter()) {
         letters++;
       } else if (s.isSpace()) {
         spaces++;
       } else if (s.isPunct()) {
         puncts++;
       }
     }

     qDebug() << QString("There are %1 characters").arg(str.count()) << " ";
     qDebug() << QString("There are %1 letters").arg(letters) << " ";
     qDebug() << QString("There are %1 digits").arg(digits) << " ";
     qDebug() << QString("There are %1 spaces").arg(spaces) << " ";
     qDebug() << QString("There are %1 punctuation characters").arg(puncts) << " ";
}



























