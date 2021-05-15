// -StDmGetFreeStagingRegionBytes@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmGetFreeStagingRegionBytes(int a1)
{
  int result; // r0
  int v3; // r4
  int *v4; // r2
  unsigned int v5; // r1
  int v6; // t1

  if ( !*(_BYTE *)(a1 + 72) )
    return -1;
  if ( *(_DWORD *)(a1 + 392) == -1 )
    result = 0;
  else
    result = *(_DWORD *)(a1 + 80) - 16 * *(_DWORD *)(a1 + 396);
  v3 = *(_DWORD *)(a1 + 80);
  v4 = (int *)(a1 + 320);
  v5 = a1 + 392;
  while ( (unsigned int)v4 < v5 )
  {
    v6 = *v4;
    v4 += 3;
    if ( v6 == -1 )
      result += v3;
  }
  return result;
}
