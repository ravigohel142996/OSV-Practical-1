echo "Calculating simple Interest Rate"
echo "Enter the Principal Amount"
read Principal
echo "Enter Annual Interest Rate"
read Rate
echo "Enter the Time period"
read Time

echo $(((Principal*Rate*Time)/100))


echo "Enter any number and check fot it is positive or negative or zero: "
read number
if [ $number -lt 0 ]; then
    echo "$number is negative"
elif [ $number -gt 0 ]; then
    echo "$number is positive"
else
    echo "$number is zero"
fi
echo "-------------------------------------------"
echo "Enter Student Details"
echo "Enter the name:"
read name
echo "Enter Roll number:"
read Roll
echo "Enter marks of subject 1:"
read m1
echo "Enter marks of subject 2:"
read m2
echo "Enter marks of subject 3:"
read m3

total=$((m1 + m2 + m3))
percent=$(($total / 3))

echo "Name: $name"
echo "Roll No: $Roll"
echo "Total marks: $total"
echo "Percentage: $percent %"
if [ $percent -gt 70 ]
then
    echo "Distinction"
elif [ $percent -gt 60 ]
then
    echo "Class: First Class"
elif [ $percent -gt 50 ]
then
    echo "Class: Second Class"
else
    echo "Class: Fail"
fi
