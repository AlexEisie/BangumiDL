#include<iostream>
#include<json/json.h>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("./config/emailR.json");
	if(!infile.is_open())
        {
                cout<<"Failed to open emailR"<<endl;
                return -1;
        }

	Json::Reader json_reader;
        Json::Value json_value;

	if(!json_reader.parse(infile,json_value,false))
        {
                cout<<"parse emailR error"<<endl;
                return -1;
        }
        infile.close();
        cout<<json_value<<endl;

	if(!json_value["mail_host"].asString().length()||!json_value["mail_user"].asString().length())
	{
		string buff;
		cout<<"mail_host:";
		cin>>buff;
		json_value["mail_host"]=buff;
		cout<<"mail_host_port:";
		int port;
		cin>>port;
		json_value["mail_host_port"]=port;
		cout<<"mail_user:";
		cin>>buff;
		json_value["mail_user"]=buff;
		cout<<"mail_pass:";
		cin>>buff;
                json_value["mail_pass"]=buff;
		cout<<"sender:";
		cin>>buff;
		json_value["sender"]=buff;
		cout<<"default receiver:";
		cin>>buff;
		Json::Value Rev;
		Rev=buff;
		json_value["receivers"].append(Rev);

		cout<<endl<<json_value<<endl;
		ofstream outfile;
                outfile.open("./config/emailR.json",ios_base::out);
                outfile<<json_value;
                outfile.close();
	}
	else
                cout<<"Email Config exists"<<endl;
        return 0;

}
