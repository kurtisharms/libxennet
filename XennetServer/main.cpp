#include "Xennet.hpp"

using namespace std;
using namespace Xennet;

int main()
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
        while (1)
        {
            data = ss->receiveDataAsString();
            if (data == ss->NET_EOD)
                break;
            cout << data <<endl;
            //cout << "Data line finished!" <<endl;
            ss->sendData("Got DATA line!");
        }
        ss->sendData("Connection closing!");
    }
    return 0;
}
