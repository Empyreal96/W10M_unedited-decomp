// PiDrvDbUnloadNodeReset 
 
int __fastcall PiDrvDbUnloadNodeReset(int a1)
{
  unsigned int *v2; // r4
  int v3; // r5
  unsigned int v5; // r2

  v2 = (unsigned int *)(a1 + 240);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5553C8();
  do
    v5 = __ldrex(v2);
  while ( __strex(1u, v2) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire(v2);
  *(_BYTE *)(a1 + 244) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  return KfLowerIrql(v3);
}
