// WdipSemAddEndEventToScenario 
 
int __fastcall WdipSemAddEndEventToScenario(int a1, unsigned int a2)
{
  int v2; // r5
  int v3; // r4
  unsigned int v5; // r7
  unsigned int v6; // r8
  int v7; // r9
  unsigned int v8; // r10
  int v9; // r0
  int v10; // r7

  v2 = a1;
  v3 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  v5 = *(_DWORD *)(a1 + 52);
  v6 = 0;
  if ( v5 )
  {
    v7 = a1;
    while ( 1 )
    {
      v8 = *(_DWORD *)(v7 + 552);
      if ( !memcmp(a2, v8, 16) && *(unsigned __int16 *)(a2 + 16) == *(unsigned __int16 *)(v8 + 16) )
        break;
      ++v6;
      v7 += 4;
      if ( v6 >= v5 )
        goto LABEL_9;
    }
    WdipSemMergeEvents(v8, a2);
  }
  else
  {
LABEL_9:
    if ( v5 < 0x10 )
    {
      v9 = WdipSemFastAllocate(0, 48);
      v10 = v9;
      if ( v9 )
      {
        memmove(v9, a2, 0x30u);
        *(_DWORD *)(v2 + 4 * (*(_DWORD *)(v2 + 52))++ + 552) = v10;
      }
      else
      {
        v3 = -1073741670;
      }
    }
    else
    {
      v3 = -1073741823;
    }
  }
  return v3;
}
