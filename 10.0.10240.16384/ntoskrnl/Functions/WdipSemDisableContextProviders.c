// WdipSemDisableContextProviders 
 
int __fastcall WdipSemDisableContextProviders(int result, int a2)
{
  int v2; // r4
  int v4; // r5
  unsigned int v5; // r6
  int v6; // r7

  v2 = result;
  if ( result )
  {
    v4 = *(_DWORD *)(result + 24);
    v5 = 0;
    if ( *(_DWORD *)(v4 + 48) )
    {
      v6 = v4 - result;
      do
      {
        result = *(_DWORD *)(v6 + v2 + 56);
        if ( *(int *)(v2 + 36) >= 0 )
        {
          result = WdipSemDisableContextProvider(result, a2);
          *(_DWORD *)(v2 + 36) = result;
        }
        ++v5;
        v2 += 4;
      }
      while ( v5 < *(_DWORD *)(v4 + 48) );
    }
  }
  return result;
}
