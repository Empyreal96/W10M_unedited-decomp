// PspSetProcessPriorityClass 
 
int __fastcall PspSetProcessPriorityClass(int a1, unsigned int a2)
{
  char v2; // r6
  int v4; // r5
  int v5; // r3
  unsigned int v6; // r4
  int v8; // r0
  int v9; // r3

  v2 = a2;
  if ( a2 > 6 )
    return -1073741811;
  if ( a2 != *(unsigned __int8 *)(a1 + 375) && a2 == 4 )
    return sub_7E9A8C();
  v4 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = v5 & 0xFFFFFFC0;
  if ( v4 )
  {
    --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
    ExAcquireResourceSharedLite(v4 + 32, 1);
    if ( (*(_DWORD *)(v4 + 400) & 0x20) != 0 )
      v2 = *(_BYTE *)(v4 + 424);
    v8 = ExReleaseResourceLite(v4 + 32);
    v9 = (__int16)(*(_WORD *)(v6 + 308) + 1);
    *(_WORD *)(v6 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  *(_BYTE *)(a1 + 375) = v2;
  return 0;
}
