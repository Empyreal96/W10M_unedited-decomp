// IopPortFindSuitableRange 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopPortFindSuitableRange(int a1, int a2)
{
  int v3; // r2
  unsigned __int8 v5; // r0
  unsigned int v6; // r9 OVERLAPPED
  unsigned int v7; // r10 OVERLAPPED
  int v9; // r1
  int v10; // r3
  unsigned __int64 v11; // kr08_8
  unsigned int v12; // r7 OVERLAPPED
  unsigned int v13; // r8 OVERLAPPED
  int v14; // r3

  v3 = *(_DWORD *)(a2 + 36);
  v5 = 0;
  *(_QWORD *)&v6 = *(_QWORD *)(v3 + 16);
  if ( !*(_QWORD *)&v6 )
  {
    *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 4);
    return 1;
  }
  v9 = *(_DWORD *)(a2 + 32);
  v10 = *(_DWORD *)(v9 + 20);
  if ( !v10 || v10 == 2 || (*(_DWORD *)(v9 + 24) & 1) != 0 )
    v5 = 1;
  v11 = *(_QWORD *)(a2 + 16);
  *(_QWORD *)&v12 = *(_QWORD *)(a2 + 24);
  if ( v11 <= *(_QWORD *)&v12 )
  {
    v14 = *(_DWORD *)(v3 + 36);
    if ( (v14 & 1) != 0 )
      LOBYTE(v14) = 1;
    if ( (*(_DWORD *)(v3 + 36) & 1) == 0 )
      LOBYTE(v14) = 0;
    if ( RtlFindRange(
           *(_DWORD *)(a1 + 24),
           v11,
           __PAIR64__(v13, v12),
           __SPAIR64__(v7, v6),
           *(_QWORD *)(v3 + 24),
           v14,
           v5,
           *(_DWORD *)(a1 + 160),
           *(_DWORD *)(a1 + 164),
           (unsigned __int64 *)a2) >= 0
      || (*(int (__fastcall **)(int, int))(a1 + 136))(a1, a2) )
    {
      *(_QWORD *)(a2 + 8) = *(_QWORD *)a2 + *(_QWORD *)(*(_DWORD *)(a2 + 36) + 16) - 1i64;
      return 1;
    }
  }
  return 0;
}
