// EtwpMapEnableFlags 
 
int __fastcall EtwpMapEnableFlags(int result, int a2)
{
  int *v2; // r5
  int v3; // r6

  v2 = &EtwpEnableFlagMap;
  v3 = 8;
  while ( 1 )
  {
    if ( a2 != 1 )
    {
      if ( result )
      {
        if ( (*(_DWORD *)(result + 4 * ((unsigned int)v2[1] >> 29)) & v2[1] & 0x1FFFFFFF) != 0 )
          *(_DWORD *)(result + 4 * ((unsigned int)*v2 >> 29)) |= *v2 & 0x1FFFFFFF;
      }
      goto LABEL_6;
    }
    if ( result && (*(_DWORD *)(result + 4 * ((unsigned int)*v2 >> 29)) & *v2 & 0x1FFFFFFF) != 0 )
      return sub_7EFC20();
LABEL_6:
    v2 += 2;
    if ( !--v3 )
      return result;
  }
}
