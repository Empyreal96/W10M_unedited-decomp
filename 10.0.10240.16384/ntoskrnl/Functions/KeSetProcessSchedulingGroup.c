// KeSetProcessSchedulingGroup 
 
int __fastcall KeSetProcessSchedulingGroup(int a1, int a2)
{
  int v4; // r6
  unsigned int *v5; // r4
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r7
  _DWORD *i; // r5
  unsigned int v12; // r1

  v4 = KfRaiseIrql(2);
  v5 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51572C();
  v7 = (unsigned __int8 *)(a1 + 51);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1 + 48);
  while ( 1 )
  {
    v9 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex(v5);
      while ( v12 == v9 && __strex(v9 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = *(_DWORD *)(a1 + 144);
  if ( v10 != a2 )
  {
    for ( i = *(_DWORD **)(a1 + 40); i != (_DWORD *)(a1 + 40); i = (_DWORD *)*i )
    {
      if ( *(i - 100) != a2 )
        KiSetThreadSchedulingGroup(i - 117, a2);
    }
    *(_DWORD *)(a1 + 144) = a2;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 48);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v4);
  return v10;
}
