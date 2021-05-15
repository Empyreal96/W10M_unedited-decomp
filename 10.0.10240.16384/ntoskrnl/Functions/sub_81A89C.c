// sub_81A89C 
 
void sub_81A89C()
{
  _DWORD *v0; // r4

  if ( (v0[12] & 0x10) != 0 && (*v0 || v0[4] || v0[1] || v0[8]) )
    JUMPOUT(0x7B7EA8);
  JUMPOUT(0x7B7E4A);
}
