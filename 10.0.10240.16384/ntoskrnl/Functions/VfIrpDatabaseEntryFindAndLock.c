// VfIrpDatabaseEntryFindAndLock 
 
int __fastcall VfIrpDatabaseEntryFindAndLock(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v6; // r1
  __int64 v7; // r2
  int v8; // r0
  unsigned int *v9; // r6
  unsigned int v10; // r2
  char v11; // r7
  unsigned int *v12; // r5
  unsigned int v13; // r2
  unsigned int v14; // r2
  _DWORD v16[6]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a3;
  v16[1] = a4;
  v4 = 0;
  if ( !VfIrpDatabaseInitialized )
    return v4;
  v6 = a1 + 112;
  v7 = *(_QWORD *)(ViIrpDatabaseAddressRanges + 8 * (unsigned __int8)(-125 * (a1 >> 12)));
  __dmb(0xBu);
  if ( (unsigned int)v7 >= HIDWORD(v7) )
    return v4;
  if ( a1 <= (unsigned int)v7 )
  {
    if ( v6 >= HIDWORD(v7) )
      goto LABEL_9;
    if ( a1 < (unsigned int)v7 )
    {
LABEL_7:
      if ( v6 <= (unsigned int)v7 || v6 > HIDWORD(v7) )
        return v4;
      goto LABEL_9;
    }
  }
  if ( a1 >= HIDWORD(v7) )
    goto LABEL_7;
LABEL_9:
  ViIrpDatabaseAcquireLockShared(v16);
  v8 = ViIrpDatabaseFindPointer(a1);
  v4 = v8;
  if ( v8 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(v8 + 12);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
    __dmb(0xBu);
    v11 = v16[0];
    ViIrpDatabaseReleaseLockShared(LOBYTE(v16[0]));
    v12 = (unsigned int *)(v4 + 4);
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v4 + 4);
    }
    else
    {
      do
        v13 = __ldrex(v12);
      while ( __strex(1u, v12) );
      __dmb(0xBu);
      if ( v13 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v4 + 4));
    }
    *(_BYTE *)(v4 + 8) = v11;
    __dmb(0xBu);
    do
      v14 = __ldrex(v9);
    while ( __strex(v14 - 1, v9) );
    __dmb(0xBu);
    if ( !*(_DWORD *)(v4 + 16) )
    {
      VfIrpDatabaseEntryReleaseLock(v4);
      v4 = 0;
    }
  }
  else
  {
    ViIrpDatabaseReleaseLockShared(LOBYTE(v16[0]));
  }
  return v4;
}
