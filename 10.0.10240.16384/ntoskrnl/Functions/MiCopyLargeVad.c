// MiCopyLargeVad 
 
int __fastcall MiCopyLargeVad(int a1, int a2)
{
  int v2; // r7
  int v3; // r9
  int **v4; // r8
  int *v5; // r4
  __int64 v6; // kr00_8
  int v7; // r0
  unsigned int v8; // r6

  v2 = *(_DWORD *)(a1 + 12) << 12;
  v3 = (unsigned __int8)*(_DWORD *)(a1 + 28) >> 3;
  v4 = *(int ***)(*(_DWORD *)(a2 + 36) + 8);
  v5 = *v4;
  while ( 1 )
  {
    if ( v5 == (int *)v4 )
      return 1;
    v6 = *((_QWORD *)v5 + 1);
    v7 = MiMapContiguousMemory((unsigned __int64)(unsigned int)v6 << 12, HIDWORD(v6) << 12, v3, 0);
    v8 = v7;
    if ( !v7 )
      break;
    memmove(v7, v2, HIDWORD(v6) << 12);
    if ( (v3 & 2) != 0 )
      KeSweepIcacheRange(1, v8, HIDWORD(v6) << 12);
    MmUnmapIoSpace(v8, HIDWORD(v6) << 12);
    v5 = (int *)*v5;
    v2 += HIDWORD(v6) << 12;
  }
  return 0;
}
