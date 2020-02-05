# Bobble.AI
Bobble AI Challenge


The three assigments are in there respective folders.

# Permutations
This is a python program(main.py)
Also file2.csv is the csv file having the characters.
You can modify the csv file.

To run :  ```python main.py file2.csv```

**Sample Image**
![permutation](https://github.com/kshubham506/Bobble.AI/blob/master/readmeimages/permutation.png)


# Word Suggestion
This is a python program(main.py)
Also file2.csv is the csv file having the words separated by comma.
You can modify the csv file.

To run first go inside the folder word suggestion then run in terminal :  ```python main.py file2.csv help```

This program uses the SequenceMatcher library(from difflib) to match the incorrect word with all the words in the file in order to find the best possible suggestion.

**Sample Image**
![wordsuggestoion](https://github.com/kshubham506/Bobble.AI/blob/master/readmeimages/word_suggestion.png)


# CharacterTree
This is a C++ program(main.cpp)
Also file2.csv is the csv file having the words separated by comma.
You can modify the csv file and add as many words as you want.

To run first go inside the folder CharacterTree then in terminal type :  ```g++ -o main main.cpp``` to compile.
Then to serialize : ```./main create file2.csv output.bin```
and to load : ```./main load output.bin```

**Sample Image**
![wordsuggestoion](https://github.com/kshubham506/Bobble.AI/blob/master/readmeimages/charactertree.png)
