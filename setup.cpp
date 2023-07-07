#include<iostream>
#include<json/json.h>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("./config/serversideconfig.json");
	if(!infile.is_open())
	{
		cout<<"Failed to open serversideconfig"<<endl;
		return -1;
	}

	Json::Reader json_reader;
	Json::Value json_value;

	if(!json_reader.parse(infile,json_value,false))
	{
		cout<<"parse serversideconfig error"<<endl;
		return -1;
	}
	infile.close();
	cout<<json_value<<endl;

	if(!json_value["url"].asString().length()||!json_value["api"].asString().length())
	{
		cout<<"Please input emby url:";
		string buff;
		cin>>buff;
		json_value["url"]=buff;
		cout<<"Please input emby api:";
		cin>>buff;
		json_value["api"]=buff;
		cout<<json_value<<endl;	
		ofstream outfile;
		outfile.open("./config/serversideconfig.json",ios_base::out);
		outfile<<json_value;
		outfile.close();
	}
	else
		cout<<"Server Config exists"<<endl;
	
	return 0;
}

