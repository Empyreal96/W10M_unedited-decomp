// IovpCompleteRequest3 
 
int __fastcall IovpCompleteRequest3(int result, int a2, int a3)
{
  int v5; // r6
  int v6; // r7
  unsigned int *v7; // r5
  char v8; // r9
  unsigned int v9; // r2
  _BYTE *v10; // r1
  bool v11; // r3

  v5 = result;
  if ( *(_DWORD *)a3 )
  {
    v6 = *(_DWORD *)(a3 + 4);
    v7 = (unsigned int *)(v6 + 4);
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v6 + 4);
    }
    else
    {
      do
        v9 = __ldrex(v7);
      while ( __strex(1u, v7) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v6 + 4));
    }
    *(_BYTE *)(v6 + 8) = v8;
    v10 = *(_BYTE **)(v5 + 96);
    v11 = *(char *)(v5 + 35) <= *(char *)(v5 + 34) && *v10 == 27 && v10[1] == 2;
    *(_BYTE *)(a3 + 8) = v11;
    *(_DWORD *)(a3 + 16) = a2;
    result = VfIrpDatabaseEntryReleaseLock(v6);
  }
  return result;
}
