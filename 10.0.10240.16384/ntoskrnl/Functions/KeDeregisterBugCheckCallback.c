// KeDeregisterBugCheckCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeDeregisterBugCheckCallback(_BYTE *a1)
{
  int v2; // r8
  unsigned int v3; // r2
  int v4; // r6
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KeBugCheckCallbackLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&KeBugCheckCallbackLock);
    while ( __strex(1u, (unsigned int *)&KeBugCheckCallbackLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KeBugCheckCallbackLock);
  }
  v4 = 0;
  if ( a1[28] == 1 )
  {
    a1[28] = 0;
    *(_QWORD *)&v5 = *(_QWORD *)a1;
    if ( *(_BYTE **)(*(_DWORD *)a1 + 4) != a1 || (_BYTE *)*v6 != a1 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    v4 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KeBugCheckCallbackLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KeBugCheckCallbackLock = 0;
  }
  KfLowerIrql(v2);
  return v4;
}
