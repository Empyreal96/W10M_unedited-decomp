// -StAddRemoveRegions@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StAddRemoveRegions(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  int v6; // r5
  unsigned int *v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r0
  int result; // r0
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  if ( (a2[1] & 7) == 4 )
  {
    v6 = a2[3];
    v7 = (unsigned int *)a2[2];
    v8 = 0;
    while ( v6 )
    {
      v9 = RtlFindSetBits(v7, 1u, v8);
      --v6;
      *(_BYTE *)((v9 >> 3) + *(_DWORD *)(a1 + 180)) |= 1 << (v9 & 7);
      ++*(_DWORD *)(a1 + 184);
      v8 = v9 + 1;
    }
    result = 0;
  }
  else
  {
    v11 = a2[3];
    v12 = 0;
    result = -1;
    v13[0] = 0;
    if ( v11 )
    {
      while ( 1 )
      {
        result = ST_STORE<SM_TRAITS>::StDmRegionRemove(a1 + 56, v13);
        if ( result < 0 )
          break;
        ++v12;
        *(_BYTE *)((v13[0] >> 3) + *(_DWORD *)(a2[2] + 4)) |= 1 << (v13[0] & 7);
        if ( v12 >= v11 )
          goto LABEL_12;
      }
      if ( result != -1073741818 )
        result = 0;
    }
LABEL_12:
    a2[3] = v12;
  }
  return result;
}
