from cs50 import get_string
letter = 0
word = 1
sentence = 0

text = get_string("Text: ")
r = len(text)

for i in range(r): 
    if text[i].isalnum() or text[i].isupper() or text[i].islower() == True: 
        letter = letter+1
for i in range(r):
    if text[i].isspace() == True:
        word = word+1
for i in range(r):
    if text[i]=="?" or text[i]=="." or text[i]=="!":
        sentence = sentence+1
grade = round (0.0588 * ((100 * letter) / word) - 0.296 * ((100 * sentence) / word) - 15.8)
if grade < 1:
    print("Before Grade 1")
elif grade < 16:
    print(f"Grade {grade}")
else:
    print("Grade 16+");