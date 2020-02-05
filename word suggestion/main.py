# -*- coding: utf-8 -*-
"""
By : kshubham506@gmail.com
@author: kshubham506
"""
from difflib import SequenceMatcher
import sys
import csv


file_name=sys.argv[1]
mispelled_word=sys.argv[2]
#file_name="file2.csv"
#mispelled_word="you"

print("Contents of file : ",file_name)
a=[]
with open(file_name, 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        print(", ".join((map(str,row))))
        a.append(row)

suggestions=[]
for i in range(len(a)):
    matchRatio=SequenceMatcher(None, mispelled_word,a[i][0]).ratio()
    field=[a[i][0],matchRatio]    
    suggestions.append(field)
    

suggestions.sort(key = lambda x: x[1],reverse=True) 
#print(suggestions)
if len(suggestions)>=5:
    rangeTill=5
else:
    rangeTill=len(suggestions)
topsuggestions=[]
for i  in range(rangeTill):
    topsuggestions.append(suggestions[i][0])


print("\nTop Suggestions :")
print(", ".join((map(str,topsuggestions))))
    
    

        