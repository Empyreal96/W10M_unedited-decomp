// sub_546D28 
 
void sub_546D28()
{
  _DWORD *v0; // r6
  unsigned int v1; // r0
  unsigned int v2; // r1

  __pld(v0);
  v1 = *v0 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v2 = __ldrex(v0);
  while ( v2 == v1 && __strex(v1 - 2, v0) );
  if ( v2 != v1 )
    ExfReleaseRundownProtection((unsigned __int8 *)v0);
  JUMPOUT(0x4C31BC);
}
