from functools import cmp_to_key

class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        # 1. Convert all integers to strings
        num_strs = [str(num) for num in nums]
        
        # 2. Define custom comparator 
        # Returns negative if x should come before y (meaning x+y > y+x)
        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
        
        # 3. Sort string list using the custom key
        num_strs.sort(key=cmp_to_key(compare))
        
        # 4. Join the sorted strings
        result = "".join(num_strs)
        
        # 5. Handle edge case: if the array contains only zeros (e.g. [0, 0]), 
        # result becomes "00". We must return "0".
        return "0" if result[0] == "0" else result
