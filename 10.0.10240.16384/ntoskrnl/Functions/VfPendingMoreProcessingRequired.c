// VfPendingMoreProcessingRequired 
 
int __fastcall VfPendingMoreProcessingRequired(int a1, int a2, int a3, int a4)
{
  int v7; // r6
  int v8; // r0
  int v9; // r4
  int v10; // r1
  unsigned int *v11; // r5
  char v12; // r7
  unsigned int v13; // r2

  v7 = 0;
  v8 = VfIrpDatabaseEntryFindAndLock(a2);
  v9 = v8;
  if ( v8 )
  {
    if ( a3 == *(_DWORD *)(v8 + 128) )
    {
      v10 = *(_DWORD *)(v8 + 36);
      if ( v10 >= 0 )
      {
        *(_DWORD *)(v8 + 36) = v10 | 0x80000000;
        v7 = 1;
      }
    }
    VfIrpDatabaseEntryReleaseLock(v8);
    if ( v7 )
    {
      v7 = ViPendingDelayCompletion(a1, v9, a3, a4);
      if ( !v7 )
      {
        v11 = (unsigned int *)(v9 + 4);
        v12 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v9 + 4);
        }
        else
        {
          do
            v13 = __ldrex(v11);
          while ( __strex(1u, v11) );
          __dmb(0xBu);
          if ( v13 )
            KxWaitForSpinLockAndAcquire((unsigned int *)(v9 + 4));
        }
        *(_BYTE *)(v9 + 8) = v12;
        VfIrpDatabaseEntryDereference(v9, 1);
        VfIrpDatabaseEntryReleaseLock(v9);
      }
    }
  }
  return v7;
}
