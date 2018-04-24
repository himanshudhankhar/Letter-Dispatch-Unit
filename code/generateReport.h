#include"util.h"

#ifndef GENERATE_REPORT_H
#define GENERATE_REPORT_H

class Generate_Report{





public:
void showLettersReport(); // it will ask a input to continue after displaying the report
void showPaymentsReport();
void showComplainsReport();
void displayLReport(vector<string>);
void displayPReport(vector<string>);
void displayCReport(vector<string>);
vector<string> extract(string);
void ShowDashBoard();
};
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void
Generate_Report::ShowDashBoard(){
	again:
	system("clear");
	cout<<"\t\t Select which report do you want to see\n";
	cout<<"\t\t1. Letters report\n";
	cout<<"\t\t2. Payments report\n";
	cout<<"\t\t3. Complains report\n";
	cout<<"\t\t4. Back\n";
	string n;
	cin.clear();
	getline(cin,n);
	if(n.size()>1){
	goto again;
	}
	switch (n[0]){
	case '1': showLettersReport();break;
	case '2': showPaymentsReport();break;
	case '3': showComplainsReport();break;
	case '4': return;
	default : goto again;
	}
	cout<<"\t\tDo you want to go back or see some other report press y/n\n";
	string y;
	cin.clear();
	getline(cin,y);
	if(y=="y"||y=="Y"){
	
	return;
	}else{
	goto again;
	}
};
void
Generate_Report::showLettersReport(){
	ifstream inFile("all_letters1.txt");
	if(inFile.is_open()){
	vector<string> vec;	
	string line;	
	while(!inFile.eof()){getline(inFile,line);
	vec.push_back(line);
	}
	displayLReport(vec);
	}else{
cout<<"\t\t Error all_letters1.txt file not opened\n";
	}
};

void
Generate_Report::showPaymentsReport(){
	ifstream inFile("payments.txt");
	if(inFile.is_open()){
	vector<string> vec;	
	string line;	
	
	while(!inFile.eof()){
	
	getline(inFile,line);
	
	vec.push_back(line);
	}
	displayPReport(vec);
	}else{
cout<<"\t\t Error payments.txt file not opened\n";
	}
};

void
Generate_Report::showComplainsReport(){
	ifstream inFile("complains.txt");
	if(inFile.is_open()){
	vector<string> vec;	
	string line;
		
	while(getline(inFile,line)){
	vec.push_back(line);
	}
	displayCReport(vec);
	}else{
cout<<"\t\t Error complains.txt file not opened\n";
	}
};

void 
Generate_Report::displayLReport(vector<string> vec){
	system("clear");
	cout<<setw(15)<<"Recipient ID"<<setw(15)<<"Letter ID"<<setw(10)<<"status"<<setw(10)<<"Date of entry\n"; 
	vector<string>::iterator it = vec.begin();
	while(it!=vec.end()){
	vector<string> single_entry = extract(*it);
	if(single_entry.size()<4){return;}
	cout<<setw(15)<<single_entry[0]<<setw(15)<<single_entry[1]<<setw(10)<<single_entry[2]<<setw(10)<<single_entry[3]<<endl;
	it++;
	}
};

void Generate_Report::displayPReport(vector<string> vec){
	system("clear");
	cout<<setw(15)<<"Name"<<setw(10)<<"Institute ID"<<setw(10)<<"city"<<setw(5)<<"Payment(Rs)"<< setw(10)<<"Payment id\n";
	vector<string>::iterator it = vec.begin();
	while(it!=vec.end()){
	vector<string> single_entry = extract(*it);
	if(single_entry.size()<5){
	return;
	}
	cout<<setw(15)<<single_entry[0]<<setw(10)<<single_entry[1]<<setw(10)<<single_entry[2]<<setw(5)<<single_entry[3]<<setw(10)<<single_entry[4]<<endl;
	it++;
}

};
void Generate_Report::displayCReport(vector<string> vec){
	system("clear");
	cout<<setw(10)<<"Complain Registered by"<<setw(10)<<"Regarding"<<setw(10)<<"status\n";
	vector<string>::iterator it= vec.begin();
while(it!=vec.end()){
	vector<string> se = extract(*it);
	if(se.size()<3){
	return;	
	}
	cout<<setw(10)<<se[0]<<setw(20)<<se[1]<<setw(10)<<se[2]<<endl;
	it++;
	}
	
};

vector<string> Generate_Report::extract(string info){
	int i=0;
	vector<string> vec;
	
	while(i<info.size()){
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

	
			
