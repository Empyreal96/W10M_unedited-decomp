// sub_6E1AAC 
 
int __fastcall sub_6E1AAC(char a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7)
{
  return ((a7 >> (a3 % 0xF + 1)) | (a7 << (15 * (a3 / 0xF) - a3 + 31)))
       + (*(unsigned __int16 *)(a6 + 2 * ((a1 + (unsigned __int8)(a2 / 3) + (_BYTE)a2 + 1) & 3)) ^ a7)
       * *(unsigned __int16 *)(a6 + 2 * (a1 & 3));
}
