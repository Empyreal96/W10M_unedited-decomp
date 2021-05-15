// ExReleaseRundownProtectionCacheAwareEx 
 
int __fastcall ExReleaseRundownProtectionCacheAwareEx(_DWORD *a1, int a2)
{
  unsigned int v4; // r1
  unsigned int v5; // r0
  int result; // r0
  int v7; // r1
  int v8; // t0
  int *v9; // r5
  int v10; // r4
  unsigned int v11; // r1
  unsigned int *v12; // r4

  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v5 = a1[3];
  if ( !v5 )
    __brkdiv0();
  v8 = v4 / v5;
  v7 = v4 % v5;
  result = v8;
  v9 = (int *)(*a1 + v7 * a1[2]);
  __pld(v9);
  while ( 1 )
  {
    v10 = *v9;
    if ( (*v9 & 1) != 0 )
      break;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)v9);
    while ( v11 == v10 && __strex(v10 - 2 * a2, (unsigned int *)v9) );
    __dmb(0xBu);
    if ( v11 == v10 )
      return result;
  }
  if ( v10 == 1 )
    return sub_50AA2C(result);
  v12 = (unsigned int *)(v10 & 0xFFFFFFFE);
  __dmb(0xBu);
  do
    result = __ldrex(v12);
  while ( __strex(result - a2, v12) );
  __dmb(0xBu);
  if ( result == a2 )
    result = KeSetEvent(v12 + 1, 0, 0);
  return result;
}
