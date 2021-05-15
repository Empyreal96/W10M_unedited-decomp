// sub_7D651C 
 
void sub_7D651C()
{
  int v0; // r4
  _DWORD *v1; // r5
  unsigned int *v2; // r1
  unsigned int v3; // r0
  signed int v4; // r0

  v2 = (unsigned int *)(v0 + 12);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 + 1;
  }
  while ( __strex(v4, v2) );
  if ( v4 <= 1 )
    __fastfail(0xEu);
  *v1 = v0;
  JUMPOUT(0x6DC96A);
}
