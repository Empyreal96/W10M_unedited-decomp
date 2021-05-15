// ArbBacktrackAllocation 
 
__int64 __fastcall ArbBacktrackAllocation(int a1, int a2)
{
  __int64 v3; // [sp+0h] [bp-10h]

  RtlDeleteRange(
    *(_DWORD **)(a1 + 24),
    a2,
    *(_DWORD *)a2,
    *(_DWORD *)(a2 + 4),
    *(_QWORD *)(a2 + 8),
    *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16));
  return v3;
}
