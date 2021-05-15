// PspSystemThreadStartup 
 
int __fastcall PspSystemThreadStartup(void (__fastcall *a1)(int), int a2)
{
  int v4; // r0
  unsigned int v5; // r5
  int v6; // r6
  unsigned __int8 *v7; // r3
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r4
  __int16 v11; // r3

  v4 = KfLowerIrql(0);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_DWORD *)(v5 + 0x74);
  if ( (*(_DWORD *)(v6 + 188) & 0x8000) == 0 )
  {
    __dmb(0xBu);
    v7 = (unsigned __int8 *)(v6 + 189);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    --*(_WORD *)(v5 + 308);
    __dmb(0xFu);
    v9 = *(_DWORD *)(v6 + 168);
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
    {
      v10 = KeAbPreAcquire(v6 + 168, 0, 0);
      ExfAcquirePushLockExclusiveEx(v6 + 168, v10, v6 + 168);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v4 = ExfReleasePushLockExclusive(v6 + 168);
      if ( v10 )
        v4 = KeAbPostRelease(v6 + 168);
    }
    v11 = *(_WORD *)(v5 + 308) + 1;
    *(_WORD *)(v5 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      KiCheckForKernelApcDelivery(v4);
  }
  if ( (((unsigned __int8)*(_DWORD *)(v5 + 960) ^ 1) & 3) == 3 )
    a1(a2);
  return PspTerminateThreadByPointer(v5, 0, 1);
}
