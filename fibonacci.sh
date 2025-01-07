echo "Enter the Number:"
read n
x=0
y=1
echo "Fibonacci Series = "
for((i=0;i<=n;i++))
do
  echo $x
  f=$(($x+$y))
  x=$y
  y=$f
done
