/*
Design a Call taxi booking application
-There are n number of taxi’s. For simplicity, assume 4. But it should work for any number of taxi’s.
-The are 6 points(A,B,C,D,E,F)
-All the points are in a straight line, and each point is 15kms away from the adjacent points.
-It takes 60 mins to travel from one point to another
-Each taxi charges Rs.100 minimum for the first 5 kilometers and Rs.10 for the subsequent kilometers.
-For simplicity, time can be entered as absolute time. Eg: 9hrs, 15hrs etc.
-All taxi’s are initially stationed at A.
-When a customer books a Taxi, a free taxi at that point is allocated
-If no free taxi is available at that point, a free taxi at the nearest point is allocated.
-If two taxi’s are free at the same point, one with lower earning is allocated
-Note that the taxi only charges the customer from the pickup point to the drop point. Not the distance it travels from an adjacent point to pickup the customer.
-If no taxi is free at that time, booking is rejected

Design modules for

1)    Call taxi booking 
Input 1:
Customer ID: 1
Pickup Point: A
Drop Point: B
Pickup Time: 9

Output 1:
Taxi can be allotted.
Taxi-1 is allotted

Input 2:
Customer ID: 2
Pickup Point: B
Drop Point: D
Pickup Time: 9

Output 1:
Taxi can be allotted.
Taxi-2 is allotted 
(Note: Since Taxi-1 would have completed its journey when second booking is done, so Taxi-2 from nearest point A which is free is allocated)


Input 3:
Customer ID: 3
Pickup Point: B
Drop Point: C
Pickup Time: 12

Output 1:
Taxi can be allotted.
Taxi-1 is allotted 
2) Display the Taxi details


Taxi No:    Total Earnings:
BookingID    CustomerID    From    To    PickupTime    DropTime    Amount
   
Output:
Taxi-1    Total Earnings: Rs. 400

1     1     A    B    9    10    200
3    3    B    C    12    13    200

Taxi-2 Total Earnings: Rs. 350
2    2    B    D    9    11    350 
*/

#include <iostream>
// #include <conio>
#include <math.h>
using namespace std;
int numberofcustomer[4] = {0};
int taxiride[4] = {0};
class taxi
{
	int taxi_earning;
	int isfree;
	int earnings;

public:
	taxi()
	{
		isfree = 1;
		taxi_earning = 0;
	}
	int free()
	{
		return isfree;
	}
	void allocate()
	{
		isfree = 0;
	}
	void deallocate()
	{
		isfree = 1;
	}
	void assign(int amount)
	{
		this->earnings += amount;
	}
	int AmountEarned()
	{
		return earnings;
	}
} car[4];
class customer
{
	int cust_id;
	char cust_statpoint;
	char cust_endpoint;
	int cust_stattime;
	int km;
	int travel_time;

public:
	void input()
	{
		cout << "Customer Id :";
		cin >> cust_id;
		cout << "\nStarting point :";
		cin >> cust_statpoint;
		cout << "\nEnd point :";
		cin >> cust_endpoint;
		cout << "\nPickup Time :";
		cin >> cust_stattime;
		int temp = abs((int)cust_endpoint - (int)cust_statpoint);
		km = temp * 15;
		travel_time = temp * 60;
		//cout<<travel_time;
	}
	void display(int ta)
	{
		cout << "Taxi is allocated!!\n";
		cout << "Taxi allocated to you is : " << ta << "\n";
	}
	void print()
	{
		cout << cust_id << "\t" << cust_statpoint << "\t" << cust_endpoint << "\t" << cust_stattime << "\t";
	}
	int time()
	{
		return travel_time;
	}
	void change()
	{
		this->travel_time = 0;
	}
	void changegre(int t)
	{
		this->travel_time = this->travel_time - t;
	}
	int CalculateTaxiRent()
	{
		int t;
		int len = km;
		if (km <= 5)
		{
			t = 100;
		}
		else
		{
			t = 100;
			len = len - 5;
			t += len * 10;
		}
		//cout<<t;
		return t;
	}

} cus[4][10];
int main()
{
	// clrscr();
	int t, amt;
	cout << "\t\t\tCall Taxi Booking\n\n";
	while (t != 3)
	{
		cout << "1.Booking\n2.Details\n3.Exit\n";
		cin >> t;
		switch (t)
		{
		case 1:
			if (car[0].free())
			{
				cus[0][numberofcustomer[0]].input();
				//	cout<<"###"<<cus[0][numberofcustomer[0]].time()<<"\n";
				cus[0][numberofcustomer[0]].display(1);
				amt = cus[0][numberofcustomer[0]].CalculateTaxiRent();
				car[0].assign(amt);
				taxiride[0] = 1;
				car[0].allocate();
				for (int i = 0; i < 4; i++)
				{
					if (i == 0)
					{
						continue;
					}
					if ((cus[i][numberofcustomer[i] - 1].time() - cus[0][numberofcustomer[0]].time()) <= 0)
					{
						cus[i][numberofcustomer[i] - 1].change();

						car[i].deallocate();
					}
					else if (cus[i][numberofcustomer[i] - 1].time() > cus[0][numberofcustomer[0]].time())
					{
						cus[i][numberofcustomer[i] - 1].changegre(cus[0][numberofcustomer[0]].time());
					}
					//	cout<<"!!!!!"<<cus[i][numberofcustomer[i]].time()<<"!!!!!"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
				}
				numberofcustomer[0]++;
			}
			else if (car[1].free())
			{

				cus[1][numberofcustomer[1]].input();
				//cout<<"####"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
				cus[1][numberofcustomer[1]].display(2);
				amt = cus[1][numberofcustomer[1]].CalculateTaxiRent();
				car[1].assign(amt);
				taxiride[1] = 1;
				car[1].allocate();
				//cout<<"@@@@@"<<cus[1][numberofcustomer[1]].time()<<"@@@@@"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
				//cus[1][numberofcustomer[1]].compare(cus[0][numberofcustomer[0]-1]);
				for (int i = 0; i < 4; i++)
				{
					if (i == 1)
					{
						continue;
					}
					if ((cus[i][numberofcustomer[i] - 1].time() - cus[1][numberofcustomer[1]].time()) <= 0)
					{
						cus[i][numberofcustomer[i] - 1].change();
						//	cout<<"!!!!!"<<cus[1][numberofcustomer[1]].time()<<"!!!!!"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
						car[i].deallocate();
					}
					else if (cus[i][numberofcustomer[i] - 1].time() > cus[1][numberofcustomer[1]].time())
					{
						cus[i][numberofcustomer[i] - 1].changegre(cus[1][numberofcustomer[1]].time());
					}

					//	cout<<"!!!!!"<<cus[i][numberofcustomer[i]].time()<<"!!!!!"<<cus[1][numberofcustomer[1]-1].time()<<"\n";
				}
				numberofcustomer[1]++;
			}
			else if (car[2].free())
			{

				cus[2][numberofcustomer[2]].input();
				cus[2][numberofcustomer[2]].display(3);
				amt = cus[2][numberofcustomer[2]].CalculateTaxiRent();
				car[2].assign(amt);
				taxiride[2] = 1;
				car[2].allocate();
				for (int i = 0; i < 4; i++)
				{
					if (i == 2)
					{
						continue;
					}
					if ((cus[i][numberofcustomer[i] - 1].time() - cus[2][numberofcustomer[2]].time()) <= 0)
					{
						cus[i][numberofcustomer[i] - 1].change();
						//	cout<<"!!!!!"<<cus[1][numberofcustomer[1]].time()<<"!!!!!"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
						car[i].deallocate();
					}
					else if (cus[i][numberofcustomer[i] - 1].time() > cus[2][numberofcustomer[2]].time())
					{
						cus[i][numberofcustomer[i] - 1].changegre(cus[2][numberofcustomer[2]].time());
					}
					//	cout<<"!!!!!"<<cus[i][numberofcustomer[i]].time()<<"!!!!!"<<cus[2][numberofcustomer[2]-1].time()<<"\n";
				}
				numberofcustomer[2]++;
			}
			else if (car[3].free())
			{

				cus[3][numberofcustomer[3]].input();
				cus[3][numberofcustomer[3]].display(4);
				amt = cus[3][numberofcustomer[3]].CalculateTaxiRent();
				car[3].assign(amt);
				taxiride[3] = 1;
				car[3].allocate();
				for (int i = 0; i < 4; i++)
				{
					if (i == 3)
					{
						continue;
					}
					if ((cus[i][numberofcustomer[i] - 1].time() - cus[3][numberofcustomer[3]].time()) <= 0)
					{
						cus[i][numberofcustomer[i] - 1].change();
						//	cout<<"!!!!!"<<cus[1][numberofcustomer[1]].time()<<"!!!!!"<<cus[0][numberofcustomer[0]-1].time()<<"\n";
						car[i].deallocate();
					}
					else if (cus[i][numberofcustomer[i] - 1].time() > cus[3][numberofcustomer[3]].time())
					{
						cus[i][numberofcustomer[i] - 1].changegre(cus[3][numberofcustomer[3]].time());
					}
					//cout<<"!!!!!"<<cus[i][numberofcustomer[i]].time()<<"!!!!!"<<cus[3][numberofcustomer[3]-1].time()<<"\n";
				}
				numberofcustomer[3]++;
			}
			else
			{
				cout << "All Cars Are currently Busy";
			}

			break;
		case 2:
			//int amt;
			cout << "Customer_Id  Starting_point  Ending_point  Pickup_time\n";
			for (int i = 0; i < 4; i++)
			{
				if (taxiride[i] == 1)
				{
					//amt = car[i].AmountEarned();
					cout << "Taxi : " << i + 1 << "\t\t"
						 << "Amount Earned :" << car[i].AmountEarned() << "\n";
					for (int j = 0; j < numberofcustomer[i]; j++)
					{
						cus[i][j].print();
						cout << "\n\n";
					}
				}
				else
				{
					break;
				}
			}

			break;
		}
		cout << "\nwant to exit(press 3 else press 1)\n";
		cin >> t;
	}
	return 0;
}