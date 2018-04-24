#include"post_letter.h"




void Post_Letter::ShowDashBoard(){
	rett:
	system("clear");
	cout<<"\t\t Enter Sender's name\n";
		
	string name;
	cin.clear();getline(cin,name);
	if(name.size()==0){
		goto rett;
	}
	cout<<"\t\t Enter contact \n";
	string contact;
	tter:	
	cin.clear();getline(cin,contact);
	if(contact.size()==0){
		goto tter;
		}
	cout<<"Enter Destination of Letter\n";
	string dest;
	cin.clear();getline(cin,dest);
	payment pb;
	int price = pb.getpayment(dest);
	if(price<=0){
	cout<<"\t\t!!!!Our services are not provided in this city\n";
	cout<<"\t\t!!!!Return the letter\n";
	cout<<"\t\tEnter to continue\n";	
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);			

	
	return; // post Letter class will end up here	
	}	AB:
		system("clear");
	cout<<"\t\t cost: "<<price<<endl;
	
	cout<<"press y to confirm payment has been received else any other string\n";
	string y;
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');getline(cin,y);   // pron to error
	
	cin.clear();getline(cin,y);
	if(!(y == "y" || y == "Y")){
	cout<<"y was not entered so payment has been cancelled taking you back\n press Enter to continue\n";
	cin.clear();
	string bh;getline(cin,bh);
	return;
	}
		
	if(y == "y" || y=="Y"){
	
	vector<string> vec;
	vec.push_back(name);
	vec.push_back(contact);
	vec.push_back(dest);
	
string paymentid=pb.add(vec);// txn number or payment id will generated inside
	cout<<"\t\t payment id: "<<paymentid<<endl;
	cout<<"\t\tPayment is successfull\n";
	cout<<"\t\tLetter will be posted to post office by our delivery VAN\n";
	cout<<"\t\tTaking you back to dash board\n";	
	cout<<"\t\tEnter to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	
	return;
	}else{
	cout<<"\t\tTaking you back to dashboard\n";
	cout<<"\t\tEnter to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	//cout<<"yo baby\n";
	return;
	}
}; // showdashboard function complete

