import time
import requests
from bs4 import BeautifulSoup

# ==========================================
# 🔥 💥 核心配置区 💥 🔥
# ==========================================
# 1. 配置你想爬取的章节信息
START_CHAPTER = 20640716  # 起始章节 ID
CHAPTER_COUNT = 10        # 连续爬取的章节数量（例如爬取 10 章）

# 2. 填入你刚才测试成功的真实浏览器凭证
HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/149.0.0.0 Safari/537.36 Edg/149.0.0.0",
    "Cookie": "connect.sid=s%3AR8BgpfOwCe4vvs7hmF-X1ATCxmLVka_e.Hl5ofibLgP7mSYJp%2B%2Fmr4rqhB1gCfBWQoujZ0R0MBWI; cf_clearance=pw3gM.1R8EUUV3xiuUO7zhHugMY272YdNZl.PUbSK_w-1781451295-1.2.1.1-1A7brefIOcAGWE6V15O.l54rYxtErvK85PUfA9sQHg0QZ.vLR5EStzqDC_YARP4bJLHFrCoLh7Rp6uUho6D5CPCjXAYTIlDcwtFJOWE6HCSBcl1ZU1N8ml174TN0qzHWxCSmuF4YvLoWXQ4.1dcjynFYNpH4SB8gnALIx_imvkJ5ol7pONnnISJ8ixcUMbl8iKGmhuIUmLgwKfjkT_Y2C2Gtgb6DUqkB2LAT8RCYNdlc3skFy.kMebyE8vuGW8W1TP3JtNZOm1WTHRTIQQF4tExhntUIzRWwPlAbK8YcHI0KsuB88yKaQMmEibPvH.or0KCml.bx61LCLJOPZosHWw",
    "Referer": "https://hlib.cc/",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
    "Accept-Language": "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2"
}

# 保存的文件名
SAVE_FILE_NAME = "小说完整合集.txt"
# ==========================================


def crawl_page_content(chapter_id, page_num):
    """
    爬取单页的正文内容
    """
    url = f"https://hlib.cc/n/{chapter_id}?p={page_num}"
    try:
        response = requests.get(url, headers=HEADERS, timeout=12)
        response.encoding = response.apparent_encoding
        
        # 安全墙二次检测
        if "人机校验" in response.text:
            print(f"🛑 糟糕！在爬取 [章节:{chapter_id}, 页码:{page_num}] 时 Cookie 似乎失效了，触发了人机验证。")
            return "COOKIE_EXPIRED"
            
        soup = BeautifulSoup(response.text, 'html.parser')
        content_tag = soup.find('pre', id='content')
        
        if content_tag:
            paragraphs = content_tag.find_all('p')
            page_lines = []
            
            for p in paragraphs:
                text = p.get_text().strip()
                # 过滤掉空白行和图片占位符 [uploadedimage:xxxx]
                if text and not text.startswith("["):
                    page_lines.append(text)
            
            if page_lines:
                return "\n".join(page_lines)
                
    except Exception as e:
        print(f"❌ 网络请求异常 [章节:{chapter_id}, 页码:{page_num}]: {e}")
        
    return None


def main():
    # 根据配置生成章节 ID 列表
    # 💡 提示：如果发现网站的章节 ID 不是纯数字连续递增的，可以在这里手动改成一个列表：[20640716, 20640725, 20640750]
    chapter_list = [START_CHAPTER + i for i in range(CHAPTER_COUNT)]
    
    print("🎬 自动化小说爬虫启动...")
    print(f"📋 本次计划爬取章节数: {len(chapter_list)} 章")
    print(f"💾 内容将保存至: {SAVE_FILE_NAME}\n" + "="*40)
    
    with open(SAVE_FILE_NAME, "w", encoding="utf-8") as f:
        
        for c_index, chapter_id in enumerate(chapter_list, 1):
            print(f"\n📂 [{c_index}/{len(chapter_list)}] 正在准备抓取章节 ID: {chapter_id} ...")
            
            # 写入章节隔离线，方便在 TXT 里阅读
            f.write(f"\n\n==================== 章节 ID: {chapter_id} ====================\n\n")
            
            page_num = 1
            last_page_content = "" # 用于处理有些网站单页翻到头后，内容会不断重复的特殊情况
            
            # 内部循环：抓取当前章节的每一页
            while True:
                print(f" -> 正在读取第 {page_num} 页...", end="", flush=True)
                
                current_content = crawl_page_content(chapter_id, page_num)
                
                # 情况1：Cookie 失效，触发验证码
                if current_content == "COOKIE_EXPIRED":
                    print("\n⚠️ 爬虫被迫中止！请重新去浏览器获取最新的 Cookie 填入代码。")
                    return
                
                # 情况2：成功拿到正文
                if current_content:
                    # 检查内容是否与上一页完全一样（防止部分网站死循环返回同一页内容）
                    if current_content == last_page_content:
                        print(" [检测到内容重复，判定本章结束] ✨")
                        break
                        
                    f.write(current_content + "\n")
                    last_page_content = current_content
                    print(" OK!")
                    
                    page_num += 1
                    # 🔔 每次翻页温和歇息 1.5 秒，避免因为速度太快把 Cookie 刷失效
                    time.sleep(1.5)
                    
                # 情况3：拿不到内容，说明这章已经彻底翻完了
                else:
                    print(f" [本章结束] ✨ (共 {page_num - 1} 页)")
                    break
                    
    print("\n" + "="*40 + "\n🎉 恭喜！全部指定章节已成功下载完成！")


if __name__ == "__main__":
    main()