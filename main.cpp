#include <vector>
#include <iterator>
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

using namespace std;
using namespace sdbus;

int main(int argc, char** argv) {
    const char* destinationName = "org.freedesktop.DBus";
    const char* objectPath = "/org/freedesktop/DBus";
    
    auto dbusProxy = sdbus::createObjectProxy(destinationName, objectPath);

    const char* interfaceName = "org.freedesktop.DBus";

    std::string type;
    std::string contents;

    auto methodCall = dbusProxy->createMethodCall(interfaceName, "ListNames");
    auto reply = dbusProxy->callMethod(methodCall);
    vector<string> devicePaths;
    reply >> devicePaths;

    /*
    dbusProxy->callMethod("EnumerateDevices").onInterface(interfaceName).storeResultsTo(devicePaths);
    */

    cout << "{" << endl << "\t";
    std::copy(devicePaths.begin(), devicePaths.end(), ostream_iterator<string>(cout, ",\n\t"));
    cout << "}" << endl;

    cout << "Hello, World." << endl;
    return 0;
}