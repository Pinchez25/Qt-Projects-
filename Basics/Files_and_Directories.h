#ifndef FILES_AND_DIRECTORIES_H
#define FILES_AND_DIRECTORIES_H

#endif // FILES_AND_DIRECTORIES_H
#include<QDebug>
#include<QFileInfo>
#include<QTextStream>
#include<QDir>

class FileDirectories{
public:
    void fileSize();
    void readFile();
    void writeToFile();
    void copyFile();
    void fileOwner();
    void fileInfo();
    void workWithDirectories();
    void specialPaths();
    void filePaths();
    void filePermissions();
    void directoryContents();


};
void FileDirectories::fileSize(){
    QString filename = "C:\\JCrack\\jetbrains-agent.jar";

    QFile f{filename};

    if(!f.exists()){
        qWarning("The file does not exist");

    }
    QFileInfo fileinfo{filename};

    // qint64 is a type guaranteedto be 64 bit on all supported platforms.
    qint64 size = fileinfo.size();

    qDebug() <<"The size is: "<<size<<" bytes";


}
void FileDirectories::readFile(){
    QFile f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};
  // Simply QIODevice::ReadOnly
    if(!f.open(QIODevice::OpenModeFlag::ReadOnly)){
        QString str = "Error: "+f.errorString();
        qWarning()<<str;

    }
    QTextStream in{&f};

    while(!in.atEnd()){
        QString line = in.readLine();
        qDebug() <<line;
    }


}
void FileDirectories::writeToFile(){
    QTextStream out{stdout};
    QFile f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

    if(f.open(QIODevice::WriteOnly)){
        QTextStream out(&f);

        out<<"Name: Peter\n";
        out<<"Age: 23\n";
        out<<"Status: Single";


    }else{
        qWarning()<<f.errorString();
    }
}
void FileDirectories::copyFile(){
    QString src{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

    if(!QFile{src}.exists()){
        qWarning()<<" The source file doesn't exist";
    }

    QString dest{"C:/Users/thuam/Desktop/copied.txt"};


       QFile::copy(src, dest);



}
void FileDirectories::fileOwner(){
     QString f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

     QFileInfo info{f};

     QString group = info.group();
     QString owner = info.owner();


     qDebug()<<" ";
     qDebug()<<"Group: "<<group;
     qDebug()<<"Owner: "<<owner;
}
void FileDirectories::fileInfo(){
    QFile f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

    QFileInfo info{f};

    QDateTime last_read = info.lastRead();
    QDateTime last_modidied = info.lastModified();


    qDebug() <<"Last read: "<<last_read.toString();
    qDebug() <<"Last modified: "<<last_modidied.toString();


}
void FileDirectories::workWithDirectories(){
    QDir dir;

   dir.mkdir("Images");
   qDebug()<<dir.absolutePath();




    dir.mkdir("Assets");

    if(dir.exists("Assets")){
        dir.rename("Assets","newdir");
    }
    dir.mkpath("temp/newdir");


}
void FileDirectories::specialPaths(){
    qDebug()<<"Current path: "<<QDir::currentPath();
    qDebug()<<"Home path: "<<QDir::homePath();
    qDebug()<<"Temporary path: "<<QDir::tempPath();
    qDebug()<<"Root path: "<<QDir::rootPath();
}
void FileDirectories::filePaths(){
    QFile f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

    QFileInfo info{f};
    QString absPath = info.absoluteFilePath();
      QString baseName = info.baseName();
      QString compBaseName = info.completeBaseName();
      QString fileName = info.fileName();
      QString suffix = info.suffix();
      QString compSuffix = info.completeSuffix();

      qDebug() << "Absolute file path: " << absPath ;
      qDebug() << "Base name: " << baseName ;
      qDebug() << "Complete base name: " << compBaseName ;
      qDebug() << "File name: " << fileName ;
      qDebug() << "Suffix: " << suffix ;
      qDebug() << "Whole suffix: " << compSuffix ;

}
void FileDirectories::filePermissions(){
    QString f{"C:\\Users\\thuam\\Documents\\QtC++ Projects\\Qt Tutorial\\Basics\\Files\\doc.txt"};

    auto ps = QFile::permissions(f);


    QString fper;

    if(ps & QFile::ReadOwner){
        fper.append('r');
    }else{
        fper.append("-");
    }

    if(ps & QFile::WriteOwner){
        fper.append('w');
    }else{
        fper.append('-');
    }

    if (ps & QFile::ExeOwner) {

          fper.append('x');
      } else {
          fper.append('-');
      }

      if (ps & QFile::ReadGroup) {

          fper.append('r');
      } else {
          fper.append('-');
      }

      if (ps & QFile::WriteGroup) {

          fper.append('w');
      } else {
          fper.append('-');
      }

      if (ps & QFile::ExeGroup) {

          fper.append('x');
      } else {
          fper.append('-');
      }

      if (ps & QFile::ReadOther) {

          fper.append('r');
      } else {
          fper.append('-');
      }

      if (ps & QFile::WriteOther) {

          fper.append('w');
      } else {
          fper.append('-');
      }

      if (ps & QFile::ExeOther) {

          fper.append('x');
      } else {
          fper.append('-');
      }

      /*
       * NOTE: The & operator is used to determine whether the returned
       * enumeration consists of the QFile::FLAG flag.
*/

     qDebug() <<fper;

}
void FileDirectories:: directoryContents(){
    QString directory = "C:/Users/thuam/Desktop/C++";

    QDir dir{directory};

    if(!dir.exists()){
        qWarning("The directory does not exist");
    }

    // specify the kind of files to be returned by the entryInfoList
    dir.setFilter(QDir::Files | QDir::AllDirs);

    //order of the files used by the entryInfoList
    dir.setSorting(QDir::Size | QDir::Reversed);

    //entryInfoList() returns a list of QFileInfo objects for all the fies and directories in the directory
    // QFileInfoList == QList<QFileInfo>
    QFileInfoList list = dir.entryInfoList();

    int max_size = 0;

    for(QFileInfo finfo:list){
        QString name = finfo.fileName();

        int size = name.size();

        if(size > max_size){
            max_size = size;
        }
    }

    // This adds 2 spaces to the length of the column
    int len = max_size + 2;

    qDebug() <<QString("Filename").leftJustified(len).append("Bytes");

    for(int i=0; i< list.size();++i){
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));

        qDebug() << str;
    }

}



















