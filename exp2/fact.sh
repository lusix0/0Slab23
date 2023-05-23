echo "Factorial of the given number"
echo "Enter the number"
read a
fact=1
n=$a
if [ $a -eq 0 ]
then
echo "Factorial of 0 is 1"
else
while [ $a -gt 0 ]
do
fact=`expr $fact \* $a`
a=`expr $a - 1`
done
echo "Factorial of $n is $fact"
fi
