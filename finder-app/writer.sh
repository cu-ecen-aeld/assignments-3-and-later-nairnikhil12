if [ "$#" -ne 2 ]; then 
    echo "Error: Expected 2 arguments."
    exit 1
fi  

mkdir -p "$(dirname $1)"

if [ $(echo "$2" > $1) ]; then
    echo "Error: Cannot create file."
fi
