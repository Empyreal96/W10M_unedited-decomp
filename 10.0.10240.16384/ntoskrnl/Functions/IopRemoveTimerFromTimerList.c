// IopRemoveTimerFromTimerList 
 
int __fastcall IopRemoveTimerFromTimerList(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  __int64 v4; // r0
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&IopTimerLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&IopTimerLock);
    while ( __strex(1u, (unsigned int *)&IopTimerLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&IopTimerLock);
  }
  v4 = *(_QWORD *)(a1 + 4);
  if ( *(_DWORD *)(v4 + 4) != a1 + 4 || *(_DWORD *)HIDWORD(v4) != a1 + 4 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  if ( *(_WORD *)(a1 + 2) )
    --IopTimerCount;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&IopTimerLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    IopTimerLock = 0;
  }
  return KfLowerIrql(v2);
}
