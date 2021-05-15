// sub_54B704 
 
void sub_54B704()
{
  _DWORD *v0; // r6

  if ( ExfAcquireRundownProtection(v0) )
    JUMPOUT(0x4D3C2A);
  JUMPOUT(0x4D3CBC);
}
