/*--------------------------------------------------
функция AnsiToChar предназначена для
перевода строк из типа AnsiString в char *
--------------------------------------------------*/
#include <vcl.h>

char *AnsiToChar(AnsiString string_a)
{
        char *string_c;//указатель на имя файла типа char
        unsigned int length_string;//длина имени файла

        length_string=string_a.Length();//определить длину имени файла, заданной переменной string_a

        string_c=new char[length_string+1];//выделить память под имя файла в формате char (дополнительный символ - признак окончания строки)
        for(unsigned int i=0;i<length_string;i++)//посимвольное копирование имени файла из переменной string_a в string_c
                string_c[i]=string_a[i+1];
        string_c[length_string]=NULL;//последний символ - признак окончания строки
        return string_c;//возвратить имя файла типом char
}
 