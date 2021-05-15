// -StReleaseRegion@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StReleaseRegion(int result, unsigned int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r3
  int v6[4]; // [sp+10h] [bp-10h] BYREF

  v3 = result;
  if ( *(_BYTE *)(result + 72) )
  {
    *(_BYTE *)(*(_DWORD *)(result + 312) + a2) = 0;
  }
  else
  {
    v4 = *(_DWORD *)(result + 92);
    if ( (*(_BYTE *)(v4 + 3517) & 4) != 0 )
    {
      result = SMKM_STORE<SM_TRAITS>::SmStReleaseVirtualRegion(v4, a2, 0);
    }
    else
    {
      SMKM_STORE<SM_TRAITS>::SmStReleasePhysicalRegion(v4, a2);
      result = 0;
    }
    if ( result == -1073741650 )
      result = ST_STORE<SM_TRAITS>::StDmUpdateRegionLazyCleanup(v3, a2, 1);
    if ( (dword_636E9C & 0x10) != 0 )
      result = SmEtwLogRegionOp(&unk_636E90, 5, v3, a2, 0, *(_WORD *)(*(_DWORD *)(v3 + 304) + 2 * a2) & 0x1FFF, 0);
  }
  if ( *(_BYTE *)(v3 + 72) )
    v5 = 0;
  else
    v5 = *(unsigned __int16 *)(*(_DWORD *)(v3 + 304) + 2 * a2) >> 13;
  --*(_DWORD *)(v3 + 8 * v5 + 684);
  if ( !*(_BYTE *)(v3 + 72) )
    *(_WORD *)(*(_DWORD *)(v3 + 304) + 2 * a2) &= 0x1FFFu;
  if ( (*(_DWORD *)(v3 + 116) & 4) != 0 )
  {
    result = ST_STORE<SM_TRAITS>::StDmGetSpaceStats(v3, v6, 0);
    if ( (unsigned int)(*(_DWORD *)(v3 + 128) - v6[0]) >= 8 && (*(_DWORD *)(v3 + 976) & 1) == 0 )
    {
      *(_DWORD *)(v3 + 964) = 0;
      *(_DWORD *)(v3 + 976) |= 1u;
      result = SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(*(_DWORD *)(v3 + 92), v3 + 952, 6);
    }
  }
  return result;
}
