// sub_6E20BC 
 
int __fastcall sub_6E20BC(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return *(_DWORD *)(a6 + 4 * ((a1 - 1) & 1)) ^ *(_DWORD *)(a6 + 4 * (a1 & 1)) ^ a7;
}
