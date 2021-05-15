// MiInsertPrivateVad 
 
int __fastcall MiInsertPrivateVad(int a1, int a2, int a3)
{
  int v6; // r7
  int result; // r0
  unsigned int *v8; // r5
  int v9; // r9
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1

  v6 = __mrc(15, 0, 13, 0, 3);
  if ( (*(_DWORD *)(a1 + 28) & 7) == 3 )
    return sub_51A4D4();
  v8 = (unsigned int *)(a3 + 492);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a3 + 492);
  }
  else
  {
    v10 = (unsigned __int8 *)(a3 + 495);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a3 + 492);
    while ( 1 )
    {
      v12 = *v8;
      if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(v8);
        while ( v13 == v12 && __strex(v12 | 0x40000000, v8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiInsertVad(a1, a3);
  if ( (*(_DWORD *)(a1 + 28) & 7) == 3 )
    MiCreatePageTablesForPhysicalRange(a1, v9);
  result = MiUnlockWorkingSetExclusive(a3 + 492, v9);
  if ( (*(_DWORD *)(a1 + 28) & 7) == 3 )
  {
    MiAweViewInserter(a3, a2);
    result = MiUnlockVad(v6 & 0xFFFFFFC0, a1);
  }
  return result;
}
