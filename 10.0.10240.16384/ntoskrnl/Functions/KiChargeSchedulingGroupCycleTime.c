// KiChargeSchedulingGroupCycleTime 
 
unsigned int __fastcall KiChargeSchedulingGroupCycleTime(unsigned int result, __int64 *a2)
{
  __int64 v2; // r4
  __int64 v3; // kr00_8
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned __int64 v6; // kr08_8
  unsigned __int64 *v7; // r3
  unsigned __int64 v8; // kr10_8
  unsigned int *v9; // r2

  v2 = *a2;
  v3 = a2[5];
  a2[5] = *a2;
  __dmb(0xBu);
  v6 = v3 - v2;
  v5 = HIDWORD(v6);
  v4 = v6;
  v7 = (unsigned __int64 *)(result + 32);
  do
    v8 = __ldrexd(v7);
  while ( __strexd(v8 + __PAIR64__(v5, v4), v7) );
  __dmb(0xBu);
  if ( (__int64)(v8 + __PAIR64__(v5, v4)) <= 0 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(result + 48);
    do
      result = __ldrex(v9);
    while ( __strex(0, v9) );
    __dmb(0xBu);
    if ( result )
      result = KiInsertQueueDpc(result, 0, 0, 0, 0);
  }
  return result;
}
