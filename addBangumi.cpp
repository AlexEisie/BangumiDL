#include<iostream>
#include<string>
#include<fstream>
#include<json/json.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("./config/Bangumi.json");
	if(!infile.is_open())
	{
		cout<<"Failed to open Bangumi.json"<<endl;
		return -1;
	}
	
	Json::Reader json_reader;
	Json::Value json_value;

	if(!json_reader.parse(infile,json_value,false))
	{
		cout<<"parse Bangumi error"<<endl;
		return -1;
	}
	infile.close();
	
	cout<<json_value<<endl;

	Json::Value single_object;
	
	string buff;
	cout<<"Please input name(just for identify):";
	cin>>buff;
	single_object["name"]=buff;
	cout<<"Please input nyaa url:";
	cin>>buff;
	single_object["url"]=buff;
	cout<<"Please input upload dir path:";
	getchar();
	getline(cin, buff, '\n');	//使用getline来获取带空格的路径，截止符为回车
	single_object["upload_dir"]=buff;
	cout<<"Please input emby refresh dir path(no '/' in the rear):";
	getline(cin, buff, '\n');
	single_object["refresh_dir"]=buff;

	json_value.append(single_object);
	//cout<<endl<<json_value.toStyledString()<<endl;

	Json::StreamWriterBuilder builder;
	static Json::Value def = []() {
		Json::Value def;
		Json::StreamWriterBuilder::setDefaults(&def);
		def["emitUTF8"] = true;
		return def;
	}();

	builder.settings_ = def;//Config emitUTF8
	const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

	ofstream outfile;
	outfile.open("./config/Bangumi.json",ios_base::out);	//清空后写入
	if(!outfile.is_open())
	{
		cout<<"Failed to open Bangumi.json"<<endl;
		return -1;
	}
	//outfile<<json_value.toStyledString();		//此处必须要使toStyledString()方法
	
	writer->write(json_value, &std::cout);
        writer->write(json_value, &outfile);
	
	outfile.close();
	return 0;
}
