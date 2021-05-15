// PpDevNodeInsertIntoTree 
 
int __fastcall PpDevNodeInsertIntoTree(_DWORD *a1, int a2)
{
  int v4; // r8
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int v8; // r3
  _DWORD *v9; // r3

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_518A64();
  do
    v6 = __ldrex((unsigned int *)&PnpSpinLock);
  while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  v7 = a1[19] + 1;
  v8 = IopMaxDeviceNodeLevel;
  *(_DWORD *)(a2 + 76) = v7;
  if ( v7 > v8 )
    IopMaxDeviceNodeLevel = v7;
  *(_DWORD *)(a2 + 8) = a1;
  __dmb(0xFu);
  v9 = (_DWORD *)a1[3];
  if ( v9 )
    *v9 = a2;
  else
    a1[1] = a2;
  a1[3] = a2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  return KfLowerIrql(v4);
}
