#include "Xennet.hpp"

using namespace std;
using namespace Xennet;

int main()
{
    int port = 5000;
    string host;
    cout << "Enter the hostname of ip address of server: ";
    cin >> host;
    cout << "\nEnter the port number: ";
    cin >> port;
    Socket* sock = new Socket(port);
    sock->setIPAddress(host);
    sock->connectSocket();
    //Packet* pa = new Packet("hi there");
    //cout << pa->getData() <<endl;
    sock->sendData("hi there");
    cout << "From Server: " << sock->readDataAsString() <<endl;
    return 0;
}
