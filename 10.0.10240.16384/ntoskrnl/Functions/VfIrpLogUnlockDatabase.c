// VfIrpLogUnlockDatabase 
 
__int64 __fastcall VfIrpLogUnlockDatabase(int a1)
{
  int v1; // r5
  int v2; // r8
  unsigned int v3; // r2
  _DWORD *v4; // r7
  _DWORD *v5; // r5
  unsigned int v6; // r6
  int v7; // r3
  __int64 v8; // r0
  int vars4; // [sp+24h] [bp+4h]

  v1 = 3 * a1;
  *(_DWORD *)(ViIrpLogDatabase + 12 * a1) = 0;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViIrpLogDatabaseLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&ViIrpLogDatabaseLock);
    while ( __strex(1u, (unsigned int *)&ViIrpLogDatabaseLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViIrpLogDatabaseLock);
  }
  v4 = (_DWORD *)(ViIrpLogDatabase + 4 * v1 + 4);
  v5 = (_DWORD *)*v4;
  while ( v5 != v4 )
  {
    v6 = (unsigned int)(v5 - 1);
    v7 = v5[2];
    v5 = (_DWORD *)*v5;
    if ( (v7 & 4) != 0 )
    {
      ObfDereferenceObject(*(_DWORD *)v6);
      v8 = *(_QWORD *)(v6 + 4);
      if ( *(_DWORD *)(v8 + 4) != v6 + 4 || *(_DWORD *)HIDWORD(v8) != v6 + 4 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v8) = v8;
      *(_DWORD *)(v8 + 4) = HIDWORD(v8);
      ExFreePoolWithTag(v6);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViIrpLogDatabaseLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViIrpLogDatabaseLock = 0;
  }
  return KfLowerIrql(v2);
}
