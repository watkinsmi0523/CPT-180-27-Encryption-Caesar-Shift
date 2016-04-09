#include <iostream>
#include <fstream>

std::string PLAIN_TEXT_FILE = "./plain.txt";
std::string CYPHER_TEXT_FILE = "./encrypted.txt";
std::string DECYPHER_TEXT_FILE = "./decrypted.txt";
int SHIFT = 1;

char* encrypt(std::string plain_text, int shift);
char* decrypt(std::string cypher_text, int shift);
char shift_letter(char current_letter, int shift);
char unshift_letter(char current_letter, int shift);
int index_of(char letter);
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                  'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                  'Y', 'Z'};


int main(int argc, char* argv[]) {

    int shift = SHIFT;
    if(argc > 1){
        int param_shift = atoi(argv[1]);
        if(param_shift > 0 && param_shift < 27) shift = param_shift;
    }

    std::string file = PLAIN_TEXT_FILE;
    if(argc > 2) {
        std::string param_file = static_cast<std::string>(argv[2]);
        if(argv[1] != nullptr) file = param_file;
    }

    std::cout << argc << " " << argv[0] << std::endl;

    // Open the Plain File and Read the first line
    std::ifstream plain_text;
    std::string line = "";
    plain_text.open(file);
    getline(plain_text, line);
    plain_text.close();

    // Encrypt read line
    char* cypher = encrypt(line, shift);
    // Write Encrypted Text to File
    std::ofstream cypher_text;
    cypher_text.open(CYPHER_TEXT_FILE);
    cypher_text << cypher;
    cypher_text.close();

    // Test Decryption by decrypting the encrypted string
    // To a new file
    char* plain_again = decrypt(cypher, shift);
    std::ofstream plain_text_again;
    plain_text_again.open(DECYPHER_TEXT_FILE);
    plain_text_again << plain_again << std::endl;
    plain_text_again.close();
    return 0;
}

char shift_letter(char current_letter, int shift){
    int current_index = index_of(current_letter);
    int shifted = current_index + shift;

    if(shifted > 25) shifted -= 26;

    return LETTERS[shifted];
}

char unshift_letter(char current_letter, int shift){
    int current_index = index_of(current_letter);
    int unshifted = current_index - shift;

    if(unshifted < 0) unshifted += 26;

    return LETTERS[unshifted];
}

int index_of(char letter){
    for(int i = 0; i < 26; i++){
        if(LETTERS[i] == letter){
            return i;
        }
    }
    return -1;
}

char* encrypt(std::string plain_text, int shift){
    int plain_length = plain_text.size();
    char* cypher = new char[plain_length];

    for(int i = 0; i < plain_length; i++){
        cypher[i] = shift_letter(plain_text[i], shift);
    }
    return cypher;
}

char* decrypt(std::string cypher_text, int shift){
    int cypher_length = cypher_text.size();
    char* plain = new char[cypher_length];

    for(int i = 0; i < cypher_length; i++){
        plain[i] = unshift_letter(cypher_text[i], shift);
    }
    return plain;
}
