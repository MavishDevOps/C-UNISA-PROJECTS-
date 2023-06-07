#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
#include<QDebug>
#include<QInputDialog>
#include<QString>
#include<QMessageBox>


QString User_Login(QString & usrname ,QString initial_password)

{



   QString user_fullname=QInputDialog::getText(0,"Good day User, please enter in your fullname","Enter in your namemfollowed by your surname:");



      QStringList information_user=user_fullname.split(",",QString::SkipEmptyParts);

       QString usrname_parts;

       usrname_parts=information_user.join(",");


      QString name=usrname_parts.section(",",0);
      QString surname=usrname_parts.section(",",-1);






   //there will be two algorithms to generate the username ,one being a standard  one whereby the length of the user's fullname and surname is entered has more than 5 letters and the other will be for those with less than 5 letters (i.e; 4 letters

   if(information_user.size()>=2)//validation that if our user has entered his/her name and surname
   {

       QString name_Charactrs;
       QString surname_Charactrs;

                    if(surname.size()>=5)//for users with surnames having length of 5 or more such as Williams, Smith,Torres
                      {

                        QString frst_alphbet=QString(surname.at(0));
                        frst_alphbet.toUpper();

                        QString secnd_alphbet=QString(surname.at(1));
                        secnd_alphbet.toLower();

                        QString thrd_alphbet=QString(surname.at(2));
                        thrd_alphbet.toLower();

                        QString frth_alphbet=QString(surname.at(3));
                        frth_alphbet.toLower();


                        surname_Charactrs=frst_alphbet+secnd_alphbet+thrd_alphbet+frth_alphbet;
                        name_Charactrs=QString(name.at(1));


                    }else if(surname.size()<=4)//for surnames with 4 alphabets or less such as Owen,West,Lee,Chi
                    {
                        QString frst_alphbet=QString(surname.at(0));
                        frst_alphbet.toUpper();

                        QString secnd_alphbet=QString(surname.at(1));
                        secnd_alphbet.toLower();

                        QString thrd_alphbet=QString(surname.at(2));
                        thrd_alphbet.toLower();


                        surname_Charactrs=frst_alphbet+secnd_alphbet+thrd_alphbet;
                        name_Charactrs=QString(name.at(1))+QString(name.at(2));


                    }
                    else{//If username is less than 4 characters then append zero

                         usrname+="0";

                     }

                            usrname=surname_Charactrs+name_Charactrs.toLower();


                            //Algorithm to create password
                                   for(int i=0;i<5;i++)
                                   {
                                       int index_Passwrd=qrand()%name.size();
                                       initial_password+=name[index_Passwrd];

                                   }

   }

   QMessageBox::information(0,"Your username:  Your initial password: ",usrname,initial_password);


return initial_password;


}






int main(int argc, char *argv[])
{
    QApplication Cos2614_Login(argc, argv);

    QString password;//possible password=Mcheial // please note this code was created on a poorly installed Qtcreator hence could not produce a valid output
    QString Usr_ID;//possible username WenMi

    User_Login(Usr_ID,password);


    return Cos2614_Login.exec();
}
