// -StDmGetSpaceStats@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@PAK1@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmGetSpaceStats(int result, _DWORD *a2, _DWORD *a3)
{
  int v3; // r4

  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  if ( *(_BYTE *)(result + 72) )
    v3 = 1;
  else
    v3 = 8;
  do
  {
    if ( a2 )
      *a2 += *(_DWORD *)(result + 684);
    if ( a3 )
      *a3 += *(_DWORD *)(result + 688);
    result += 8;
    --v3;
  }
  while ( v3 );
  return result;
}
