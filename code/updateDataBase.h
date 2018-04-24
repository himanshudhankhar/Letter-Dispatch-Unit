
//very important change here
#include"instituteMemberDatabase.h"
#include"util.h"
#ifndef UPDATEDATABASE_H
#define UPDATEDATABASE_H

class UpdateDataBase{

InstituteMemberList IMB;


public:
        void ShowDashBoard();
	//void addmember(InstituteMember);
	//void deleteMember(InstituteMember);
	//void modifyMember(InstituteMember);
	void showMembers();
	
};
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void UpdateDataBase::ShowDashBoard(){
Re:
system("clear");
	cout<<"\t\tSelect the Following options\n";
	cout<<"\t\t1. Add member\n";
	cout<<"\t\t2. Modify Member\n";
	cout<<"\t\t3. Delete Member\n";
	cout<<"\t\t4. Show Members\n";
	cout<<"\t\t5. Go back\n";
	string n;cin.clear();getline(cin,n);
string h[5];
string info;
	if(n.size()>1){
	goto Re;
	}
	switch (n[0]) {
        case '1':
		{cout<<"\t\tAll the information about Member will be needed\n";
              cout<<"\t\tEnter name\n";
		string name;cin.clear();getline(cin,name);
	      cout<<"\t\tEnter Institute ID\n";
		string ID;cin.clear();getline(cin,ID);
		cout<<"\t\tEnter contact number\n";
		string cont;cin.clear();getline(cin,cont);
		cout<<"\t\tEnter emailid\n";
		string email;cin.clear();getline(cin,email);
		cout<<"Enter Building\n";
		string build;cin.clear();getline(cin,build);
		
	h[0]=name;
	h[1]=ID;
	h[2]=cont;
	h[3]=email;
	h[4]=build;
	info =name+'|'+ID+'|'+email+'|'+cont+'|'+build+'|'+"0";
	InstituteMember mem = IMB.verifyfornewmember(h);
	if(mem.Recipient_name=="error" || mem.Recipient_id=="Dispute"){
	cout<<"\t\tThis member already exist !!!! cannot add again!!! or Invalid Credientials Please confirm again\n";
	cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
	goto Re;
	}else{
	mem = InstituteMemberList::make_member(info);
	cout<<mem.Recipient_name<<" "<<mem.Recipient_id<<" "<<mem.Recipient_contact<<" "<<mem.Recipient_email<<" "<<mem.building_or_department<<" "<<mem.number_of_letters_recieved<<endl;


	IMB.updateMember(mem);
	IMB.printListToFile();
	cout<<"\t\tMember has been successfully added\n";
	cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
	goto Re;
	};
	break;
	}
case '2':
	{cout<<"\t\tAll the information about Member will be needed\n";
              cout<<"\t\tEnter name\n";
		string name;cin.clear();getline(cin,name);
	      cout<<"\t\tEnter Institute ID\n";
		string ID;cin.clear();getline(cin,ID);
		cout<<"\t\tEnter contact number\n";
		string cont;cin.clear();getline(cin,cont);
		cout<<"\t\tEnter emailid\n";
		string email;cin.clear();getline(cin,email);
		cout<<"Enter Building\n";
		string build;cin.clear();getline(cin,build);
	
	h[0]=name;
	h[1]=ID;
	h[2]=cont;
	h[3]=email;
	h[4]=build;
	string info =name+'|'+ID+'|'+email+'|'+cont+'|'+build+'|'+"0";
	InstituteMember mem = IMB.verifymember(h);
	InstituteMember memprev = mem;
	if(mem.Recipient_name=="error" || mem.Recipient_id =="Dispute"){
cout<<"\t\tThis member doesn't exist Please Try Again Or credientials are wrong please check again!!\n"; 
	cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
	
	goto Re;
	}else{
	mod:
	system("clear");
	cout<<"\t\tMember found\n";	
	cout<<"\t\tWhat do you want to update\n";
	cout<<"\t\t1. name\n";
	cout<<"\t\t2. ID\n";
	cout<<"\t\t3. Contact\n";	
	cout<<"\t\t4. Email\n";
	cout<<"\t\t5. Building\n";
	cout<<"\t\t6. Go Back\n";	
	string k;
cin.clear();getline(cin,k);
	if(k.size()>1){goto mod;}
	switch (k[0]){
	case '1':
		{cout<<"\t\tEnter new name\n";
		string newn;
		cin.clear();getline(cin,newn);
		mem.modify("name",newn);
		cout<<"\t\tName has been successfully modified\n";
			cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
	
		goto mod;
		break;}
	case '2':
		{cout<<"\t\tEnter new ID\n";
		string newID;
		cin.clear();getline(cin,newID);	
		mem.modify("id",newID);
		cout<<"\t\tID has been successfully modified\n";	
		
			cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);	
		goto mod;
		break;}
	case '3':
		{cout<<"\t\tEnter new Contact\n";
		string newcont;
		cin.clear();getline(cin,newcont);
		mem.modify("contact",newcont);
		cout<<"\t\tContact has been modified successfully!\n";
			cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
	
		goto mod;
		break;}
	case '4':
		{cout<<"\t\tEnter new Email\n";
		string nemail;
		cin.clear();getline(cin,nemail);	
		mem.modify("email",nemail);
		cout<<"\t\tEmail has been successfully modified\n";

			cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
		goto mod;
		break;}
	case '5':
		{cout<<"\t\tEnter new Building\n";
		string nbuild;
		cin.clear();getline(cin,nbuild);
		mem.modify("building",nbuild);
	cout<<"\t\tBuilding has been successfully modified\n";
	cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
			
		goto mod;
		break;}
	case '6': 
		{
		
	IMB.deleteMember(memprev);
	IMB.updateMember(mem);
		
	IMB.printListToFile();
	
	
					
		goto Re;
		break;
		}
	default : {goto mod;}
	};
	}
	break;}
case '3':{
	cout<<"\t\tAll the information about Member will be needed\n";
              cout<<"\t\tEnter name\n";
		string name;cin.clear();getline(cin,name);
	      cout<<"\t\tEnter Institute ID\n";
		string ID;cin.clear();getline(cin,ID);
		cout<<"\t\tEnter contact number\n";
		string cont;cin.clear();getline(cin,cont);
		cout<<"\t\tEnter emailid\n";
		string email;cin.clear();getline(cin,email);
		cout<<"Enter Building\n";
		string build;cin.clear();getline(cin,build);
		
	h[0]=name;
	h[1]=ID;
	h[2]=cont;
	h[3]=email;
	h[4]=build;
	string info =name+'|'+ID+'|'+email+'|'+cont+'|'+build+'|'+"0";
	InstituteMember mem = IMB.verifymember(h);
	if(mem.Recipient_name=="error"){
	cout<<"\t\tThis member already doesn't exist\n";
	cout<<"\t\tEnter any non empty string to go back\n";
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);
		
        goto Re;
	}else{
	IMB.deleteMember(mem);
	IMB.printListToFile();
	cout<<"Member has been successfully deleted\n";
	cout<<"\t\tEnter any non empty string to continue\n";	
	string hh;
	cin.clear();getline(cin,hh);	
	};
	break;
	}
case '4':
        {	
	showMembers();
	break;
	}
case '5':
     { return;
	}
default:
	{goto Re;}
	
}

};
	
void UpdateDataBase::showMembers(){
list<InstituteMember> lt = IMB.getList();
list<InstituteMember>::iterator it = lt.begin();
	system("clear");		
	cout<<setw(19)<<"Name"<<setw(19)<<"Institute id"<<setw(19)<<"contact"<<setw(19)<<"Email"<<setw(10)<<"building\n";

		while(it!=lt.end()){
	cout<<setw(19)<<  it->Recipient_name << setw(19)<< it->Recipient_id << setw(19) << it->Recipient_contact <<setw(19)<< it->Recipient_email<<setw(10)<< it->building_or_department<<endl;
it++;
}

cout<<"\t\t Enter any non empty string to go back \n";
string hh;
	cin.clear();getline(cin,hh);

return;
};

	
	
*/			
