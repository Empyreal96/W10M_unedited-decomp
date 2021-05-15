// -StStagingRegionReuse@-$ST_STORE@USM_TRAITS@@@@SAPAU_ST_STAGING_REGION@1@PAU_ST_DATA_MGR@1@@Z 
 
int *__fastcall ST_STORE<SM_TRAITS>::StStagingRegionReuse(_DWORD *a1)
{
  int v2; // r8
  int *v3; // r4
  unsigned int v4; // r7
  int *v5; // r6
  int v6; // r3

  v2 = a1[76];
  v3 = a1 + 80;
  v4 = a1[26] - a1[27] + 1;
  v5 = a1 + 98;
  while ( v3 < v5 )
  {
    v6 = *v3;
    if ( *v3 != -1 && (*(_WORD *)(v2 + 2 * v6) & 0xC000) == 0 )
    {
      if ( (*(_WORD *)(v2 + 2 * v6) & 0x1FFFu) < v4 )
        return v3;
      ST_STORE<SM_TRAITS>::StStagingRegionIssueIo((int)a1, v3);
    }
    v3 += 3;
  }
  return 0;
}
