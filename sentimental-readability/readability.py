fullText = input("Text: ")

def count_letters(text):
    letterCount = 0
    for i in text:
        if i.isalpha() == True:
            letterCount += 1
    return letterCount

def count_words(text):
    wordCount = 0
    for i in text:
        if i.isspace() == True:
            wordCount += 1
    wordCount += 1
    return wordCount+1

def count_sentences(text):
    sentenceCount = 0
    for i in text:
        if i == chr(46) or i == chr(33) or i == chr(63):
            sentenceCount += 1
    return sentenceCount

L = count_letters(fullText) / count_words(fullText) * 100
S = count_sentences(fullText) / count_words(fullText) * 100