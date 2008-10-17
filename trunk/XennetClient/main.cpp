#include "Xennet.hpp"

using namespace std;
using namespace Xennet;

int main()
{
    string tcpudp = "";
    while (tcpudp != "1" && tcpudp != "2")
    {
        cout << "Choose:  1)TCP   2)UDP: ";
        cin >> tcpudp;
        cout << "\n\n";
    }

    if (tcpudp == "1")
    {
        int port = 5000;
        string host;
        cout << "Enter the hostname of ip address of TCP server: ";
        cin >> host;
        cout << "\nEnter the port number of TCP server: ";
        cin >> port;
        Socket* sock = new Socket(port);
        sock->setIPAddress(host);
        sock->connectSocket();
        sock->sendData("hi there");
        cout << "From Server: " << sock->readDataAsString() <<endl;
        return 0;
    }
    else if (tcpudp == "2")
    {
        int port = 5000;
        string host;
        cout << "Enter the hostname of ip address of UDP server: ";
        cin >> host;
        cout << "\nEnter the port number of UDP server: ";
        cin >> port;
        DatagramSocket* sock = new DatagramSocket(port);
        sock->setIPAddress(host);
        sock->setTimeout(5);
        sock->connectSocket();
        sock->sendData("hi there");
        cout << "From Server: " << sock->readDataAsString() <<endl;
        return 0;
    }

    // This should never be reached!
    return 0;
}
