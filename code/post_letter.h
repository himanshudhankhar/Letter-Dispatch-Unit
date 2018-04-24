#include"util.h"
#include "payment.h"

#ifndef POST_LETTER_H
#define POST_LETTER_H
class Post_Letter{


public:
	void ShowDashBoard();


};

#endif
/*



void Post_Letter::ShowDashBoard(){

	system("clear");
	cout<<"\t\t Enter Sender's name\n";
	string name;
	cin.clear();getline(cin,name);
	cout<<"\t\t Enter contact \n";
	string contact;
	cin.clear();getline(cin,contact);
	cout<<"Enter Destination of Letter\n";
	string dest;
	cin.clear();getline(cin,dest);
	payment pb;
	int price = pb.getpayment(dest);
	if(price<=0){
	cout<<"\t\t!!!!Our services are not provided in this city\n";
	cout<<"\t\t!!!!Return the letter\n";
	cout<<"\t\tEnter any non empty string to continue\n";	
	//cin.clear();
	string hh;
	cin.clear();getline(cin,hh);			

	
	return; // post Letter class will end up here	
	}	AB:
		system("clear");
	cout<<"\t\t cost: "<<price<<endl;
	
	cout<<"confirm that payment has been recieved or not press y/n\n";
	string y;
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');getline(cin,y);   // pron to error
	
	cin.clear();getline(cin,y);
	if(y.size()>2){
	goto 	AB;
	}
		
	if(y[0]=='y' || y[0]=='Y'){
	
	vector<string> vec;
	vec.push_back(name);
	vec.push_back(contact);
	vec.push_back(dest);
	
string paymentid=pb.add(vec);// txn number or payment id will generated inside
	cout<<"\t\t payment id: "<<paymentid<<endl;
	cout<<"\t\tPayment is successfull\n";
	cout<<"\t\tLetter will be posted to post office by our delivery VAN\n";
	cout<<"\t\tTaking you back to dash board\n";	
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	
	return;
	}else{
	cout<<"\t\tTaking you back to dashboard\n";
	cout<<"\t\tEnter non empty string to continue\n";
	string hh;
	cin.clear();getline(cin,hh);
	//cout<<"yo baby\n";
	return;
	}
}; // showdashboard function complete

*/

