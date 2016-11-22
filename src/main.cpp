#include "ofMain.h"
#include "ofxPJControl.h"

//========================================================================
int main(int argc, char *argv[]){
    
    string address = "";
    string password = "";
    string command = "%1POWR ?";

    for (int i=0; i<argc; i++) {
        
        string arg = argv[i];
        if (arg[0] == '-' && i<argc-1) {
            string option = arg.substr(1);
            if (option == "a") {
                address = argv[i+1];
            }
            else if (option == "p") {
                password = argv[i+1];
            }
            else if (option == "c") {
                string param = argv[i+1];
                if (param == "on")
                    command = "%1POWR 1";
                if (param == "off")
                    command = "%1POWR 0";
                if (param == "status")
                    command = "%1POWR ?";
            }
            else {
                cout << "Invalid option: " << option << endl;
            }
        }
    }
    
    if (address == "") {
        cout << "Error. No address set" << endl;
        return -1;
    }
    
    ofxPJControl pjlink;
    pjlink.setup(address);
    pjlink.setProjectorPassword(password);
    pjlink.sendPJLinkCommand(command);
    
    return 0;
}