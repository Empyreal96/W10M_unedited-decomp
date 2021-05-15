// -StUnlockAndUnmapRegion@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@KPAD@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(int a1, int a2, int a3)
{
  int v4; // r0
  int v6; // r2
  int v7; // r1
  int v8; // r3
  int result; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r1
  int v14; // [sp+0h] [bp-18h]

  v14 = a2;
  v4 = *(_DWORD *)(a1 + 92);
  if ( (*(_BYTE *)(v4 + 3517) & 4) != 0 )
  {
    SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion((_DWORD *)v4, a2, a3, 1, a2, 1u);
  }
  else
  {
    v6 = *(_DWORD *)(v4 + 3660);
    v7 = *(_DWORD *)(v6 + 4 * a2);
    *(_DWORD *)(v6 + 4 * a2) = v7 & 0xFFFFFFFE;
    if ( (v7 & 2) == 0 )
      SmFpFree(v4 + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v7 & 0xFFFFFFF8);
  }
  if ( *(_BYTE *)(a1 + 72) )
    v8 = 0;
  else
    v8 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * a2) >> 13;
  result = *(_DWORD *)(a1 + 92);
  v10 = (8 * v8) | 4;
  v11 = *(unsigned __int8 *)(result + 3517);
  if ( (v11 & 4) != 0 )
    return SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion((_DWORD *)result, a2, v10, v11, v14, v10);
  v12 = *(_DWORD *)(result + 3660);
  v13 = *(_DWORD *)(v12 + 4 * a2);
  *(_DWORD *)(v12 + 4 * a2) = v13 & 0xFFFFFFFD;
  if ( (v13 & 1) == 0 )
    result = SmFpFree(result + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v13 & 0xFFFFFFF8);
  return result;
}
