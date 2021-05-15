// SepIsChildTokenByPointer 
 
int __fastcall SepIsChildTokenByPointer(int a1, _BYTE *a2)
{
  int v4; // r8
  unsigned int v5; // r0
  __int64 v6; // kr00_8

  *a2 = 0;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = PsReferencePrimaryToken(v4);
  if ( !v5 )
    return -1073741823;
  v6 = *(_QWORD *)(v5 + 16);
  ObFastDereferenceObject((_DWORD *)(v4 + 244), v5);
  if ( *(_QWORD *)(a1 + 32) == v6 )
    *a2 = 1;
  return 0;
}
