#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>

using namespace std;

void LogIn();

class Disease{
	protected:
		string diseasename,state;
	public:
		void setDiseaseName(string n)
		{
			diseasename=n;
		}
		void setState(string s)
		{
			state=s;
		}
		
		string getDiseaseName() const
		{
			return diseasename;
		}
		string getState() const
		{
			return state;
		}
		
		void enterDisease()
		{
			cout<<endl<<"Enter name of disease: ";
			cin>>diseasename;
			cout<<endl<<"Enter state of patient(normal/critical): ";
			cin>>state;
		}
};

class Date{
	protected:
		int day,month,year;
	public:
		void setDay(int d)
		{
			if(d <= 31 && d > 0)
			{
				day=d;
			}
		}
		void setMonth(int m)
		{
			if(m <= 12 && m > 0)
			{
				month=m;
			}
		}
		void setYear(int y)
		{
			if(y > 0)
			{
				year=y;
			}
		}
		
		int getDay() const
		{
			return day;
		}
		int getMonth() const
		{
			return month;
		}
		int getYear() const
		{
			return year;
		}
		
		void inputDate()
		{
			int d,m,y;
			cout<<"(DD/MM/YYYY): " ;
			cin>>d>>m>>y;
			if(d <= 31 && d > 0)
			{
				day=d;
			}
			if(m <= 12 && m > 0)
			{
				month=m;
			}
			if(y > 0)
			{
				year=y;
			}
		}
};

class Human{
	
	protected:
		string name,address,number; 
		int age;
		Date date;

	public:
		Human()
		{
			name="\0";
			age=0;
		}
		void setName(string nam)
		{
			name=nam;
		}
		void setAge(int age)
		{
			this->age=age;
		}
		void setNumber(string num)
		{
			number=num;
		}
		void setAddress(string add)
		{
			address=add;
		}
		
		string getName() const
		{
			return name;
		}
		int getAge() const
		{
			return age;
		}
		string getNumber() const
		{
			return number;
		}
		string getAddress() const
		{
			return address;
		}
		
		int getDay() const
		{
			return date.getDay();
		}
		int getMonth() const
		{
			return date.getMonth();
		}
		int getYear() const
		{
			return date.getYear();
		}
		Date getDate() const
		{
			return date;
		}



		void getDetails()
		{
			cout<<endl<<"Enter name: ";
			fflush(stdin);
			getline(cin,name);
			cout<<endl<<"Enter age: ";
			cin>>age;
			cout<<endl<<"Enter phone number: ";
			fflush(stdin);
			getline(cin,number);
			cout<<endl<<"Enter address: ";
			fflush(stdin);
			getline(cin,address);
		}
};
	   	
class Patient: public Human{
   	protected:
		int pat_ID,doc_ID;
		static int ID;
   		Disease disease;
    	float bill;
		
	public:
		Patient()
		{
			pat_ID=ID;
			ID++;
			bill=0.0;
			address="\0";
		}
		
		void setBill(float bill)
		{
		    this->bill=bill;
		}
		void setDocID(int doc_id)
		{
		    doc_ID=doc_id;
		}
		
		int getPatientID() const
		{
			return pat_ID;
		}
		
		int getDocID() const
		{
			return doc_ID;
		}
		
		float getBill() const
		{
	     	return bill;
		}
		
		string getDiseaseName() const
		{
			return disease.getDiseaseName();
		}
		string getState() const
		{
			return disease.getState();
		}
		
		Disease getDisease() const
		{
			return disease;
		}
		
		void getDetails()
		{   
			cout << "Enter patient information: "<<endl<<"-------------------------------------------------------------------------------"<<endl<<endl<<endl<<endl;
		    fflush stdin;
		    disease.enterDisease();
		    cout<<"\t\t\t\t\t\tEnter date of appointment: ";
		 	fflush stdin;
		 	date.inputDate();
		    cout<<"\n\t\t\t\t\t\tPatient Successfully Booked!"<<endl<<endl;
		    fflush stdin;
		}
};
int Patient::ID=1;

class Normal : public Patient{
};

class Admitted : public Patient{
	protected:
		int room_no;
	public:
		void setRoomNo(int room)
		{
			room_no=room;
		}
		int getRoomNo()
		{
			return room_no;
		}
		
		void getDetails()
		{
			cout<<endl<<"Enter room number to admit patient in: ";
			cin>>room_no;
		}
		
		void operator =(const Normal &obj)
		{
			name = obj.getName();
			age = obj.getAge();
			number = obj.getNumber();
			address = obj.getAddress();
			pat_ID = obj.getPatientID();
			doc_ID = obj.getDocID();
			date = obj.getDate();
			disease = obj.getDisease();
		}
};

class Staff:public Human{
	protected:
		int empID;
		float salary;
	public:
		static int ID;
		Staff()
		{
			empID=ID;
			ID++;
		}
	    int getEmpID(){
	    	return empID;
		}
		void setSalary(float salary){
			this->salary=salary;
		}
		float getSalary(){
			return salary;
		}
		
		void getDetails()
		{
			Human::getDetails();
			cout<<endl<<"Enter date of hiring: ";
			date.inputDate();
			cout<<endl<<"Enter salary: ";
			cin>>salary;
		}
};
int Staff::ID=1;

class Receptionist:public Staff{
	public:
		void addPatient()
		{
			Human *pat;
			Normal patient;
			pat=&patient;
			pat->getDetails();
			int ID,doc_ID;
			cout<<endl<<"Enter ID of doctor treating patient: ";
			cin>>doc_ID;
			patient.setDocID(doc_ID);
			
			ifstream ReadFile("Patient.txt");
			
			ofstream WriteFile("TEMP.txt");
			
			if(ReadFile!=NULL)
			{
				int t=0;
				char c;
				while(!ReadFile.eof())
				{
					cout<<".";
					ReadFile.get(c);
					
					WriteFile << c;
					
					if(c=='\n')
					{
						t=0;
						ReadFile >> ID;
						WriteFile << ID;
					}
					if(c=='\t')
					{
						t++;
						if(t==2||t==5||t==9)
						{
							float l;
							ReadFile >> l;
							WriteFile << l;
						}
					}
				}
				ID++;
			}
			else
			{
				ID = patient.getPatientID();
			}
			WriteFile <<'\n'<<ID<<'\t'<<pat->getName()<<'\t'<<pat->getAge()<<'\t'<<pat->getNumber()<<'\t'<<pat->getAddress()<<'\t'<<patient.getDocID();
			
			ReadFile.close();
			WriteFile.close();
			
			remove("Patient.txt");
			rename("TEMP.txt","Patient.txt");
			
			getch();
		}
		
		void admitPatient()
		{
			int ID;
			Admitted admit;
			cout<<endl<<"Enter the patient ID to admit"<<endl;
			cin>>ID;
			admit.getDetails();
			
			ifstream ReadAFile("Admitted.txt");
			ofstream WriteFile("TEMP.txt");
			
			if(ReadAFile!=NULL)
			{
				char c;
				int t=0;
				while(!ReadAFile.eof())
				{					
					ReadAFile.get(c);
					WriteFile << c;
					
					if(c=='\n')
					{
						t=0;
					}
					if(c=='\t')
					{
						t++;
						if(t==2||t==5||t==9||t==10)
						{
							float l;
							ReadAFile >> l;
							WriteFile << l;
						}
					}
				}
			}
			
			ReadAFile.close();
			
			ifstream ReadPFile("Patient.txt");
			
			if(ReadPFile!=NULL)
			{
				int id;
				char c;
				bool found=0;
				
				while(!ReadPFile.eof())
				{
					ReadPFile.get(c);
				
					if(c=='\n')
					{
						ReadPFile >> id;
						if(id==ID)
						{
							found = 1;
							WriteFile << '\n' << ID;
							ReadPFile.get(c);
							while(c!='\n'&&!ReadPFile.eof())
							{
								WriteFile << c;
								ReadPFile.get(c);
							}
							WriteFile << '\t' << admit.getRoomNo();
							cout<<endl<<"Patient with ID "<<ID<<" successfully admitted.";
							break;
						}
					}
				}
				if(!found)
				{
					cout<<endl<<"Patient with ID "<<ID<<" doesn't exist.";
				}
				
				
				ReadPFile.close();
				WriteFile.close();
				
				remove("Admitted.txt");
				rename("TEMP.txt","Admitted.txt");
			}
			else
			{
				cout<<endl<<"No patient records exist";
			}
			
			getch();
		}
		
		void dischargePatient()
		{
			int ID;
			cout<<endl<<"Enter the patient ID to discharge: ";
			cin>>ID;
			
			ifstream ReadFile("Admitted.txt");
			ofstream WriteFile("TEMP.txt");
			
			if(ReadFile!=NULL)
			{
				char c;
				int t=0;
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					WriteFile << c;
					
					if(c=='\n')
					{
						t=0;
						int id;
						ReadFile >> id;
						if(ID==id)
						{
							ReadFile.get(c);
							while(c!='\n'&&!ReadFile.eof())
							{
								ReadFile.get(c);
							}
							
						}
						else
						{
							WriteFile << id;
						}
					}
					if(c=='\t')
					{
						t++;
						if(t==6||t==7)
						{
							float l;
							ReadFile >> l;
							WriteFile << l;
						}
					}
				}
				cout<<endl<<"Patient with ID "<<ID<<" successfully discharged.";
			}
			else
			{
				cout<<endl<<"No patients currently admitted";
			}
			
			ReadFile.close();
			WriteFile.close();
			
			remove("Admitted.txt");
			rename("TEMP.txt","Admitted.txt");
			
			getch();
		}
		
		void viewPatients()
		{
			ifstream ReadFile("Patient.txt");
			
			cout<<"ID\t\tName\t\tAge\t\tNumber\t\tAddress\t\tDoctor ID\t\tDisease\t\tState\t\tAppointment date\t\tMedicine\t\tQuantity\n";
			
			if(ReadFile!=NULL)
			{
				char c;
				int t=0;
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					cout<<c;
					if(c=='\n')
					{
						t=0;
					}
					if(c=='\t')
					{
						cout<<'\t';
						t++;
						if(t==5||t==6)
						{
							float l;
							ReadFile >> l;
							cout << l;
						}
					}
				}
			}
			else
			{
				cout<<endl<<"No records exist";
			}
			
			ReadFile.close();
			
			getch();
		}
		
		void printBill()
		{
			int pat_ID,doc_ID;
			float bill;
			cout<<endl<<"Enter ID of patient to calculate bill for: ";
			cin>>pat_ID;
			
			ifstream ReadFile("Patient.txt");
			
			if(ReadFile!=NULL)
			{
				
				char c;
				bool found = 0;
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					if(c=='\n')
					{
						int id;
						int t;
						ReadFile >> id;
						if(id==pat_ID)
						{
							t=0;
							found = 1;
							ReadFile.get(c);
							while(c!='\n'&&!ReadFile.eof())
							{
								if(c=='\t')
								{
									t++;
									if(t==5)
									{
										ReadFile >> doc_ID;
										break;
									}
								}
								ReadFile.get(c);
							}
							break;
						}
					}
				}
				if(found)
				{
					found=0;
					ifstream ReadDFile("Doctor.txt");
					
					if(ReadDFile!=NULL)
					{
						while(!ReadDFile.eof())
						{
							ReadDFile.get(c);
							if(c=='\n')
							{
								int id;
								ReadDFile >> id;
								if(id==doc_ID)
								{
									found=1;
									int	t=0;
									ReadDFile.get(c);
									while(c!='\n')
									{
										if(c=='\t')
										{
											t++;
											if(t==6)
											{
												ReadDFile >> bill;
												cout<<endl<<"Bill for patient "<<pat_ID<<" is: "<<bill;
												break;
											}
										}
										ReadDFile.get(c);
									}
									break;
								}
							}
						}
						
					}
					else
					{
						cout <<endl<< "Doctor not available";
					}
					
					ReadFile.close();
					ReadDFile.close();
				}
				else
				{
					cout<<endl<<"Patient with ID "<<pat_ID<<" not found.";
				}
			}
			else
			{
				cout<<endl<<"No patients exist";
			}
			
			getch();
		}
		
		void menu()
		{
			while(1)
			{
				system("cls");
				int choice;
				cout<<endl<<"Options:\n1.Add patient\n2.Admit patient\n3.Discharge patient\n4.View all patient information\n5.Print bill\n6.Return\n7.Exit\n\nSelect option: ";
				cin>>choice;
				system("cls");
				if(choice==1)
				{
					addPatient();
				}
				else if(choice==2)
				{
					admitPatient();
				}
				else if(choice==3)
				{
					dischargePatient();
				}
				else if(choice==4)
				{
					viewPatients();
				}
				else if(choice==5)
				{
					printBill();
				}
				else if(choice==6)
				{
					LogIn();
				}
				else if(choice==7)
				{
					exit(6);
				}
				else		//this and while loop allows choosing option again if invalid choice entered
				{
					cout<<endl<<"Invalid choice, try again"<<endl;
					cout<<endl<<"Enter your choice: ";
					cin>>choice;
				}
			}
		}
};

class Doctor : public Staff
{
	protected:
		string specialisation;
		float doc_fees;
	public:
		Doctor()
		{
			doc_fees=0.0;
		}
		
		void setFees(float doc_fees)
		{
			this->doc_fees=doc_fees;
		}
		
		float getFees()
	 	{
	    	return doc_fees;
		}
		
		string getSpecialisation()
	 	{
	    	return specialisation;
		}
		
		void getDetails()
		{
			Staff::getDetails();
			cout<<endl<<"Enter specialisation of doctor: ";
			fflush(stdin);
			getline(cin,specialisation);
			cout<<endl<<"Set fees of doctor: ";
			cin>>doc_fees;
		}
		
		void treatPatient()
		{
			int ID,quan;
			string name;
			Normal patient;
			
			cout<<endl<<"Enter ID of patient to diagnose: ";
			cin>>ID;
			
			cout<<endl<<"Enter medicine to give to patient: ";
			fflush(stdin);
			getline(cin,name);
			
			cout<<endl<<"Enter quantity to give: ";
			cin>>quan;
			
			patient.getDetails();
			
			ifstream ReadFile("Patient.txt");
			ofstream WriteFile("TEMP.txt");
			
			if(ReadFile!=NULL)
			{
				char c;
				int t=0;
				int found=0;
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					WriteFile << c;
					if(c=='\n')
					{
						t=0;
						int id;
						ReadFile >> id;
						WriteFile << id;
						if(id==ID)
						{
							found = 1;
						}
					}
					if(c=='\t')
					{
						t++;
						if(t==5)
						{
							float l;
							ReadFile >> l;
							WriteFile << l;
							if(found)
							{
								found=0;
								WriteFile <<'\t'<< patient.getDiseaseName() <<'\t'<< patient.getState() <<'\t'<< patient.getDay() <<'/'<< patient.getMonth() <<'/'<< patient.getYear() <<'\t'<< name <<'\t'<<quan;
								bool foundM=0;
								ifstream ReadMFile("Inventory.txt");
			
								ofstream WriteMFile("TEMP2.txt");
								
								if(ReadMFile!=NULL)
								{
									char c,nam[30];
									int i=0;
									bool t=0;
									
									while(!ReadMFile.eof())
									{
										ReadMFile.get(c);
										
										WriteMFile << c;
										
										if(c=='\t')
										{
											t = 1;
											
											if(nam==name)
											{
												foundM=1;
												int prev_quan;
												ReadMFile >> prev_quan;
												if(prev_quan>=quan)
												{
													quan=prev_quan-quan;
												}
												else
												{
													cout<<endl<<"Quantity of medicine required is not available"<<endl;
													quan=prev_quan;
												}
												
												WriteMFile << quan << '\n';
												while(c!='\n'&&!ReadMFile.eof())
												{
													ReadMFile.get(c);
												}
											}
											
										}
										
										if(!t&&c!='\t')
										{
											nam[i]=c;
											i++;
										}
										
										if(c=='\n')
										{
											t=0;
											for(i=0;i<30;i++)
											{
												nam[i]='\0';
											}
											i=0;
										}
										
									}
									
									if(!foundM)
									{
										cout<<endl<<"Medicine not available"<<endl;
									}
								}
								else
								{
									cout<<endl<<"Medicine not available"<<endl;;
								}
								
								ReadMFile.close();
								WriteMFile.close();
								
								remove("Inventory.txt");
								rename("TEMP2.txt","Inventory.txt");
							}
						}
					}
				}
			}
			else
			{
				cout<<endl<<"No previous records exist";
			}
			
			ReadFile.close();
			WriteFile.close();
			
			remove("Patient.txt");
			rename("TEMP.txt","Patient.txt");
		}
		
		void menu()
		{
			while(1)
			{
				system("cls");
				int choice;
				cout<<endl<<"Options:\n1.Treat patient\n2.Return\n\nSelect option: ";
				cin>>choice;
				if(choice==1)
				{
					treatPatient();
					getch();
				}
				else if(choice==2)
				{
					LogIn();
				}
				else		//this and while loop allows choosing option again if invalid choice entered
				{
					cout<<endl<<"Invalid choice, try again"<<endl;
					cout<<endl<<"Enter your choice: ";
					cin>>choice;
				}
			}
		}
};

class Manager : public Human{
	public:
		void addStaff()
		{
			int sel;
			cout<<endl<<"Enter 1 to add doctor 2 for adding receptionist";
			cin>>sel;
			while(1)
			{
				if(sel==1)
				{
					Doctor doctor;
					doctor.getDetails();
					int ID;
					
					ifstream ReadFile("Doctor.txt");
					
					ofstream WriteFile("TEMP.txt");
					
					if(ReadFile!=NULL)
					{
						int t=0;
						char c;
						while(!ReadFile.eof())
						{
							cout<<".";
							ReadFile.get(c);
							
							WriteFile << c;
							
							if(c=='\n')
							{
								t=0;
								ReadFile >> ID;
								WriteFile << ID;
							}
							if(c=='\t')
							{
								t++;
								if(t==2||t==7||t==8)
								{
									float l;
									ReadFile >> l;
									WriteFile << l;
								}
							}
						}
						ID++;
					}
					else
					{
						ID = doctor.getEmpID();
					}
					WriteFile <<'\n'<< ID <<'\t'<< doctor.getName() <<'\t'<< doctor.getAge() <<'\t'<< doctor.getNumber() <<'\t'<< doctor.getAddress() <<'\t'<< doctor.getDay() <<'/'<< doctor.getMonth() <<'/'<< doctor.getYear() <<'\t'<< doctor.getSpecialisation() <<'\t'<< doctor.getFees() <<'\t'<< doctor.getSalary();
					
					ReadFile.close();
					WriteFile.close();
					
					remove("Doctor.txt");
					rename("TEMP.txt","Doctor.txt");
					break;
				}
				else if(sel==2)
				{
					Receptionist recep;
					recep.getDetails();
					int ID;
					
					ifstream ReadFile("Receptionist.txt");
					
					ofstream WriteFile("TEMP.txt");
					
					if(ReadFile!=NULL)
					{
						int t=0;
						char c;
						while(!ReadFile.eof())
						{
							cout<<".";
							ReadFile.get(c);
							
							WriteFile << c;
							
							if(c=='\n')
							{
								t=0;
								ReadFile >> ID;
								WriteFile << ID;
							}
							if(c=='\t')
							{
								t++;
								if(t==2||t==6)
								{
									float l;
									ReadFile >> l;
									WriteFile << l;
								}
							}
						}
						ID++;
					}
					else
					{
						ID = recep.getEmpID();
					}
					WriteFile <<'\n'<< ID <<'\t'<< recep.getName() <<'\t'<< recep.getAge() <<'\t'<< recep.getNumber() <<'\t'<< recep.getAddress() <<'\t'<< recep.getDay() <<'/'<< recep.getMonth() <<'/'<< recep.getYear() <<'\t'<< recep.getSalary();
					
					ReadFile.close();
					WriteFile.close();
					
					remove("Receptionist.txt");
					rename("TEMP.txt","Receptionist.txt");
					break;
				}
				else
				{
					cout<<endl<<"Invalid choice. Enter again: ";
					cin>>sel;
				}
			}
			
			getch();
		}
		
		void removeStaff()
		{
			int sel;
			cout<<endl<<"Enter 1 to remove doctor 2 for removing receptionist: ";
			cin>>sel;
			
			while(1)
			{
				if(sel==1)
				{
					int ID;
					cout<<endl<<"Enter the doctor's' ID to remove: ";
					cin>>ID;
					
					ifstream ReadFile("Doctor.txt");
					ofstream WriteFile("TEMP.txt");
					
					if(ReadFile!=NULL)
					{
						char c;
						int t=0;
						while(!ReadFile.eof())
						{
							ReadFile.get(c);
							WriteFile << c;
							
							if(c=='\n')
							{
								t=0;
								int id;
								ReadFile >> id;
								if(ID==id)
								{
									ReadFile.get(c);
									while(c!='\n'&&!ReadFile.eof())
									{
										ReadFile.get(c);
									}
									
								}
								else
								{
									WriteFile << id;
								}
							}
							if(c=='\t')
							{
								t++;
								if(t==2||t==7||t==8)
								{
									float l;
									ReadFile >> l;
									WriteFile << l;
								}
							}
						}
						cout<<endl<<"Doctor with ID "<<ID<<" successfully removed.";
					}
					else
					{
						cout<<endl<<"No doctors currently working";
					}
					
					ReadFile.close();
					WriteFile.close();
					
					remove("Doctor.txt");
					rename("TEMP.txt","Doctor.txt");
					break;
				}
				else if(sel==2)
				{
					int ID;
					cout<<endl<<"Enter the receptionist's ID to remove: ";
					cin>>ID;
					
					ifstream ReadFile("Receptionist.txt");
					ofstream WriteFile("TEMP.txt");
					
					if(ReadFile!=NULL)
					{
						char c;
						int t=0;
						while(!ReadFile.eof())
						{
							ReadFile.get(c);
							WriteFile << c;
							
							if(c=='\n')
							{
								t=0;
								int id;
								ReadFile >> id;
								if(ID==id)
								{
									ReadFile.get(c);
									while(c!='\n'&&!ReadFile.eof())
									{
										ReadFile.get(c);
									}
									
								}
								else
								{
									WriteFile << id;
								}
							}
							if(c=='\t')
							{
								t++;
								if(t==2||t==6)
								{
									float l;
									ReadFile >> l;
									WriteFile << l;
								}
							}
						}
						cout<<endl<<"Receptionist with ID "<<ID<<" successfully removed.";
					}
					else
					{
						cout<<endl<<"No receptionists currently working";
					}
					
					ReadFile.close();
					WriteFile.close();
					
					remove("Receptionist.txt");
					rename("TEMP.txt","Receptionist.txt");
					break;
				}
				else
				{
					cout<<endl<<"Invalid choice. Enter again: ";
					cin>>sel;
				}
			}
			
			getch();
		}
		
		void viewStaff()
		{
			cout<<endl<<"\n\nDOCTORS\n\n-------------------------------------------------------------------------------\n\n\n";
			ifstream ReadDFile("Doctor.txt");
			cout<<"ID\t\tName\t\tAge\t\tNumber\t\tAddress\t\tDate Hired\tSpecialisation\tFees\t\tSalary\n";
			
			if(ReadDFile!=NULL)
			{
				char c;
				int t=0;
				while(!ReadDFile.eof())
				{
					ReadDFile.get(c);
					cout<<c;
					if(c=='\n')
					{
						t=0;
					}
					if(c=='\t')
					{
						cout<<'\t';
						t++;
						if(t==2||t==7||t==8)
						{
							float l;
							ReadDFile >> l;
							cout << l;
						}
					}
				}
			}
			else
			{
				cout<<endl<<"No records exist";
			}
			ReadDFile.close();
			
			cout<<endl<<"\n\n\nRECEPTIONISTS\n\n-------------------------------------------------------------------------------\n\n\n";
			ifstream ReadRFile("Receptionist.txt");
			
			cout<<"ID\t\tName\t\tAge\t\tNumber\t\tAddress\t\tDate Hired\tSalary\n";
			
			if(ReadRFile!=NULL)
			{
				char c;
				int t=0;
				while(!ReadRFile.eof())
				{
					ReadRFile.get(c);
					cout<<c;
					if(c=='\n')
					{
						t=0;
					}
					if(c=='\t')
					{
						cout<<'\t';
						t++;
						if(t==2||t==6)
						{
							float l;
							ReadRFile >> l;
							cout << l;
						}
					}
				}
			}
			else
			{
				cout<<endl<<"No records exist";
			}
			ReadRFile.close();
			
			getch();
		}
		
		void addInventory()
		{
			int quan;
			string name;
			bool found=0;
			
			cout << endl << "Enter name of medicine/machine to order: ";
			fflush(stdin);
			getline(cin,name);
			cout << endl << "Enter quantity of medicine/machine to order: ";
			cin >> quan;
			
			ifstream ReadFile("Inventory.txt");
			
			ofstream WriteFile("TEMP.txt");
			
			if(ReadFile!=NULL)
			{
				char c,nam[30];
				int i=0;
				bool t=0;
				
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					
					WriteFile << c;
					
					if(c=='\t')
					{
						t = 1;
						
						if(nam==name)
						{
							ReadFile.get(c);
							WriteFile << c;
							found=1;
							int prev_quan;
							ReadFile >> prev_quan;
							quan += prev_quan;
							
							WriteFile << quan << '\n';
							while(c!='\n')
							{
								ReadFile.get(c);
							}
						}
						
					}
					
					if(!t&&c!='\t')
					{
						nam[i]=c;
						i++;
					}
					
					if(c=='\n')
					{
						t=0;
						for(i=0;i<30;i++)
						{
							nam[i]='\0';
						}
						i=0;
					}
					
				}
				
				if(!found)
				{
					WriteFile << name << "\t\t" << quan << '\n';
				}
			}
			else
			{
				WriteFile << name << "\t\t" << quan << '\n';
			}
			
			ReadFile.close();
			
			WriteFile.close();
			
			remove("Inventory.txt");
			
			rename("TEMP.txt","Inventory.txt");
			
			getch();
		}
		
		void viewInventory()
		{
			ifstream ReadFile("Inventory.txt");
			
			char c;
			
			if(ReadFile==NULL)
			{
				cout<<endl<<"No records exist"<<endl;
			}
			else
			{
				cout<<"Name: \t\tQuantity:"<<endl<<endl;
				
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					cout<<c;
				}
				
				ReadFile.close();
			}
			
			getch();
		}
		
		void removeInventory()
		{
			string name;
			int quan;
			bool found=0,removed=0;
			cout<<endl<<"Enter name of medcine/machinery to remove: ";
			fflush(stdin);
			getline(cin,name);
			cout<<endl<<"Enter quantity of medcine/machinery to remove: ";
			cin>>quan;
			
			ifstream ReadFile("Inventory.txt");
			
			ofstream WriteFile("TEMP.txt");
			
			if(ReadFile!=NULL)
			{
				char c,nam[30];
				int i=0;
				bool t=0;
				
				while(!ReadFile.eof())
				{
					ReadFile.get(c);
					
					WriteFile << c;
					
					if(c=='\t')
					{
						t = 1;
						
						if(nam==name)
						{
							ReadFile.get(c);
							WriteFile << c;
							found=1;
							int prev_quan;
							ReadFile >> prev_quan;
							if(prev_quan>=quan)
							{
								quan=prev_quan-quan;
								removed=1;
							}
							else
							{
								cout<<endl<<"Quantity to remove was greater than quantity present. No changes made"<<endl;
								quan=prev_quan;
							}
							
							WriteFile << quan << '\n';
							while(c!='\n')
							{
								ReadFile.get(c);
							}
						}
						
					}
					
					if(!t&&c!='\t')
					{
						nam[i]=c;
						i++;
					}
					
					if(c=='\n')
					{
						t=0;
						for(i=0;i<30;i++)
						{
							nam[i]='\0';
						}
						i=0;
					}
					
				}
				
				if(!found)
				{
					cout<<endl<<"Material not present in inventory"<<endl;
				}
			}
			else
			{
				cout<<endl<<"Inventory is empty"<<endl;;
			}
			
			if(removed)
			{
				cout<<endl<<"Successfully removed."<<endl;
			}
			
			ReadFile.close();
			WriteFile.close();
			
			remove("Inventory.txt");
			rename("TEMP.txt","Inventory.txt");
			getch();
		}
		
		void menu()
		{
			
			
			while(1)
			{
				system("cls");
				int choice;
				cout<<endl<<"Options:\n1.Add staff\n2.Remove staff\n3.View all staff information\n4.Add inventory\n5.Remove inventory\n6.View inventory\n7.Return\n\nSelect option: ";
				cin>>choice;
				if(choice==1)
				{
					addStaff();
				}
				else if(choice==2)
				{
					removeStaff();
				}
				else if(choice==3)
				{
					viewStaff();
				}
				else if(choice==4)
				{
					addInventory();
				}
				else if(choice==5)
				{
					removeInventory();
				}
				else if(choice==6)
				{
					viewInventory();
				}
				else if(choice==7)
				{
					LogIn();
				}
				else		//this and while loop allows choosing option again if invalid choice entered
				{
					cout<<endl<<"Invalid choice, try again"<<endl;
					cout<<endl<<"Enter your choice: ";
					cin>>choice;
				}
			}
		}
		
};


class Password{
		//static passwords so they can be checked anywhere
		static string managerpass;
		static string receppass;
		static string docpass;
	public:
		static string getManagerPass()
		{
			return managerpass;
		}
		static string getRecepPass()
		{
			return receppass;
		}
		static string getDoctorPass()
		{
			return docpass;
		}
};
//Hardcoded password for manager
string Password :: managerpass="managpass123";
//Hardcoded password for receptionist
string Password :: receppass="receppass123";
//Hardcoded password for doctor
string Password :: docpass="docpass123";

void LogIn()
{
	int sel;
	string pass;
	Password obj;
	cout <<endl<< "Log in:" <<endl<< "1. Manager" <<endl<< "2. Receptionist" <<endl<< "3. Doctor" <<endl<< "4. Exit" <<endl<< "Select: ";
	cin >> sel;
	
	while(1)
	{
		if(sel==1)
		{
			cout << endl << "Enter password: ";
			cin >> pass;
			
			if(pass == obj.getManagerPass())
			{
				Manager manager;
				manager.menu();
			}
			else
			{
				cout << "Invalid password";
				exit(1);
			}
			
			break;
		}
		else if(sel==2)
		{
			cout << endl << "Enter password: ";
			cin >> pass;
			
			if(pass == obj.getRecepPass())
			{
				Receptionist recep;
				recep.menu();
			}
			else
			{
				cout << "Invalid password";
				exit(2);
			}
			
			break;
		}
		else if(sel==3)
		{
			cout << endl << "Enter password: ";
			cin >> pass;
			
			if(pass == obj.getDoctorPass())
			{
				Doctor doctor;
				doctor.menu();
			}
			else
			{
				cout << "Invalid password";
				exit(3);
			}
			
			break;
		}
		else if(sel==4)
		{
			exit(0);
		}
		else
		{
			cout << endl << "Invalid choice. Enter again: ";
			cin >> sel;
		}
	}
}

int main()
{
	LogIn();
	
	
	return 1;
}
