#网络通讯库
import pprint
import requests
#邮件库
import smtplib
from email.mime.text import MIMEText
from email.header import Header
from email.utils import parseaddr, formataddr

import json
import sys

def emailR (name) :
    with open("config/emailR.json") as json_data:
        json_value=json.load(json_data)
    content='Emby服务器的 '+name+' 已经更新啦!'
    message=MIMEText(content,'plain','utf-8')
    message['Subject']=name+' 已更新'
    message['From']="Emby Update Reminder"
    message['To']=json_value["receivers"][0]
    try:
        smtp=smtplib.SMTP(json_value["mail_host"],json_value["mail_host_port"])
        smtp.set_debuglevel(2)
        smtp.starttls()
        smtp.login(json_value["mail_user"],json_value["mail_pass"])
        smtp.sendmail(json_value["sender"],json_value["receivers"],message.as_string())
        smtp.quit()
        print('Mail Success')
    except smtplib.SMTPException as e:
        print('Mail error',e)

def embyRefresh(path) :
    with open("config/serversideconfig.json") as json_data:
        json_value=json.load(json_data)
    folder_path = path
    emby_url = json_value["url"]
    api_key = json_value["api"]

    response = requests.get(
         f'{emby_url}/emby/Items?Recursive=true&Fields=Path&Path={folder_path}',
         params={'X-Emby-Token': f'{api_key}'},
         headers={'accept': 'application/json'},
    )
    res = response.json()
    pprint.pprint(res)
    item_id = res['Items'][0]['Id']
    print(f'{item_id=}')

    response = requests.post(
         f'{emby_url}/emby/Items/{item_id}/Refresh',
         params={
             'Recursive': 'true',
             'ImageRefreshMode': 'Default',
            'MetadataRefreshMode': 'Default',
           'ReplaceAllImages': 'false',
             'ReplaceAllMetadata': 'false',
             'X-Emby-Token': f'{api_key}',
      })
    print(response.status_code)

#主程序第一个参数为番剧名称,第二个参数为刷新路径（使用双引号封装避免空格识别参数失败）
if __name__ == '__main__' :
    emailR(sys.argv[1].strip('"')) 
    embyRefresh(sys.argv[2].strip('""'))

