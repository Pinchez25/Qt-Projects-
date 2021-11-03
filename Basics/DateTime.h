#ifndef DATETIME_H
#define DATETIME_H
#endif // DATETIME_H

#include<QDate>
#include<QTime>
#include<QDateTime>
#include<QDebug>

class WorkWithDateTime{
public:
    void setDateTime();
    void getDateTime();
    void dateCompare();
    void dateFormats();
    void timeFormats();
    void getWeekDay();
    void ifLeapYear(QDate y);
    void validateDate();
    void add_determine_days();
    void dateTime();
    void utcTime();
};

void WorkWithDateTime::setDateTime(){
    QDate dt1{2021, 4,14};
    QTime tm{17,30,12,55};
    QTime tm2;

    tm2.setHMS(13,34,56,96);


    qDebug() <<dt1.toString();
    qDebug() <<tm.toString("hh:mm:ss.zzz");
    qDebug() <<tm2.toString("hh:mm:ss.zzz");


}
void WorkWithDateTime::getDateTime(){
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();

    qDebug() <<"Today is "<<d.toString();
    qDebug() <<"The time is "<<t.toString();
}
void WorkWithDateTime::dateCompare(){
    QDate dt1 { 2020, 4, 5 };
       QDate dt2 { 2019, 4, 5 };

       if (dt1 < dt2) {

           qDebug() << dt1.toString() << " comes before "
                << dt2.toString() << " ";
       } else {

           qDebug() << dt1.toString() << " comes after "
                << dt2.toString() << " ";
       }
}
void WorkWithDateTime::dateFormats(){
    QDate current = QDate::currentDate();
    qDebug() << "Today is " << current.toString(Qt::TextDate) << " ";
    qDebug() << "Today is " << current.toString(Qt::ISODate) << " ";

    // Custom date formats
    // d - day as a number(1-31), dd- daya as a number with leadding 0 (01-31), ddd- day abbrev (Mon to Sun)
    // dddd - long localised day name (Monday to Sunday)
    //MONTHS - M(1 to 12), MM(01-12), MMM(Jan to Dec), MMMM(January to Dec)
    //Years - yy(00 to 99), yyyy(year as four digit number)

    qDebug() <<"Today: "<<current.toString("yyyy-MMM-dd");



}
void WorkWithDateTime::timeFormats(){
    QTime tm = QTime::currentTime();
    qDebug() <<"Time: "<<tm.toString(Qt::TextDate);
    qDebug() <<"Time: "<<tm.toString(Qt::ISODate);

    // Custom formats
    // HOUR - h(0 to 23 or 1 to 12 if AM/PM),hh(00to 23 or 01 to 12), H (0 to 23, even with AM/PM), HH (00 to 23, even with AM/PM)
    //MINUTES - m(0 to 59) , mm(00 to 59)
    //SECONDS - s(0 to 59), ss(00 to 59)
    //MILLISECONDS - z(0 to 999), zzz(000 to 999)
    //AP OR A - use AM/PM display
    //ap or a - use am/pm display
    //t - timezone

    qDebug() <<"Time: "<<tm.toString("h:m:s a");

}

void WorkWithDateTime::getWeekDay(){
    QDate cd = QDate::currentDate();

    int wd = cd.dayOfWeek();


    QLocale locale(QLocale("en_US"));

    qDebug() <<"Today is "<<locale.dayName(wd);
    qDebug() <<"Today is "<<locale.dayName(wd, QLocale::ShortFormat);

}
void WorkWithDateTime::ifLeapYear(QDate y= {2020, 5, 24}){
    if(QDate::isLeapYear(y.year())){
        qDebug() <<y.year()<<" is a leap year";
    }else{
        qDebug() <<y.year()<< "is not a leap year";
    }

}
void WorkWithDateTime::validateDate(){
    QList<QDate> dates{
      QDate(2020,5,11), QDate(2020,8,1),QDate(2020,2,30)
    };

    for(int i=0;i<dates.size();i++){
        if(dates.at(i).isValid()){
            qDebug()<<"Date "<<i+1<<" is a valid date";

        }else {
            qDebug()<<"Date "<<i+1<<" is not a valid date";

}
    }
}
void WorkWithDateTime::add_determine_days(){
    // Add days
    QDate dt{2021,3,23};
    QDate nd = dt.addDays(23);

    //Daya to christmass
    QDate cd = QDate::currentDate();
    int year = cd.year();
    QDate xmas{year, 12, 25};

    qDebug()<<"23 days from "<<dt.toString()<<" is "<<nd.toString();

    qDebug()<<"It is "<<cd.daysTo(xmas)<<" days to christmass";



}
void WorkWithDateTime::dateTime(){
    //QDateTime combines QDate and QTime classes
    QDateTime cdt = QDateTime::currentDateTime();

    qDebug() <<"The current datetime is "<<cdt.toString();
    qDebug() <<"The current date is "<<cdt.date().toString();
    qDebug() <<"The current time is "<<cdt.time().toString();

}
void WorkWithDateTime::utcTime(){
    //UTC is a global time format
    QDateTime cdt = QDateTime::currentDateTime();
    QDateTime cdt2 = QDateTime::currentDateTimeUtc();

    qDebug() <<"Universal datetime: "<<cdt.toUTC().toString();
    qDebug() <<"Local datetime: "<<cdt.toLocalTime().toString();


    qDebug() <<"Universal datetime2: "<<cdt2.toString();
    qDebug() <<"Local datetime2: "<<cdt2.toLocalTime().toString();
}











