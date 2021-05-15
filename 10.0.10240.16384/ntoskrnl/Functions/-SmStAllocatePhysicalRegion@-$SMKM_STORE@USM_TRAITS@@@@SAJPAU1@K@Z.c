// -SmStAllocatePhysicalRegion@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStAllocatePhysicalRegion(int a1, int a2)
{
  int v2; // r5
  int v4; // r0

  v2 = *(_DWORD *)(a1 + 3660);
  v4 = MmAllocatePagesForMdlEx(0, 0, -1, -1, 0, 0, *(_DWORD *)(a1 + 3652), 1, 13);
  if ( !v4 )
    return -1073741670;
  *(_DWORD *)(v2 + 4 * a2) = v4;
  return 0;
}
