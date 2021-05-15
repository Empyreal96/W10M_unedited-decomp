// ObpLookupObjectName 
 
int __fastcall ObpLookupObjectName(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, _DWORD *a11)
{
  *a11 = 0;
  *(_BYTE *)(a10 + 18) = 0;
  *(_BYTE *)(a10 + 19) = 0;
  *(_DWORD *)a10 = 0;
  *(_DWORD *)(a10 + 4) = 0;
  *(_DWORD *)(a10 + 20) = -60876;
  return sub_7FF730();
}
