// CcAllocateVacbLevels 
 
int __fastcall CcAllocateVacbLevels(unsigned int a1, int a2, _DWORD *a3)
{
  unsigned int v4; // r3
  int v7; // r5
  _DWORD *v8; // r0
  _DWORD *v9; // r2
  int v10; // r0

  v4 = a3[3];
  v7 = 0;
  while ( a1 > v4 )
  {
    v8 = (_DWORD *)ExAllocateFromNPagedLookasideList((int)&CcVacbLevelLookasideList);
    if ( !v8 )
      goto LABEL_9;
    v9 = (_DWORD *)a3[1];
    *v8 = a3;
    v8[1] = v9;
    if ( (_DWORD *)*v9 != a3 )
      __fastfail(3u);
    *v9 = v8;
    a3[1] = v8;
    v4 = a3[3] + 1;
    a3[3] = v4;
  }
  if ( a2 )
  {
    if ( !a3[2] )
    {
      v10 = ExAllocateFromNPagedLookasideList((int)&CcVacbLevelWithBcbListHeadsLookasideList);
      a3[2] = v10;
      if ( !v10 )
      {
LABEL_9:
        CcFreeUnusedVacbLevels(a3);
        return v7;
      }
    }
  }
  return 1;
}
