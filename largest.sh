echo "Enter the number of numbers: "
read n
echo "Enter the Numbers: "
for((i=0;i<n;i++))
do
read array[i]
done

for((i=0;i<n-1;i++))
do
   for((j=0;j<n-i-1;j++))
   do
      if((array[j] > array[j+1]))
      then
         temp=${array[j]}
         array[j]=${array[j+1]}
         array[j+1]=${temp}
      fi
   done
done 

echo "Largest Number = ${array[n-1]}"
