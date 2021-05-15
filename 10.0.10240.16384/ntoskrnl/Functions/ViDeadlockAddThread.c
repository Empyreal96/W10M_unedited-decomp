// ViDeadlockAddThread 
 
int __fastcall ViDeadlockAddThread(unsigned int a1, int a2)
{
  int v2; // r4
  unsigned int v4; // r7
  int v5; // r6
  int v6; // r2
  __int64 v7; // r0

  v2 = a2;
  if ( !a2 )
    return 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  __dmb(0xBu);
  *(_DWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)a2 = a1;
  v4 = (a1 >> 12)
     - 1023
     * ((unsigned int)((((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                     + ((unsigned int)((a1 >> 12) - (((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  v5 = ViDeadlockGlobals;
  v6 = a2 + 12;
  HIDWORD(v7) = *(_DWORD *)(ViDeadlockGlobals + 8208) + 8 * v4;
  LODWORD(v7) = *(_DWORD *)HIDWORD(v7);
  *(_QWORD *)(v2 + 12) = v7;
  if ( *(_DWORD *)(v7 + 4) != HIDWORD(v7) )
    __fastfail(3u);
  *(_DWORD *)(v7 + 4) = v6;
  *(_DWORD *)HIDWORD(v7) = v6;
  VfUtilAddressRangeAdd((unsigned int *)(v5 + 8 * (v4 + 1027)), a1, 1104);
  ++*(_DWORD *)(v5 + 8212);
  return v2;
}
