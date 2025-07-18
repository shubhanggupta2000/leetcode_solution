                                   nums = [1,1,2,2,3,3]
sorting the nums in reverse order  nums = [3,3,2,2,1,1]

                3  3  2  2  1  1
           i =  0  1  2  3  4  5  (indexes)
                |__|
    
    We have two 3, so we need 2 step to convert '3 3' to '2 2'. 

               '2  2' 2  2  1  1
           i =  0  1  2  3  4  5            Total 2 step right now.
                |________|
 
    We have four 2, so we need 4 step to convert '2 2 2 2' to '1 1 1 1'.
   
               '1  1  1  1' 1  1
           i =  0  1  2  3  4  5            Total 2 + 4 = 6 step right now.
                |______________|
                 All are equal!

So we need total 6 step here to make all of them equal.

When we calculated how many value there is for 3? when there was a different value after 3

starting from i = 1, if nums[i] != nums[i-1] then we calculate total steps, total_steps = 0
   
             3  3  2  2  1  1
        i =  0  1  2  3  4  5 
                   |____ Here nums[2] != nums[1], so total_steps += the frequency of 3 = 0 + 2 = 2
    If you look closely, frequency of 3 and i are both 2, so no need to count frequency. Just add i

Now :       2  2  2  2  1  1  
       i =  0  1  2  3  4  5
                        |____ Here nums[4] != nums[3], so total_steps += i '=' 2 + 4 = 6.
    See? just add i which is working as frequency here. 