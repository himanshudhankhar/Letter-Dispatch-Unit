#include"admin.h"



void Admin::showDashboard(){
        admindash:
        system("clear");

        cout<<"\t\tCHOOSE ANY ONE OF THE FOLLOING OPTION:\n\t\t 1. ADD LETTER\n\t\t 2. POST LETTER\n\t\t 3. GENERATE REPORT\n\t\t 4. UPDATE DATABASE\n\t\t 5. LETTER STATUS\n\t\t 6. COMPLAIN\n\t\t 7.EXIT\n";
        string n;
        		
		getline(cin,n);
	
	Add_Letter L1;
	Post_Letter L2;
        Generate_Report R1;
	UpdateDataBase D1;
	Letter_Status LS1;
	ComplainList CL1;
	if(n.size()>1){
	goto admindash;
	}
	switch (n[0])
        {  
       	 case '1': L1.showAddLetterDashboard();break;
        case '2': L2.ShowDashBoard();break;
         case '3': R1.ShowDashBoard();break;
        case '4': D1.ShowDashBoard();break;
        case '5': LS1.ShowDashBoard();break;
        case '6': CL1.ShowDashBoard();break;
        case '7': return;
        default: goto admindash;
	}	
	cout<<"yo\n";
        goto admindash;



	};

const string Admin::pass = "1";
const string Admin::AdminID = "d";

