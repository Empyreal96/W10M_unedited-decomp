// sub_817580 
 
void sub_817580()
{
  _DWORD *v0; // r5

  if ( *v0 )
  {
    PiSwInterfaceFree(*v0);
    *v0 = 0;
  }
  JUMPOUT(0x7AF69E);
}
