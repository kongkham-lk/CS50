import cs50

# Get text from user
text = cs50.get_string("Text: ")

# set initial value
l = 0
w = 1
w2 = 0
s = 0

for i in range(0, len(text)):
    # Counting number of letter
    if text[i].isalpha():
        l += 1
    # Counting number of word base on white space
    if text[i].isspace():
        w += 1
    # Counting number of sentence when there is end sentence symbols
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        s += 1
        
# Calculate the level of text
index = round(0.0588 * (l / w * 100) - 0.296 * (s / w * 100) - 15.8)

# printing the level of text for reader
if index <= 16 and index > 1:
    print(f"Grade {index}", )

elif index <= 1:
    print("Before Grade 1")

else:
    print("Grade 16+")
