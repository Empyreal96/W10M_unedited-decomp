// sub_6E1844 
 
int __fastcall sub_6E1844(char a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5, int a6, unsigned int a7)
{
  unsigned int v7; // r1

  v7 = *(unsigned __int16 *)(a6 + 2 * (((_BYTE)a2 + a1 + (unsigned __int8)(a2 / 3) + 1) & 3)) ^ a7;
  return (((v7 >> (7 * (a3 / 7) - a3 + 31)) | (v7 << (a3 % 7 + 1))) * *(unsigned __int16 *)(a6 + 2 * (a1 & 3))) ^ ((a7 >> (a4 % 0x1F + 1)) | (a7 << (31 * (a4 / 0x1F) - a4 + 31)));
}
