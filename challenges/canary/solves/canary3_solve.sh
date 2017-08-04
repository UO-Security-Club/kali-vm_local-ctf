SRC_FILE="canary3_res/predict_canary.c"
BIN_FILE="canary3_res/predict_canary"
gcc -m32 $SRC_FILE -o $BIN_FILE

$BIN_FILE | ../canary3
