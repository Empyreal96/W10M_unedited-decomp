// ExAcquireRundownProtectionCacheAware 
 
int __fastcall ExAcquireRundownProtectionCacheAware(_DWORD *a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r0
  _DWORD *v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r0
  int result; // r0

  v2 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v3 = a1[3];
  if ( !v3 )
    __brkdiv0();
  v4 = (_DWORD *)(*a1 + v2 % v3 * a1[2]);
  __pld(v4);
  v5 = *v4 & 0xFFFFFFFE;
  v6 = v5 + 2;
  do
    v7 = __ldrex(v4);
  while ( v7 == v5 && __strex(v6, v4) );
  __dmb(0xBu);
  if ( v7 == v5 )
    result = 1;
  else
    result = sub_51DC10(v7, v6);
  return result;
}
