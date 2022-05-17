import module

text = module.get_input() # get input from user
print("Before: \n", text) # what was before changes
module.file_op(text) # change the text and insert it in a file
module.dopys() #do you want to run the program again?

