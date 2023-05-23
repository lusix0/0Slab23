echo "1.add"
echo "2.subtract"
echo "3.multiply"
echo "4.divide"
echo "Enter your choice"
read i
echo "Enter two numbers"
read a
read b
case $i in
1) x=`expr $a + $b`
echo "The sum is $x";;
2) x=`expr $a - $b`
echo "The result is $x";;
3) x=`expr $a \* $b`
echo "The product is $x";;
4) x=`expr $a / $b`
echo "The result is $x";;
esac
