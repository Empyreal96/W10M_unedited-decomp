// KeDeregisterBugCheckReasonCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeDeregisterBugCheckReasonCallback(_BYTE *a1)
{
  int v2; // r8
  unsigned int v4; // r2
  int v5; // r6
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED

  v2 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5545B8();
  do
    v4 = __ldrex((unsigned int *)&KeBugCheckCallbackLock);
  while ( __strex(1u, (unsigned int *)&KeBugCheckCallbackLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KeBugCheckCallbackLock);
  v5 = 0;
  if ( a1[24] == 1 )
  {
    a1[24] = 0;
    *(_QWORD *)&v6 = *(_QWORD *)a1;
    if ( *(_BYTE **)(*(_DWORD *)a1 + 4) != a1 || (_BYTE *)*v7 != a1 )
      __fastfail(3u);
    *v7 = v6;
    *(_DWORD *)(v6 + 4) = v7;
    v5 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KeBugCheckCallbackLock);
  }
  else
  {
    __dmb(0xBu);
    KeBugCheckCallbackLock = 0;
  }
  KfLowerIrql(v2);
  return v5;
}
