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

for folder in FOLDERS:

    path = os.path.join(ROOT_DIR,folder)

    if not os.path.exists(path):
        continue

    files = sorted([f for f in os.listdir(path) if f.endswith(".cpp")])

    for f in files:

        name = f.replace(".cpp","")
        problems.append(f"- {name}")

section = "\n"+START+"\n"

for p in problems:
    section += p+"\n"

section += END+"\n"

with open(README_FILE,"r",encoding="utf-8") as f:
    readme = f.read()

readme = re.sub(f"{START}.*?{END}",section,readme,flags=re.DOTALL)

with open(README_FILE,"w",encoding="utf-8") as f:
    f.write(readme)

print("Problem list updated!")
