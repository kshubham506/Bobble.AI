# -*- coding: utf-8 -*-
"""
By : kshubham506@gmail.com
@author: kshubham506
"""

import sys
import itertools
import csv


file_name=sys.argv[1]
#file_name="file2.csv"

print("Contents of file : ",file_name)

a=[]

#read the csv file nad store the contents in list a
with open(file_name, 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        print(", ".join((map(str,row))))
        a.append(row)

print("\nOutput Strings :")

#using itertools to print all the permutations
permutedStrings=["".join(x) for x in itertools.product(*a)]

print(", ".join((map(str,permutedStrings))))



  
