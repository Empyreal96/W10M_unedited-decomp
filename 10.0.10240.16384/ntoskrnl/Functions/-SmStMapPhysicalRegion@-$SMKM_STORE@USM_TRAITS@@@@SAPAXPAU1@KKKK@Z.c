// -SmStMapPhysicalRegion@-$SMKM_STORE@USM_TRAITS@@@@SAPAXPAU1@KKKK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStMapPhysicalRegion(int a1, int a2, int a3, int a4, char a5)
{
  int v5; // r5
  int v7; // r3
  int result; // r0
  int v10; // r3
  int v11; // r3

  v5 = *(_DWORD *)(a1 + 3660);
  v7 = *(_DWORD *)(v5 + 4 * a2);
  if ( (v7 & 3) != 0 )
  {
    result = *(_DWORD *)((v7 & 0xFFFFFFF8) + 12);
  }
  else
  {
    result = SmFpAllocate(a1 + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v7 & 0xFFFFFFF8);
    if ( !result )
      return result;
  }
  v10 = *(_DWORD *)(v5 + 4 * a2);
  if ( (a5 & 0x10) != 0 )
    v11 = v10 | 2;
  else
    v11 = v10 | 1;
  *(_DWORD *)(v5 + 4 * a2) = v11;
  result += a3;
  return result;
}
