// ViCreateProcessCallbackInternal 
 
void __fastcall __spoils<R2,R3,R12> ViCreateProcessCallbackInternal(__int64 a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r3
  int v5; // r9
  unsigned int v6; // r2
  unsigned int *v7; // r2
  unsigned int v8; // r4
  __int64 v9; // [sp+0h] [bp-28h] BYREF
  _DWORD var20[10]; // [sp+8h] [bp-20h] BYREF

  v9 = a1;
  var20[0] = a2;
  var20[1] = a3;
  if ( HIDWORD(a1) && PsLookupProcessByProcessId(a1, (int *)&v9 + 1) >= 0 )
  {
    v3 = HIDWORD(v9);
    if ( PsGetAllocatedFullProcessImageName(SHIDWORD(v9), &v9) >= 0 )
    {
      ViFaultsGetBaseImageName(v9, var20);
      RtlUpcaseUnicodeString((unsigned __int16 *)var20, (unsigned __int16 *)var20, 0, v4);
      v5 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
      }
      else
      {
        do
          v6 = __ldrex((unsigned int *)&ViFaultInjectionLock);
        while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
        __dmb(0xBu);
        if ( v6 )
          KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
      }
      ViFaultLockOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( ViFaultsIsAppTarget(var20) )
      {
        __dmb(0xBu);
        v7 = (unsigned int *)(v3 + 188);
        do
          v8 = __ldrex(v7);
        while ( __strex(v8 | 0x10000, v7) );
        __dmb(0xBu);
      }
      ViFaultLockOwner = 0;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&ViFaultInjectionLock, var20[9]);
      }
      else
      {
        __dmb(0xBu);
        ViFaultInjectionLock = 0;
      }
      KfLowerIrql(v5);
      ExFreePoolWithTag(v9);
    }
    ObfDereferenceObjectWithTag(v3);
  }
}
