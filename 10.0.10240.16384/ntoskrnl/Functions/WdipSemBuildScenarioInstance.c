// WdipSemBuildScenarioInstance 
 
_DWORD *__fastcall WdipSemBuildScenarioInstance(int a1, _DWORD *a2)
{
  _DWORD *v2; // r7
  _BYTE *v5; // r0
  int v6; // r3
  int v7; // r4
  int v8; // r5

  v2 = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = (_BYTE *)WdipSemFastAllocate(3, 532);
      v2 = v5;
      if ( v5 )
      {
        memset(v5, 0, 532);
        v6 = a2[1];
        v7 = a2[2];
        v8 = a2[3];
        v2[2] = *a2;
        v2[3] = v6;
        v2[4] = v7;
        v2[5] = v8;
        v2[6] = a1;
        v2[7] = 0;
        v2[8] = 1;
      }
    }
  }
  return v2;
}
