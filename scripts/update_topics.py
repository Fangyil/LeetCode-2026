# scripts/update_readme_topics.py
import os
import re

# ==== 配置區 ====
ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")
FOLDERS = ["Array", "BinarySearch", "BruteForce", "DynamicProgramming", "Graph",
           "Greedy", "HashTable", "LinkedList", "Math", "Optimized", 
           "SlidingWindow", "Stack", "String", "Tree"]

PROGRESS_START = "<!-- PROGRESS-START -->"
PROGRESS_END = "<!-- PROGRESS-END -->"
# =================

# 1️⃣ 統計每個資料夾題目數
# total_count = 0
folder_counts = []
for folder in FOLDERS:
    path = os.path.join(ROOT_DIR, folder)
    if os.path.exists(path):
        count = len([f for f in os.listdir(path) if f.endswith(".cpp")])
    else:
        count = 0
    folder_counts.append((folder, count))
    # total_count += count

# 2️⃣ 生成 Markdown 表格
progress_lines = ["\n", PROGRESS_START, "\n",
                  "| Folder | Solved |\n",
                  "|--------|--------|\n"]
for folder, count in folder_counts:
    progress_lines.append(f"| {folder} | {count} |\n")
progress_lines.append(PROGRESS_END)
progress_lines.append("\n")

# 3️⃣ 讀取 README
with open(README_FILE, "r", encoding="utf-8") as f:
    readme_content = f.read()

# 4️⃣ 替換 Progress 區塊
pattern = re.compile(f"{PROGRESS_START}.*?{PROGRESS_END}", re.DOTALL)
if pattern.search(readme_content):
    updated_readme = pattern.sub("".join(progress_lines), readme_content)
else:
    # 如果 README 沒有區塊，直接加在最後
    updated_readme = readme_content + "".join(progress_lines)

# 5️⃣ 寫回 README
with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(updated_readme)

print(f"README.md updated!")
