// sub_54B76C 
 
void sub_54B76C()
{
  _DWORD *v0; // r6

  if ( !ExfAcquireRundownProtection(v0) )
    JUMPOUT(0x4D3D46);
  JUMPOUT(0x4D3D10);
}
