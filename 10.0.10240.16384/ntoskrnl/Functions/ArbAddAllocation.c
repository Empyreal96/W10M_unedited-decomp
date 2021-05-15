// ArbAddAllocation 
 
int __fastcall ArbAddAllocation(int a1, int a2)
{
  int v2; // r2

  if ( (*(_DWORD *)(*(_DWORD *)(a2 + 36) + 36) & 1) != 0 )
    v2 = 2;
  else
    v2 = 0;
  return RtlAddRange(
           *(_DWORD *)(a1 + 24),
           a2,
           *(_DWORD *)a2,
           *(_DWORD *)(a2 + 4),
           *(_DWORD *)(a2 + 8),
           *(_DWORD *)(a2 + 12),
           *(unsigned __int8 *)(a2 + 50),
           v2 + 1,
           0,
           *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16));
}
