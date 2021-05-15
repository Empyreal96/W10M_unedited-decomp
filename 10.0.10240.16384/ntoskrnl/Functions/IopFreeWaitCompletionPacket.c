// IopFreeWaitCompletionPacket 
 
int __fastcall IopFreeWaitCompletionPacket(int a1, int a2)
{
  int v2; // r8
  unsigned int *v4; // r4
  int v6; // r9
  unsigned int v8; // r2

  v2 = *(_DWORD *)(a1 + 40);
  v4 = (unsigned int *)(a1 + 48);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_522BE0();
  do
    v8 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire(v4);
  __dmb(0xBu);
  *(_BYTE *)(a1 + 52) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v6);
  ObfDereferenceObjectWithTag(v2);
  ObfDereferenceObjectWithTag(a2);
  return ObfDereferenceObjectWithTag(a1);
}
