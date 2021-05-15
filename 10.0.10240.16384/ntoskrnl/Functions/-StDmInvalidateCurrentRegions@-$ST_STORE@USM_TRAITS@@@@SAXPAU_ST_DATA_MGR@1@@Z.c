// -StDmInvalidateCurrentRegions@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmInvalidateCurrentRegions(int result)
{
  int v1; // r6
  _DWORD *i; // r4

  if ( *(_BYTE *)(result + 72) )
    v1 = 1;
  else
    v1 = 8;
  for ( i = (_DWORD *)(result + 392); *i == -1; i += 3 )
  {
    *i = -1;
    i[1] = -1;
    i[2] = 0;
    if ( !--v1 )
      return result;
  }
  return sub_511804();
}
