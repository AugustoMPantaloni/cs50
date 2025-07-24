text = input("Text: ")

words = text.split()
wordCount = len(words)
sentenceCount = text.count(".") + text.count("?") + text.count("!")
letterCount = sum(1 for c in text if c.isalpha())

L = letterCount / wordCount * 100
S = sentenceCount / wordCount * 100
grade = 0.0588 * L - 0.296 * S - 15.8

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")
