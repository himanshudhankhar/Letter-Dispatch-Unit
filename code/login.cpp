#include"admin.h"
#include"password.h"
#include "error.h"
#include"util.h"
//using namespace std;






int main(){

loginagain:
system("clear");
cout<<"\t\t"<<"Enter Admin ID:\n";
string adminID;

getline(cin,adminID);

cout<<"\t\tEnter Password\n";
string pass = passwd::getpasswd();

if(adminID==Admin::getadminID() && pass==Admin::getpasswd()){
Admin first;
first.showDashboard(); // or admin constructor will set the screen no showDashBoard will work and take input and correspondingly call another object

// login ends here i think


}else{
	error::showLoginerror();
	goto loginagain;
    
}



return 0;


}
