// PspSetEffectiveRateControlJob 
 
int __fastcall PspSetEffectiveRateControlJob(_DWORD *a1, int a2, int a3)
{
  int result; // r0
  unsigned int *v7; // r4
  unsigned int v8; // r6
  unsigned int *v9; // r2
  unsigned int v10; // r4

  result = PspGetRateControlJobFlag(a3, 0);
  __dmb(0xBu);
  if ( a2 )
  {
    v7 = a1 + 186;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | result, v7) );
  }
  else
  {
    result = ~result;
    v9 = a1 + 186;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & result, v9) );
  }
  __dmb(0xBu);
  if ( a3 )
    a1[97] = a2;
  else
    a1[98] = a2;
  return result;
}
