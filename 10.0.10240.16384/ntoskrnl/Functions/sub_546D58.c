// sub_546D58 
 
void sub_546D58()
{
  _DWORD *v0; // r4
  int v1; // r9
  int v2; // r8
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r1
  _DWORD *v6; // r5
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r2

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&ExpCallBackFlush);
  }
  else
  {
    v3 = ExpCallBackFlush & 0x7FFFFFFF;
    v4 = (ExpCallBackFlush & 0x7FFFFFFF) + 1;
    do
      v5 = __ldrex((unsigned int *)&ExpCallBackFlush);
    while ( v5 == v3 && __strex(v4, (unsigned int *)&ExpCallBackFlush) );
    __dmb(0xBu);
    if ( v5 != v3 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ExpCallBackFlush);
  }
  v6 = (_DWORD *)(*v0 & ~v1);
  if ( v6 )
  {
    __pld(v6);
    v7 = *v6 & 0xFFFFFFFE;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 2, v6) );
    __dmb(0xBu);
    if ( v8 != v7 && !ExfAcquireRundownProtection(v6) )
      v6 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ExpCallBackFlush);
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&ExpCallBackFlush);
    while ( __strex(v9 & 0xBFFFFFFF, (unsigned int *)&ExpCallBackFlush) );
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&ExpCallBackFlush);
    while ( __strex(v10 - 1, (unsigned int *)&ExpCallBackFlush) );
  }
  KfLowerIrql(v2);
  if ( v6 )
    JUMPOUT(0x4C3204);
  JUMPOUT(0x4C31EC);
}
