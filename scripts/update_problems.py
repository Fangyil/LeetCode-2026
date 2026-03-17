import os
import re

ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")

FOLDERS = ["Array","BinarySearch","BruteForce","DynamicProgramming","Graph",
           "Greedy","HashTable","LinkedList","Math","Optimized",
           "SlidingWindow","Stack","String","Tree"]

START = "<!-- PROBLEMS-START -->"
END = "<!-- PROBLEMS-END -->"

problems = []

easy = medium = hard = 0

# 🎨 顏色
def color(diff):
    if diff == "Easy":
        return "🟢 Easy"
    elif diff == "Medium":
        return "🟠 Medium"
    else:
        return "🔴 Hard"

for folder in FOLDERS:
    path = os.path.join(ROOT_DIR, folder)
    if not os.path.exists(path):
        continue

    files = [f for f in os.listdir(path) if f.endswith(".cpp")]

    for f in files:
        name = f.replace(".cpp","")
        parts = name.split("_")

        if len(parts) < 4:
            continue

        pid = parts[0]
        title = parts[1]
        difficulty = parts[2]
        method = parts[3]

        # Title 加空格
        title = re.sub(r'([a-z])([A-Z])', r'\1 \2', title)

        # 統計
        if difficulty == "Easy":
            easy += 1
        elif difficulty == "Medium":
            medium += 1
        elif difficulty == "Hard":
            hard += 1

        # 🔗 LeetCode link
        slug = title.lower().replace(" ", "-")
        link = f"https://leetcode.com/problems/{slug}/"

        problems.append((int(pid), pid, title, difficulty, method, link))

# 排序
problems.sort()

# ==== 生成 README 區塊 ====
section = "\n" + START + "\n"

# 📊 統計
section += f"**Total:** {len(problems)}  \n"
section += f"🟢 Easy: {easy} | 🟠 Medium: {medium} | 🔴 Hard: {hard}\n\n"

# 📋 表格
section += "| # | Title | Difficulty | Solution |\n"
section += "|---|-------|------------|----------|\n"

for _, pid, title, diff, method, link in problems:
    section += f"| {pid} | [{title}]({link}) | {color(diff)} | {method} |\n"

section += END + "\n"

# ==== 寫回 README ====
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

readme = re.sub(f"{START}.*?{END}", section, readme, flags=re.DOTALL)

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(readme)

print("🔥 README problem table updated!")
