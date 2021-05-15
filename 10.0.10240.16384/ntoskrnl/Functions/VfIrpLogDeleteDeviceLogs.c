// VfIrpLogDeleteDeviceLogs 
 
__int64 __fastcall VfIrpLogDeleteDeviceLogs(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  unsigned int v6; // r2
  int *v7; // r0
  unsigned int v8; // r5
  __int64 v9; // kr00_8
  int var18[8]; // [sp+0h] [bp-18h] BYREF

  var18[0] = a3;
  var18[1] = a4;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViIrpLogDatabaseLock);
  }
  else
  {
    do
      v6 = __ldrex((unsigned int *)&ViIrpLogDatabaseLock);
    while ( __strex(1u, (unsigned int *)&ViIrpLogDatabaseLock) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViIrpLogDatabaseLock);
  }
  v7 = (int *)ViIrpLogDatabaseFindPointer(a1, var18);
  v8 = (unsigned int)v7;
  if ( v7 )
  {
    if ( *(_DWORD *)var18[0] )
    {
      v7[3] |= 4u;
    }
    else
    {
      ObfDereferenceObject(*v7);
      v9 = *(_QWORD *)(v8 + 4);
      if ( *(_DWORD *)(v9 + 4) != v8 + 4 || *(_DWORD *)HIDWORD(v9) != v8 + 4 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v9) = v9;
      *(_DWORD *)(v9 + 4) = HIDWORD(v9);
      ExFreePoolWithTag(v8);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViIrpLogDatabaseLock, var18[7]);
  }
  else
  {
    __dmb(0xBu);
    ViIrpLogDatabaseLock = 0;
  }
  return KfLowerIrql(v5);
}
