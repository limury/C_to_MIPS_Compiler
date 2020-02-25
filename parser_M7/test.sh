test_dir="tests"
executable="bin/printTree"
c_files=$(find $test_dir -name "*.c")

RED='\033[0;31m'
NC='\033[0m' # No Color
make clean
make
for file in $(find $test_dir -name "*.c"); do
    echo -e "\n\n${RED}Executing ${file}${NC}"
    cat $file | ./$executable
done