// sub_96915C 
 
void sub_96915C()
{
  _DWORD **v0; // r5
  _DWORD **v1; // r7
  _DWORD **v2; // r8

  IoDeleteDevice(*v1);
  IoDeleteDevice(*v2);
  IoDeleteDevice(*v0);
  JUMPOUT(0x951762);
}
