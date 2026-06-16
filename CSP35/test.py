import time
import requests
from bs4 import BeautifulSoup

# ⚠️ 必须替换为你自己浏览器里复制出来的真实数据！
HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/149.0.0.0 Safari/537.36 Edg/149.0.0.0",
    "Cookie": "connect.sid=s%3AR8BgpfOwCe4vvs7hmF-X1ATCxmLVka_e.Hl5ofibLgP7mSYJp%2B%2Fmr4rqhB1gCfBWQoujZ0R0MBWI; cf_clearance=pw3gM.1R8EUUV3xiuUO7zhHugMY272YdNZl.PUbSK_w-1781451295-1.2.1.1-1A7brefIOcAGWE6V15O.l54rYxtErvK85PUfA9sQHg0QZ.vLR5EStzqDC_YARP4bJLHFrCoLh7Rp6uUho6D5CPCjXAYTIlDcwtFJOWE6HCSBcl1ZU1N8ml174TN0qzHWxCSmuF4YvLoWXQ4.1dcjynFYNpH4SB8gnALIx_imvkJ5ol7pONnnISJ8ixcUMbl8iKGmhuIUmLgwKfjkT_Y2C2Gtgb6DUqkB2LAT8RCYNdlc3skFy.kMebyE8vuGW8W1TP3JtNZOm1WTHRTIQQF4tExhntUIzRWwPlAbK8YcHI0KsuB88yKaQMmEibPvH.or0KCml.bx61LCLJOPZosHWw",
    "Referer": "https://hlib.cc/"
}

def crawl_page(chapter_id, page_num):
    url = f"https://hlib.cc/n/{chapter_id}?p={page_num}"
    try:
        # 使用带验证信息的 Headers 绕过防护
        response = requests.get(url, headers=HEADERS, timeout=10)
        
        # 如果再次遇到验证码页面，说明 Cookie 失效了
        if "人机校验" in response.text:
            print("⚠️ 糟糕，Cookie 失效或被安全墙拦截了，需要重新去浏览器获取新 Cookie。")
            return None
            
        soup = BeautifulSoup(response.text, 'html.parser')
        content_tag = soup.find('pre', id='content')
        if content_tag:
            paragraphs = content_tag.find_all('p')
            return "\n".join([p.get_text().strip() for p in paragraphs if p.get_text().strip() and not p.get_text().startswith("[")])
    except Exception as e:
        print(f"请求失败: {e}")
    return None

# 测试抓取第一页
text = crawl_page(20640716, 1)
if text:
    print("🎉 成功绕过安全墙！正文前100字：\n", text[:100])