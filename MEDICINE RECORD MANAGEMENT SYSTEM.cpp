#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
using namespace std;
int r=0,counter=0;
ofstream fout;
ifstream fin;
struct date{
int mm,dd,yy;	
};
date d;
class medi
{
    int medino;
    char name[25];     
public:
    void add()
    {
        cout<<"\n\n\tUID FOR Medicine: ";
        
		cin>>medino;
        fflush(stdin);
		cout<<"\n\n\tName of the Medicine: ";
        cin>>name;
        fflush(stdin);
        cout<<"\n\n\tExpiry Date(dd-mm-yy) of the batch: ";
        cin>>d.mm>>d.dd>>d.yy;
    }
    void show()
    {
        cout<<"\n\tUID OF Medicine: ";
        cout<<medino;
        fflush(stdin);
        cout<<"\n\n\tName of the Medicine: ";
        cout<<name;
        fflush(stdin);
        cout<<"\n\n\tExp. Date of Batch: ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    void report()
	{
		
	cout<<"\t\t\t"<<medino<<"\t";
        puts(name);
        cout<<retno();
    }
    int retno()
    {
        return(medino);
    }};

class amount: public medi
{
  float price,qty,netamt;
public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt()
    {
        return(netamt);
    }
} 
amt;
void amount::add()
{
	cout<<"\n\n\n\t\t\tAdmin Persmisson Required for Authorization....Enter the 4 digit pin";
cin>>r;
if(r==1999){

    medi::add();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    fout.write((char*)&amt,sizeof(amt));
    fout.close();
}
else 
cout<<"Acess Denied!!";}
void amount::show()
{
    fin.open("medistore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    medi::show();
    cout<<"\n\n\tAvailable of Amount: ";
    cout<<qty*price;
    fin.close();
 system("pause");
   
}
void amount::report()
{   medi::report();
    cout<<"\t\t "<<price;
    cout<<"\t "<<qty;
    cout<<"\t "<<netamt;
    {
        cout<<"Searching...";
        getch();
        system("cls");
        cout<<"MEDICINE DETAILS";
        cout<<"NUMBER";
        cout<<"NAME";
        cout<<"PRICE";
        cout<<"QUANTITY";
        cout<<"NET AMOUNT";
    }
}
void amount::pay()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
	cout<<"\n\n\t\tPRICE                     :"<<price;
    cout<<"\n\n\t\tEXP OF BATCH              :"<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    cout<<"\n\n\t\tQUANTITY                  :"<<qty;
    cout<<"\n\n\n\t\tTOTAL AMOUNT AVAILABLE IN STOCK     :Rs."<<qty*price;
    cout<<"\n\t\t*********************************************"; }

int main()
{ fstream tmp("temp.dat",ios::binary|ios::out);
menu:
    system("cls");
    cout<<"\t\t\n\n\n\n\t\t********************************************************************************** ";
    cout<<"\n\t\t==================================================================================\n";
    cout<<"\t\t||\t\t||\t\t\t\t\t    ||\t\t\t||\n";
    cout<<"\t\t||\t\t|| \tMEDICINAL RECORD MANAGMENT SYSTEM   ||\t\t\t||\n";
    cout<<"\t\t||\t\t||\t\t\t\t\t    ||\t\t\t||";
 cout<<"\n\t\t==================================================================================\n";
    cout<<"\t\t**********************************************************************************\n";
	cout<<"\n\t\t\t1.****ADD****DELETE****ALTER THE RECORDS****\n\n";
    cout<<"\t\t\t2.SHOW MEDICINE FROM OUR MEDICOS\n\n";
    cout<<"\t\t\t3.EXIT SYSTEM\n\n";
    cout<<"\n\n\t\t\t\tPlease Enter Required Option: ";
    int ch,ff;
    float gtotal;
    cin>>ch;
    switch(ch)
    {
    case 1:
db:
        system("cls");
        cout<<"\n\n\t\t=================";
        
		cout<<"RECORD EDITOR ";
        cout<<"=================\n\n";
        cout<<"\n\t\t1.ADD MEDICINE DETAILS\n\n";
        cout<<"\t\t2.EDIT MEDCINE DETAILS\n\n";
        cout<<"\t\t3.DELETE MEDCINE DETAILS\n\n";
        cout<<"\t\t4.Back to Main Menu ";
        int apc;
        cin>>apc;
        switch(apc)
        {
        case 1:
            fout.open("medistore.dat",ios::binary|ios::app);
            amt.add();
            cout<<"\n\t\tRecord Saved Successfully!";
            getch();
            goto db;

        case 2:
            int mno;
            counter=0;
            cout<<"\n\n\tEnter UID Number to be Edited :";
            cin>>mno;
            fin.open("medistore.dat",ios::binary);
            fout.open("medistore.dat",ios::binary|ios::app);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    int x=amt.medi::retno();
                    if(x==mno)
                    {
                        counter=1;
                        fout.seekp(r*sizeof(amt));
                        system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        amt.show();
                        cout<<"\n\n\t\tEnter New Details\n";
                        amt.add();
                        cout<<"\n\t\tMedicine Details Altered Successfully!!";
                    getch();
					goto db;
					}
					
                    
                }
                r++;
			}
            
            if(counter==0)
            {
                cout<<"\n\t\tMedicine Record does not exist...Please Enter CORRECT values!!!";
                getch();
                goto db;
            }
            fin.close();
            getch();
            goto db;

        case 3:
            counter=0;
            cout<<"\n\n\tEnter medi Number to be deleted :";
            cin>>mno;
            fin.open("medistore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }

            fin.seekg(0);
            while(fin.read((char*)&amt, sizeof(amt)))
            {
                int x=amt.medi::retno();
                if(x!=mno)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    counter=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("medistore.dat",ios::trunc|ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat",ios::binary|ios::in);
            if(!tmp)
            {
                cout<<"Error in File";
                goto db;
            }
            while(tmp.read((char*)&amt,sizeof(amt)))
                fout.write((char*)&amt,sizeof(amt));
            tmp.close();
            fout.close();
            if(counter==1)
                cout<<"\n\t\tMEDICINE RECORD Succesfully Deleted";
            else if (counter==0)
                cout<<"\n\t\t Medicine does not Exist! Please Retry";
            getch();
            goto db;
        case 4:
            goto menu;
        default:
            cout<<"\n\n\t\tWrong Choice!!! Retry";
            getch();
            goto db;
        }
    case 2:
        system("cls");
        counter=0;
        int mno;
        cout<<"\n\n\t\tEnter Medicine Number :";
        cin>>mno;
        fin.open("medistore.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.medi::retno();
            if(x==mno)
            {
                amt.pay();
                counter=1;
                break;
            }
            system("pause");
        }
        if(counter==0)
            cout<<"\n\t\t Medicine does not exist....Please Retry!";
        getch();
        fin.close();
        goto menu;
    case 3:
        system("cls");
        cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
            system("cls");
            cout<<"\n\n\n\t************************** THANKS FOR USING THIS SYSTEM ********************************************";
            
			cout<<"\n\n\t\tBy : RAHUL RATHORE \n\n\t\t Reg. No: 11702112 LPU";
			cout<<"\n\t\t TO MRS. RICHA JAIN CSE DEPRT. 2018-19";
			getch();
            exit(0);
        }
    default:
        cout<<"\n\n\t\tWrong Choice!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TRY AGAIN!";
        getch();
		goto menu;}
		return 0;} 
