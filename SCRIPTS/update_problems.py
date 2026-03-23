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

    for item in os.listdir(folder_path):
        item_path = os.path.join(folder_path, item)
        # -----------------------------
        # 判斷是檔案還是子資料夾
        # -----------------------------
        if os.path.isdir(item_path):
            # 二層資料夾情況
            pid_folder = item
            pid_match = re.match(r"(\d+)", pid_folder)
            if not pid_match:
                continue
            pid = pid_match.group(1)
            title = title_map.get(int(pid), f"Unknown-{pid}")
            diff = get_diff(pid)

            for f in os.listdir(item_path):
                if not f.endswith(".cpp"):
                    continue
                method = f.replace(".cpp","")
                problems_dict[pid].append((title, folder, diff, method, folder, pid_folder, f))
        else:
            # 單層資料夾檔案情況
            f = item
            if not f.endswith(".cpp"):
                continue
            name = f.replace(".cpp","")
            pid_match = re.match(r"(\d+)", name)
            if not pid_match:
                continue
            pid = pid_match.group(1)
            title_match = re.match(r"\d+_(.+?)(?:_[^_]+)?$", name)
            if title_match:
                title_candidate = title_match.group(1)
                title = title_map.get(int(pid), title_candidate.replace("_", " "))
            else:
                title = title_map.get(int(pid), f"Unknown-{pid}")

            parts = name.split("_")
            method = parts[-1] if len(parts) > 1 else "Unknown"
            problems_dict[pid].append((title, folder, get_diff(pid), method, folder, None, f))

# -----------------------------
# 🔹 生成 README 區塊
# -----------------------------
section = "\n" + START + "\n"
section += "| # | Title| Difficulty | Topics | Solution |\n"
section += "|---|-------|------------|------------|----------|\n"

for pid in sorted(problems_dict.keys(), key=lambda x: int(x)):
    entries = problems_dict[pid]
    title = entries[0][0]
    topics = entries[0][1]
    diff = entries[0][2]

    links = []
    seen_methods = set()
    for e in entries:
        method = e[3]
        if method in seen_methods:
            continue
        seen_methods.add(method)
        folder = e[4]
        subfolder = e[5]
        filename = e[6]

        if subfolder:
            # 二層資料夾
            file_url = f"https://github.com/Fangyil/LeetCode-2026/blob/main/TOPICS/{folder}/{subfolder}/{filename}"
        else:
            # 單層資料夾
            file_url = f"https://github.com/Fangyil/LeetCode-2026/blob/main/TOPICS/{folder}/{filename}"
        links.append(f"[{method}]({file_url})")

    # 先按方法名稱字母排序，短的在前
    links = sorted(links, key=lambda x: (re.sub(r"\[|\]\(.*\)","",x), len(x)))
    methods_str = " / ".join(links)

    slug = title.lower().replace(" ", "-")
    leetcode_link = f"https://leetcode.com/problems/{slug}/"

    section += f"| {pid} | {title} |[{color(diff)}]({leetcode_link}) | {topics} | {methods_str} |\n"

section += END + "\n"

# -----------------------------
# 🔹 寫回 README
# -----------------------------
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = re.split(f"{START}.*?{END}", readme, flags=re.DOTALL)[0] + section

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README updated with merged and sorted solutions!")
