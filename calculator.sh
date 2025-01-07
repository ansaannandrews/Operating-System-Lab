echo "Enter 1st number:"
read x
echo "Enter 2st number:"
read y
echo "Enter the serial number to perform following Operations:"
echo "1.Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read opr
case $opr in
1)rs=$(($x+$y))
echo $x" + "$y" = "$rs;;
2)rs=$(($x-$y))
echo $x" - "$y" = "$rs;;
3)rs=$(($x*$y))
echo $x" * "$y" = "$rs;;
4)rs=$(($x/$y))
echo $x" / "$y" = "$rs;;
*)echo "Invalid choice";;
esac


