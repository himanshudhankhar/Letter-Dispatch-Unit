#include"payment.h"





payment::payment(){
	ifstream inFile("cities.txt");	
	if(inFile.is_open()){
	string line;
	while(getline(inFile,line)){
	vector<string> vec= this->extract(line);
	stringstream ss;
	ss << vec[1];
	int price;
	ss>>price;	
	cities[vec[0]]=	price;
	}
	}else{
	cout<<"cities.txt file not opened\n";
	}
	};
int payment::getpayment(string city){
	map<string,int>::iterator it=cities.begin();
	while(it!=cities.end()){
	if(it->first == city){
	this->pay = it->second;
	return it->second;
	}
	it++;
	}
	this->pay = it->second;
	return -1;
	};
string payment::add(vector<string> vec){
	//it is sure that payment has been confirmed
	this->paymentid= this->generatePaymentId(vec);
	ofstream outFile("payments.txt",ios::out|ios::app);
	int n =pay;	
	stringstream ss;ss<<n;
	string py;
	ss>>py;
	string date = Date::dateString();
	string info = vec[0]+'|'+vec[1]+'|'+vec[2]+'|'+py+'|'+this->paymentid+'|'+date;
	//outFile.seekp(0,ios::end);
	outFile<<info<<endl;
	return this->paymentid;
	};
string payment::generatePaymentId(vector<string> vec){
	int n =pay;	
	stringstream ss;ss<<n ;
	string py;
	ss>>py;
	string date = Date::dateString();
		
	string id = vec[0]+date+py;
return id;
};

vector<string> payment::extract(string info){
	char ch;
	int i=0;
	string h1,h2;
	while(info[i]!='|'){
	h1+=info[i];
	i++;
	}
	i++;
	while(info[i]!='\0'){
	h2+=info[i];
	i++;
	}
	vector<string> vec;
	vec.push_back(h1);
	vec.push_back(h2);
	return vec;
	};
