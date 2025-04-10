#pragma once
#include <iostream>
using namespace std;
#include <queue>
#include <string>
#include <stack>
#include "clsDate.h"
class clsQueueLine
{
private:
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";

	class clsTicket {
	private:
		short _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
	public:

		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime) {
			_Number = Number;
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		
		}

		short Number() {
			return _Number;
		}

		string Prefix() {
			return _Prefix;
		}

		string TicketTime() {
			return _TicketTime;
		}

		short WaitingClients() {
			return _WaitingClients;
		}

		short ExpectedServeTime() {
			return _WaitingClients * _AverageServeTime;
		}

		string FullNumber() {
			return _Prefix + to_string(_Number);
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";


		}
	};

public:

	queue <clsTicket> Queue;

	clsQueueLine(string Prefix, short AverageServeTime) {
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0;
	}

	void IssueTicket() {
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		Queue.push(Ticket);
	}

	short WaitingClients() {
		return Queue.size();
	}

	string WhoIsNext() {
		if (Queue.empty()) {
			return "\nTicket Not Found\n";
		}
		else  {
			return Queue.front().FullNumber();
		}
	}

	bool ServeNextClient() {
		if (Queue.empty())
			return false;

		Queue.pop();
		return true;
	}

	short ServedClients() {
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}

	void PrintTicketRTL() {
		if (Queue.empty())
			cout << "\n\t\Tickets : No Tickets.\n";
		else {
			cout << "\n\t\tTickets: \n";

			queue <clsTicket> TempQueue = Queue;

			while (!TempQueue.empty()) {
				clsTicket Ticket = TempQueue.front();

				cout << " " << Ticket.FullNumber() << " <-- ";

				TempQueue.pop();
			}

		}
	}

	void PrintTicketLTR() {
		if (Queue.empty())
			cout << "\n\t\Tickets : No Tickets.\n";
		else {
			cout << "\n\t\tTickets: \n";

			queue <clsTicket> TempQueue = Queue;
			stack <clsTicket> TempStack;

			while (!TempQueue.empty()) {
				TempStack.push(TempQueue.front());
				TempQueue.pop();
			}

			while (!TempStack.empty()) {
				clsTicket Ticket = TempStack.top();

				cout << " " << Ticket.FullNumber() << " --> ";

				TempStack.pop();
			}
			cout << "\n";

		}
	}

	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (Queue.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = Queue;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}

	}
};

