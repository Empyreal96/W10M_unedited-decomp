// SepIsSiblingTokenByPointer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepIsSiblingTokenByPointer(int a1, _BYTE *a2)
{
  int v4; // r8
  _DWORD *v5; // r0
  int v6; // r9
  unsigned int v7; // r4
  int v8; // r6
  unsigned int v9; // r7
  int v10; // r2 OVERLAPPED
  unsigned int v11; // r1

  *a2 = 0;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = (_DWORD *)PsReferencePrimaryToken(v4);
  if ( !v5 )
    return -1073741823;
  v6 = v5[9];
  v7 = v5[8];
  v8 = v5[7];
  v9 = v5[6];
  ObFastDereferenceObject((_DWORD *)(v4 + 244), (unsigned int)v5);
  *(_QWORD *)(&v10 - 1) = *(_QWORD *)(a1 + 24);
  if ( __PAIR64__(*(_DWORD *)(a1 + 32), v11) == __PAIR64__(v7, v9) && *(_DWORD *)(a1 + 36) == v6 && v10 == v8 )
    *a2 = 1;
  return 0;
}
