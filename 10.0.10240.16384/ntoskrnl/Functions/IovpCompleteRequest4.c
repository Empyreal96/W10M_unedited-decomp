// IovpCompleteRequest4 
 
int __fastcall IovpCompleteRequest4(int result, int a2, int a3, _DWORD *a4)
{
  int v6; // r5
  int v7; // r4
  unsigned int *v8; // r6
  char v9; // r8
  unsigned int v10; // r2
  unsigned __int8 *v11; // r6
  int v12; // r3

  v6 = result;
  if ( *a4 )
  {
    v7 = a4[1];
    v8 = (unsigned int *)(v7 + 4);
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v7 + 4);
    }
    else
    {
      do
        v10 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( v10 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 4));
    }
    *(_BYTE *)(v7 + 8) = v9;
    if ( a2 != -1073741802 )
    {
      v11 = *(unsigned __int8 **)(v6 + 96);
      if ( *(char *)(v6 + 35) <= *(char *)(v6 + 34) )
      {
        v12 = *v11;
        if ( (v12 == 3 || v12 == 4) && *(_DWORD *)(v6 + 4) && (MmVerifierData & 0x6000) != 0 )
          MdlInvariantPostDriverCompletion((_BYTE *)v7, v6);
      }
      if ( *(_DWORD *)(v7 + 128) && *(int *)(v7 + 36) >= 0 && (v11[3] & 1) == 0 )
      {
        VfErrorReport1(552, a3, v6);
        *(_BYTE *)(*(_DWORD *)(v6 + 96) + 3) |= 1u;
      }
    }
    result = VfIrpDatabaseEntryReleaseLock(v7);
  }
  return result;
}
