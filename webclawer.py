import urllib.request
import os
import ssl
import json

ssl._create_default_https_context = ssl._create_stdlib_context

# 定义保存函数
def saveFile(data,path):
    f = open(path, 'wb')
    f.write(data)
    f.close()
#设置请求头
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
                         'Chrome/51.0.2704.63 Safari/537.36'}
#确定文件夹存在
if not os.path.exists("html"):
    os.makedirs("html")
if not os.path.exists("downloads"):
    os.makedirs("downloads")
if not os.path.exists("torrent"):
    os.makedirs("torrent")
#打开文件读取并爬取网页保存到html文件夹
with open("config/Bangumi.json",'r') as json_data:
    json_value=json.load(json_data)
    for object in json_value:
        req = urllib.request.Request(url=object["url"], headers=headers)
        res = urllib.request.urlopen(req)
        data=res.read()
        # 保存到文件
        path='html/'+object["name"]+'.html'
        saveFile(data,path)
        #data = data.decode('utf-8')
        #print(data)
