// IopPortAddAllocation 
 
int __fastcall IopPortAddAllocation(int a1, int a2)
{
  int v4; // r0
  char v5; // r2
  unsigned __int64 v6; // r6
  int v7; // r5
  int result; // r0
  char v9; // r2
  unsigned __int64 v10[5]; // [sp+18h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a1 + 24);
  if ( (*(_DWORD *)(*(_DWORD *)(a2 + 36) + 36) & 1) != 0 )
    v5 = 2;
  else
    v5 = 0;
  RtlAddRange(
    v4,
    *(_QWORD *)a2,
    *(_QWORD *)(a2 + 8),
    *(_BYTE *)(a2 + 50),
    v5 + 1,
    0,
    *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16));
  v6 = *(_QWORD *)a2;
  for ( v10[0] = *(_QWORD *)a2;
        ;
        RtlAddRange(
          *(_DWORD *)(a1 + 24),
          v10[0],
          *(_QWORD *)(v7 + 16) + v10[0] - 1,
          *(_BYTE *)(a2 + 50) | 0x10,
          v9 + 1,
          0,
          *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16)) )
  {
    v7 = *(_DWORD *)(a2 + 36);
    result = IopPortGetNextAlias(
               *(unsigned __int16 *)(*(_DWORD *)(v7 + 40) + 4),
               *(_DWORD *)(v7 + 40),
               v6,
               HIDWORD(v6),
               v10);
    if ( !result )
      break;
    v6 = v10[0];
    if ( (*(_DWORD *)(v7 + 36) & 1) != 0 )
      v9 = 2;
    else
      v9 = 0;
  }
  return result;
}
