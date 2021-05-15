// RtlpLookupOrCreateLowBox 
 
int __fastcall RtlpLookupOrCreateLowBox(int a1, int a2, int a3)
{
  int v5; // r5
  int result; // r0
  int *v7; // r6
  int v8; // r2
  int v9; // r2

  if ( (*(_DWORD *)(a1 + 16) & 1) != 0 )
    v5 = 0;
  else
    v5 = RtlpQueryLowBoxId();
  if ( !v5 )
    return a2 + 8;
  result = *(_DWORD *)(a2 + 8);
  v7 = (int *)(a2 + 8);
  while ( (int *)result != v7 )
  {
    if ( *(_DWORD *)(result + 8) == v5 )
    {
      if ( a3 )
        result = sub_514C44();
      return result;
    }
    result = *(_DWORD *)result;
  }
  result = RtlpAllocateAtom(16, 1282241601);
  if ( !result )
    return 0;
  v8 = *v7;
  *(_DWORD *)result = *v7;
  *(_DWORD *)(result + 4) = v7;
  if ( *(int **)(v8 + 4) != v7 )
    __fastfail(3u);
  *(_DWORD *)(v8 + 4) = result;
  *v7 = result;
  *(_WORD *)(result + 12) = 0;
  *(_WORD *)(result + 14) = 0;
  *(_DWORD *)(result + 8) = v5;
  if ( a3 )
  {
    *(_WORD *)(result + 14) = 4;
    *(_WORD *)(result + 12) = 1;
    v9 = *(unsigned __int16 *)(a2 + 20);
    if ( v9 == 0xFFFF )
      *(_WORD *)(a2 + 22) |= 1u;
    else
      *(_WORD *)(a2 + 20) = v9 + 1;
  }
  return result;
}
