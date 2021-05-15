// sub_96E384 
 
void sub_96E384()
{
  int v0; // r4
  int v1; // r5
  _BYTE *v2; // r2
  unsigned int i; // r3

  v2 = (_BYTE *)(v1 + 10203);
  for ( i = (v0 + 0x80000000) >> 22; i; --i )
    *v2-- = 3;
  JUMPOUT(0x95F948);
}
