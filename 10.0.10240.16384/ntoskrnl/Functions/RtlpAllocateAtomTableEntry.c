// RtlpAllocateAtomTableEntry 
 
int __fastcall RtlpAllocateAtomTableEntry(int a1, int **a2, char a3)
{
  unsigned int v3; // r0
  int v6; // r0
  int v7; // r4
  int *v8; // r5
  int v9; // r6
  int *v10; // r0
  int v12; // r2

  v3 = a1 + 28;
  if ( v3 < 0x1C )
    return 0;
  v6 = RtlpAllocateAtom(v3, 1097692225);
  v7 = v6;
  if ( !v6 )
    return 0;
  *(_DWORD *)v6 = 0;
  *(_WORD *)(v6 + 20) = 1;
  if ( (a3 & 2) != 0 )
    *(_WORD *)(v6 + 22) = 2;
  else
    *(_WORD *)(v6 + 22) = 0;
  v8 = (int *)(v6 + 8);
  *(_DWORD *)(v6 + 16) = 0;
  *(_DWORD *)(v6 + 8) = v6 + 8;
  *(_DWORD *)(v6 + 12) = v6 + 8;
  v9 = RtlpQueryLowBoxId();
  if ( v9 )
  {
    v10 = (int *)RtlpAllocateAtom(16, 1282241601);
    if ( !v10 )
      return sub_514D44();
    v10[3] = 1;
    v10[2] = v9;
    v12 = *v8;
    *v10 = *v8;
    v10[1] = (int)v8;
    if ( *(int **)(v12 + 4) != v8 )
      __fastfail(3u);
    *(_DWORD *)(v12 + 4) = v10;
    *v8 = (int)v10;
  }
  else
  {
    v10 = (int *)(v7 + 8);
  }
  *a2 = v10;
  return v7;
}
