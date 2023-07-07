该程序是BangumiDLChecker-on-nyaa.si的延续版
https://github.com/AlexEisie/BangumiDLChecker-on-nyaa.si
它是较为简单的版本

本程序的功能：
	定时循环爬取nyaa.si的某链接中的种子文件，下载并上传到指定云盘位置，并且可以在有更新情况下发送更新提醒邮件以及让emby服务器刷新指定库。你的追番RPA好帮手

运行环境：
	Linux
必须的软件：
	python3 wget aria2(aria2c) rclone
可以下载Releases中的已编译版本(Linux_x86_64)或者自行编译（自行编译时注意本程序使用了jsoncpp，注意链接库）

使用：运行main

注意事项：
爬取的页面文件保存到html文件夹中,下载的种子文件保存到torrent文件夹中(程序不会自动清除，如果体积过大请手动删除torrent目录)，下载的番剧暂时存在downloads中并且上传到预设目录。

程序每6分钟运行一次，所以建议在screen中运行然后置之不理

为了避免种子卡下载，种子下载0速度5分钟后会结束任务（没写报错QAQ）！

手动操作config文件夹中的文件请在linux下进行，在windows下编辑可能会出现行末符异常问题
