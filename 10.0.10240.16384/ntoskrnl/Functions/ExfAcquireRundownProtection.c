// ExfAcquireRundownProtection 
 
int __fastcall ExfAcquireRundownProtection(_DWORD *a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r4

  __pld(a1);
  v1 = *a1;
  if ( (*a1 & 1) != 0 )
    return 0;
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v2 = __ldrex(a1);
    while ( v2 == v1 && __strex(v1 + 2, a1) );
    __dmb(0xBu);
    if ( v2 == v1 )
      break;
    v1 = v2;
    if ( (v2 & 1) != 0 )
      return 0;
  }
  return 1;
}
