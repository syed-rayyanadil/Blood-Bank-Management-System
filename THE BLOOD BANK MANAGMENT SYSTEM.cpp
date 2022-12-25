#include <iostream>
#include <fstream>
#include <cstring>
#include<math.h>
#include<dos.h>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<ctype.h>
#include<windows.h>
#include<process.h>
#include<conio.h>
#include<cstdio>
#include <unistd.h>
#include <iomanip>

using namespace std;


/********************************************* Declaration of all functions******************/

void delay (unsigned int);
void exit_menu(void);
void loading(void);
void gotoxy(int , int );
int t(void);
void boxOperation(char ,int ,int,int  ,int ,void (*functionPtr)(char,int ,int,int,int ));
void printSquareBox(char ,int ,int ,int  ,int );
void printLineSlowly(char ,int ,int );
void printStringSlowly(string , int );
void draw_symbol(int , int , int );
void mainmenu_general(void);
void mainmenu_user(void);
void user_option(void);
void mainmenu(void);
bool Password(string ); 
void clear_Area(int, int , int, int);
void mainmenu_staff(void);
void user_signup();
void user_home(string);
void donate(string);
void req_blood(string);
//void mainmenu_user(void);
/********************************************* Declaration of class******************/
class User;
class Staff;
class Donor;
//class Acceptor;

/********************************Global Variables*****************************/
const char* password = "fast123";
const char* staffname1 = "Rayyan";
const char* staffname2 = "Ijlal";
const char* staffname3 = "Maham";
const char* staffname4 = "Nuces";
/********************************** Date class***************************************/
class Date{
	int date;
	int month ;
	int year;
	public:
		Date();
		void set_d(int d);
		void set_m(int m);
		void set_y(int y);
		int get_d()const;
		int get_m()const;
		int get_y()const;
		friend ostream& operator<<(ostream&, const Date &d );
		~Date();
		};
/******************************************* Date class functions**************************/
Date::Date():date(0),month(0),year(0){
}
void Date::set_d(int d){
	if(d>=1 || d<=31)
	date=d;
	else
	date =0;
}
void Date::set_m(int m){
	if(m>=1 || m<=12)
	month = m;
	else
	month = 0;
}
void Date::set_y(int y){
	if(y>0)
	year = y;
	else
	year = 0;
	}
int Date::get_d()const{
	return date;
	}
int Date::get_m()const{
	return month;
	}
int Date::get_y()const{
	return year;
}
ostream& operator<<(ostream& out , const Date &d){
	out<<d.date<<"-"<<d.month<<"-"<<d.year;
}
Date::~Date(){
}
//*********************************Staff Class*************************************//
/*class Staff{
	int staff_id;
	string name;
	string user_name;
	string password;
	public:
		Staff();
		void setid(int staff_id);
		void setname(string name);
		void setusername(string user_name);
		void setpassword(string password);
		int getid()const;
		string getname()const;
		string getusername();
		string getpassword();
		void check_donor(string un);
		void form();
		~Staff();
	friend class Donor;
		//friend class Acceptor;
};
Staff::Staff(){
	staff_id=0;
	name='\0';
	user_name='\0';
	password='\0';
}
Staff::~Staff(){
	
}
		void Staff::setid(int staff_id){
			this->staff_id=staff_id;
		}
		void Staff::setname(string name){
			this->name=name;
		}
		void Staff::setusername(string user_name){
			this->user_name=user_name;
		}
		void Staff::setpassword(string password){
			this->password=password;
		}
		int Staff::getid()const{
			return staff_id;
			}
		string Staff::getname()const{
			return name;
		}
		string Staff::getusername(){
			return user_name;
		}
		string Staff::getpassword(){
			return password;
		}
		void Staff::form(){
			int s_id;
      string n,un,p;
			gotoxy(45,15);cout<<"Staff ID:";
			gotoxy(105,15);cout<<"Name:";
			gotoxy(105,16);cout<<"User Name:";
			gotoxy(45,16);cout<<"Password:";
			gotoxy(56,15);cin>>s_id;
			this->setid(s_id);
			gotoxy(116,15);getline(cin,n);
			this->setname(n);
			gotoxy(56,16);getline(cin,un);
			this->setusername(un);
			gotoxy(116,16);getline(cin,p);
			this->setpassword(p);
		}
void Staff::check_donor(string un){
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(75,12); 
	printStringSlowly("PLEASE FILL UP THE FORM FOR SIGNING UP", 5);
	gotoxy(113,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(80,20);cout<<"Wait! while Nurse is doing your medical checkup.";
	delay(10);
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(50,12); 
	printLineSlowly('^',40,5);
	gotoxy(80,12); 
	printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(100,12); printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,100,6);
	float h, w;
	string bg, ad;
	int pr, bu, bd;
	ifstream fin;
	fin.open("User all_details.txt", ios::in);
	int tag=0;
	string s2,s3;
	while(!fin.eof()||tag==0)
	{
		fin>>s2;
		if(s2==un){
		tag=1;}
		else tag=0;}
		if(tag==1){
		getline(fin,s3);
		gotoxy(60,15); cout<<"Check up of Ms./Mr. ";
		gotoxy(80,15);cout<<s3<<"\n";
		}
	gotoxy(45,16);cout<<"Weight: ";
	gotoxy(53,16); cin>>w;
		if(w<50)
		{
			clear_Area(45,13,100,6);
			gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HE/SHE IS UNDERWEIGHT";
			user_home(un);
		}
	gotoxy(105,17);cout<<"Blood Pressure(UP):";
	gotoxy(123,17); cin>>bu;
	gotoxy(45,18);cout<<"Blood Pressure(DOWN):";
	gotoxy(65,18); cin>>bd;  
	if(bu<125 || bd<75){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HIS/HER BP IS LOW";
		user_home(un);
}
	gotoxy(105,18);cout<<"Heamoglobin: ";
	gotoxy(118,18);cin>>h;	    
	if(h<11.5){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HIS/HER HEAMOGLOBIN IS LOW";
		user_home(un);
	}
	gotoxy(45,19);cout<<"Blood Group:"; 
	gotoxy(57,19);cin>>bg;
	gotoxy(105,19);cout<<"Pulse rate:"; 
	gotoxy(116,19);cin>>pr;
	gotoxy(45,20); cout<<"Any disease?:"; 
	gotoxy(58,20);cin>>ad;
	if(ad=="Cancer"||ad=="cancer"){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HE/SHE HAS A DANGEROUS DISEASE";
		user_home(un);
	}
	//Donor d1;
	Donor::set_wt(w);
	Donor::set_bu(bu);
	Donor::set_bd(bd);
	Donor::set_h(h);
	Donor::set_bg(bg);
	Donor::set_ad(ad);
}*/
//*******************************User Class******************//
class User{
	private:
	string first_name;
	string last_name;
	Date DOB;
	int age;
	string phone;
	string address;
	string email;
	string city;
	string country;
	string nationality;
	string religion;
	string gender;
	public:
		User();
		~User();
		void setfirstname(string first_name);
		void setlastname(string last_name);
		void setphone(string phone);
		void setage(int age);
		void setaddress(string address);
		void setemail(string email);
		void setcity(string city);
		void setcountry(string country);
		void setnationality(string nationality);
		void setreligion(string religion);
		void setgender(string gender);
		string getfirstname()const;
		string getlastname()const;
		string getphone()const;
		int getage()const;
		string getaddress()const;
		string getemail()const;
		string getcity()const;
		string getcountry()const;
		string getnationality()const;
		string getreligion()const;
		string getgender()const; 
		void form();
		void assign_un();
};
User::User(){
	first_name='\0';
	last_name='\0';
	phone='\0';
	age=0;
	address='\0';
	city='\0';
	country='\0';
	nationality='\0';
	religion='\0';
	gender='\0';
}
void User::setfirstname(string first_name){
	this->first_name=first_name;
}
		void User::setlastname(string last_name){
			this->last_name=last_name;
		}
		void User::setphone(string phone){
			this->phone=phone;
		}
		void User::setage(int age){
			this->age=age;
		}
		void User::setaddress(string address){
			this->address=address;
		}
		void User::setemail(string email){
			this->email=email;
		}
		void User::setcity(string city){
			this->city=city;
		}
		void User::setcountry(string country){
			this->country=country;
		}
		void User::setnationality(string nationality){
			this->nationality=nationality;
		}
		void User::setreligion(string religion){
			this->religion=religion;
		}
		void User::setgender(string gender){
			this->gender=gender;
		}
		string User::getfirstname()const{
			return first_name;
		}
		string User::getlastname()const{
			return last_name;
		}
		string User::getphone()const{
			return phone;
		}
		int User::getage()const{
			return age;
		}
		string User::getaddress()const{
			return address;
		}
		string User::getemail()const{
		return email;
		}
		string User::getcity()const{
			return city;}
		string User::getcountry()const{
			return country;
		}
		string User::getnationality()const{
			return nationality;
		}
		string User::getreligion()const{
			return religion;
		}
		string User::getgender()const{
			return gender;
		}
		User::~User(){	
		} 
		void User::form(){ 
		string f_n,s_n,a,ci,co,N,G,ph,e; 
		int d,m,y,ag;
		 gotoxy(45,15);cout<<"First name:"; 
		 gotoxy(105,15);cout<<"Second name:"; 
		   gotoxy(45,16);cout<<"Date of Birth:";
			gotoxy(105,16);cout<<"Age:";	    
		    gotoxy(45,17);cout<<"Phone number:"; 
			 gotoxy(105,17);cout<<"Address:";
			 gotoxy(45,18);cout<<"Email:"; 
			  gotoxy(105,18);cout<<"City:"; 
			   gotoxy(45,19);cout<<"Country:";  
			    gotoxy(105,19);cout<<"Nationality:"; 
				gotoxy(45,20);cout<<"Gender:";  
				 gotoxy(56,15);getline(cin,f_n);  
				 this->setfirstname(f_n);
				 gotoxy(117,15);getline(cin,s_n); 
				 this->setlastname(s_n);
				 gotoxy(61,16); cout<<"/";
				 gotoxy(64,16); cout<<"/";
				 gotoxy(59,16); cin>>d; 
				 gotoxy(62,16);cin>>m; 
				gotoxy(65,16);cin>>y; 
				  DOB.set_d(d); 
				  DOB.set_m(m); 
				  DOB.set_y(y);  
				  gotoxy(109,16);cin>>ag;
				this->setage(ag);
				gotoxy(59,17); getline(cin,ph); 
			     this->setphone(ph); 
				 gotoxy(113,17);getline(cin,a); 
				 this->setaddress(a);
				 gotoxy(51,18);getline(cin,e);
				 this->setemail(e); 
				 gotoxy(110,18);getline(cin,ci); 
				 this->setcity(ci);   
				 gotoxy(53,19);getline(cin,co); 
				 this->setcountry(co); 
				gotoxy(117,19);getline(cin,N); 
				 this->setnationality(N); 
				 gotoxy(52,20);getline(cin,G); 
				 this->setgender(G); 
				 assign_un();    
		}
void User::assign_un(){
	clear_Area(45,13,115,9);
	string s,si;
	string c1,c2;
	bool tag;
	ofstream fout;
	ifstream fin;
	do {
	again:
	gotoxy(45,14);cout<<"Enter a Unique Username: ";
	//fflush(stdin);
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";
			getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		getline(fin,si);
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
		fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}while(c1!=c2);
	fout.open("UserPasswords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("User all_details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getfirstname()<<" "<<getlastname()<<"\nDetails\n\n\nAge: "<<getage()<<"\nDate of Birth: "<<DOB.get_d()<<"/"<<DOB.get_m()<<"/"<<DOB.get_y()<<"\nAddress: "<<getaddress()<<"\nCity: "<<getcity()
	<<"\nCountry: "<<getcountry() <<"\nNationality : "<<getnationality()<<"\nEmail : "<<getemail()<< "\nContact: "<<getphone()<<"\n\n***\n\n";	
	/*char* fname[20];
	strcpy(fname,first_name.c_str());
	strcat(fname,".txt");
	int len=strlen(fname);
	fname[len+1]='\0';
	ofstream uf;
	uf.open(fname,ios::out ,ios::app);*/
		ofstream fm( ("Members Details\\"+getfirstname()+".txt").c_str() );
	fm<<"\n"<<getfirstname()<<" "<<getlastname()<<"\'Details\n\n\nAge: "<<getage()<<"\nDate of Birth: "<<DOB.get_d()<<"/"<<DOB.get_m()<<"/"<<DOB.get_y()<<"\nAddress: "<<getaddress()<<"\nCity: "<<getcity()
	<<"\nCountry: "<<getcountry() <<"\nNationality : "<<getnationality()<<"\nEmail : "<<getemail()<< "\nContact: "<<getphone()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,13,115,9);
	gotoxy (45,15); cout << "Your account has been created";
	gotoxy (45,17); cout << "THANK YOU FOR CHOOSING THE BLOOD BANK";
	getch();	
	user_home(s);
}
class Donor:virtual public User{
	friend class Staff;
	private:
	string blood_grp;
	float weight;
	int bp_up;
	int bp_down;
	int pulse_rate;
	float heamoglobin;
	string any_disease;
	public:
		Donor();
		void set_bg(string bg);
		void set_wt(float wt);
		void set_bu(int bu);
		void set_bd(int bd);
		void set_pr(int pr);
		void set_h(float h);
		void set_ad(string ad);
		string get_bg()const;
		float get_wt()const;
		int get_bu()const;
		int get_bd()const;
		int get_pr()const;
		float get_h()const;
		string get_ad()const;
		~Donor();
		
};
Donor::Donor(){
	blood_grp = '\0';
	weight = 0;
	bp_up = 0;
	bp_down = 0;
	pulse_rate=0;
	heamoglobin = 0;
	any_disease = '\0';
}
void Donor::set_ad(string ad){
	any_disease = ad;
}
void Donor::set_wt(float wt){
	weight = wt;
}
void Donor::set_bu(int bu){
	bp_up = bu;
}
void Donor::set_bd(int bd){
	bp_down = bd;
}
void Donor::set_h(float h){
	heamoglobin = h;
}
void Donor::set_bg(string bg){
	blood_grp= bg;
}
string Donor::get_bg()const{
return blood_grp;}
float Donor::get_wt()const{
	return weight;
}
int Donor::get_bu()const{
	return bp_up;
}
int Donor::get_bd()const{
	return bp_down;
}
float Donor::get_h()const{
	return heamoglobin;
}
string Donor::get_ad()const{
	return any_disease;
}
Donor::~Donor(){
}
//**********************ACCEPTOR*****************//
class Acceptor:virtual public User{
private:
	string req_blood;
	int phone;
	int amount;
	public:
		Acceptor();
		void setreq_blood(string req_blood);
		void setphone(int phone);
		void setamount(int amount);
		string getreq_blood()const;
		int getphone()const;
		int getamount()const;
		~Acceptor();
};
Acceptor::Acceptor():req_blood(NULL),phone(0),amount(0){
}
void Acceptor::setreq_blood(string req_blood){
	this->req_blood=req_blood;
}
void Acceptor::setamount(int amount){
	this->amount=amount;
}
string Acceptor::getreq_blood()const{
	return req_blood;
}
int Acceptor::getamount()const{
	return amount;
}
Acceptor::~Acceptor(){
	
}	
class Staff{
	int staff_id;
	string name;
	string user_name;
	string password;
	public:
		Staff();
		void setid(int staff_id);
		void setname(string name);
		void setusername(string user_name);
		void setpassword(string password);
		int getid()const;
		string getname()const;
		string getusername();
		string getpassword();
		void check_donor(string un);
		void handle_acceptor(string un);
		void form();
		~Staff();
	friend class Donor;
	friend class Acceptor;
};
Staff::Staff(){
	staff_id=0;
	name='\0';
	user_name='\0';
	password='\0';
}
Staff::~Staff(){
	
}
		void Staff::setid(int staff_id){
			this->staff_id=staff_id;
		}
		void Staff::setname(string name){
			this->name=name;
		}
		void Staff::setusername(string user_name){
			this->user_name=user_name;
		}
		void Staff::setpassword(string password){
			this->password=password;
		}
		int Staff::getid()const{
			return staff_id;
			}
		string Staff::getname()const{
			return name;
		}
		string Staff::getusername(){
			return user_name;
		}
		string Staff::getpassword(){
			return password;
		}
		void Staff::form(){
			int s_id;
      string n,un,p;
			gotoxy(45,15);cout<<"Staff ID:";
			gotoxy(105,15);cout<<"Name:";
			gotoxy(105,16);cout<<"User Name:";
			gotoxy(45,16);cout<<"Password:";
			gotoxy(56,15);cin>>s_id;
			this->setid(s_id);
			gotoxy(116,15);getline(cin,n);
			this->setname(n);
			gotoxy(56,16);getline(cin,un);
			this->setusername(un);
			gotoxy(116,16);getline(cin,p);
			this->setpassword(p);
		}
void Staff::check_donor(string un){
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(75,12); 
	printStringSlowly("PLEASE FILL UP THE FORM FOR SIGNING UP", 5);
	gotoxy(113,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(80,20);cout<<"Wait! while Nurse is doing your medical checkup.";
	delay(10);
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(50,12); 
	printLineSlowly('^',40,5);
	gotoxy(80,12); 
	printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(100,12); printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,100,6);
	float h, w;
	string bg, ad;
	int pr, bu, bd;
	ifstream fin;
	fin.open("User all_details.txt", ios::in);
	int tag=0;
	string s2,s3;
	while(!fin.eof()||tag==0)
	{
		fin>>s2;
		if(s2==un){
		tag=1;}
		else tag=0;}
		if(tag==1){
		getline(fin,s3);
		gotoxy(60,15); cout<<"Check up of Ms./Mr. ";
		gotoxy(80,15);cout<<s3<<"\n";
		}
	gotoxy(45,16);cout<<"Weight: ";
	gotoxy(53,16); cin>>w;
		if(w<50)
		{
			clear_Area(45,13,100,6);
			gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HE/SHE IS UNDERWEIGHT";
			user_home(un);
		}
	gotoxy(105,17);cout<<"Blood Pressure(UP):";
	gotoxy(123,17); cin>>bu;
	gotoxy(45,18);cout<<"Blood Pressure(DOWN):";
	gotoxy(65,18); cin>>bd;  
	if(bu<125 || bd<75){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HIS/HER BP IS LOW";
		user_home(un);
}
	gotoxy(105,18);cout<<"Heamoglobin: ";
	gotoxy(118,18);cin>>h;	    
	if(h<11.5){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HIS/HER HEAMOGLOBIN IS LOW";
		user_home(un);
	}
	gotoxy(45,19);cout<<"Blood Group:"; 
	gotoxy(57,19);cin>>bg;
	gotoxy(105,19);cout<<"Pulse rate:"; 
	gotoxy(116,19);cin>>pr;
	gotoxy(45,20); cout<<"Any disease?:"; 
	gotoxy(58,20);cin>>ad;
	if(ad=="Cancer"||ad=="cancer"){
		clear_Area(45,13,100,6);
		gotoxy(45,17); cout<<"SORRY! DONOR CANNOT DONATE BLOOD AS HE/SHE HAS A DANGEROUS DISEASE";
		user_home(un);
	}
	Donor d1;
	d1.set_wt(w);
	d1.set_bu(bu);
	d1.set_bd(bd);
	d1.set_h(h);
	d1.set_bg(bg);
	d1.set_ad(ad);
}
void Staff::handle_acceptor(string un){
	string bg;
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(75,12); 
	printStringSlowly("USER REQUIRE BLOOD SECTION", 5);
	gotoxy(113,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(45,17);cout<<"Mention the blood group you want to search: ";
	gotoxy(89,17);cin>>bg;
	gotoxy(80,20);cout<<"Wait! while our staff is looking for your blood.";
	delay(10);
	clear_Area(0,0,200,50);
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(50,12); 
	printLineSlowly('^',40,5);
	gotoxy(80,12); 
	printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(100,12); printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,100,6);
	Acceptor a1;
	a1.setreq_blood(bg);
	float amt;
	ifstream fin, fin2;
	fin.open("User all_details.txt", ios::in);
	int tag=0;
	string s2,s3;
	while(!fin.eof()||tag==0)
	{
		fin>>s2;
		if(s2==un){
		tag=1;}
		else tag=0;}
		if(tag==1){
		getline(fin,s3);
		gotoxy(60,15); cout<<"Searching blood for Ms./Mr. ";
		gotoxy(88,15);cout<<s3<<"\n";
		}
	fin2.open("Blood record.txt", ios::in);
	Donor temp;
	while(!fin.eof()||tag==0)
	{
		fin.read((char*)&temp, sizeof(temp));
		if(temp.get_bg()==bg){
		tag=1;}
		else tag=0;}
		if(tag==1){
		float p;
		gotoxy(60,15); cout<<"Price:";
		gotoxy(66,15); cin>>p;
		a1.setamount(p);
		ofstream fout3;
		fout3.open("Acceptors.txt", std::fstream::out | std::fstream::app);		
		fout3<<un;
		fout3<<a1.getreq_blood();
		fout3<<a1.getamount();
		fout3.close();
		}
}
COORD coord = {0, 0};
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

void gotoxy(int x, int y){ 
	COORD coord; 
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading()
{
	std::cout << std::setw(20) << " " << "\n\n\t\t\t\t LOADING...\n";
	std::cout << "               \r";
	std::cout << "\t\t\t     ";
	SetConsoleTextAttribute( hstdout, 0xCF );
	for(int i=0; i<15; i++)
	{
		std::cout<<" ";
		Sleep(250);
	}
}
int t(void){
	time_t t;
	time(&t);
	cout<<ctime(&t);
	return 0 ;
}
void boxOperation(char l,int height,int width,int x ,int y,void (*functionPtr)(char,int ,int,int,int )){
	(*functionPtr)(l,height,width,x,y);
}

void printSquareBox(char l,int height,int width,int x ,int y){
	if(width>=200 ){
		width=180;
	}
	if(y>=140 ){
		y=100;
	}
	if(height>=80){
		height=70;
	}
	if(x>=60){
		x=50;
	}
	gotoxy(x,y++);
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(i==height || i==1 || i==height-1 || i==2 || i==height-2 || i==3 || i==height-3 || i==4 ){
				cout<<l;
			}
			else
			{
				if( j==1 || j==width || j==2 || j==width-1 || j==3 || j==width-2 || j==4 || j==width-3 || j==5 || j==width-4){
					cout<<l;
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		gotoxy(x,y++);
	}	
}
void printLineSlowly(char l,int k,int t){
	for(int i=0;i<k;i++){
		delay(t);
		cout<<l;
	}
}

void delay (unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void printStringSlowly(string s, int t){
	int len = s.length();
	for(int i=0;i<len;i++){
		delay(t);
		cout<<s[i];
	}
}
void draw_symbol(int x, int y, int t){
	int i;
	for (i = 1; i <= 6; i++){
		switch(i){
			case 1:
				gotoxy(x, y); 
				printStringSlowly("*", t-1);
				break;
			case 2:
				gotoxy(x-1, y+1); 
				printStringSlowly("*'*", t-1);
				break;
			case 3:
				gotoxy(x-2, y+2); 
				printStringSlowly("*'''* ", t-1);
				break;
			case 4:
				gotoxy(x-3, y+3); 
				printStringSlowly("*'''''* ", t-1);
				break;
			case 5:
				gotoxy(x-2, y+4); printStringSlowly("*'*'*", t-1);
				break;
			
		}
	}
	for (i = 1; i <= 2; i++){
		switch(i){
			case 1:
				gotoxy(x+5, y+2); printStringSlowly("THE", t);
				break;
			case 2:
				gotoxy(x+6, y+3); printStringSlowly("BLOOD BANK", t);
				break;
		}
	}
}
void mainmenu_general(){
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 40, 5);
	gotoxy(80,12); 
	printStringSlowly("WELCOME TO THE BLOOD BANK", 5);
	gotoxy(106,12); 
	printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	gotoxy(57,18); cout<<"                            ";
	gotoxy(45,14); cout<<"1. FOR USER";
	gotoxy(45,15); cout<<"2. FOR STAFF";
//	gotoxy(45,16); cout<<"3. ADMINISTRATOR";
	gotoxy(45,17); cout<<"4. EXIT";
	gotoxy(45,19); cout<<"CHOOSE ONE: ";
	char ch;
	ch = getch();
	if (ch == 27){
		exit_menu();
	}
	switch(ch){
		case '1':
			mainmenu_user();
			break;
		case '2':
			mainmenu_staff();
			break;
	//	case '3':
	//		mainmenu_admin();
	//		break;
		case '4':
			gotoxy(1,35);
			exit_menu();
		default:
			gotoxy(57,18); cout<<"WRONG ENTRY. ";
			getch();
			mainmenu_general();
	}
}
bool verify_un(string s){
	string s1;
	ifstream fin1;
	fin1.open("Username.txt");
	while(!fin1.eof()){
		getline(fin1,s1);
		if(s1==s)
		return true;
		else
		return false;
	}
	}
void user_signup(){
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 30, 5);
	gotoxy(75,12); 
	printStringSlowly("PLEASE FILL UP THE FORM FOR SIGNING UP", 5);
	gotoxy(113,12); 
	printLineSlowly('^', 30, 5);	
	loading();
	User u1;
	u1.form();
	}
void user_signin(){
	bool flag; 
	string un;
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('^', 40, 5);
	gotoxy(80,12); printStringSlowly("  USER SECTION  ", 5);
	gotoxy(96,12); printLineSlowly('^', 40, 5);
	gotoxy(45,13); cout<<"ENTER USERNAME: ";
	gotoxy(65,13); cin>>un;
	flag = verify_un(un);
	if (flag== true)
	{
		Password("Enter User Password: ");
		user_home(un);
	}
	else {
		gotoxy(45,16); cout<<"WRONG USERNAME! ";
		gotoxy(45,17); cout<<"Don't have a username?";
		gotoxy(45,18); cout<<"Press 1 to SIGN UP";
		gotoxy(45,19); cout<<"Press 2 to TRY AGAIN";
		gotoxy(45,20); cout<<"Press 3(Backspace) to EXIT";
		char ch;
		ch = getch();
		switch(ch){
		case '1':
			user_signup();
		case '2':
			user_signin();
		case '3':
			exit_menu();
		default:
			gotoxy(45,21);
			
	}
	
}
}
void mainmenu_user(){
	char ch;
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('^', 40, 5);
	gotoxy(80,12); printStringSlowly(" USER SECTION ", 5);
	gotoxy(94,12); printLineSlowly('^', 40, 5);
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	gotoxy(45,14); 
	ch = getch();
	if (ch == 8){
		mainmenu_general();
	}
	else{
		clear_Area(45,13,115,6);
		gotoxy(45,13);
		user_option();
	}
}
void user_option(){
	
	//gotoxy(57,18); cout<<"                            ";
	gotoxy(45,14); cout<<"1. SIGN IN";
	gotoxy(45,15); cout<<"2. SIGN UP";
	gotoxy(45,17); cout<<"3. EXIT";
	gotoxy(45,19); cout<<"CHOOSE ONE: ";
	char ch;
	ch = getch();
	if (ch == 27){
		exit_menu();
	}
	switch(ch){
		case '1':
			user_signin();
			break;
		case '2':
			user_signup();
			break;
		case '3':
			gotoxy(1,35);
			exit_menu();
		default:
			gotoxy(57,20); cout<<"WRONG ENTRY. ";
			getch();
			user_option();
	}
}
void user_home(string un){
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(45,12); 
	printLineSlowly('^', 40, 5);
	gotoxy(80,12); 
	printStringSlowly(" HOME ", 5);
	gotoxy(86,12); 
	printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	gotoxy(57,18); cout<<"                            ";
	gotoxy(45,14); cout<<"1. DONATE";
	gotoxy(45,15); cout<<"2. NEED BLOOD";
	gotoxy(45,16); cout<<"3. MY ACCOUNT";
	gotoxy(45,17); cout<<"4. REFER A FRIEND";
	gotoxy(45,18); cout<<"5.SIGN OFF";
	gotoxy(45,20); cout<<"CHOOSE OPTION: ";
	char ch;
	ch = getch();
	if (ch == 8){
		exit_menu();
	}
	switch(ch){
		case '1':
			donate(un);
			break;
		case '2':
			req_blood(un);
			break;
		case '3':
	//	user_account(un);
			break;
		case '4':
	//		refer_friend(un);
		case '5':
	//		mainmenu_user();
		default:
			gotoxy(57,18); cout<<"WRONG ENTRY. ";
			getch();
			user_home(un);
	}
}

void req_blood(string un){
	Staff s2;
	s2.handle_acceptor(un);
}
void donate(string un){
	Staff s1;
	s1.check_donor(un);
	
}
void mainmenu(){
	
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(50,12); 
	printLineSlowly('^',40,5);
	gotoxy(80,12); 
	printStringSlowly("PASSWORD PROTECTED", 5);
	gotoxy(98,12); 
	printLineSlowly('^',40,5);
	draw_symbol(130, 15, 5);
    Password("ENTER PASSWORD: ");
	mainmenu_general();
}
void print_thankYou(int x, int y){
	int i;
	int a = x-3;
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a,y); cout<<"    * * * * *";
				break;
			case 2:
				gotoxy(a,y+1); cout<<"       *    ";
				break;
			case 3:
				gotoxy(a,y+2); cout<<"      *    ";
				break;
			case 4:
				gotoxy(a,y+3); cout<<"     *    ";
				break;
			case 5:
				gotoxy(a,y+4); cout<<"    *    ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+13,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+12,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+12,y+2); cout<<"  * * * * *";
				break;
			case 4:
				gotoxy(a+12,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+12,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+25,y); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(a+24,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+24,y+2); cout<<"  * * * * *";
				break;
			case 4:
				gotoxy(a+24,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+24,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+37,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+36,y+1); cout<<"   * *     *";
				break;
			case 3:
				gotoxy(a+36,y+2); cout<<"  *   *   *";
				break;
			case 4:
				gotoxy(a+36,y+3); cout<<" *     * *";
				break;
			case 5:
				gotoxy(a+36,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+49,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+48,y+1); cout<<"   *     *  ";
				break;
			case 3:
				gotoxy(a+48,y+2); cout<<"  * * *";
				break;
			case 4:
				gotoxy(a+48,y+3); cout<<" *     *  ";
				break;
			case 5:
				gotoxy(a+48,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+64,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+63,y+1); cout<<"     *   *  ";
				break;
			case 3:
				gotoxy(a+63,y+2); cout<<"      *    ";
				break;
			case 4:
				gotoxy(a+63,y+3); cout<<"     *    ";
				break;
			case 5:
				gotoxy(a+63,y+4); cout<<"    *    ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+76,y); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(a+75,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+75,y+2); cout<<"  *       *";
				break;
			case 4:
				gotoxy(a+75,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+75,y+4); cout<<"* * * * *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+88,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+87,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+87,y+2); cout<<"  *       *";
				break;
			case 4:
				gotoxy(a+87,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+87,y+4); cout<<"    *    ";
				break;
		}
	}
	gotoxy(x+43,y+6); cout<<"        FOR  COPERATING        ";
	gotoxy(x+39,y+15); cout<<"HAVE A GOOD DAY!";
}
void exit_menu(){
	clear_Area(0,0,200,50);
	print_thankYou(45,13);
	delay(5000);
	gotoxy(1,35);
	exit(0);
	
}
bool Password(string s){ 
   	char ch, incrementer='A';
   	int i=0,j;
   	char* pass = new char[20];
   	gotoxy(60,13); cout<<"                                            ";
   	gotoxy(45,16); cout<<"                                                                   ";
   	gotoxy(45,13);
   	string str = s;
   	cout<<s;
   	char a;
	while(ch!=13){
		ch=getch();
		if (ch == 8) {
			if (i != 0) {
				cout << "\b \b";
				i--;
			}
		}
		if(ch!=13 && ch!=8){
		   pass[i] = ch;
		   putch('*');
		   i++;
		}
	}
   	pass[i] = '\0';
   	if (str == "ENTER PASSWORD: "){
   		if(strcmp(pass,password)==0){
    		gotoxy(45,16);
    		cout<<"CORRECT PASSWORD.";
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
     		gotoxy(45,16);
     		cout<<"WRONG PASSWORD. ";
     		ch = getch();
     		if (ch == 27){
     			exit_menu();
			}
     		Password(s);
   		}
	}
   	else{
   		if(strcmp(pass,staffname1)==0 || strcmp(pass,staffname2)==0 || strcmp(pass,staffname3)==0){
    		gotoxy(45,16);
    		cout<<"ACCESSED TO Ms./Mr. "<<pass;
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
     		gotoxy(45,16);
     		cout<<"INVALID PASSWORD. If You are not an Staff member Please Press Backspace.";
     		ch = getch();
     		if (ch == 8){
     			mainmenu_general();
			}
     		else if(ch == 27){
     			exit_menu();
			}
			Password(s);
		}
	}
}
void clear_Area(int x, int y, int width, int height){
	int x1 = x;
	for (int i = 1; i <= height; i++){
		for (int j = 1; j <= width; j++){
			gotoxy(x,y); cout<<" ";
			x++;
		}
		x = x1;
		y++;
	}
}
void mainmenu_staff(){
	boxOperation('^',25,130,24,7,printSquareBox);
	gotoxy(50,12); 
	printLineSlowly('^',40,5);
	gotoxy(80,12); 
	printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(100,12); printLineSlowly('^', 40, 5);
	draw_symbol(130, 15, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,100,6);
	char ch;
	int i=15,tag=0;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	gotoxy(45,14); 
	ch = getch();
	if (ch == 8){
		mainmenu_general();
	}
	else {
		if(ch == 27){
			exit_menu();
		}
		else{
			back:
			clear_Area(45,13,115,11);
			gotoxy(45,16);
			cout<<"1.View Details About users ";
			gotoxy(45,17);
			cout<<"2.Go Back (Backspace) ";
			gotoxy(45,18);
			cout<<"3.Exit";
			gotoxy(45,19);	
			cout<<"Enter Your Choice : ";
			char choice,d;
			choice=getch();
			if(ch==8 || ch=='2'){
				mainmenu_staff();
			}
			switch(choice){
				case '1':
					hi:
					clear_Area(45,13,115,11);
					gotoxy(45,15);
					cout<<"1.View Usernames and their Passwords.";
					gotoxy(45,16);
					cout<<"2.View Details by Username. ";
					gotoxy(45,17);
					cout<<"3.Go Back (Backspace) ";
					gotoxy(45,18);
					cout<<"Enter your Choice :";
					d=getch();
					switch(d){
						case '1':
							fin1.open("Usernames.txt");
							fin2.open("Passwords.txt");
							clear_Area(45,13,115,11);
							gotoxy(45,13);
							cout<<"USERNAMES: \tPasswords";
							while(!fin1.eof() || !fin2.eof()){
								getline(fin1,s1);
								getline(fin2,s2);
								
								gotoxy(45,i);
								cout<<s1;
								gotoxy(65,i);
								cout<<s2;
								i++;
							}
							fin1.close();
							fin2.close();
							gotoxy(45,i);
							cout<<"Press any key to go back . ";
							getch();
							goto hi;
							break;
						case '2':
							wapis:
							clear_Area(45,13,115,11);
							gotoxy(45,15);
							cout<<"Enter Username of Any Member to show details of his / her : ";
							cin>>s1;
								fin1.open("User all_details.txt");
								while(!fin1.eof()){
									do{
									fin1>>s2;
									if(s2==s1){
										tag=1;
										getline(fin1,s3);
											while(s3!="***"){
											gotoxy(45,i++);
											cout<<s3<<"\n";
											getline(fin1,s3);
											}
										}	
									} 
									while(s2!=s1);
								}
								if(tag==0){
									goto wapis;
								}
								fin1.close();
								gotoxy(45,13);
								cout<<"Press any key to go back.";getch();
								clear_Area(45,13,115,15);
								goto hi;
						break;
						case '3':
							goto back;
						break;
						default:
						gotoxy(57,18); cout<<"WRONG ENTRY. press any key..";
						getch();
						goto back;
					}
				break;
				case '4':
					
				break;
				default:
				gotoxy(57,18); cout<<"WRONG ENTRY. press any key";
				getch();
				mainmenu_staff();
			}
		}	
	}
	clear_Area(45,13,115,6);
	gotoxy(45,13);
}

int main(){
	system("mode con: cols=200 lines=80");
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_SHOWMAXIMIZED);
    gotoxy(90,2);
    cout<<"Starting Time Of Program";
    gotoxy(90,4);
	t();
	loading();
	mainmenu();
	return 0;
	}
