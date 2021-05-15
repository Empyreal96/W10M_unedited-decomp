// PoFxCompleteDevicePowerNotRequired 
 
int __fastcall PoFxCompleteDevicePowerNotRequired(int result)
{
  int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r6
  signed int v4; // r6
  bool v5; // nf
  unsigned int *v6; // r4
  int v7; // r8
  unsigned int v8; // r2

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 24);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  v5 = v4 < 0;
  if ( !v4 )
  {
    v6 = (unsigned int *)(result + 184);
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_523660();
    do
      v8 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire(v1 + 184);
    if ( *(_DWORD *)(v1 + 20) == 2 )
      PopFxQueueWorkOrder(&PopFxSystemWorkQueue, v1 + 156, v1, 0);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v1 + 184);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    result = KfLowerIrql(v7);
    v5 = 0;
  }
  if ( v5 )
    PopFxBugCheck(1555, v1, 0, 0);
  return result;
}
