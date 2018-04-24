#include"util.h"
#ifndef INSTITUTEMEMBERDATABASE_H
#define INSTITUTEMEMBERDATABASE_H

class InstituteMember{
////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	string Recipient_name;
	string Recipient_id;
	string Recipient_contact;
	string Recipient_email;
	string building_or_department;
	 int number_of_letters_recieved;
public:
	InstituteMember(string Recipient_name="",string Recipient_id="",string Recipient_email="",string Recipient_contact="",string building="",int number_of_letters_recieved=0){
	  this->Recipient_name=Recipient_name;
	  this->Recipient_id=Recipient_id;
	  this->Recipient_contact=Recipient_contact;
	  this->Recipient_email=Recipient_email;
	  this->building_or_department=building;
	  this->number_of_letters_recieved = number_of_letters_recieved;
	}
	void modify(string a,string b){
	if(a=="name"){
	this->Recipient_name=b;
	}

	if(a=="id"){// verify that new id already occupied or not  if yes then show the error message and return else update the id
	ifstream inFile("allmembers.txt");
	string identity;
	if(inFile.is_open()){
	while(getline(inFile,identity)){
	int ii=0;int jj=0;
	while(identity[ii]!='|'){
	ii++;
	}
	//now identity[i]=='|'
	// second string will be id for sure
	 jj =ii+1;
	string h;
	while(identity[jj]!='|'){
	h+= identity[jj];
	jj++;
	}
	if(h == b ){
	cout<<"This ID already exists you cannot modify it\n";
	cin.clear();
	cout<<"press enter to continue\n";
	string g;
	getline(cin,g);
	return ; 
	}
	}
	
	}
	

	this->Recipient_id=b;
	cout<<"ID has been successfully modified\n";
	cout<<"Press Enter to continue\n";
	string bb;
	cin.clear();
	getline(cin,bb);
	return;
	}
	if(a=="contact"){
	this->Recipient_contact=b;
	}
	if(a=="email"){
	this->Recipient_email=b;
	}
	if(a=="building"){
	this->building_or_department=b;
	}

	}

///////////////////////////////////////////////////////functionalities provided by Letter class
	void update_letter_recieved(int n=1){
	this->number_of_letters_recieved+=n;
	}
	friend  InstituteMember make_member(string);
	friend  string make_from_member(InstituteMember);
//////////////////////////////////////////////////////////////
};

class InstituteMemberList{
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	list<InstituteMember> All_members;
public:
	InstituteMemberList(); // this constructor will initialize the given list from file data base
	list<InstituteMember> getList();  // it will return the list
	void printListToFile();     // it will print the list
	vector<InstituteMember> find_by_name(string);
	InstituteMember  find_by_id(string);
	InstituteMember  find_by_email(string);
	InstituteMember  find_by_contact(string);
	static InstituteMember make_member(string);
	static string make_from_member(InstituteMember);
	void updateMember(InstituteMember);
	InstituteMember verify(string []);
	InstituteMember verifymember(string []);
	InstituteMember  verifyfornewmember(string []);
	string generateLetterCode(InstituteMember);  // this is very very important function to be implemented ||||||||
	void deleteMember(InstituteMember);
	InstituteMember match_name(vector<InstituteMember>,InstituteMember);
	InstituteMember getMemberbyID(string);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
#endif
/*

InstituteMember InstituteMemberList::getMemberbyID(string id){
	list<InstituteMember>::iterator it = All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id == id){
	return *it;
	}
	it++;
	}
	InstituteMember mem("error");
	
	return mem;
	}


void InstituteMemberList::deleteMember(InstituteMember mem){
	list<InstituteMember>::iterator it = All_members.begin();//it is verified that mem will exists in All_members
	while(it!=All_members.end()){
	if(it->Recipient_id==mem.Recipient_id){
	it = All_members.erase(it);
	continue;	
	}
	it++;
	
	}
	//All_members.remove(mem);
	

// cin.ignore(numeric_limits<streamsize>::max());getline(cin,);
};	


string InstituteMemberList::generateLetterCode(InstituteMember mem){
//building+id+number of letter
string build = mem.building_or_department;
string id = mem.Recipient_id;
string number = to_string(mem.number_of_letters_recieved);
return build+id+number;
};



InstituteMember InstituteMemberList::verifymember(string info[]){
list<InstituteMember>::iterator it = All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id == info[1] && it->Recipient_name == info[0] && it->Recipient_contact == info[2] && it->Recipient_email == info[3] && it->building_or_department == info[4]){
		//InstituteMember mem("error");
		return *it;
	}
	it++;
	}
	InstituteMember mem("error");
	return mem;
	};






InstituteMember InstituteMemberList::verifyfornewmember(string info[]){
///////////////////////..................................................................................
list<InstituteMember>::iterator it = All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id == info[1]){
		InstituteMember mem("error");
		return mem;
	}
	it++;
	}
	InstituteMember mem(info[0],info[1],info[2],info[3],info[4],0);
	return mem;
	};






InstituteMember InstituteMemberList::verify(string info[]){
/*if(info[1]!="NA"){
vector<
}
if(info[2]!="NA"){
return find_by_contact(info[2]); // contact will be same
}
*/
/*
if(info[0]!="NA"){
vector<InstituteMember> vec = find_by_name(info[0]);
if(vec.size()==0){
InstituteMember mem("error");
return mem;
}
if(vec.size()==1){return vec[0];
}
if(vec.size()>1){
if(info[1]!="NA"){
InstituteMember mem1=  find_by_id(info[1]);// i want only id
	if(mem1.Recipient_name!="error" && mem1.Recipient_id!="error")
	{	if(info[2]!="NA"){//3
			InstituteMember mem2=find_by_contact(info[2]);
			if(mem2.Recipient_id == "error" && mem2.Recipient_name !="error"){//2
				if(mem2.Recipient_id == mem1.Recipient_id){
						return mem2;
				}else{//1
						InstituteMember ret("Dispute");
							return ret;
				}//1

			}else{
					return match_name(vec,mem1);
			}

		}else{//2
				return match_name(vec,mem1);
		}
	}else{
		InstituteMember ret("Dispute");
		return ret;
	}
}else{
	if(info[2]!="NA"){
		   	InstituteMember mem3=find_by_contact(info[2]);
			if(mem3.Recipient_id == "error" && mem3.Recipient_name !="error"){
				return match_name(vec,mem3);
			}else{
				InstituteMember ret("Dispute");						
				return ret;
			}

	}else{
		if(info[3]=="NA"){		
		InstituteMember mem4("error");
			return mem4;
		}else{
			InstituteMember mem5("Dispute");
		}
}
}
}else{
	InstituteMember ret("error");
		return ret;
}


};

};
InstituteMember InstituteMemberList::match_name(vector<InstituteMember> vec,InstituteMember mem){
	vector<InstituteMember> ::iterator it = vec.begin();
	while(it!=vec.end()){
		if(it->Recipient_name == mem.Recipient_name && it->Recipient_id == mem.Recipient_id )
			{	return mem;
			}
		it++;
	}
	InstituteMember ret("Dispute");
	return ret;
};	














  InstituteMember InstituteMemberList::make_member(string identity){
// given that that identity will be of the form name|id|email|contact|building|letters_recieved_till_now
if(identity.size()<11){InstituteMember mem("error");
	return mem;
	}
string name="";
string contact="";
string id="";
string email="";
string building="";
int letter_recieved=0;

int i=0;
while(identity[i]!='|'){
name+=identity[i];
i++;
}
i++;
while(identity[i]!='|'){
id+=identity[i];
i++;
}
i++;
while(identity[i]!='|'){
email+=identity[i];
i++;
}
i++;
while(identity[i]!='|'){
contact+=identity[i];
i++;
}
i++;
while(identity[i]!='|'){
building+=identity[i];
i++;
}
i++;
string number="";
while(identity[i]!='\0'){
number+=identity[i];
i++;
}
stringstream ss;
ss<<number;
ss>>letter_recieved;

InstituteMember mem(name,id,email,contact,building,letter_recieved);
return mem;
};



  string InstituteMemberList::make_from_member(InstituteMember mem){
	stringstream ss;
ss<<mem.number_of_letters_recieved;
string h;
ss>>h;
	string tobereturned =mem.Recipient_name+'|'+mem.Recipient_id+'|'+mem.Recipient_email+'|'+mem.Recipient_contact+'|'+mem.building_or_department+'|'+h;
return tobereturned;
};



InstituteMemberList::InstituteMemberList(){	
	ifstream inFile("allmembers.txt");
	if(inFile.is_open()){
	string identity;
	//int i=0;int j=0;	
	while(getline(inFile,identity)){
	//i++;
	//cout<<i<<endl;
	//cout<<"identity is"<<identity.size()<<endl;
	InstituteMember mem = InstituteMemberList::make_member(identity);              // make member needed to be implemented
	if(mem.Recipient_name!="error"){
	All_members.push_back(mem);
	}
	//j++;
	//cout<<j<<endl;
	}
	//cout<<"'iml task finished\n";
	}else{
	cout<<"allmembers file not opened\n";
	}
	}; // function over

list<InstituteMember> InstituteMemberList::getList(){
	return All_members;	
	}
void InstituteMemberList::printListToFile(){
	ofstream outFile("allmembers.txt");
	list<InstituteMember>::iterator it=All_members.begin();
	
	if(outFile.is_open()){
	while(it!=All_members.end()){
	string print= InstituteMemberList::make_from_member(*it);                       //make from meber needed to be implemented
	it++;
	outFile<<print<<endl;
	}
	outFile.close();
	
	}
	else{
	cout<<"error allmembers.txt not opened\n";
 	}
}

vector<InstituteMember> InstituteMemberList::find_by_name(string name)
	{vector<InstituteMember> vec;
	list<InstituteMember>::iterator it=All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_name==name){
	InstituteMember s=*it;
	vec.push_back( s);
	}
	it++;
	}
	return vec;
	};
InstituteMember InstituteMemberList::find_by_id(string id){
	list<InstituteMember>::iterator it=All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id==id){
	InstituteMember s=*it;
	return s;
	}
it++;
	}

 InstituteMember mem("error");
	return mem;
	};


InstituteMember InstituteMemberList::find_by_contact(string contact){
	list<InstituteMember>::iterator it=All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_contact==contact){
	return *it;
	}
it++;
	}
 InstituteMember mem("error");
return mem;
	};
InstituteMember InstituteMemberList::find_by_email(string id){
	list<InstituteMember>::iterator it=All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id==id){
	return *it;
	}
it++;
	}
	InstituteMember mem("error");
return mem;
	};

void InstituteMemberList::updateMember(InstituteMember mem){
	list<InstituteMember>::iterator it=All_members.begin();
	while(it!=All_members.end()){
	if(it->Recipient_id==mem.Recipient_id){
		*it=mem;
		return;
		}
	it++;
	}
	All_members.push_back(mem);
	};

*/
