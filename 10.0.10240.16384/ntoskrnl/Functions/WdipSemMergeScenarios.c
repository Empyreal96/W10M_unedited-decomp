// WdipSemMergeScenarios 
 
int __fastcall WdipSemMergeScenarios(int a1, int a2)
{
  int v2; // r5
  unsigned int v5; // r7
  int v6; // r6
  unsigned int v7; // r7
  int v8; // r6

  v2 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  WdipSemMergeEvents(a1, a2);
  v5 = 0;
  if ( *(_DWORD *)(a2 + 48) )
  {
    v6 = a2;
    while ( 1 )
    {
      v2 = WdipSemAddContextEventToScenario(a1, *(_DWORD *)(v6 + 56));
      if ( v2 < 0 )
        break;
      ++v5;
      v6 += 4;
      if ( v5 >= *(_DWORD *)(a2 + 48) )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v7 = 0;
    if ( *(_DWORD *)(a2 + 52) )
    {
      v8 = a2;
      do
      {
        v2 = WdipSemAddEndEventToScenario(a1, *(_DWORD *)(v8 + 552));
        if ( v2 < 0 )
          break;
        ++v7;
        v8 += 4;
      }
      while ( v7 < *(_DWORD *)(a2 + 52) );
    }
  }
  return v2;
}
