#include <iostream>
using namespace std;
#include "clsQueueLine.h"
int main()
{
    clsQueueLine PayBillQueue("A0", 10);
    PayBillQueue.IssueTicket();
    PayBillQueue.IssueTicket();
    PayBillQueue.IssueTicket();
    PayBillQueue.PrintInfo();
    PayBillQueue.PrintAllTickets();

    system("pause > 0");
}

