fullText = input("Text: ")

def count_letters(text):
    letterCount = 0
    for i in text:
        if i.isalpha() == True:
            letterCount += 1
    print(letterCount)
    return letterCount

def count_words(text):
    wordCount = 0
    for i in text:
        if i.isspace() == True:
            wordCount += 1
    print(wordCount)
    wordCount += 1
    return wordCount

def count_sentences(text):
    

L = count_letters(fullText) / count_words(fullText) * 100
S = count_sentences(fullText) / count_words(fullText) * 100