// ExAcquireRundownProtectionEx 
 
int __fastcall ExAcquireRundownProtectionEx(int *a1, int a2)
{
  int v2; // r4
  unsigned int v3; // r5
  int result; // r0

  __pld(a1);
  v2 = *a1;
  if ( (*a1 & 1) != 0 )
    return 0;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)a1);
  while ( v3 == v2 && __strex(v2 + 2 * a2, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v3 == v2 )
    result = 1;
  else
    result = sub_50D7D4();
  return result;
}
