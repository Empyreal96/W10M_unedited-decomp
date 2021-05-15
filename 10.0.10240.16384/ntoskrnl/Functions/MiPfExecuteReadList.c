// MiPfExecuteReadList 
 
int __fastcall MiPfExecuteReadList(int result, char a2)
{
  unsigned int v3; // r5
  char v4; // r8
  int v5; // r4
  int v6; // r7
  int v7; // r10
  int v8; // r0

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = 0;
  v5 = *(_DWORD *)(result + 56);
  v6 = result + 56;
  while ( v5 != v6 )
  {
    v7 = *(_DWORD *)(v5 + 144);
    *(_WORD *)(v7 + 6) |= 0x42u;
    *(_DWORD *)(v5 + 104) = *(_DWORD *)(v7 + 20);
    v8 = MiReferenceInPageFile(v5);
    if ( v8 )
      *(_DWORD *)(v5 + 116) = v8;
    else
      v8 = *(_DWORD *)(v5 + 116);
    *(_DWORD *)(v5 + 132) = *(_DWORD *)(v5 + 136);
    *(_DWORD *)(v5 + 96) = 0;
    if ( (a2 & 1) != 0 )
    {
      v4 = *(_BYTE *)(v3 + 972);
      *(_BYTE *)(v3 + 972) = 1;
    }
    if ( (*(_BYTE *)(v5 + 113) & 0x80) != 0 )
      return sub_80693C();
    result = IoPageRead(v8 | 2, v7 | 1, (_DWORD *)(v5 + 56), v5 + 16, v5 + 48);
    if ( (a2 & 1) != 0 )
      *(_BYTE *)(v3 + 972) = v4;
    if ( result < 0 )
    {
      *(_DWORD *)(v5 + 48) = result;
      *(_DWORD *)(v5 + 52) = 0;
      result = KeSetEvent(v5 + 16, 0, 0);
    }
    v5 = *(_DWORD *)v5;
  }
  return result;
}
