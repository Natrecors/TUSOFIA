nums = []
for i in range(5):
    n= int(input("chislo"))
    nums.append(n)
sum_nums = sum(nums)

even_nums = []
for y in nums:
    if y % 2 == 0:
        even_nums.append(y)

        
avarage = sum_nums / len(nums)


print(nums)
print(sum_nums)
print(even_nums)
print(even_nums[0])