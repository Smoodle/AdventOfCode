import fileinput
import time
import re
from queue import Queue

t = time.process_time()
bags = {}

#Parse data
for line in fileinput.input():
    line = line.replace(".\n", "").strip()
    split_bags = line.split(" bags contain ")

    bags[split_bags[0]] = []

    if "no other bags" in split_bags[1]:
        continue

    for elem in split_bags[1].replace(" bags", "").replace(" bag", "").split(", "):
        bags[split_bags[0]].append({ re.sub(r"\d+ ", "", elem) : int(re.findall(r"\d+", elem)[0]) })


#Parte 1
def count_bags(color, bags):
    can_contain = set()
    bags_to_search = Queue()
    bags_to_search.put(color)

    while not bags_to_search.empty():
        color_to_search = bags_to_search.get()

        for key, value in bags.items():
            if key == color:
                continue

            for val in value:
                for k, _ in val.items():
                    if k == color_to_search:
                        can_contain.add(key)
                        bags_to_search.put(key)

    return len(can_contain)

#Parte 2
def count_sub_bags(color, bags):
    bags_to_search = Queue()
    bags_to_search.put(color)
    total_bags = 0

    while bags_to_search.empty() == False:
        color_to_search = bags_to_search.get()

        for values in bags[color_to_search]:
            for k,v in values.items():
                total_bags += v
                for _ in range(v):
                    bags_to_search.put(k)

    return total_bags

print(count_bags("shiny gold", bags))
print(count_sub_bags("shiny gold", bags))
