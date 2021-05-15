// AslpFileHasSecuromWrapper 
 
int __fastcall AslpFileHasSecuromWrapper(int a1)
{
  unsigned int v1; // r7
  int v2; // r5
  unsigned int v3; // r6
  int v4; // r4

  v1 = *(unsigned __int16 *)(a1 + 6);
  v2 = 0;
  v3 = 0;
  v4 = *(unsigned __int16 *)(a1 + 20) + a1 + 24;
  if ( *(_WORD *)(a1 + 6) )
  {
    while ( !*(_DWORD *)(v4 + 12) || !*(_DWORD *)(v4 + 8) || strncmp((_BYTE *)v4, ".securom", 8u) )
    {
      ++v3;
      v4 += 40;
      if ( v3 >= v1 )
        return v2;
    }
    v2 = 1;
  }
  return v2;
}
