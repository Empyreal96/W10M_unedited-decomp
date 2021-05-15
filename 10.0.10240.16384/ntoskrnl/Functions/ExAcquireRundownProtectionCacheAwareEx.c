// ExAcquireRundownProtectionCacheAwareEx 
 
int __fastcall ExAcquireRundownProtectionCacheAwareEx(_DWORD *a1, int a2)
{
  unsigned int v4; // r1
  unsigned int v5; // r0
  int *v6; // r5
  int v7; // r4
  unsigned int v8; // r0
  int result; // r0

  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v5 = a1[3];
  if ( !v5 )
    __brkdiv0();
  v6 = (int *)(*a1 + v4 % v5 * a1[2]);
  __pld(v6);
  v7 = *v6;
  if ( (*v6 & 1) != 0 )
    return 0;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v6);
  while ( v8 == v7 && __strex(v7 + 2 * a2, (unsigned int *)v6) );
  __dmb(0xBu);
  if ( v8 == v7 )
    result = 1;
  else
    result = sub_50D7C8();
  return result;
}
