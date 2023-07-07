#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{
	while(1)
	{
	cout<<"欢迎使用BangumiDL,此入口程序将为您提供帮助,首次使用请按序号顺序操作"<<endl;
	int select=10;
	cout<<"0:设置Emby URL和API(用于刷新库)"<<endl;
	cout<<"1:设置邮件服务"<<endl;
	cout<<"2:增加邮件接收方"<<endl;
	cout<<"3:增加番剧列表"<<endl;
	cout<<"4:运行主程序(CTRL+C停止运行)"<<endl;
	cout<<"5:退出入口程序"<<endl;
	cin>>select;
	switch (select)
	{
		case 0:
			system("./setup");
			break;
		case 1:
			system("./emailsetup");
			break;
		case 2:
			system("./addRev");
			break;
		case 3:
			system("./addBangumi");
			break;
		case 4:
			system("./BangumiDL");
			break;
		case 5:
			return 0;
	}
	}
}
