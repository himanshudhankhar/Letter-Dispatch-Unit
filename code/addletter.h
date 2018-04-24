
#include"LetterDatabase.h"
#include"util.h"

#ifndef ADDLETTER_H
#define ADDLETTER_H

class Add_Letter{
private:
	string Recipient_name;
	string Recipient_ID;
	string Recipient_contact;
	string Recipient_email;
	string building;
	InstituteMemberList IMB;
	LetterDatabase LDB;
	

public:
	~Add_Letter(){
			system("clear");
			
		};

	 void proceed(InstituteMember);   // This function will proceed after the member has been verified from InstituteMember DataBase
	 void showAddLetterDashboard();   
};

#endif
/*
	void showAddLetterDashboard(){ // this function has to be transfered to addletter.cpp here will be only declaration definition will
		dash:
		system("clear");
		string info[4];
		cout<<"\t\tEnter the name of recipient if not available Press NA and Return Letter NOT Accepted \n";
		string name;
		cin.clear();getline(cin,name);
		if(name=="NA"){
		return;	
		}
		info[0]=name;
		cout<<"Enter ID or NA \n";
		string id ;
		cin.clear();getline(cin,id);
		info[1]=id;
		cout<<"Enter contact or NA \n";
		string cont;
		cin.clear();getline(cin,cont);
		info[2]=cont;
		cout<<"Enter building or NA \n";
		string build;
		cin.clear();getline(cin,build);
		info[3]=build;
		//name|id|contact|building
		// institute member will be verified 
		InstituteMember mem=IMB.verify(info);
				if(mem.Recipient_name=="error"){
			cout<<"\t\tThis person doesn't exist in our institute.\n\t\t";
			cout<<"\t\tReturn This Letter because this cann't be verified\n";
			cout<<"\t\tEnter any  non empty string to go back to dash board\n";
			//cin.clear();
			string hh;			
			cin.clear();getline(cin,hh);			
			//string g;
			//getline(cin,g);			

			return;
			}
			
		if(mem.Recipient_name=="Dispute"){
			cout<<"\t\tThis Letter is under Dispute and this Dispute can be solved manually only\n";
			cout<<"\t\tSystem is storing this Letter as DisputeLetter\n";
			InstituteMember ret(info[0],"Dispute","Dispute","Dispute","Dispute",0);
			proceed(ret);	
			
			return;
			
			}
		proceed(mem);
		
		return;
		};















		void proceed( InstituteMember & mem){
			// provided by IMB.verify that mem will be correct 
			system("clear");
			//cout<<"\t\tMember has been verified confirm the addition of Letter Press Y/N\n\t\t";
			//char c;
			//cin>>c;
			//if(c=='Y' || c=='y'){
				
				
				string letter_code = IMB.generateLetterCode(mem);
				if(mem.Recipient_id=="Dispute"){
				cout<<"\t\tThis Letter is under Dispute and Stored in system as Dispute you need to manually resolve this  Dispute\n";
}else{
					
				
				cout<<"\n\t\t Letter has been successfully added\n\t\t";
				cout<<"\n\t\tLetter code generated is: "<<letter_code<<endl;
				}			
				cout<<"\n\t\tPlease put the letter in corresponding bundle for the correct delivery by delivery system\n\t\t";
									
				cout<<"\t\tEnter  any non empty string to continue\n";
				
				//cin.clear();				
				string hh;
				cin.clear();getline(cin,hh);				
				//string g;
			        //getline(cin,g);			
				
				if(mem.Recipient_id=="Dispute"){
				LDB.add(mem,1,letter_code,"Dispute");
				LDB.printListtoDataBase();
				}else{				
				LDB.add(mem,1,letter_code,"Stage 1");
				mem.update_letter_recieved();
				LDB.printListtoDataBase();				
				IMB.updateMember(mem);
				IMB.printListToFile();
				}
			


		};


		



	};


*/





