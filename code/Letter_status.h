#include"util.h"
#ifndef LETTER_STATUS_H
#define LETTER_STATUS_H
class Letters{

public:
	string Recipient_id;
	string Letter_id;
	string Date;	
	string status;
	Letters(string,string,string,string);

};

/////////////////////////////////////////////////////////////////////////////////////////////////////

class Letter_Status{
	
	list<Letters> All_letters;

public:
	Letter_Status();
	void ShowDashBoard();//done
	vector<Letters> getletters_by_id(string); //Done	 // id of Recipient
	void checkLetterStatus();//done
	Letters getletter_by_id1(string); //done                // it will give letter by Letter_id that is unique
        vector<string> extract(string);	
	void displayLetter(vector<Letters>);//Done     //it contains nultiple letters
	void UpdateLetterStatus();//done
	void printListtoFile();//Done
	void showAllLetters();
};

#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void Letter_Status::showAllLetters(){
	system("clear");
	vector<Letters> vec;
	list<Letters>::iterator it =All_letters.begin();
	while(it!=All_letters.end()){
	vec.push_back(*it);
	it++;
	}
	displayLetter(vec);
	
	};
	



void
Letter_Status::ShowDashBoard(){
turn:
system("clear");
	cout<<"\t\tSelect:\n";
	cout<<"\t\t1. Check Letter Status\n";
	cout<<"\t\t2. Update Letter Status\n";
	// you cannot add letters here and you cannot delete letters from anywhere
	cout<<"\t\t3. Show All Letters\n";
	cout<<"\t\t4. Back\n";
	string n;cin.clear();getline(cin,n);
	if(n.size()>1){
	goto turn;
	}
	switch (n[0]){
	case '1': checkLetterStatus();break;
	case '2': UpdateLetterStatus();break;
	case '3': showAllLetters();break;
	case '4': return; break;
	default: goto turn;
	}
	goto turn;









}


void Letter_Status::checkLetterStatus(){
Ram:
system("clear");
cout<<"\t\tEnter Letter_Code if you know else enter NA\n";
string letter_code;
	cin.clear();getline(cin,letter_code);
if(letter_code=="NA"){
cout<<"\t\tEnter the Recipient_ID\n";
string id;
cin.clear();getline(cin,id);

vector<Letters> letter_with_Recipient_id = this->getletters_by_id(id);//id of recipient

displayLetter(letter_with_Recipient_id);
}else{
	Letters letter = getletter_by_id1(letter_code);
	if(letter.Recipient_id=="error"){
	cout<<"\t\tLetter_code doesn't exist Please try again\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		
	goto Ram;
	}else{
	
	vector<Letters> vec;
	vec.push_back(letter);
	displayLetter(vec);
	
		return;
	}
}
};
void Letter_Status::UpdateLetterStatus(){
	system("clear");
	cout<<"\t\tEnter Letter code or Enter Back\n";
	string code;
	cin.clear();getline(cin,code);
	if(code=="back"||code=="Back"){
	return;
	}else{
	list<Letters>::iterator it=All_letters.begin();
	while(it!=All_letters.end()){
	if(it->Letter_id == code){
	cout<<"\t\tEnter new Status\n";
	string status;
	//cin.clear();
	//cin.ignore(INT_MAX , '\n' );
	//getline(cin,status);
	cin.clear();getline(cin,status);	
	it->status=status; //4 sized vector
	printListtoFile();
	cout<<"\t\tstatus has been update successfully\n";	
	return;
	}
	it++;
	}
	cout<<"\t\tThis Letter codedoesn't exist\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		}
	};

void Letter_Status::displayLetter(vector<Letters> vec){
	vector<Letters>::iterator it =vec.begin();
	if(vec.size()==0){
	cout<<"\t\tNo Letters exist with this Letter code or Recipient id\n";
	cout<<"\t\tEnter any non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	return;
	}	
	
	cout<<setw(10)<<"Recipient_id"<<setw(20)<<"Letter_id"<<setw(10)<<"status"<<setw(19)<<"Date\n";
	while(it!=vec.end()){
	//vector<string> single=extract(*it);
	
	cout<<setw(10)<<(it->Recipient_id)<<setw(20)<<(it->Letter_id)<<setw(10)<<(it->status)<<setw(19)<<(it->Date)<<endl;
	it++;	
	}
	cout<<"\t\tTaking you back\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		return;
};
Letters Letter_Status::getletter_by_id1(string id){
	//it will return a letter with that letter id 
	list<Letters>::iterator it =All_letters.begin();
	while(it!=All_letters.end()){
	if(it->Letter_id == id ){
	return *it;
	}
	it++;
	}
	Letters get("error","error");
	return get;
	};
vector<Letters> Letter_Status::getletters_by_id(string id)//this will be the id of recipient 
	{	vector<Letters> vec;
	list<Letters>::iterator it = All_letters.begin();
	while(it!=All_letters.end()){
	if(it->Recipient_id == id){
	vec.push_back(*it);
	}
	it++;
	}
	return vec;
	};
void Letter_Status::printListtoFile(){  // obviously you have updated status of any letter in file and now you need to update it in file
	ofstream outFile("all_letters1.txt");	
	if(outFile.is_open()){	
	list<Letters>::iterator it =All_letters.begin();
	while(it!=All_letters.end()){
	string info =it->Recipient_id+'|'+it->Letter_id+'|'+it->status+'|'+it->Date;
	outFile<<info<<endl;
	it++;
	};//it is guarnted that you will print all the letters again with updated status
	}else{
	cout<<"all_letters1.txt file not openend\n";
	}
	};

Letter_Status::Letter_Status(){
	ifstream inFile("all_letters1.txt");
	if(inFile.is_open()){
	string line;
	while(getline(inFile,line)){
	vector<string> vec =this->extract(line);
	Letters L1(vec[0],vec[1],vec[2],vec[3]);// vec[0] is recipient id vec[1] is letter id 2 is status 3 is date
	All_letters.push_back(L1);
	}
	}else{
	cout<<"in file all_letters1.txt not opened\n";
	}
};
vector<string> Letter_Status::extract(string info){
	int i=0;
	vector<string> vec;
	while(i<=info.size()){
	string h;
	int j=i;
	while(info[j]!='|' && info[j]!='\0'){
	h+=info[j];
	j++;
	i++;
	}
	vec.push_back(h);
	i++;
	};

return vec;
};*/
