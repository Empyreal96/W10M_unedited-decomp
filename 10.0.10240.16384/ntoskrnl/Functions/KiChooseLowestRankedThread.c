// KiChooseLowestRankedThread 
 
int __fastcall KiChooseLowestRankedThread(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r1
  int v8; // r10
  BOOL v9; // r2
  int result; // r0
  _DWORD *v11; // r4
  unsigned int v12; // r8
  int v13; // r5
  unsigned int v14; // r3
  int v15; // r3
  _DWORD *v16; // r2
  int v17[8]; // [sp+8h] [bp-20h] BYREF

  v17[0] = a4;
  v5 = *(_DWORD *)(a2 + 68);
  if ( !v5 )
    return 0;
  v8 = a1[588] + v5;
  if ( !v8 )
    return 0;
  v9 = a1 == (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408) || a2 != a1[1];
  if ( !KiGetThreadEffectiveRankNonZero(a2, v8, v9) )
    return 0;
  result = KiSelectReadyThread(1, a1);
  if ( result )
    return result;
  v11 = (_DWORD *)a1[495];
  v12 = *(_DWORD *)(*(_DWORD *)(v8 + 240) + 96);
  if ( !v11 )
    return 0;
  v13 = (int)(v11 - 20);
  v14 = v11[4];
  if ( v14 >= v12 )
  {
    if ( v14 != v12 )
      return 0;
    if ( a3 < *(char *)(a2 + 123) )
      a3 = *(char *)(a2 + 123);
    while ( 1 )
    {
      result = KiSelectThreadFromSchedulingGroup((int)a1, v13, a3);
      if ( v13 == v8 )
      {
        v15 = 1;
      }
      else
      {
        LOBYTE(v17[0]) = 0;
        if ( result )
          return result;
        if ( !*(_DWORD *)(v13 + 228) )
          goto LABEL_20;
        result = KiSelectThreadFromScbQueue(v13 + 228, (int)a1, a3, v8, v17);
        v15 = LOBYTE(v17[0]);
      }
      if ( result )
        return result;
      if ( v15 )
        return 0;
LABEL_20:
      v16 = v11;
      if ( v11[1] )
        return sub_52B674();
      while ( 1 )
      {
        v11 = (_DWORD *)(v11[2] & 0xFFFFFFFC);
        if ( !v11 || (_DWORD *)*v11 == v16 )
          break;
        v16 = v11;
      }
      if ( v11 )
      {
        v13 = (int)(v11 - 20);
        if ( v11[4] == v12 )
          continue;
      }
      return 0;
    }
  }
  while ( !*(_WORD *)(v13 + 94) )
    v13 = *(_DWORD *)(v13 + 232) - 80;
  return KiSelectThreadFromSchedulingGroup((int)a1, v13, 0);
}
