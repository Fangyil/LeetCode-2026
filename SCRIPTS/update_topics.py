import os
import re

# ==== 配置區 ====
ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_FILE = os.path.join(ROOT_DIR, "README.md")
FOLDERS = ["Array", "Graph",
           "Greedy", "HashTable", "LinkedList", "Math", "Stack", "String", "Tree"]

PROGRESS_START = "<!-- TOPICS-START -->"
PROGRESS_END = "<!-- TOPICS-END -->"
# =================

folder_counts = []

for folder in FOLDERS:
    path = os.path.join(ROOT_DIR, "TOPICS", folder)
    count = 0
    if os.path.exists(path):
        for item in os.listdir(path):
            item_path = os.path.join(path, item)
            if os.path.isdir(item_path):
                # 二層資料夾：子資料夾下的 cpp
                count += len([f for f in os.listdir(item_path) if f.endswith(".cpp")])
            elif item.endswith(".cpp"):
                # 單層資料夾：直接檔案
                count += 1
    folder_counts.append((folder, count))

# 生成 Markdown 表格
progress_lines = ["\n", PROGRESS_START, "\n",
                  "| Folder | Solved |\n",
                  "|--------|--------|\n"]
for folder, count in folder_counts:
    file_url = f"https://github.com/Fangyil/LeetCode-2026/blob/main/TOPICS/{folder}"
    if count > 0:
        progress_lines.append(f"| [{folder}]({file_url}) | {count} |\n")
    else:
        progress_lines.append(f"| {folder} | {count} |\n")
progress_lines.append(PROGRESS_END)
progress_lines.append("\n")

# 讀取 README
with open(README_FILE, "r", encoding="utf-8") as f:
    readme_content = f.read()

# 替換 Progress 區塊
pattern = re.compile(f"{PROGRESS_START}.*?{PROGRESS_END}", re.DOTALL)
if pattern.search(readme_content):
    updated_readme = pattern.sub("".join(progress_lines), readme_content)
else:
    updated_readme = readme_content + "".join(progress_lines)

# 寫回 README
with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(updated_readme)

print("🔥 README.md updated with topic progress!")
