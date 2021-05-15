// sub_6E1B08 
 
int __fastcall sub_6E1B08(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return a7 - *(unsigned __int16 *)(a6 + 2 * (a1 & 3)) - *(_DWORD *)(a6 + 4 * (((unsigned __int8)(a1 >> 1) - 1) & 1));
}
