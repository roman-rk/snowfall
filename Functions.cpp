/*--------------------------------------------------
������� AnsiToChar ������������� ���
�������� ����� �� ���� AnsiString � char *
--------------------------------------------------*/
#include <vcl.h>

char *AnsiToChar(AnsiString string_a)
{
        char *string_c;//��������� �� ��� ����� ���� char
        unsigned int length_string;//����� ����� �����

        length_string=string_a.Length();//���������� ����� ����� �����, �������� ���������� string_a

        string_c=new char[length_string+1];//�������� ������ ��� ��� ����� � ������� char (�������������� ������ - ������� ��������� ������)
        for(unsigned int i=0;i<length_string;i++)//������������ ����������� ����� ����� �� ���������� string_a � string_c
                string_c[i]=string_a[i+1];
        string_c[length_string]=NULL;//��������� ������ - ������� ��������� ������
        return string_c;//���������� ��� ����� ����� char
}
 