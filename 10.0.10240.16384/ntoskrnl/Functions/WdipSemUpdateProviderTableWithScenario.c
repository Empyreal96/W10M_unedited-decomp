// WdipSemUpdateProviderTableWithScenario 
 
int __fastcall WdipSemUpdateProviderTableWithScenario(_DWORD *a1)
{
  int result; // r0
  unsigned int v3; // r6
  _DWORD *v4; // r5
  unsigned int v5; // r6
  _DWORD *v6; // r5

  if ( !a1 )
    return -1073741811;
  result = WdipSemUpdateProviderTableWithEvent(a1);
  if ( result >= 0 )
  {
    v3 = 0;
    if ( a1[12] )
    {
      v4 = a1;
      while ( 1 )
      {
        result = WdipSemUpdateProviderTableWithEvent((_DWORD *)v4[14]);
        if ( result < 0 )
          break;
        ++v3;
        ++v4;
        if ( v3 >= a1[12] )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      v5 = 0;
      if ( a1[13] )
      {
        v6 = a1;
        do
        {
          result = WdipSemUpdateProviderTableWithEvent((_DWORD *)v6[138]);
          if ( result < 0 )
            break;
          ++v5;
          ++v6;
        }
        while ( v5 < a1[13] );
      }
    }
  }
  return result;
}
