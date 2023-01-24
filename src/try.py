nums = ['1','2','3','4']
sum = 0

for i in range(4):
  firstC = nums[i]
  nums.pop(i)  
  for j in range(3):
    secC = nums[j]
    nums.pop(j)
    for k in range(2):
      thirdC = nums[k]
      nums.pop(k)
      print(firstC + secC + thirdC + nums[0])
      sum += 1
      nums.insert(k, thirdC)
    nums.insert(j, secC)
  nums.insert(i, firstC)

      # print(nums[i]+nums[(i+j)%4]+nums[(i+j+k)%4]+nums[(i+j+k+l)%4])


print(sum)