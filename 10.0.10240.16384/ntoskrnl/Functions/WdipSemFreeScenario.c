// WdipSemFreeScenario 
 
int __fastcall WdipSemFreeScenario(int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r6
  int v3; // r5
  _DWORD *v4; // r1
  int v5; // r3
  unsigned int v6; // r6
  _DWORD *v7; // r5
  _DWORD *v8; // r1

  v1 = (_DWORD *)result;
  if ( result )
  {
    v2 = 0;
    if ( *(_DWORD *)(result + 48) )
    {
      v3 = result;
      do
      {
        v4 = *(_DWORD **)(v3 + 56);
        if ( v4 )
        {
          WdipSemFastFree(0, v4);
          *(_DWORD *)(v3 + 56) = 0;
        }
        ++v2;
        v3 += 4;
      }
      while ( v2 < v1[12] );
    }
    v5 = v1[13];
    v6 = 0;
    v1[12] = 0;
    if ( v5 )
    {
      v7 = v1;
      do
      {
        v8 = (_DWORD *)v7[138];
        if ( v8 )
        {
          WdipSemFastFree(0, v8);
          v7[138] = 0;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v1[13] );
    }
    v1[13] = 0;
    result = WdipSemFastFree(1, v1);
  }
  return result;
}
