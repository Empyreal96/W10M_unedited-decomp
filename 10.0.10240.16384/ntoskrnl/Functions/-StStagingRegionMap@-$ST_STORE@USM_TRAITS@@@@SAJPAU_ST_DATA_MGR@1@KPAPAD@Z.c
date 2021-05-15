// -StStagingRegionMap@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@KPAPAD@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StStagingRegionMap(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r7
  int v5; // r9
  int v9; // r5
  int v10; // r3

  v3 = 0;
  v4 = a1 + 80;
  v5 = a1[76];
  while ( v4 < a1 + 98 )
  {
    if ( *v4 == -1 )
    {
      if ( !v3 )
        v3 = v4;
    }
    else if ( *v4 == a2 )
    {
      goto LABEL_23;
    }
    v4 += 3;
  }
  v4 = v3;
  if ( !v3 )
    return -1073739774;
  if ( (*(_WORD *)(v5 + 2 * a2) & 0x1FFF) != 0 )
  {
    v10 = a1[29];
    if ( (v10 & 2) != 0 )
    {
      if ( (v10 & 4) != 0 && (a1[244] & 1) == 0 )
      {
        a1[241] = 0;
        a1[241] = 1;
        a1[244] |= 1u;
        SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(a1[23], (int)(a1 + 238), 6);
      }
      return -1073741535;
    }
    if ( (a1[18] & 0x1000) != 0 )
      return -1073741535;
  }
  v9 = ST_STORE<SM_TRAITS>::StStagingRegionStart(a1, v3, a2);
  if ( v9 >= 0 )
  {
    if ( (*(_WORD *)(v5 + 2 * a2) & 0x1FFF) != 0
      && (v9 = ST_STORE<SM_TRAITS>::StDmRegionEvict((int)a1, (int)(a1 + 63), a2), v9 < 0) )
    {
      if ( *v3 != -1 )
      {
        ExFreePoolWithTag(v3[1]);
        ExFreePoolWithTag(v3[2]);
      }
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = -1;
    }
    else
    {
LABEL_23:
      v9 = 0;
      *a3 = v4[1];
    }
  }
  return v9;
}
