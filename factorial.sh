echo "Enter the Number: "
read n
fact=1
for((i=1;i<=n;i++))
do
   fact=$(($i*$fact))
   
done
echo "Factorial of "$n" = "$fact
