#include"util.h"
#include"instituteMemberDatabase.h"
#include"Date.h"
#ifndef LETTER_DATABASE_H
#define LETTER_DATABASE_h
class Letter{
public:
string Letter_code;
string status;
string recieving_date;
string Recipient_id;
int choice;
public:
//////////////////////////////////////////////////
static string getRecivingDate();
static vector<string> getinfo(string);
Letter(string,string,string,string,int);
static Letter makeLetter(string);//string will be in format id|code|status|date|choice
///////////////////////////////////////////////////

};
/*

Letter Letter::makeLetter(string info){
//cout<<"in makeLetter\n";
vector<string> inf = Letter::getinfo(info);

//cout<<inf[0]<<" "<<inf[1]<<" "<<inf[2]<<endl;

//cout<<"go ing to Letter()\n";
Letter L1(inf[0],inf[1],inf[2],1);
return L1;
}
;

vector<string> Letter::getinfo(string info){
//cout<<"in getinfo\n"<<info<<endl;
vector<string> vec;
string h[4];
//cout<<info<<endl;
int i=0;
int j=0;
while(j<4){
while(info[i]!='|' && info[i]!='\0'){
h[j]+=info[i];
i++;
}
//cout<<h[j]<<endl;
i++;
j++;
}
vec.push_back(h[0]);
vec.push_back(h[1]);
vec.push_back(h[2]);
vec.push_back(h[3]);
//cout<<"get info over\n";
return vec;

};
/*class Date{
public:
static string dateString(tm *locTime)
{
return to_string(locTime->tm_year) + "/" + to_string(locTime->tm_mon) + "/" + to_string(locTime->tm_mday);
};
};
*/
/*
Letter::Letter(string Recipient_id,string Letter_code,string status,int choice){
//cout<<"entered in Letter\n";
this->Recipient_id=Recipient_id;
//cout<<"id initialized\n";
this->Letter_code=Letter_code;
//cout<<"Letter code set\n";
this->status=status;

//cout<<"yahan tak sab thik hai\n";
this->recieving_date = Letter::getRecivingDate();
//cout<<"reciving date "<<this->recieving_date<<endl;
this->choice=choice;
}; //icsdc
//id,code,status,date,choice


string Letter::getRecivingDate(){
// how to get current Date in c++
   string h= Date::dateString();
return h;

};//
*/
class LetterDatabase{
list<Letter> All_letters;


public:
////////////////////////////////////////////////
LetterDatabase();
list<Letter> getList();
void add(InstituteMember,int,string,string,string);
void printListtoDataBase();
void updateLetterinList(Letter L);
Letter getLetter_by_Letter_Code(string);
vector<Letter> getLetter_by_Letter_status(string);
vector<Letter> getLetter_by_RecivingDate(string); // in letter data base letter will be stored be like id|code|status|date|choice
///////////////////////////////////////////////////////
};
#endif
/*
LetterDatabase::LetterDatabase(){
ifstream inFile;
inFile.open("all_letters1.txt");
//cout<<"pl\n";
if(inFile.is_open()){
string letterinfo;
while(getline(inFile,letterinfo)){
//cout<<"uouo\n";
	Letter L1= Letter::makeLetter(letterinfo); // id|code|status|date|choice
	All_letters.push_back(L1);
	}
//cout<<"uop\n";
	}else{
//cout<<"all letters file not opened\n";
}
};
list<Letter> LetterDatabase::getList(){
return All_letters;
};

void LetterDatabase::add(InstituteMember mem,int choice,string letter_code,string status){
list<Letter>::iterator it=All_letters.begin();
while(it!=All_letters.end()){
if(it->Letter_code==letter_code){
it->Recipient_id=mem.Recipient_id;
it->choice = choice;
it->status=status;
return;
}
it++;
}
Letter L1(mem.Recipient_id,letter_code,status,choice);
All_letters.push_back(L1);
printListtoDataBase();
};

void LetterDatabase::printListtoDataBase(){
ofstream outFile;
outFile.open("all_letters1.txt");
if(outFile.is_open()){

list<Letter>::iterator it=All_letters.begin();
while(it!=All_letters.end()){
stringstream ss; ss<<( it->choice);
string ch;
ss>>ch;
string info=it->Recipient_id+'|'+it->Letter_code+'|'+it->status+'|'+it->recieving_date+'|'+ch;
outFile<<info<<endl;
it++;
}
outFile.close();
}
};


void LetterDatabase::updateLetterinList(Letter L){
list<Letter>::iterator it =All_letters.begin();
while(it!=All_letters.end()){
if(it->Letter_code==L.Letter_code){
*it=L;
return;
}
it++;
}
All_letters.push_back(L);
};

vector<Letter> LetterDatabase::getLetter_by_Letter_status(string inf){

vector<string> info=Letter::getinfo(inf);

vector<Letter> vec;

list<Letter>::iterator it=All_letters.begin();
while(it!=All_letters.end()){
if(it->status==info[2]){
vec.push_back(*it);
}
it++;
}
return vec;

};
vector<Letter> LetterDatabase::getLetter_by_RecivingDate(string info){
vector<string> inf= Letter::getinfo(info);
vector<Letter> vec;
list<Letter>::iterator it=All_letters.begin();
while(it!=All_letters.end()){
if(it->recieving_date==inf[3]){
vec.push_back(*it);
}
it++;
}
return vec;
};

*/

