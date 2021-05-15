// KeAcquireSpinLockForDpc 
 
int __fastcall KeAcquireSpinLockForDpc(unsigned int *a1)
{
  int v2; // r5
  unsigned int v3; // r2

  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) == 0 )
    {
      do
        v3 = __ldrex(a1);
      while ( __strex(1u, a1) );
      goto LABEL_8;
    }
LABEL_6:
    KiAcquireSpinLockInstrumented((int)a1);
    return v2;
  }
  v2 = 2;
  if ( (dword_682604 & 0x210000) != 0 )
    goto LABEL_6;
  do
    v3 = __ldrex(a1);
  while ( __strex(1u, a1) );
LABEL_8:
  __dmb(0xBu);
  if ( v3 )
    KxWaitForSpinLockAndAcquire(a1);
  return v2;
}
