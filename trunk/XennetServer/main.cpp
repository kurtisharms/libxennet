#include <iostream>
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
        bool ago = true;
        cout << "Enter the port number to listen on: ";
        cin >> port;
        ServerSocket* ss = new ServerSocket(port,10);
        ago = ss->bindSocket();
        if (!ago)
        {
            cout << "Could not bind Server Socket! ABORTING!!!!!!" <<endl;
            abort();
        }
        while (1)
        {
            cout << "Waiting for TCP connection on port " << ss->getPort() <<endl;
            ago = ss->acceptConnections();
            if (!ago)
            {
                cout << "Could not create Server Socket! ABORTING!!!!!" <<endl;
                abort();
            }
            string data;
            while (ss->receiveDataAsString(data))
            {
                cout << data <<endl;
                //cout << "Data line finished!" <<endl;
                ss->sendData("Got DATA line!");
            }
            ss->sendData("Connection closing!");
        }
        return 0;
    }
    else if (tcpudp == "2")
    {
        int port = 5000;
        bool ago = true;
        cout << "Enter the port number to listen on: ";
        cin >> port;
        DatagramServerSocket* ss = new DatagramServerSocket(port,10);
        ago = ss->bindSocket();
        if (!ago)
        {
            cout << "Could not bind Server Socket! ABORTING!!!!!!" <<endl;
            abort();
        }
        while (1)
        {
            cout << "Waiting for TCP connection on port " << ss->getPort() <<endl;
            string data;
            while (ss->receiveDataAsString(data))
            {
                cout << data <<endl;
                //cout << "Data line finished!" <<endl;
                ss->sendData("Got DATA line!");
            }
            ss->sendData("Connection closing!");
        }
        return 0;
    }


    // This should never be reached!
    return 0;

}
