// sub_7C2298 
 
void sub_7C2298()
{
  _DWORD *v0; // r9

  if ( !ExfAcquireRundownProtection(v0) )
    JUMPOUT(0x6AABDA);
  JUMPOUT(0x6AABA2);
}
