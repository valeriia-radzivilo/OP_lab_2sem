def get_input(): #get input from user
    print("Enter a text. Tap enter twice to stop input")
    lines = []
    while True:
        line = input()
        if line:
            lines.append(line)
        else:
            break
    text = '\n'.join(lines)
    return text

def file_op(text): #open and edit file
    usText = open("Text_py.txt", "a+")
    usText.write(changed_text(text))
    usText.write("\n")
    usText.close()
    print("Done")

def changed_text(text): # change the text
    us_len = int(input("Enter the length: "))
    lines = text.split("\n")
    newtext=""
    for line in lines:

        length = len(line)
        if length < us_len:
            words = line.split(" ")
            spaces = line.count(" ")
            add = us_len - length
            need_more = int(add / spaces)
            check = add / spaces
            for x in words:
                if add > 0:
                    newtext += x
                    if words.index(x) != len(words) - 1:
                        newtext += ' ' * (need_more+1)


        else:
            newtext += line

        newtext += "\n"
    print("After: \n", newtext)
    return newtext

def dopys(): #to re-run the program
    while True:
        answ = input("Press yes if you want to add and no if you don`t:  ")
        if answ == "yes":
            text = get_input()
            file_op(text)
        if answ != "yes":
            break



