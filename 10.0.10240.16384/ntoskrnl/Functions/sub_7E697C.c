// sub_7E697C 
 
void sub_7E697C()
{
  _DWORD *v0; // r6

  if ( ExfAcquireRundownProtection(v0) == 1 )
    JUMPOUT(0x6F2986);
  JUMPOUT(0x6F29C8);
}
