// -SmStAllocateVirtualRegion@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStAllocateVirtualRegion(int a1, int a2)
{
  int v2; // r5
  int result; // r0
  int v6[10]; // [sp+0h] [bp-28h] BYREF

  v2 = *(_DWORD *)(a1 + 3660);
  if ( *(_DWORD *)(v2 + 4 * a2) )
    return 0;
  memset(v6, 0, 24);
  v6[1] = *(_DWORD *)(a1 + 3652);
  result = SMKM_STORE<SM_TRAITS>::SmStHelperSendCommand(a1, 2, v6, 4);
  if ( result >= 0 )
  {
    result = v6[5];
    if ( v6[5] >= 0 )
    {
      *(_DWORD *)(v2 + 4 * a2) = v6[4];
      return 0;
    }
  }
  return result;
}
