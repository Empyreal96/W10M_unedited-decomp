// ExInterlockedExtendZone 
 
int __fastcall ExInterlockedExtendZone(_DWORD *a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  int v8; // r6
  unsigned int v9; // r2
  int v10; // r4
  int vars4; // [sp+24h] [bp+4h]

  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)a4);
  }
  else
  {
    do
      v9 = __ldrex(a4);
    while ( __strex(1u, a4) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(a4);
  }
  v10 = ExExtendZone(a1, a2, a3);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *a4 = 0;
  }
  KfLowerIrql(v8);
  return v10;
}
