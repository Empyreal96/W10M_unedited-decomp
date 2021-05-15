// ExpWnfDeleteNameInstanceCallback 
 
int __fastcall ExpWnfDeleteNameInstanceCallback(int a1, int a2)
{
  _DWORD *v3; // r0
  unsigned int v5; // r5
  unsigned int v6; // r4

  v3 = (_DWORD *)(a1 - 4);
  __pld(v3);
  v5 = *v3 & 0xFFFFFFFE;
  do
    v6 = __ldrex(v3);
  while ( v6 == v5 && __strex(v5 + 2, v3) );
  __dmb(0xBu);
  if ( v6 != v5 )
    ExfAcquireRundownProtection(v3);
  return ExpWnfDeleteNameInstance(a2, a1 - 8, 0);
}
