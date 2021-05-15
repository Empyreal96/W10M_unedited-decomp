// ExUnregisterCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExUnregisterCallback(int a1)
{
  int v1; // r9
  unsigned int *v3; // r4
  int v4; // r7
  unsigned int v6; // r2
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  unsigned int v9; // r2

  v1 = *(_DWORD *)(a1 + 8);
  v3 = (unsigned int *)(v1 + 4);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5553E8();
  do
    v6 = __ldrex(v3);
  while ( __strex(1u, v3) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(v1 + 4));
  while ( *(_DWORD *)(a1 + 20) )
  {
    *(_BYTE *)(a1 + 24) = 1;
    KeResetEvent((int)&ExpCallbackEvent);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v3);
    }
    else
    {
      __dmb(0xBu);
      *v3 = 0;
    }
    KfLowerIrql(v4);
    KeWaitForSingleObject((unsigned int)&ExpCallbackEvent, 0, 0, 0, 0);
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v3);
    }
    else
    {
      do
        v9 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire(v3);
    }
  }
  *(_QWORD *)&v7 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v8 != a1 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v4);
  ExFreePoolWithTag(a1, 0);
  return ObfDereferenceObjectWithTag(v1);
}
