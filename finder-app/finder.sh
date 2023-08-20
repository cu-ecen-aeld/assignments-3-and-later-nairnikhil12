if [ "$#" -ne 2 ]; then 
    echo "Error: Expected 2 arguments."
    exit 1
fi  

if [ ! -d "$1" ]; then
    echo "Error: $1 is not a valid directory."
    exit 1
fi


files=$(grep -Rl "$2" $1)
X=$(echo "$files" | wc -l)

Y=0
for file in $files
do
    Y=$(($Y + $(grep -RFc "$2" $file)))
done

echo "The number of files are $X and the number of matching lines are $Y"