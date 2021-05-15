// VF_MARK_FOR_DEFERRED_REMOVE 
 
__int64 __fastcall VF_MARK_FOR_DEFERRED_REMOVE(int a1)
{
  int v2; // r6
  unsigned int v3; // r1
  int i; // r2
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_908C58);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&dword_908C58);
    while ( __strex(1u, (unsigned int *)&dword_908C58) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C58);
  }
  for ( i = ViAdapterList; &ViAdapterList != (int *)i; i = *(_DWORD *)i )
  {
    if ( *(_DWORD *)(i + 12) == a1 )
      *(_BYTE *)(i + 16) = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_908C58, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_908C58 = 0;
  }
  return KfLowerIrql(v2);
}
