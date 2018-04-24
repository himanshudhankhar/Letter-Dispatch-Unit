#include"instituteMemberDatabase.h"
#include"Date.h"
#ifndef COMPLAIN_H
#define COMPLAIN_H
#include"util.h"
class Complain{
	//complain will contain complainee_id | regarding which matter | status of complain |Date of complain Recieved
	public:	
	string complainee_id;
	// it is guaranteed that complainee will be a institute member
	string matter;
	// matter can be anything since complain will be resolved manually whether it be letter not recieved or wrong delivery or any database wrong update
	string status_of_complain;
	// status can registered | unresolved | resolved |underEnquiry
	string DateR;

	string ComplainID;
	
public:
 	Complain(string,string,string,string);
	void updateStatus(string);
	string getComplainID();	
	
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Complain::Complain(string id="",string matter ="",string status ="",string date=""){
this->complainee_id = id;
	this->matter =matter;
	this->status_of_complain = status;
	this->DateR = date;//Date::dateString();
	this->ComplainID = "CP"+id+"DT"+this->DateR;
};

void Complain::updateStatus(string newStatus){
	this->status_of_complain = newStatus;
};

string Complain::getComplainID(){
	return this->ComplainID;
	};
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
class ComplainList{
	list<Complain> All_complains;
	InstituteMemberList IMB;
	
	public :
		ComplainList();       //Done
		void ShowDashBoard(); //Done
		void updateComplainStatus(); // Done
		vector<Complain> findComplain_by_RecipientID(string);   //Done   //auxiliary and used in check complain status
		vector<Complain> findComplain_by_ComplainId(string);     //Done      //auxiliary
		void showAllComplains();             //Done        
		void displayComplains(vector<Complain>);  //Done   //auxiliary // it can display single complain as well as multiple complains
		void printComplainListtoFile();    //Done              //auxiliary
		void addComplain();                //Done
		void CheckComplainStatus();        //Done
		vector<string> extract(string);        //Done  //auxiliary
};	

#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
ComplainList::ComplainList(){
	ifstream inFile("complains.txt");
	if(inFile.is_open()){
	string Line;
	while(getline(inFile,Line)){
	vector<string> vec = extract(Line);
	Complain C1(vec[0],vec[1],vec[2],vec[3]); // 0 is CPid 1 is matter 2 is status 3 date provided
	All_complains.push_back(C1);
	}
	}else{
	cout<<"complains.txt file not opened\n";
	}
};

void ComplainList::ShowDashBoard(){
	rec:
	system("clear");
	cout<<"\t\tSelect:\n";
	cout<<"\t\t1. Register Complain\n";
	cout<<"\t\t2. Check Complain Status\n";	
	cout<<"\t\t3. Update Complain Status\n";
	cout<<"\t\t4. Display All Complains\n";
	cout<<"\t\t5. Back\n";
	string n;
cin.clear();getline(cin,n);
	if(n.size()>1){
	goto rec;
	}
	switch (n[0]){
	case '1': addComplain();break; //  note that its interface has to be developed in addComplain itself
	case '2': CheckComplainStatus();break;
	case '3': updateComplainStatus();break;
	case '4': showAllComplains();break;
	case '5': return;
	default: goto rec;		
	};		
	goto rec;
};//Show Dash Board ends here	
	
void ComplainList::updateComplainStatus(){
	system("clear");
	cout<<"\t\tEnter Complain ID or go back\n";
	string complainid;
	cin.clear();getline(cin,complainid);
	if(complainid=="back" || complainid == "Back"){
	return;
	}
	
	list<Complain>::iterator it =All_complains.begin();
	while(it!=All_complains.end()){	
	if(it->ComplainID == complainid){
	cout<<"\t\tEnter new status\n";
	string newstatus;
	cin.clear();getline(cin,newstatus);
	it->status_of_complain = newstatus;
	this->printComplainListtoFile();
	cout<<"\t\tStatus has been updated successfully\n";
	cout<<"\t\tTaking you back\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		return;
	}
	it++;
	}
	cout<<"\t\tNo Complain was Registered with this Complain ID\n";
	cout<<"\t\tTaking you back\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		return;
	};// updateComplainStatus completed

vector<Complain> ComplainList::findComplain_by_RecipientID(string Rid){
	list<Complain>::iterator it =All_complains.begin();
	vector<Complain> vec;	
	while(it!=All_complains.end()){
	if(it->complainee_id == Rid){
	vec.push_back(*it);
	}
	it++;
	}
	return vec;
	};


vector<Complain> ComplainList::findComplain_by_ComplainId(string Cid){
	list<Complain>::iterator it =All_complains.begin();
	vector<Complain> vec;	
	while(it!=All_complains.end()){
	if(it->ComplainID == Cid){
	vec.push_back(*it);
	}
	it++;
	}
	return vec;
	};

void ComplainList::showAllComplains(){	
	RTE:
	system("clear");
	vector<Complain> vec;
	list<Complain>::iterator it =All_complains.begin();
	while(it!=All_complains.end()){
	vec.push_back(*it);
	it++;
	}
	displayComplains(vec);
	cout<<"\n\n\t\tEnter back to go back if you want\n";
	string b;
	cin.clear();getline(cin,b);
	if(b=="back" || b=="Back"){
return;
	}else{
	goto RTE;
	}
	
};

void ComplainList::displayComplains(vector<Complain> vec){
	cout<<setw(15)<<"Complainee ID"<<setw(20)<<"Regarding "<<setw(15)<<"Status"<<setw(15)<<"Date"<<setw(20)<<"complain ID\n";	
	vector<Complain>::iterator it =vec.begin();
	while(it!=vec.end()){
	cout<<setw(15)<<(it->complainee_id)<<setw(20)<<(it->matter)<<setw(15)<<(it->status_of_complain)<<setw(15)<<(it->DateR)<<setw(20)<<    
        (it->ComplainID)<<endl;
	it++;
	};
	};
		

void ComplainList::printComplainListtoFile(){
	ofstream outFile("complains.txt");
	list<Complain>::iterator it = All_complains.begin();
	while(it!=All_complains.end()){
	string h = (it->complainee_id)+'|'+(it->matter)+'|'+(it->status_of_complain)+'|'+(it->DateR);
	outFile<<h<<endl;
	it++;
	}
	
};

void ComplainList::addComplain(){
	RY:
	system("clear");
	cout<<"enter back any time\n";
	cout<<"\t\tEnter Complainee Institute Id \n";
	string id;
	cin.clear();getline(cin,id);
	if(id == "back" || id=="Back"){
	return;
	}
	
	InstituteMember mem = IMB.getMemberbyID(id);
	if(mem.Recipient_name =="error"){
	cout<<"\t\tThis Member Id is not Correct please try again\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hhh;
	cin.clear();getline(cin,hhh);
	goto 	RY;
	}
		
	cout<<"\t\tEnter Complain matter\n";
	string matter;
	cin.clear();getline(cin,matter);
	if(matter == "back" || matter =="Back"){
	return;
	}		
	string status ="Registered";
	string date =Date::dateString();
	Complain C1(id,matter,status,date);
	All_complains.push_back(C1);
	this->printComplainListtoFile();			
	cout<<"\t\tComplain has been successfully Registered Now it has to be manually resolved\n";
	cout<<"\t\tTaking you back\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		return;
};
	
	
void 	ComplainList::CheckComplainStatus(){
	RT:	
	system("clear");
	cout<<"Type Back if you want to go back\n";
	cout<<"\t\tEnter Complain ID else NA\n";
	string cid;
	cin.clear();getline(cin,cid);
	if(cid=="Back" || cid =="back"){
return;
	}
	
	if(cid !="NA"){
	vector<Complain> vec= findComplain_by_ComplainId(cid);
	if(vec.size()==0){
	cout<<"This complain id doesn't exist\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
		goto	RT;
	}else{
	REW:	
	system("clear");
	displayComplains(vec);
	cout<<"Enter back to go back\n";
	string bb;
	cin.clear();getline(cin,bb);
	if(bb=="back" || bb== "Back"){
	
	return;	
	}else{
	goto REW;
	}
	
	};
	}else{
	cout<<"\t\tEnter Complainee Institute ID\n";
	string Cid;
	cin.clear();getline(cin,Cid);
	vector<Complain> vec = findComplain_by_RecipientID(Cid);
	if(vec.size()==0){
	cout<<"This institute member either doesn't exist or never registered a complain\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	goto RT;
	}else{	
	displayComplains(vec);
	cout<<"enter back to go back\n";
	string ba;
	cin.clear();getline(cin,ba);
	if(ba=="back"||ba=="Back"){
	return;
	}else{
	goto RT;
	}
	
	}
	}
};


vector<string> ComplainList::extract(string info){
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
};
	
	
*/




