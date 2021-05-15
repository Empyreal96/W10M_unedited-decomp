// sub_6E1D44 
 
int __fastcall sub_6E1D44(unsigned int a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, unsigned int a7)
{
  unsigned int v7; // r7

  v7 = *(_DWORD *)(a6 + 4 * (((unsigned __int8)(a1 >> 1) - 1) & 1)) - a7;
  return (((v7 >> (a3 % 0x1F + 1)) | (v7 << (31 * (a3 / 0x1F) - a3 + 31))) * *(unsigned __int16 *)(a6 + 2 * (a1 & 3))) ^ ((a7 << (31 * (a4 / 0x1F) - a4 + 31)) | (a7 >> (a4 % 0x1F + 1)));
}
