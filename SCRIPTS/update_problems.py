import os
import requests
from collections import defaultdict

# -----------------------------
# 路徑設定
# -----------------------------
ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")
TOPICS_DIR = os.path.join(ROOT_DIR, "TOPICS")

START = "<!-- PROBLEMS-START -->"
END = "<!-- PROBLEMS-END -->"

# -----------------------------
# 🔗 抓 LeetCode 題目資料
# -----------------------------
print("Fetching LeetCode data from LeetCode API...")
url = "https://leetcode.com/api/problems/all/"
data = requests.get(url).json()

difficulty_map = {}
title_map = {}

for item in data["stat_status_pairs"]:
    qid = item["stat"]["frontend_question_id"]
    level = item["difficulty"]["level"]
    title = item["stat"]["question__title"]
    difficulty_map[qid] = level
    title_map[qid] = title

def get_diff(qid):
    level = difficulty_map.get(int(qid), 2)
    return ["Easy", "Medium", "Hard"][level-1]

def color(diff):
    return {
        "Easy": "![Easy](https://img.shields.io/badge/%20Easy%20-green)",
        "Medium": "![Medium](https://img.shields.io/badge/Medium-orange)",
        "Hard": "![Hard](https://img.shields.io/badge/%20Hard%20-red)"
    }[diff]

# -----------------------------
# 🔹 整理檔案資料
# -----------------------------
problems_dict = defaultdict(list)  # key=pid, value=[(title, diff, method, folder, filename)]

for folder in os.listdir(TOPICS_DIR):
    folder_path = os.path.join(TOPICS_DIR, folder)
    if not os.path.isdir(folder_path):
        continue

    for pid_folder in os.listdir(folder_path):
        pid_path = os.path.join(folder_path, pid_folder)
        if not os.path.isdir(pid_path):
            continue

        pid = pid_folder
        title = title_map.get(int(pid), f"Unknown-{pid}")
        diff = get_diff(pid)

        for f in os.listdir(pid_path):
            if not f.endswith(".cpp"):
                continue
            method = f.replace(".cpp", "")
            problems_dict[pid].append((title, diff, method, folder, f))

# -----------------------------
# 🔹 生成 README 區塊
# -----------------------------
section = "\n" + START + "\n"

section += "| # | Title | Difficulty | Solution |\n"
section += "|---|-------|------------|----------|\n"

for pid in sorted(problems_dict.keys(), key=lambda x: int(x)):
    entries = problems_dict[pid]
    title = entries[0][0]
    diff = entries[0][1]

    seen = set()
    links = []
    for e in entries:
        method = e[2]
        if method in seen:
            continue
        seen.add(method)
        folder = e[3]
        filename = e[4]
        file_url = f"https://github.com/Fangyil/LeetCode-2026/blob/main/TOPICS/{folder}/{pid}/{filename}"
        links.append(f"[{method}]({file_url})")
    methods = " / ".join(links)

    # 使用 API title 與 colored difficulty
    slug = title.lower().replace(" ", "-")
    leetcode_link = f"https://leetcode.com/problems/{slug}/"

    section += f"| {pid} | [{title}]({leetcode_link}) | {color(diff)} | {methods} |\n"

section += END + "\n"

# -----------------------------
# 🔹 寫回 README
# -----------------------------
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = readme.split(START)[0] + section + readme.split(END)[1]

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README updated with merged solutions!")
