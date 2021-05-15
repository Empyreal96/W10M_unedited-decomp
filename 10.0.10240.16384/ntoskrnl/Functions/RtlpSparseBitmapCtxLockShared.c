// RtlpSparseBitmapCtxLockShared 
 
int __fastcall RtlpSparseBitmapCtxLockShared(int a1, unsigned int *a2)
{
  int v4; // r5
  int v5; // r0
  unsigned int v6; // r1

  if ( (*(_DWORD *)(a1 + 48) & 4) != 0 )
    return 1;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(a2);
  }
  else
  {
    v5 = *a2 & 0x7FFFFFFF;
    do
      v6 = __ldrex(a2);
    while ( v6 == v5 && __strex(v5 + 1, a2) );
    __dmb(0xBu);
    if ( v6 != v5 )
      ExpWaitForSpinLockSharedAndAcquire(a2);
  }
  return v4;
}
