// IopInsertPassiveInterruptBlock 
 
int __fastcall IopInsertPassiveInterruptBlock(_DWORD *a1, _BYTE *a2)
{
  int v4; // r9
  unsigned int v6; // r2
  int v7; // r6
  unsigned int *v8; // r2
  unsigned int v9; // r1
  int **v10; // r1

  *a2 = 1;
  v4 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F9A8();
  do
    v6 = __ldrex((unsigned int *)&PassiveInterruptListLock);
  while ( __strex(1u, (unsigned int *)&PassiveInterruptListLock) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(&PassiveInterruptListLock);
  v7 = IopFindPassiveInterruptBlockLocked(a1[2]);
  if ( !v7 )
  {
    __dmb(0xBu);
    v8 = a1 + 27;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 + 1, v8) );
    __dmb(0xBu);
    v10 = (int **)dword_630C84;
    *a1 = &PassiveInterruptList;
    a1[1] = v10;
    if ( *v10 != &PassiveInterruptList )
      __fastfail(3u);
    *v10 = a1;
    dword_630C84 = (int)a1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PassiveInterruptListLock);
  }
  else
  {
    __dmb(0xBu);
    PassiveInterruptListLock = 0;
  }
  KfLowerIrql(v4);
  if ( v7 )
    *a2 = 0;
  return 0;
}
