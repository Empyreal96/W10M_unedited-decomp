// sub_517F58 
 
void sub_517F58()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r6
  int v2; // r8

  while ( (v1[6] & 1) != 0 || !AuthzBasepEqualUnicodeString((int)(v1 + 2), v2) )
  {
    v1 = (_DWORD *)*v1;
    if ( v1 == v0 )
      JUMPOUT(0x43AD9E);
  }
  JUMPOUT(0x43ADA4);
}
