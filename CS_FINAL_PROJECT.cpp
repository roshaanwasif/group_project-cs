#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS



class hotel
{
protected:
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    char ID_NUMBER[15];
    char Gender[20];

public:

    
    
     		
    void rooms();			//to display alloted rooms
    int check(int);		    //to check room status
    void bill(int);         //for the bill of a record
	void display();        //to display the customer record                
//END OF CLASS
};




//END OF DISPLAY FUNCTION



class Managment : public hotel{
	public:
	void add();			//to book a room
	void edit();			//to edit the customer record
	void modify(int);		//to modify the record
    void delete_rec(int);		//to delete the record
    void main_menu();		//to dispay the main menu
	
};



//FOR DISPLAYING MAIN MENU



void Managment::main_menu()
{ 

    int choice;
    while (choice != 5)
    {

        system("cls");
        cout << "\n\t\t\t\t***";
        cout << "\n\t\t\t\t HOTEL MANAGEMENT "; 
        cout << "\n\t\t\t\t      * MAIN MENU *";
        cout << "\n\t\t\t\t***";
        cout << "\n\n\n\t\t\t1.Book A Room";
        cout << "\n\t\t\t2.Customer Records";
        cout << "\n\t\t\t3.Rooms Allotted";
        cout << "\n\t\t\t4.Edit Record";
        cout << "\n\t\t\t5.Exit";
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:	add();
            break;

        case 2: display();
            break;

        case 3: rooms();
            break;

        case 4:	edit();
            break;

        case 5: break;

        default:
        {

            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to   continue....!!";
            getch();

        }

        }

    }

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM


void Managment::add()
{

    system("cls");
    int r, flag;
    ofstream fout("Record.txt", ios::app);

    cout <<"\n Enter Customer Detalis";
    cout <<"\n ----------------------";
    cout <<"\n\n Room no: ";
    cout <<"\n Total no. of   Rooms - 50";
    cout <<"\n STANDARD Rooms from 1---20";
    cout << "\n MODERATE Rooms from 21---30";
    cout << "\n SUPERIOR Rooms from 31--40";
    cout<< "\n JUNIOR  Suit ROoms from 41--45"; 
	cout << "\n SUIT Rooms from 46--50";
    cout << "\n Enter The Room no. you want to stay in :- " << endl;
    cin >> r;

    flag = check(r);
	if(r>=51){cout<<"invalid";
	system("pause");
	}
    if (flag)
        cout << "\n Sorry..!!!Room is already booked";

    else
    {

        room_no = r;
        cout << " Name: ";
        cin >> name;
        cout << " Address: ";
        cin >> address;
        cout << " Phone No: ";
        cin >> phone;
        cout<<"ID NUMBER:";
        cin>>ID_NUMBER;
        cout<<"Gender:";
        cin>>Gender;

       fout.write((char*)this, sizeof(hotel));
        cout << "\n Room is booked...!!!";

    }

    cout << "\n Press any key to continue.....!!";
    fout.close();
    getch();
    

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD
void hotel::display()
{

    system("cls");

    ifstream fin("Record.txt", ios::in);
    int r, flag;

    cout << "\n Enter room no. for a particular customer`s details :- " << endl;
    cin >> r;

    while (!fin.eof())
    {

        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {

            system("cls");
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            cout<<"\n ID number:" << ID_NUMBER;
            cout<<"\n Gender :" << Gender;
            flag = 1;
            break;

        }

    }

    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant....!!";
    cout << "\n\n Press any key to continue....!!";
     fin.close();
    getch();
   
}







//start OF DISPLAY FUNCTION
        
//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

    system("cls");

    ifstream fin("Record.txt", ios::in);
    cout << "\n\t\t\t    List Of Rooms Allotted"<<endl;
    cout << "\n\t\t\t    ----------------------"<<endl;
    
   
    
    while (!fin.eof())
    {

        fin.read((char*)this, sizeof(hotel));
        cout << " Room No "<< room_no <<endl;
 
    cout<<"Name: "   << name <<endl;
    cout<<"Address:   "<<address <<endl;
    cout<<"	Phone No.  " <<phone<<endl;
    cout<<" ID NUMBER: "<<ID_NUMBER << endl  ;
    cout<<" Gender: "<< Gender<<endl;
    }

    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    fin.close();
    getch();
    

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void Managment::edit()
{

    system("cls");

    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1.Modify Customer Record";
    cout << "\n 2.Delete Customer Record";
    cout << "\n 3. Bill Of Customer";
    cout << "\n Enter your choice: ";

    cin >> choice;
    system("cls");

    cout << "\n Enter room no: ";
    cin >> r;

    switch (choice)
    {

    case 1:	modify(r);
        break;

    case 2:	delete_rec(r);
        break;

    case 3: bill(r);
        break;

    default: cout << "\n Wrong Choice.....!!";

    }
    cout << "\n Press any key to continue....!!!";
    
    getch();
}


int hotel::check(int r)
{

    int flag = 0;

    ifstream fin("Record.txt", ios::in);

    while (!fin.eof())
    {

        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {

            flag = 1;
            break;

        }

    }

    fin.close();
    return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void Managment::modify(int r)
{

    long pos, flag = 0;

    fstream file("Record.txt", ios::in | ios::out );

    while (!file.eof())
    {

        pos = file.tellg();
        file.read((char*)this, sizeof(hotel));

        if (room_no == r)
        {

            cout << "\n Enter New Details";
            cout << "\n -----------------";
            cout << "\n Name: ";
            cin >> name;
            cout << " Address: ";
            cin >> address;
            cout << " Phone no: ";
            cin >> phone;
            file.seekg(pos);
            file.write((char*)this, sizeof(hotel));
            cout << "\n Record is modified....!!";
            flag = 1;
            break;

        }

    }

    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant...!!";
    file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void Managment::delete_rec(int r)
{

    int flag = 0;
    char ch;
    ifstream fin("Record.txt", ios::in);
    ofstream fout("temp.txt", ios::out);

    while (!fin.eof())
    {

        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)

        {

            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Pone No: " << phone;
            cout << "\n\n Do you want to delete this record(y/n): ";
            cin >> ch;

            if (ch == 'n')
                fout.write((char*)this, sizeof(hotel));
            flag = 1;

        }

        else
            fout.write((char*)this, sizeof(hotel));

    }

    fin.close();
    fout.close();

    if (flag == 0)
        cout << "\n Sorry room no. not found or vacant...!!";

    else
    {

        remove("Record.txt");
        rename("temp.txt", "Record.txt");

    }

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{

    hotel h1;
    ifstream f1;
    f1.open("record.txt", ios::in );

    if (!f1)
        cout << "cannot open";

    else
    {

        f1.read((char*)&h1, sizeof(hotel));
        while (f1)

        {

            f1.read((char*)&h1, sizeof(hotel));

        }

        if (h1.room_no == r)
        {

            if (h1.room_no >= 1 && h1.room_no <= 20)
                cout << "your bill = 2000";

            else if (h1.room_no >= 21 && h1.room_no <= 30)
                cout << "your bill = 3000";
                
            else if (h1.room_no >= 31 && h1.room_no <= 40)
                cout << "your bill = 5000";
                
                else if (h1.room_no >= 41 && h1.room_no <= 45)
                cout << "your bill = 6000";


            else
                cout << "your bill = 7000";

        }

        else
        {
            cout << "room no. not found";
        }

    }

    f1.close();
    getch();

}

//END OF BILLING FUNCTION

//START OF MAIN PROGARM


int main()
{
    



    Managment h;

    system("cls");

    cout << "\n\t\t\t**";
    cout << "\n\t\t\t* HOTEL MANAGEMENT SYSTEM*";
    cout << "\n\t\t\t* WELCOME DEAR USER";
    cout << "\n\t\t\t**";
   
    cout << "\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

    getch();

    h.main_menu();
    return 0;
}