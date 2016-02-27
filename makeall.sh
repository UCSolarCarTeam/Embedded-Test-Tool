RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [[ $1 != "test" ]]; then
    make
    if [ $? -eq 0 ]; then
        printf "\n${GREEN}|*******| SOURCE COMPILATION SUCCESSFUL |*******|${NC}\n\n"
    else
        printf "\n${RED}|*******| SOURCE COMPILATION FAILED |*******|${NC}\n\n"
        exit 1
    fi
fi

make -C ./test
if [ $? -eq 0 ]; then
    printf "\n${GREEN}|*******| TEST COMPILATION SUCCESSFUL |*******|${NC}\n\n"
else
    printf "\n${RED}|*******| TEST COMPILATION FAILED |*******|${NC}\n\n"
    exit 1
fi

./test/RunTests
