#include<fstream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>

struct mrk{ char a[3];};

struct stud{
		char name_c[40], roll_c[14];
		float tot_f, att_f;
		mrk m[6];
	   };

class kcg{
		private:
		stud rec;

		public:
		//void new_entry();
		void gen();
		void displogo();
		void path();
		//void correct();
		void mscreen();
		char x, p[70];
	 }a;


void kcg :: displogo()
{
	clrscr();

	cout.fill('#');
	cout<<setw(50)
	    <<"KCG College Of Technology"
	    <<setw(30)<<"#\n";

	cout.fill(' ');
	cout<<setw(26)<<"*";
	cout.fill('*');
	cout<<setw(25)<<"*\n";

	cout.fill('#');
	cout<<setw(50)
	    <<"Students Report Generator"
	    <<setw(29)<<"#";

	cout.fill(' ');
	cout<<"\n\n\n";

}


void kcg :: gen()
{

displogo();

char src[15],k[3],l[5];
//int flag[6]={0,0,0,0,0,0};

cout<<"\nEnter the Progress Report No.: ";
cin>>k;

cout<<"Enter the source file name: ";
cin>>src;

ifstream fin1(src);
ofstream fout;

//for(int i=0; i<62; i++)
while(fin1)
{

fin1.ignore();
fin1.getline(rec.roll_c,14,'\t');

fin1.getline(rec.name_c,39,'\t');

for(int i=0;i<6; i++)
{
fin1>>rec.m[i].a;
//if(fin1=="a" || fin1=="A")flag[i]=1;
//else fin1>>rec.m[i];
}

fin1>>rec.tot_f>>rec.att_f;


//ofstream fout(rec.roll_c);

ifstream f1("path.txt");
f1.getline(p,69,' ');
f1.close();

char b[90];
strcpy(b,p);
strcat(b,rec.roll_c);

fout.open("temp.txt");
fout<<b<<".doc";
fout.close();

ifstream fin;
fin.open("temp.txt");
fin>>b;
fin.close();

cout<<b;
fout.open(b);


fout<<setw(47)
    <<"KCG College Of Technology\n"
    <<setw(45)
    <<"Karapakkam, Chennai-97\n"
    //<<setw(43)
    <<"\t\t\t\tPROGRESS REPORT NO-"<<k<<"\n\n"
    <<"\n\nDear Parents,"
    <<"\n\tI am sending herewith the second Progress Report of your ward for your information. Please send the signed acknowledgement through your ward.\n"
    <<"\n\n\tName of the student\t: "<<rec.name_c
    <<"\n\tClass-I Year\t\t:"
    <<"\n\tRoll No.\t\t\t: "<<rec.roll_c
    <<"\n\nMarks secured in different subjects:-\n"
    <<"\n\tSlno.\tCode\t\tSubject\t\t\tMarks\t\tAttendance"
    <<"\n\t1\tHS2111\tEnglish-I\t\t\t"<<rec.m[0].a
    <<"\n\t2\tMA2111\tEngg. Math	\t\t"<<rec.m[1].a
    <<"\n\t3\tPH2111\tEngg. Physics     \t"<<rec.m[2].a;
    fout.precision(2);
    fout<<"\t\t   "<<rec.att_f
    <<"\n\t4\tCY2111\tEngg. Chemistry	\t"<<rec.m[3].a
    <<"\n\t5\tGE2112\tFOC	\t\t\t"<<rec.m[4].a
    <<"\n\t6\tGE2111\tEngg. Graphics	\t"<<rec.m[5].a
    <<"\n\n\n\nPlease note that a minimum of 75% attendance (average) with satisfactory progress is essential for appearing to the university Examination"
    <<"\n\nIf the progress of your ward is not satisfactory, you are requested to come and meet the HOD, S&H within a week of receiving this letter."
    <<"\n\n\n\n\nSignature of Class Teacher\t\t\t\t\tPrincipal"
    <<"\n_____________________________________________________________________\n\n"
    <<setw(45)
    <<"Acknowledgement"
    <<"\n\nFrom"
    <<"\n\n\n\n\n\nReceived with thanks the Progress Report-II of my ward and noted his/her Progress."
    <<"\n\n\nName of the Student:\t\t\t\tSignature of the parent"
    <<"\nRoll No. "<<rec.roll_c;


fout.close();
}
}

void kcg::path()
{
displogo();

ifstream fin("path.txt");
fin.read((char*)&p, sizeof(p));

cout<<"\nCurrent path: "<<p;

cout<<"\nWant to change path?(y/n) ";
cin>>x;
if(x=='e') exit(0);
if(x=='y' || x=='Y')
{
cin.ignore();
cout<<"\n\nEnter new path: ";
cin.getline(p,49,' ');

ofstream fout("path.txt", ios::trunc);
fout<<p;
//fout.write((char*)&p, sizeof(p));
}

}


void kcg::mscreen()
{
start:	displogo();
	cout<<"1. Generate files\n"
	    <<"2. Change path\n"
	    <<"3. Exit\n\n\n\n";
	int i;
	cin>>i;
	cin.ignore();

	switch(i)
	{
		case 1: gen(); goto start;
		case 2: path();goto start;
		case 3: exit(0);
		defalut : break;
	}
}



void main()
{
//a.new_entry();
//a.gen();
//a.correct();
a.mscreen();
}