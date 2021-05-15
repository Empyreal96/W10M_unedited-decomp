// PspGetProperty 
 
int __fastcall PspGetProperty(int a1, int a2, _DWORD *a3)
{
  unsigned int *v4; // r4
  int v7; // r6
  int v8; // r10
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5

  v4 = (unsigned int *)(a1 + 8);
  v7 = 0;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F780();
  do
    v10 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(v4);
  v11 = PspFindPropertySetEntry(a1, a2);
  v12 = v11;
  if ( v11 )
    ObfReferenceObjectWithTag(*(_DWORD *)(v11 + 12), 1917875024);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v8);
  if ( !v12 )
    return -1073741275;
  *a3 = *(_DWORD *)(v12 + 12);
  return v7;
}
