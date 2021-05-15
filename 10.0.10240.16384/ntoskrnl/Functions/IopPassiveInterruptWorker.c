// IopPassiveInterruptWorker 
 
int __fastcall IopPassiveInterruptWorker(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r8
  unsigned int *v5; // r4
  unsigned int v7; // r2
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r1
  int v11; // r2
  _DWORD v12[4]; // [sp+8h] [bp-40h] BYREF
  _DWORD v13[12]; // [sp+18h] [bp-30h] BYREF

  IopAcquireReleaseDispatcherLock(a1, 1);
  if ( !*(_BYTE *)(a1 + 16) )
  {
    v2 = *(_DWORD *)(a1 + 28);
    v3 = *(_DWORD *)(a1 + 32);
    v12[0] = *(_DWORD *)(a1 + 24);
    v12[1] = v2;
    v12[2] = v3;
    KeSetSystemGroupAffinityThread((int)v12, v13);
  }
  v4 = KfRaiseIrql(12);
  v5 = (unsigned int *)(a1 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_554AB0();
  do
    v7 = __ldrex(v5);
  while ( __strex(1u, v5) );
  __dmb(0xBu);
  if ( v7 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 36));
  while ( *(_BYTE *)(a1 + 41) )
  {
    *(_BYTE *)(a1 + 41) = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(a1 + 36);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    KfLowerIrql(v4);
    v8 = *(_DWORD *)(a1 + 8);
    if ( *(_BYTE *)(a1 + 16) )
      KiInterruptDispatchCommon(1, v8, 1, 0, 0);
    else
      KiInterruptDispatchCommon(0, v8, 1, 0, 0);
    v4 = KfRaiseIrql(12);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(a1 + 36);
    }
    else
    {
      do
        v9 = __ldrex(v5);
      while ( __strex(1u, v5) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 36));
    }
  }
  *(_BYTE *)(a1 + 40) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 36);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v4);
  if ( !*(_BYTE *)(a1 + 16) )
    KeRevertToUserGroupAffinityThread((int)v13, v10, v11, *(unsigned __int8 *)(a1 + 16));
  IopAcquireReleaseDispatcherLock(a1, 0);
  if ( !*(_DWORD *)(a1 + 20) )
    off_617A64(*(_DWORD *)(a1 + 12), 2);
  return IopDereferencePassiveInterruptBlock((unsigned int *)a1);
}
