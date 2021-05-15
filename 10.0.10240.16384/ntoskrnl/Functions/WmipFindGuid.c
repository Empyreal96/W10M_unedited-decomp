// WmipFindGuid 
 
int __fastcall WmipFindGuid(unsigned int a1, unsigned int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r4
  unsigned int v9; // r6
  unsigned int i; // r5
  int result; // r0
  int v12; // r2

  v6 = 0;
  v9 = a1;
  if ( !a2 )
    return 0;
  for ( i = a1; memcmp(a3, i, 16); i += 24 )
  {
    if ( ++v6 >= a2 )
      return 0;
  }
  v12 = *(_DWORD *)(v9 + 24 * v6 + 16);
  *a4 = v6;
  result = 1;
  *a5 = v12;
  return result;
}
