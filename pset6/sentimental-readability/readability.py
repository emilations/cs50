from cs50 import get_string


def main():
    para = get_string("Text: ")

    # Initialize the variables and then calculate index
    numletter = cletters(para)
    numwords = cwords(para)
    numsent = csent(para)
    L = 100 * (numletter / numwords)
    S = 100 * (numsent / numwords)
    # Calculate index
    index = round((0.0588 * L) - (0.296 * S) - 15.8)

    # Check what kind of message to return
    if index < 1:
        print("Before Grade 1")
    if index >= 16:
        print("Grade 16+")
    else:
        print("Grade ", index)


def cletters(para):
    # Count the number of letters
    num_letters = 0
    for c in para:
        if c.isalpha():
            num_letters += 1
    return num_letters


def cwords(para):
    # Count the number of words
    num_words = 1
    for c in para:
        if c == " ":
            num_words += 1
    return num_words


def csent(para):
    # count number of sentences
    num_sent = 0
    for c in para:
        if c == "!" or c == "?" or c == ".":
            num_sent += 1
    return num_sent


main()