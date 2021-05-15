// BcdUtilGetBootOption 
 
int __fastcall BcdUtilGetBootOption(int a1, int a2)
{
  int v2; // r2
  int v3; // r4

  if ( !a1 )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = v2 + a1;
    if ( *(_DWORD *)(v2 + a1) == a2 && !*(_BYTE *)(v3 + 20) )
      break;
    if ( *(_DWORD *)(v3 + 12) )
      return sub_7DCF20();
    v2 = *(_DWORD *)(v3 + 16);
    if ( !v2 )
      return 0;
  }
  return v3;
}
