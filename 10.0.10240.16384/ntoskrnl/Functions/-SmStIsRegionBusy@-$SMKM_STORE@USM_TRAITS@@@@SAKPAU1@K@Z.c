// -SmStIsRegionBusy@-$SMKM_STORE@USM_TRAITS@@@@SAKPAU1@K@Z 
 
BOOL __fastcall SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(int a1, int a2)
{
  _WORD *v2; // r2

  v2 = (_WORD *)(*(_DWORD *)(a1 + 3660) + 4 * a2);
  return (*v2 & 0x7FFF) != 0 || *(_WORD **)(a1 + 3864) == v2;
}
