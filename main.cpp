# include <iostream>
 # include <fstream>
 # include <string>
 # include <vector>
 using namespace std ;
 string xorEncryptDecrypt(const string& text, char key)
{
    string result = text ;
    for (char & c : result)
     {
        c ^= key ;
}
    return result ;
    }
 int main ()
{
    string filename = "input.txt " ;
    string encryptedFile = "encrypted.txt " ;
    string decryptedFile = "decrypted.txt " ;
    char key = 'K ' ;

    ifstream inFile(filename) ;
    if (!inFile)
    {
        cerr << "Error opening input file!" <<endl ;
        return 1 ;
}
    string text ;
    string line ;
    while (getline(inFile, line))
     {
        text += line + "\n " ;
}
    inFile.close () ;
    string encryptedText =
    xorEncryptDecrypt(text, key) ;
    ofstream outFile(encryptedFile) ;
    if (!outFile)
    {
        cerr<< "Error opening encryption file!" << endl ;
        return 1 ;
}
    outFile << encryptedText ;
    (outFile.close )  ;
    cout << "The text is encrypted andsaved in " << encryptedFile << endl ;

    ifstream encFile(encryptedFile) ;
    if (!encFile)
    {
        cerr << " Error opening encryptionfile!" << endl ;
        return 1 ;
}
    string encText ;
    while (getline(encFile, line))
     {
        encText += line + "\n " ;
}
        (encFile.close )  ;

    string decryptedText =xorEncryptDecrypt(encText, key) ;

    ofstream decFile(decryptedFile) ;
    if (!decFile)
    {
        cerr << "Error opening decryptionfile!" << endl ;
        return 1 ;
}
    decFile << decryptedText ;decFile.close ) ( ;
    cout << "Decrypted and original textsaved in " << decryptedFile << endl ;
    return 0 ;
    }
