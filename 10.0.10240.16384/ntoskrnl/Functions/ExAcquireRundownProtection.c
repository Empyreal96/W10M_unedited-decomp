// ExAcquireRundownProtection 
 
int __fastcall ExAcquireRundownProtection(_DWORD *a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r1
  int result; // r0

  __pld(a1);
  v1 = *a1 & 0xFFFFFFFE;
  do
    v2 = __ldrex(a1);
  while ( v2 == v1 && __strex(v1 + 2, a1) );
  __dmb(0xBu);
  if ( v2 == v1 )
    result = 1;
  else
    result = ExfAcquireRundownProtection(a1);
  return result;
}
