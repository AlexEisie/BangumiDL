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
                cout<<"Failed to open emailR.json"<<endl;
                return -1;
        }

        Json::Reader json_reader;
        Json::Value json_value;

        if(!json_reader.parse(infile,json_value,false))
        {
                cout<<"parse emailR.json error"<<endl;
                return -1;
        }
        infile.close();
	cout<<"Current Email Receivers:";
        for(unsigned int i=0;i<json_value["receivers"].size();i++)
		cout<<" "<<json_value["receivers"][i];

	cout<<endl;

	string buff;
	cout<<"Input New receiver:";
	cin>>buff;
	Json::Value Rev;
	Rev=buff;
	json_value["receivers"].append(Rev);
	cout<<"Current Email Receivers:";
        for(unsigned int i=0;i<json_value["receivers"].size();i++)
                cout<<" "<<json_value["receivers"][i];
	cout<<endl;
	ofstream outfile;
        outfile.open("./config/emailR.json",ios_base::out);
        outfile<<json_value;
   	outfile.close();
	return 0;
}
