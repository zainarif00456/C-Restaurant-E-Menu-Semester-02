#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Create_account{	//To create account for admin login. No further characteristics
	private:
		string email, password, final_pass;
	public:
		Create_account()
		{
			email="none";
			password="none";
			final_pass="none";
		}
		void create()
		{
			system("cls");
			system("color 0a");
			ofstream inmail;
			ofstream inpass;
			inmail.open("mail.txt");
			inpass.open("password.txt");
			cout<<"====================================================="<<endl;
			cout<<"Enter E-mail ID (Lowecase Only): ";
			cin>>email;
			cout<<"-----------------------------------------------------"<<endl;
		//callPoint	
			resetpass:
			cout<<"Password: ";
			cin>>password;
			cout<<"-----------------------------------------------------"<<endl;
			cout<<"Confirm Password: ";
			cin>>final_pass;
			cout<<"-----------------------------------------------------"<<endl;
			if(password!=final_pass)
			{
				cout<<"Wrong Password. Try again..."<<endl;
				goto resetpass;
			}
			cout<<"====================================================="<<endl;
			inmail<<email;
			inpass<<password;
			inmail.close();
			inpass.close();
		}
};
class Items_entry{
	protected:
	int counter;
	public:
		void enter_dishes(int c)
		{
			system("cls");
			system("color 0e");
			counter=c;
			counter++;
			ofstream inamu;
			inamu.open("dish_amount.txt");
			inamu<<counter;
			string items[counter];
			float price[counter];
			cout<<"			======================================"<<endl;
			cout<<"			Enter Names and Price of Dishes below."<<endl;
			for(int i=1; i<counter; i++)
			{
			cout<<"			"<<i<<"- ";
			cin>>items[i];
			cout<<"			Price of "<<items[i]<<": ";
			cin>>price[i];
			cout<<"			--------------------------"<<endl;
			}
			cout<<"			======================================"<<endl;
			ofstream indata;
			indata.open("dishes.txt");
			for(int i=1; i<counter; i++)
			{
				indata<<items[i]<<"					"<<price[i]<<endl;
			}
			cout<<"Files Saved Successfully..."<<endl;
		}
};
class Admin_login:public Items_entry{
	protected:
		string Password, File_pass, final_pass, email, file_mail;
	public:
		Admin_login()
		{
			Password="12345";
			File_pass="none";
		}
	private:
		void Reset_adminLogin()
		{
			ifstream outpass;
			ofstream inpass;
			ifstream outmail;
			ofstream inmail;
			outmail.open("mail.txt");
			inmail.open("mail.txt");
			inpass.open("password.txt");
			outpass.open("password.txt");
			outpass>>File_pass;
			outmail>>file_mail;
			start_pass:
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Enter Previous E-mail ID: ";
			cin>>email;
			if(email!=file_mail)
			{
			cout<<"-------------------------------------------------"<<endl;	
			cout<<"Wrong E-mail Address. Try Again..."<<endl;
			goto start_pass;
			}
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Enter Previous Password: ";
			cin>>Password;
			if(Password==File_pass)
			{
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Enter New E-mail ID: ";
			cin>>email;
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Enter New Password: ";
			cin>>Password;
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Confirm Password: ";
			cin>>final_pass;
			cout<<"-------------------------------------------------"<<endl;
				if(Password==final_pass)
				{
					inmail<<email;
					inpass<<final_pass;
					inmail.close();
					inpass.close();
			cout<<"Password Updated Successfully..."<<endl;
			cout<<"-------------------------------------------------"<<endl;
				}
				if(Password!=final_pass)
			{
				cout<<"Wrong Password. Try Again: "<<endl;
				goto start_pass;
			}
			}
			else
			{
				cout<<"Wrong Password. Try Again: "<<endl;
				goto start_pass;
			}
		}
		public:
		void Admin_selection_panal()
		{
			re_enter:
			ifstream outmail;
			outmail.open("mail.txt");
			ifstream outpass;
			outpass.open("password.txt");
			outmail>>file_mail;
			outpass>>File_pass;
			again:
			cout<<"========================================================="<<endl;
			cout<<"Enter Admin E-mail (Press '#' to Update Login Mail): ";
			cin>>email;
			cout<<"---------------------------------------------------------"<<endl;
			if(email=="#")
			{
				Reset_adminLogin();
				goto again;
			}
			else if(email!=file_mail)
			{
				cout<<"Invalid E-mail Address. Try again..."<<endl;
				goto re_enter;
			}
			repass:
			cout<<"Password: ";
			cin>>Password;
			
			if(Password==File_pass && email==file_mail)
			{
			cout<<"========================================================="<<endl;
				cout<<"Access Granted."<<endl;
			}
			else
			{
				cout<<"Invalid Password. Try Again..."<<endl;
				goto repass;
			}
			int count;
			cout<<"				**************************"<<endl;
			cout<<"				Enter Number Of dishes: ";
			cin>>count;
			cout<<"				**************************"<<endl;
			enter_dishes(count);
		}
};
class Customer{
	private:
		float total_bill;
	public:
		
		void Display_dishes()
		{
			total_bill=0;
			system("cls");
			system("color 0e");
			string name, cnic;
			float payed;
			int counter;
			ifstream outamu;
			outamu.open("dish_amount.txt");
			outamu>>counter;
			outamu.close();
			ifstream outdata;
			outdata.open("dishes.txt");
			int qty[counter];
			for(int i=0; i<counter; i++)
			{
				qty[i]=0;
			}
			string  items[counter];
			float price[counter];
			for(int i=1; i<counter; i++)
			{
				outdata>>items[i]>>price[i];
			}
		cout<<"			======================================================="<<endl;
		cout<<"			*******************************************************"<<endl;
		cout<<"			Items						Price"<<endl;
		cout<<"			*******************************************************"<<endl;
			for(int i=1; i<counter; i++)
			{
			cout<<"			"<<i<<")- "<<items[i];
		cout<<"					"<<"Rs."<<price[i]<<endl;
		cout<<"			------------------------------------------------------"<<endl;
						}
		cout<<"			======================================================"<<endl;
			int choice;
			
		cout<<"			Enter Your Choice (Press '0' To Get Bill): ";
			cin>>choice;
		cout<<"			******************************************************"<<endl;
			while(choice!=0)
			{
		cout<<"					You Selected: "<<items[choice]<<endl;
		cout<<"			-------------------------------------------------------"<<endl;
		cout<<"					Enter Qty: ";
		cin>>qty[choice];
		cout<<"			-------------------------------------------------------"<<endl;
		total_bill+=price[choice]*qty[choice];
		cout<<"			Enter Your Choice (Press '0' To Get Bill): ";
		cin>>choice;
		cout<<"			-------------------------------------------------------"<<endl;
			}
			system("color 0d");
		cout<<"			******************************************************"<<endl;
			cout<<"					------------------------------"<<endl;
			cout<<"						Total Bill: Rs."<<total_bill<<endl;
			cout<<"					------------------------------"<<endl;
			cout<<"				============================================="<<endl;
			cout<<"				Enter Customer Name: ";
			cin>>name;
			cout<<"				---------------------------------------------"<<endl;
			cout<<"				Enter CNIC: ";
			cin>>cnic;
			cout<<"				---------------------------------------------"<<endl;
			payagain:
			cout<<"				Amount Payed By Customer: ";
			cin>>payed;
			if(payed<total_bill)
			{
			cout<<"				---------------------------------------------"<<endl;
			cout<<"				Not Enough Amount. Pay Due Amount..."<<endl;
			goto payagain;
			}
			cout<<"				---------------------------------------------"<<endl;
			cout<<"				Remainng Amount: Rs."<<payed-total_bill<<endl;
			cout<<"				********************************"<<endl;
			cout<<"					Thanks For Shopping..."<<endl;
			cout<<"				********************************"<<endl;
			ofstream indata;
			indata.open("customer.txt", ios::app);
			indata<<"CNIC No: "<<cnic<<endl;
			indata<<"Name Of Customer: "<<name<<endl;
			indata<<"Total Bill: Rs."<<total_bill<<endl;
			indata<<"Amount Payed: Rs."<<payed<<endl;
			indata<<"Remaining Amount: Rs."<<payed-total_bill<<endl;
			system("pause");
			system("cls");
		}
};
int main()
{
	system("color 0b");
	cout<<"				**************************************"<<endl;
	cout<<"				======================================"<<endl;
	cout<<"					Team Member's Name"<<endl;
	cout<<"				======================================"<<endl;
	cout<<"				1- Zain-Ul-Abdeen"<<endl;
	cout<<"					Roll No: BCSM-F19-154"<<endl;
	cout<<"				--------------------------------------"<<endl;
	cout<<"				2- M. Umair Anjum"<<endl;
	cout<<"					Roll No: BCSM-F19-030"<<endl;
	cout<<"				--------------------------------------"<<endl;
	cout<<"				3- Sadaf Shaukat"<<endl;
	cout<<"					Roll No: BCSM-F19-438"<<endl;
	cout<<"				--------------------------------------"<<endl;
	cout<<"				4- Fatima Nasir"<<endl;
	cout<<"					Roll No: BCSM-F19-167"<<endl;
	cout<<"				--------------------------------------"<<endl;
	cout<<"				Submitted To: "<<endl;
	cout<<"					Prof. Umair Ahmad"<<endl;
	cout<<"				**************************************"<<endl;
	cout<<endl<<endl;
	system("pause");
	system("cls");
	START:
	int choice;
	string file_pass="none", file_mail="none";
			string name="none";
			ifstream outpass;
			ifstream outmail;
			outmail.open("mail.txt");
			outpass.open("password.txt");
			outmail>>file_mail;
			outpass>>file_pass;
			outmail.close();
			outpass.close();
	ifstream check;
			check.open("dishes.txt");
			check>>name;
	Admin_login AL;
	Customer C;
	system("color 0c");
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"			Enter User Type"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	
	cout<<"*************************"<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"2. Customer"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"3. Exit Program"<<endl;
	cout<<"*************************"<<endl;
	cout<<"Select Your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			if(file_pass=="none")
			{
				cout<<"				-------------------"<<endl;
				cout<<"				Create New Account."<<endl;
				cout<<"				-------------------"<<endl;
				Create_account CA;
				CA.create();
			}
			AL.Admin_selection_panal();
			goto START;
			break;
		case 2:
			if(name=="none")
			{
				check>>name;
				check.close();
				cout<<"Data Not Found. First Get Data From Admin..."<<endl;
				goto START;
			}
			C.Display_dishes();
			goto START;
			break;
		case 3:
			cout<<"Thanks for Using our Software..."<<endl;
			break;
		default:
			cout<<"Invalid Selection. Try Again..."<<endl;
			goto START;
			break;
	}
	check.close();
	system("pause");
}
