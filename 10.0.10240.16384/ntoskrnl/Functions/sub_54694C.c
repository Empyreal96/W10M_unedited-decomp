// sub_54694C 
 
void sub_54694C()
{
  _DWORD *v0; // r4
  unsigned int v1; // r2

  v1 = -v0[903];
  if ( v0[2413] << 22 <= v1 / 3 && v0[2414] << 22 <= v1 / 3 )
    JUMPOUT(0x4C1266);
  JUMPOUT(0x4C12A0);
}
