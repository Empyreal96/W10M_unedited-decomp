// ExReleaseRundownProtectionCacheAware 
 
int __fastcall ExReleaseRundownProtectionCacheAware(_DWORD *a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r0
  int result; // r0
  int v5; // r1
  int v6; // t0
  int *v7; // r5
  int v8; // r4
  unsigned int v9; // r1

  v2 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v3 = a1[3];
  if ( !v3 )
    __brkdiv0();
  v6 = v2 / v3;
  v5 = v2 % v3;
  result = v6;
  v7 = (int *)(*a1 + v5 * a1[2]);
  __pld(v7);
  while ( 1 )
  {
    v8 = *v7;
    if ( (*v7 & 1) != 0 )
      break;
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)v7);
    while ( v9 == v8 && __strex(v8 - 2, (unsigned int *)v7) );
    __dmb(0xBu);
    if ( v9 == v8 )
      return result;
  }
  return sub_51DC58(result);
}
