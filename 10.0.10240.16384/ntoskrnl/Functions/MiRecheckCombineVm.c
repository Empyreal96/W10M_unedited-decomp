// MiRecheckCombineVm 
 
BOOL __fastcall MiRecheckCombineVm(int a1, int a2, int *a3)
{
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r7
  _DWORD *v9; // r0
  int v10; // r6
  BOOL v11; // r5
  unsigned int *v12; // r2
  unsigned int v13; // r0
  int *v14; // r3

  v5 = MiCombineCandidate();
  v8 = v5;
  if ( !v5 )
    return 0;
  if ( v5 == 2 )
  {
    v14 = &dword_634E80;
  }
  else
  {
    v9 = (_DWORD *)MiGetTopLevelPfn(a2, 0, v6, v7);
    v10 = *v9;
    v11 = (v9[3] & 0x40000000) != 0;
    if ( v9 != (_DWORD *)a2 )
    {
      __dmb(0xBu);
      v12 = v9 + 3;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 & 0x7FFFFFFF, v12) );
    }
    if ( v8 == 1 )
    {
      v14 = (int *)(v10 + 492);
    }
    else
    {
      if ( v11 )
        return 0;
      v14 = (int *)(v10 + 3248);
    }
  }
  return a3 == v14;
}
