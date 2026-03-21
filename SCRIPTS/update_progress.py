import os
import re
import requests
from collections import defaultdict

# -----------------------------
# 路徑設定
# -----------------------------
ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")
TOPICS_DIR = os.path.join(ROOT_DIR, "TOPICS")

START = "<!-- PROGRESS-START -->"
END = "<!-- PROGRESS-END -->"

# -----------------------------
# 🔗 抓 LeetCode 題目資料
# -----------------------------
print("Fetching LeetCode data from LeetCode API...")
url = "https://leetcode.com/api/problems/all/"
data = requests.get(url).json()

difficulty_map = {}
for item in data["stat_status_pairs"]:
    qid = item["stat"]["frontend_question_id"]
    level = item["difficulty"]["level"]
    difficulty_map[qid] = level

def get_diff(qid):
    level = difficulty_map.get(int(qid), 2)
    return ["Easy", "Medium", "Hard"][level-1]

# -----------------------------
# 🔹 整理檔案資料
# -----------------------------
problems_seen = {}  # key=pid, value=diff

for topic in os.listdir(TOPICS_DIR):
    topic_path = os.path.join(TOPICS_DIR, topic)
    if not os.path.isdir(topic_path):
        continue

    for item in os.listdir(topic_path):
        item_path = os.path.join(topic_path, item)

        if os.path.isdir(item_path):
            # 二層資料夾
            pid_match = re.match(r"(\d+)", item)
            if not pid_match:
                continue
            pid = pid_match.group(1)
            diff = get_diff(pid)
            problems_seen[pid] = diff
        else:
            # 單層檔案
            if not item.endswith(".cpp"):
                continue
            name = item.replace(".cpp","")
            pid_match = re.match(r"(\d+)", name)
            if not pid_match:
                continue
            pid = pid_match.group(1)
            diff = get_diff(pid)
            problems_seen[pid] = diff

# -----------------------------
# 🔹 計算各難度題數
# -----------------------------
easy = medium = hard = 0
for diff in problems_seen.values():
    if diff == "Easy":
        easy += 1
    elif diff == "Medium":
        medium += 1
    else:
        hard += 1

# -----------------------------
# 🔹 生成 README 區塊
# -----------------------------
section = "\n" + START + "\n"
section += f"🟢 Easy: {easy} | 🟠 Medium: {medium} | 🔴 Hard: {hard}\n"
section += END + "\n"

# -----------------------------
# 🔹 寫回 README
# -----------------------------
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = re.sub(f"{START}.*?{END}", section, readme, flags=re.DOTALL)

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README updated with progress!")
