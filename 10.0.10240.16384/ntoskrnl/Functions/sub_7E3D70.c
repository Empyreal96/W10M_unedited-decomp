// sub_7E3D70 
 
void sub_7E3D70()
{
  _DWORD *v0; // r4

  if ( v0[3] )
    ZwClose();
  if ( v0[2] )
    ZwClose();
  if ( v0[4] )
    ZwClose();
  if ( v0[1] )
    ZwClose();
  ZwClose();
  JUMPOUT(0x77C57E);
}
