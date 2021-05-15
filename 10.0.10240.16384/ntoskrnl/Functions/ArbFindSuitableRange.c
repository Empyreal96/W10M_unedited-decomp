// ArbFindSuitableRange 
 
int __fastcall ArbFindSuitableRange(int a1, int a2)
{
  unsigned __int64 v2; // r8
  unsigned int v3; // lr
  unsigned int v5; // r7
  int v6; // r6
  int v8; // r0
  int v10; // r3
  int v11; // r3

  v2 = *(_QWORD *)(a2 + 24);
  v3 = *(_DWORD *)(a2 + 20);
  v5 = *(_DWORD *)(a2 + 16);
  v6 = 0;
  if ( __PAIR64__(v3, v5) > v2 )
    return 0;
  v8 = *(_DWORD *)(a2 + 36);
  if ( !*(_QWORD *)(v8 + 16) )
    return sub_80E558();
  v10 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 20);
  if ( !v10 || v10 == 2 )
    *(_BYTE *)(a2 + 51) |= 1u;
  if ( (*(_WORD *)(a2 + 48) & 8) != 0 )
    v6 = 2;
  v11 = *(_DWORD *)(v8 + 36);
  if ( (v11 & 1) != 0 )
    v6 |= 1u;
  if ( (v11 & 8) != 0 )
    *(_BYTE *)(a2 + 51) |= 0x40u;
  if ( RtlFindRange(
         *(_DWORD *)(a1 + 24),
         *(_DWORD *)(v8 + 20),
         v5,
         v3,
         v2,
         HIDWORD(v2),
         *(_DWORD *)(v8 + 16),
         *(_DWORD *)(v8 + 20),
         *(_DWORD *)(v8 + 24),
         *(_DWORD *)(v8 + 28),
         v6,
         *(unsigned __int8 *)(a2 + 51),
         *(_DWORD *)(a1 + 160),
         *(_DWORD *)(a1 + 164),
         a2) >= 0 )
  {
    *(_QWORD *)(a2 + 8) = *(_QWORD *)a2 + *(_QWORD *)(*(_DWORD *)(a2 + 36) + 16) - 1i64;
    return 1;
  }
  if ( ArbShareDriverExclusive(a1, a2) )
    return 1;
  return (*(int (__fastcall **)(int, int))(a1 + 136))(a1, a2);
}
