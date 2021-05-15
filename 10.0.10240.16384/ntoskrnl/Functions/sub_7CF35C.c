// sub_7CF35C 
 
void sub_7CF35C()
{
  int v0; // r4
  int v1; // r5
  _DWORD *i; // r2
  int v3; // r3
  unsigned int v4; // r3

  for ( i = *(_DWORD **)(v0 + 12); i != (_DWORD *)(v0 + 12); i = (_DWORD *)*i )
  {
    v3 = i[7];
    if ( v1 )
      v4 = v3 | 4;
    else
      v4 = v3 & 0xFFFFFFFB;
    i[7] = v4;
  }
  JUMPOUT(0x7886D8);
}
