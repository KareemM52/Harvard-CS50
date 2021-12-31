from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()
with open(argv[2]) as dnapplfile:
    dnareader = reader(dnapplfile)
    for row in dnareader:
        dnalist = row
dna = dnalist[0]
seq = {}
with open(argv[1]) as dnafile:
    people = reader(dnafile)
    for row in people:
        dnaseq = row
        dnaseq.pop(0)
        break
for item in dnaseq:
    seq[item] = 1
for key in seq:
    l = len(key)
    tmpM = 0
    tmp = 0
    for i in range(len(dna)):
        while tmp > 0:
            tmp -= 1
            continue
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                tmp += 1
                i += l
            if tmp > tmpM:
                tmpM = tmp
    seq[key] += tmpM
with open(argv[1], newline='') as pplfile:
    people = DictReader(pplfile)
    for person in people:
        match = 0
        for dna in seq:
            if seq[dna] == int(person[dna]):
                match += 1
        if match == len(seq):
            print(person['name'])
            exit()

    print("No match")