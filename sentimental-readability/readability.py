fullText = input()


#S = sentenceCount / wordCount * 100

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
    return wordCount


#count_sentences(fullText)

L = count_letters(fullText) / count_words(fullText) * 100