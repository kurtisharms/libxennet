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
    if(!ago)
    {
        cout << "Could not bind Server Socket! ABORTING!!!!!!" <<endl;
        abort();
    }
    while(1) {
        cout << "Waiting for TCP connection on port " << ss->getPort() <<endl;
        ago = ss->acceptConnections();
        if(!ago)
        {
            cout << "Could not create Server Socket! ABORTING!!!!!" <<endl;
            abort();
        }
        Packet* pd = new Packet();
        while (ss->receiveData(pd)) {
            cout << pd->getData() <<endl;
            pd->setData("Data Received at Server!");
            ss->sendData(pd);
        }
    }
    return 0;
}
