// sub_7F7594 
 
void sub_7F7594()
{
  _DWORD *v0; // r5
  unsigned int v1; // r4
  unsigned int v2; // r1

  __pld(v0);
  v1 = *v0 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v2 = __ldrex(v0);
  while ( v2 == v1 && __strex(v1 - 2, v0) );
  if ( v2 != v1 )
    ExfReleaseRundownProtection((unsigned __int8 *)v0);
  JUMPOUT(0x71BBF6);
}
