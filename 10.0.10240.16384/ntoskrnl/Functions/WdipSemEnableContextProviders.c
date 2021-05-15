// WdipSemEnableContextProviders 
 
int __fastcall WdipSemEnableContextProviders(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r6
  int v4; // r7

  v1 = result;
  if ( result )
  {
    v2 = *(_DWORD *)(result + 24);
    v3 = 0;
    if ( *(_DWORD *)(v2 + 48) )
    {
      v4 = v2 - result;
      do
      {
        result = WdipSemEnableContextProvider(*(_DWORD *)(v4 + v1 + 56));
        *(_DWORD *)(v1 + 36) = result;
        ++v3;
        v1 += 4;
      }
      while ( v3 < *(_DWORD *)(v2 + 48) );
    }
  }
  return result;
}
