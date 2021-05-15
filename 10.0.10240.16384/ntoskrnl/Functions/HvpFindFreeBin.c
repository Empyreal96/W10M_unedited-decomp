// HvpFindFreeBin 
 
int __fastcall HvpFindFreeBin(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v5; // r3
  int v6; // r10
  int v7; // r2
  int v9; // r8
  int result; // r0
  unsigned int v12; // r6
  int v13; // [sp+0h] [bp-28h]
  int i; // [sp+8h] [bp-20h]

  v5 = a3;
  v7 = a1 + 412 * a3;
  v6 = v7;
  v9 = v7 + 1352;
  v13 = v5;
  for ( i = v7; ; v7 = i )
  {
    result = *(_DWORD *)(v6 + 1352);
    if ( result != v9 )
      break;
    if ( a2 || !HvpCoalesceDiscardedBins(a1, 0, v5) )
      return 0;
    v5 = v13;
  }
  v12 = *(_DWORD *)(result + 8);
  if ( v12 < a2 || *(_DWORD *)(result + 12) + v12 > *(_DWORD *)(v7 + 952) )
    return sub_80A294();
  *a4 = v12;
  return result;
}
