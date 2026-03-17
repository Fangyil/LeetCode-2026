import os
import re
import requests
from collections import defaultdict

ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")

FOLDERS = ["Array","BinarySearch","BruteForce","DynamicProgramming","Graph",
           "Greedy","HashTable","LinkedList","Math","Optimized",
           "SlidingWindow","Stack","String","Tree"]

START = "<!-- PROBLEMS-START -->"
END = "<!-- PROBLEMS-END -->"

# -----------------------------
# 🔗 抓 LeetCode 題目資料
# -----------------------------
print("Fetching LeetCode data...")
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

def color(diff):
    return {
        "Easy": "🟢 Easy",
        "Medium": "🟠 Medium",
        "Hard": "🔴 Hard"
    }[diff]

# -----------------------------
# 🔹 整理檔案
# -----------------------------
problems_dict = defaultdict(list)  # key=ID, value=[(title, diff, method, link)]

for folder in FOLDERS:
    path = os.path.join(ROOT_DIR, folder)
    if not os.path.exists(path):
        continue

    for f in os.listdir(path):
        if not f.endswith(".cpp"):
            continue

        name = f.replace(".cpp","")
        parts = name.split("_")
        if len(parts) < 2:
            continue

        pid = parts[0]
        title = parts[1]
        method = parts[-1]  # 最後一個當 method

        # 自動補 difficulty
        difficulty = get_diff(pid)

        # Title 格式化
        title_fmt = re.sub(r'([a-z])([A-Z])', r'\1 \2', title)

        # 🔗 生成 LeetCode link
        slug = title_fmt.lower().replace(" ", "-")
        link = f"https://leetcode.com/problems/{slug}/"

        # 存進 dict
        problems_dict[pid].append((title_fmt, difficulty, method, link))

# -----------------------------
# 🔹 生成 README 區塊
# -----------------------------
section = "\n" + START + "\n"

total = len(problems_dict)
easy = medium = hard = 0

section += f"**Total:** {total}  \n"

# 先排序 ID
for pid in problems_dict:
    # 取第一個題目的 difficulty（全部方法同一題目，diff 一致）
    diff = problems_dict[pid][0][1]
    if diff == "Easy": easy += 1
    elif diff == "Medium": medium += 1
    else: hard += 1

section += f"🟢 Easy: {easy} | 🟠 Medium: {medium} | 🔴 Hard: {hard}\n\n"

section += "| # | Title | Difficulty | Solution |\n"
section += "|---|-------|------------|----------|\n"

for pid in sorted(problems_dict.keys(), key=lambda x: int(x)):
    entries = problems_dict[pid]
    title = entries[0][0]
    diff = entries[0][1]
    link = entries[0][3]
    methods = " / ".join([e[2] for e in entries])
    section += f"| {pid} | [{title}]({link}) | {color(diff)} | {methods} |\n"

section += END + "\n"

# -----------------------------
# 🔹 寫回 README
# -----------------------------
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = re.sub(f"{START}.*?{END}", section, readme, flags=re.DOTALL)

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README updated with merged solutions!")
