// sub_7EE330 
 
void sub_7EE330()
{
  _DWORD *v0; // r4

  if ( ObSetSecurityObjectByPointer((int)v0, 28) < 0 )
  {
    IoDeleteDevice(v0);
    JUMPOUT(0x77F79A);
  }
  JUMPOUT(0x77F7DA);
}
