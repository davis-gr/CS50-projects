fullText = input()


letterCount = 0
wordCount = 0
sentenceCount = 0

L = letterCount / wordCount * 100
S = sentenceCount / wordCount * 100

def count_letters(text):
    count = 0
    for i in text:
        if i.isalpha() == True:
            count += 1
    print(count)

count_letters(fullText)