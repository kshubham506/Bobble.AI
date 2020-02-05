# -*- coding: utf-8 -*-
"""
By : kshubham506@gmail.com
@author: kshubham506
"""

import sys
import csv



def createPermutations(arr): 
    print("\nOutput Strings :")
    n = len(arr) 
    indices = [0 for i in range(n)] 
    while (1):  
        for i in range(n): 
            print(arr[i][indices[i]], end = "") 
        print() 
        next = n - 1
        while (next >= 0 and 
              (indices[next] + 1 >= len(arr[next]))): 
            next-=1
            
        if (next < 0): 
            return
  
        indices[next] += 1

        for i in range(next + 1, n): 
            indices[i] = 0
            
            

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

#call the create permutation function
createPermutations(a) 



  
