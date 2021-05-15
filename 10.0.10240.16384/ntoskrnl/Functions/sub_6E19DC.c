// sub_6E19DC 
 
int __fastcall sub_6E19DC(char a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7)
{
  return (((a7 >> (a2 % 0xF + 1)) | (a7 << (15 * (a2 / 0xF) - a2 + 31))) - *(unsigned __int16 *)(a6 + 2 * (a1 & 3)))
       * *(unsigned __int16 *)(a6 + 2 * ((a1 + (unsigned __int8)(a3 / 3) + (_BYTE)a3 + 1) & 3));
}
