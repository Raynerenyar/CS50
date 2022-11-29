from cs50 import get_string
import re

text = get_string("Text ")

# get each word in list
splitTextList = re.split("""[.,"!?\s\n]+""", text)
splitTextList.pop()

letterCount = 0
# get letter count
for word in splitTextList:
    letters = [letter for letter in word]
    if ("'" in letters):
        letters.pop(letters.index("'"))
    letterCount += len(letters)
wordCount = len(splitTextList)
sentenceCount = re.findall("""[.!?]""", text)
sentenceCount = len(sentenceCount)
index = 0.0588 * (letterCount / wordCount * 100) - 0.296 * (sentenceCount / wordCount * 100) - 15.8
index = round(index)

# grading based on index
if (index > 16):
    print("Grade 16+")
elif (index < 1):
    print("Before Grade 1")
else:
    print("Grade " + str(index))