#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class cargo
{
public:
  string destination;
  float kgs;
  void getdata()
  {
    cout<<"\nEnter the destination for cargo:";
    cin>>destination;
    cout<<"\nEnter the weight in kgs:";
    cin>>kgs;
  }
  void putdata()
  {
    cout<<"\nCARGO DESTINATION:"<<destination<<"WEIGHT(kgs):"<<kgs;
  }
};

class passenger
{
public:
  int passenger_count;
  int senior_count;
  void getdata()
  {
    cout<<"\nEnter the total passenger count:";
    cin>>passenger_count;
    cout<<"\nEnter the senior passenger count:";
    cin>>senior_count;
  }
};



class Cruise
{
public:
  string maintain_num;
  string Cruise_num;
  string dep_loc;
  string arrival_loc;
  string total_jour_hrs;
  string pre_time_d_h;
  string pre_time_d_m;
  string pre_time_a_h;
  string pre_time_a_m;
  string status;
/*Cruise(string a, string b, string c, string d, int e, int f, int g)
  {
    maintain_num = a;
    Cruise_num = b;
    dep_loc = c;
    arrival_loc = d;
    total_jour_hrs = e;
    pre_time_d = f;
    pre_time_a = g;
  }*/
  /*int check_passenger()
  {

  }*/
/*  void turnaround_time()
  {

  }*/



};

class domestic:public Cruise
{
public:
  cargo c;
  passenger p;
  static int count;

  int check_passenger()
  {
    cout<<"\n\nChecking the number of passengers:";
    p.getdata();
    if(p.passenger_count==70 && p.senior_count==18)
    {
      return 1;
    }
    else {
      return 0;
    }
  }

    domestic()
    {
      string myArray[30];
      ifstream file("a.txt");
      if(file.is_open())
      {


          for(int i = 0; i < 30; i++)
          {
              file >> myArray[i];
          }
      }
      /*for(int i=count;i<count+6;i++)
      {
        cout<<myArray[i]<<"\n";
      }
      count = count+6;*/
      maintain_num = myArray[count+0];
      Cruise_num = myArray[count+1];
      dep_loc = myArray[count+2];
      arrival_loc = myArray[count+3];
      total_jour_hrs = myArray[count+4];
      pre_time_d_h = myArray[count+5];
      pre_time_d_m = myArray[count+6];
      pre_time_a_h = myArray[count+7];
      pre_time_a_m = myArray[count+8];
      status = myArray[count+9];
      count = count+10;

    }

};

int domestic::count;

class international:public Cruise
{
public:
  string country;
  cargo c;
  passenger p;
  static int counti;

  int check_passenger()
  {
    country = arrival_loc;
    cout<<"The Cruise is leaving to:"<<country;
    cout<<"\n\nChecking the number of passengers:";
    p.getdata();
    if(p.passenger_count==40 && p.senior_count==9)
    {
      return 1;
    }
    else {
      return 0;
    }
  }

  international()
  {
    string myArray[30];
    ifstream file("aa.txt");
    if(file.is_open())
    {


        for(int i = 0; i < 30; i++)
        {
            file >> myArray[i];
        }
    }
    /*for(int i=count;i<count+6;i++)
    {
      cout<<myArray[i]<<"\n";
    }
    count = count+6;*/
    maintain_num = myArray[counti+0];
    Cruise_num = myArray[counti+1];
    dep_loc = myArray[counti+2];
    arrival_loc = myArray[counti+3];
    total_jour_hrs = myArray[counti+4];
    pre_time_d_h = myArray[counti+5];
    pre_time_d_m = myArray[counti+6];
    pre_time_a_h = myArray[counti+7];
    pre_time_a_m = myArray[counti+8];
    status = myArray[counti+9];
    counti = counti+10;
  }
};

int international::counti;

class scheduling_crew
{
public:
  int total, got, onemore=0;
  scheduling_crew()
  {
    total = 15;
  }
  void out()
  {
    cout<<"Numbers of workers onto the given work:"<<total<<endl;
  }

  /*void displayClock(int h,int m,int s)
  {

  	cout << setfill(' ') << setw(55) << "		 TIMER		 \n";
  	cout << setfill(' ') << setw(55) << " --------------------------\n";
  	cout << setfill(' ') << setw(29);
  	cout << "| " << setfill('0') << setw(2) << h << " hrs | ";
  	cout << setfill('0') << setw(2) << m << " min | ";
  	cout << setfill('0') << setw(2) << s << " sec |" << endl;
  	cout << setfill(' ') << setw(55) << " --------------------------\n";
  }
  void timer(int h,int m, int s)
  {

  	while (true) {

  		displayClock(h,m,s);



  		s--;

  		if (s == 00) {

  			m--;

  			if (m == 00) {

  				h--;
  				m = 0;
  			}
  			s = 60;
  		}
      if(h==0 && m<0 && s==60)
      {
        break;
      }
  	}
  }*/
  int general_delaying(domestic dd[3], international ii[3])
  {
    out();
    string takeNum;
    a:cout<<"Enter the Cruise number of the Cruise:";
    cin>>takeNum;
    for(int i=0;i<3;i++)
    {
      if(dd[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore = 1;
      }
    }
    for(int i=0;i<3;i++)
    {
      if(ii[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore =2;
      }
    }
    cout<<"\n\nThe selected Cruise is:\n";
    if(onemore==1)
    {
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;
    }
    else if(onemore==2)
    {
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    else{
      goto a;
    }
    cout<<"\n\nThe Cruise will be halted for 30mins !!\n\n";
/*    timer(0,0,3);*/
    if(onemore==1)
    {
      //stoi(dd[got].pre_time_d_m) = stoi(dd[got].pre_time_d_m) + 10;
      if(stoi(dd[got].pre_time_d_m)+30 > 60)
      {
        dd[got].pre_time_d_h = to_string(stoi(dd[got].pre_time_d_h)+1);
        dd[got].pre_time_d_m = to_string((stoi(dd[got].pre_time_d_m)+30)-60);
      }
      else
      {
        dd[got].pre_time_d_m=to_string(stoi(dd[got].pre_time_d_m)+30);
      }
      if(stoi(dd[got].pre_time_a_m)+30 > 60)
      {
        dd[got].pre_time_a_h = to_string(stoi(dd[got].pre_time_d_h)+1);
        dd[got].pre_time_a_m = to_string(stoi(dd[got].pre_time_a_m)+30-60);
      }
      else
      {
        dd[got].pre_time_a_m=to_string(stoi(dd[got].pre_time_a_m)+30);
      }
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;


    }
    else if(onemore ==2)
    {
      //stoi(ii[got].pre_time_d_m) = stoi(ii[got].pre_time_d_m) + 10;
      if(stoi(ii[got].pre_time_d_m)+30 >= 60)
      {
        ii[got].pre_time_d_h = to_string(stoi(ii[got].pre_time_d_h)+1);
        ii[got].pre_time_d_m = to_string((stoi(ii[got].pre_time_d_m)+30)-60);
      }
      else
      {
        ii[got].pre_time_d_m=to_string(stoi(ii[got].pre_time_d_m)+30);
      }
      if(stoi(dd[got].pre_time_a_m)+30 >= 60)
      {
        ii[got].pre_time_a_h = to_string(stoi(ii[got].pre_time_d_h)+1);
        ii[got].pre_time_a_m = to_string(stoi(ii[got].pre_time_a_m)+30-60);
      }
      else
      {
        ii[got].pre_time_a_m=to_string(stoi(ii[got].pre_time_a_m)+30);
      }
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    return got;
  }
  int Cruise_cancelling(domestic dd[3], international ii[3])
  {
    out();
    string takeNum;
    a:cout<<"Enter the Cruise number of the Cruise:";
    cin>>takeNum;
    for(int i=0;i<3;i++)
    {
      if(dd[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore = 1;
      }
    }
    for(int i=0;i<3;i++)
    {
      if(ii[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore =2;
      }
    }
    //cout<<onemore;
    cout<<"\n\nThe selected Cruise is:\n";
    if(onemore==1)
    {
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;
    }
    else if(onemore==2)
    {
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    else{
      goto a;
    }
    cout<<"\n\nThe selected Cruise will be cancelled!!\n\n";
    if(onemore==1)
    {
      dd[got].status = "cancelled";
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;

    }
    else if(onemore ==2)
    {
      ii[got].status = "cancelled";
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;

    }
    return got;
  }
  int Cruise_approval(domestic dd[3], international ii[3])
  {
    out();
    string takeNum;
    a:cout<<"Enter the Cruise number of the Cruise:";
    cin>>takeNum;
    for(int i=0;i<3;i++)
    {
      if(dd[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore = 1;
      }
    }
    for(int i=0;i<3;i++)
    {
      if(ii[i].Cruise_num.compare(takeNum) == 0)
      {
        got=i;
        onemore =2;
      }
    }
    //cout<<onemore;
    cout<<"\n\nThe selected Cruise is:\n";
    if(onemore==1)
    {
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;
    }
    else if(onemore==2)
    {
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    else{
      goto a;
    }
    cout<<"\n\nThe Cruise will be approved for taking off!!\n\n";
    if(onemore==1)
    {
      dd[got].status = "ready";
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;

    }
    else if(onemore ==2)
    {
      ii[got].status = "ready";
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;

    }
    return got;
  }
  //void timestamping(){}
};

class maintenance_crew
{
public:
  int total, got,onemore=0;
  maintenance_crew()
  {
    total =30;
  }
  void out()
  {
    cout<<"Numbers of workers are the given work:"<<total<<endl;
  }
  /*void displayClock(int h,int m,int s)
  {

  	cout << setfill(' ') << setw(55) << "		 TIMER		 \n";
  	cout << setfill(' ') << setw(55) << " --------------------------\n";
  	cout << setfill(' ') << setw(29);
  	cout << "| " << setfill('0') << setw(2) << h << " hrs | ";
  	cout << setfill('0') << setw(2) << m << " min | ";
  	cout << setfill('0') << setw(2) << s << " sec |" << endl;
  	cout << setfill(' ') << setw(55) << " --------------------------\n";
  }

  void timer(int h,int m, int s)
  {

  	while (true) {

  		displayClock(h,m,s);

  		s--;

  		if (s == 00) {

  			m--;

  			if (m == 00) {

  				h--;
  				m = 0;
  			}
  			s = 60;
  		}
      if(h==0 && m<0 && s==60)
      {
        break;
      }
  	}
  }*/

  int scheduling_main(domestic dd[3], international ii[3])
  {
    out();
    string takeNum;
    a:cout<<"Enter the maintenance number of the Cruise:";
    cin>>takeNum;
    for(int i=0;i<3;i++)
    {
      if(dd[i].maintain_num.compare(takeNum) == 0)
      {
        got=i;
        onemore = 1;
      }
    }
    for(int i=0;i<3;i++)
    {
      if(ii[i].maintain_num.compare(takeNum) == 0)
      {
        got=i;
        onemore =2;
      }
    }
    cout<<"\n\nThe selected Cruise is:\n";
    if(onemore==1)
    {
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;
    }
    else if(onemore==2)
    {
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    else{
      goto a;
    }
    cout<<"\n\nThe Cruise will be halted for 30 minutes for a scheduled maintenance test!!!\n\n";
    /*timer(0,0,10);*/
    if(onemore==1)
    {
      //stoi(dd[got].pre_time_d_m) = stoi(dd[got].pre_time_d_m) + 10;
      if(stoi(ii[got].pre_time_d_m)+10 >= 60)
      {
        dd[got].pre_time_d_h = to_string(stoi(dd[got].pre_time_d_h)+1);
        dd[got].pre_time_d_m = to_string((stoi(dd[got].pre_time_d_m)+10)-60);
      }
      else
      {
        dd[got].pre_time_d_m=to_string(stoi(dd[got].pre_time_d_m)+10);
      }
      if(stoi(dd[got].pre_time_a_m)+10 >= 60)
      {
        dd[got].pre_time_a_h = to_string(stoi(dd[got].pre_time_d_h)+1);
        dd[got].pre_time_a_m = to_string(stoi(dd[got].pre_time_a_m)+10-60);
      }
      else
      {
        dd[got].pre_time_a_m=to_string(stoi(dd[got].pre_time_a_m)+10);
      }
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;


    }
    else if(onemore ==2)
    {
      //stoi(ii[got].pre_time_d_m) = stoi(ii[got].pre_time_d_m) + 10;
      if(stoi(ii[got].pre_time_d_m)+30 >= 60)
      {
        ii[got].pre_time_d_h = to_string(stoi(ii[got].pre_time_d_h)+1);
        ii[got].pre_time_d_m = to_string((stoi(ii[got].pre_time_d_m)+30)-60);
      }
      else
      {
        ii[got].pre_time_d_m=to_string(stoi(ii[got].pre_time_d_m)+30);
      }

      if(stoi(dd[got].pre_time_a_m)+30 >= 60)
      {
        ii[got].pre_time_a_h = to_string(stoi(ii[got].pre_time_d_h)+1);
        ii[got].pre_time_a_m = to_string(stoi(ii[got].pre_time_a_m)+30-60);
      }
      else
      {
        ii[got].pre_time_a_m=to_string(stoi(ii[got].pre_time_a_m)+30);
      }
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    return got;
  }
  void unscheduling_main(domestic dd[3], international ii[3])
  {
    out();
    int hh,mm;
    string takeNum;
    a:cout<<"Enter the maintenance number of the Cruise:";
    cin>>takeNum;
    for(int i=0;i<3;i++)
    {
      if(dd[i].maintain_num.compare(takeNum) == 0)
      {
        got=i;
        onemore = 1;
      }
    }
    for(int i=0;i<3;i++)
    {
      if(ii[i].maintain_num.compare(takeNum) == 0)
      {
        got=i;
        onemore =2;
      }
    }
    cout<<"\n\nThe selected Cruise is:\n";
    if(onemore==1)
    {
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;
    }
    else if(onemore==2)
    {
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;
    }
    else{
      goto a;
    }
    cout<<"\n\nNow the Cruise will be haulted for an UnScheduled maintenance!";
    cout<<"\n\nGive the expected time for which Cruise should be haulted(hh,mm):";

    cin>>hh>>mm;
    //timer(0,hh,mm);
    if(onemore==1)
    {
      //stoi(dd[got].pre_time_d_m) = stoi(dd[got].pre_time_d_m) + 10;
      dd[got].pre_time_d_h=to_string(stoi(dd[got].pre_time_d_h)+hh);
      //dd[got].pre_time_d_h=to_string(stoi(dd[got].pre_time_d_m)+mm);
      //dd[got].pre_time_a_m=to_string(stoi(dd[got].pre_time_a_h)+hh);
      dd[got].pre_time_a_m=to_string(stoi(dd[got].pre_time_a_m)+mm);
      //dd[got].pre_time_a_m=to_string(stoi(dd[got].pre_time_a_m)+ss);
      cout<<"\n\nMaintenance NO:"<<dd[got].maintain_num<<"  Cruise NO:"<<dd[got].Cruise_num<<"  DEPATURE:"<<dd[got].dep_loc<<"  ARRIVAL:"<<dd[got].arrival_loc<<"  EXP TIME DEP: "<<dd[got].pre_time_d_h<<":"<<dd[got].pre_time_d_m<<"  EXP TIME ARR: "<<dd[got].pre_time_a_h<<":"<<dd[got].pre_time_a_m<<"  TOTAL HRS:"<<dd[got].total_jour_hrs<<"    STATUS:"<<dd[got].status;


    }
    else if(onemore ==2)
    {
      //stoi(ii[got].pre_time_d_m) = stoi(ii[got].pre_time_d_m) + 10;
      ii[got].pre_time_d_h=to_string(stoi(ii[got].pre_time_d_h)+hh);
      ii[got].pre_time_d_h=to_string(stoi(ii[got].pre_time_d_m)+mm);
      ii[got].pre_time_a_m=to_string(stoi(ii[got].pre_time_a_h)+hh);
      ii[got].pre_time_a_m=to_string(stoi(ii[got].pre_time_a_m)+mm);
      cout<<"\n\nMaintenance NO:"<<ii[got].maintain_num<<"  Cruise NO:"<<ii[got].Cruise_num<<"  DEPATURE:"<<ii[got].dep_loc<<"  ARRIVAL:"<<ii[got].arrival_loc<<"  EXP TIME DEP: "<<ii[got].pre_time_d_h<<":"<<ii[got].pre_time_d_m<<"  EXP TIME ARR: "<<ii[got].pre_time_a_h<<":"<<ii[got].pre_time_a_m<<"  TOTAL HRS:"<<ii[got].total_jour_hrs<<"    STATUS:"<<ii[got].status;

    }
  }
};

class harbour
{
public:
  maintenance_crew m;
  scheduling_crew s;
  domestic d[3];
  international i[3];
  //cout<<"\n\nChoose one crew:\n1.Maintenance Crew\n2.Scheduling Crew";



  void puttingd()
  {
    cout<<"\n\n\n\n\n\n\n************************* DOMESTIC CRUISES *****************************\n";
    for(int i=0;i<3;i++)
    {
      cout<<"\n\nMaintenance NO:"<<d[i].maintain_num<<"  Cruise NO:"<<d[i].Cruise_num<<"  DEPATURE:"<<d[i].dep_loc<<"  ARRIVAL:"<<d[i].arrival_loc<<"  EXP TIME DEP: "<<d[i].pre_time_d_h<<":"<<d[i].pre_time_d_m<<"  EXP TIME ARR: "<<d[i].pre_time_a_h<<":"<<d[i].pre_time_a_m<<"  TOTAL HRS:"<<d[i].total_jour_hrs<<"    STATUS:"<<d[i].status;
    }
  }
  void puttingi()
  {
    cout<<"\n\n\n\n\n\n\n*********************** INTERNATIONAL CRUISES *****************************\n";
    for(int ii=0;ii<3;ii++)
    {
      cout<<"\n\nMaintenance NO:"<<i[ii].maintain_num<<"  Cruise NO:"<<i[ii].Cruise_num<<"  DEPATURE:"<<i[ii].dep_loc<<"  ARRIVAL:"<<i[ii].arrival_loc<<"  EXP TIME DEP: "<<i[ii].pre_time_d_h<<":"<<i[ii].pre_time_d_m<<"  EXP TIME ARR: "<<i[ii].pre_time_a_h<<":"<<i[ii].pre_time_a_m<<"  TOTAL HRS:"<<i[ii].total_jour_hrs<<"    STATUS:"<<i[ii].status;
    }
  }
  void processing()
  {
    start:int choose_flag=1, gott, go;
    cout<<"\n\n\n\nChoose one crew";
    cout<<"\n1.Maintenance Crew";
    cout<<"\n2.Scheduling Crew";
    cout<<"\n3.Cruise scenario\n";
    x:cout<<"\n\nEnter your choice:";
    cin>>choose_flag;
    if(choose_flag==1)
    {
      cout<<"\n\nGoing to maintenance crew!!\n\n";
      int flag_fun;
      cout<<"\n\n****Choose any one****\n\n";
      cout<<"\n\n1.Scheduled Maintenance";
      cout<<"\n2.UnScheduled Maintenance";

      zz:cout<<"\n\nEnter which maintenance does the crew wants to perform:";
      cin>>flag_fun;
      switch(flag_fun)
      {
        case 1: go = m.scheduling_main(d, i);
                puttingd();
                puttingi();
                break;
        case 2: m.unscheduling_main(d, i);
                puttingd();
                puttingi();
                break;
        default: goto zz;
      }
    }
    else if( choose_flag==2)
    {
      cout<<"\n\nGoing to scheduling crew!!\n\n";
      int flag_fun;
      cout<<"\n\n****Choose any one****\n\n";
      cout<<"\n\n1.General Delay";
      cout<<"\n2.Cruise Cancelling";
      cout<<"\n3.Approving Cruise for takeoff";
      //cout<<"\n3.Timestamping";
      zx:cout<<"\n\nEnter which action does the crew wants to perform:";
      cin>>flag_fun;
      switch(flag_fun)
      {
        case 1: gott = s.general_delaying(d, i);
                puttingd();
                puttingi();
                break;
        case 2: gott = s.Cruise_cancelling(d, i);
                puttingd();
                puttingi();
                break;
        case 3: gott = s.Cruise_approval(d, i);
                puttingd();
                puttingi();
                break;
        //case 3: s.timestamping();
          //      break;
        default: goto zx;
      }
    }
    else if(choose_flag==3){
      return;
    }
    else{
      goto x;
    }
    goto start;

  }

  void timestampd(domestic dd)
  {
    ofstream myfile;
  myfile.open ("timestampd.txt", ofstream::app);
  myfile <<"\n\n\nCruise no:"<<dd.Cruise_num<<" for:"<<dd.arrival_loc<<" From:"<<dd.dep_loc<<"\ntook off at:";
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal = *localtime(&now);
    myfile<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<endl;
    myfile.close();
  }
  void timestampi(international ii)
  {
    ofstream myfile;
  myfile.open ("timestampi.txt", ofstream::app);
  myfile <<"\n\n\nCruise no:"<<ii.Cruise_num<<" for:"<<ii.arrival_loc<<" From:"<<ii.dep_loc<<"\ntook off at:";
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal = *localtime(&now);
    myfile<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<endl;
    myfile.close();
  }

  void takeof()
  {
    int catchh;
    int signal_takeoff_d, signal_takeoff_i;
    cout<<"\n\nSignal for taking off for domestic Cruises(0/1):";
    cin>>signal_takeoff_d;
    if(signal_takeoff_d==1)
    {
      for(int i=0;i<3;i++)
      {
        if(d[i].status.compare("ready") == 0)
          {
            catchh=i;
            //cout<<"\nMaintenance NO:"<<d[catchh].maintain_num<<"  Cruise NO:"<<d[catchh].Cruise_num<<"  DEPATURE:"<<d[catchh].dep_loc<<"  ARRIVAL:"<<d[catchh].arrival_loc<<"  EXP TIME DEP: "<<d[catchh].pre_time_d_h<<":"<<d[catchh].pre_time_d_m<<"  EXP TIME ARR: "<<d[catchh].pre_time_a_h<<":"<<d[catchh].pre_time_a_m<<"  TOTAL HRS:"<<d[catchh].total_jour_hrs<<";
            int ff;
            ff = d[catchh].check_passenger();
            if(ff)
            {
              d[catchh].c.getdata();
            }
            d[catchh].status = "inair";
            cout<<"\n\nSelected Cruise is all set to take off! Happy Journey!!!\n\n";
            timestampd(d[catchh]);

          }

      }
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSignal for taking off for international Cruises(0/1):";
    cin>>signal_takeoff_i;
    if(signal_takeoff_i==1)
    {
      for(int ii=0;ii<3;ii++)
      {
        if(i[ii].status.compare("ready") == 0)
          {
            catchh=ii;
            //cout<<"\nMaintenance NO:"<<i[catchh].maintain_num<<"  Cruise NO:"<<i[catchh].Cruise_num<<"  DEPATURE:"<<i[catchh].dep_loc<<"  ARRIVAL:"<<i[catchh].arrival_loc<<"  EXP TIME DEP: "<<i[catchh].pre_time_d_h<<":"<<i[catchh].pre_time_d_m<<"  EXP TIME ARR: "<<i[catchh].pre_time_a_h<<":"<<i[catchh].pre_time_a_m<<"  TOTAL HRS:"<<i[catchh].total_jour_hrs<<";
            int ff;
            ff = i[catchh].check_passenger();
            if(ff)
            {
              i[catchh].c.getdata();
            }
            i[catchh].status = "inair";
            cout<<"\n\nSelected Cruise is all set to take off! Happy Journey!!!\n\n";
            timestampi(i[catchh]);

          }
      }
    }
  }


};

int main()
{
    harbour a;

    a.puttingd();
    a.puttingi();
    a.processing();
    a.takeof();
    a.puttingd();
    a.puttingi();
    return 0;
}
