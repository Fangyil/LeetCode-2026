import os
import re
import requests

ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")

FOLDERS = ["Array","BinarySearch","BruteForce","DynamicProgramming","Graph",
           "Greedy","HashTable","LinkedList","Math","Optimized",
           "SlidingWindow","Stack","String","Tree"]

START = "<!-- PROBLEMS-START -->"
END = "<!-- PROBLEMS-END -->"

# 🔗 抓 LeetCode 題目資料
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

problems = []
easy = medium = hard = 0

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
        method = parts[-1]   # 最後一個當 method

        # 自動補 difficulty
        difficulty = get_diff(pid)

        # 統計
        if difficulty == "Easy": easy += 1
        elif difficulty == "Medium": medium += 1
        else: hard += 1

        # Title spacing
        title = re.sub(r'([a-z])([A-Z])', r'\1 \2', title)

        # 🔗 link
        slug = title.lower().replace(" ", "-")
        link = f"https://leetcode.com/problems/{slug}/"

        problems.append((int(pid), pid, title, difficulty, method, link))

problems.sort()

# ==== README 區塊 ====
section = "\n" + START + "\n"

section += f"**Total:** {len(problems)}  \n"
section += f"🟢 Easy: {easy} | 🟠 Medium: {medium} | 🔴 Hard: {hard}\n\n"

section += "| # | Title | Difficulty | Solution |\n"
section += "|---|-------|------------|----------|\n"

for _, pid, title, diff, method, link in problems:
    section += f"| {pid} | [{title}]({link}) | {color(diff)} | {method} |\n"

section += END + "\n"

with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = re.sub(f"{START}.*?{END}", section, readme, flags=re.DOTALL)

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README updated with auto difficulty!")
