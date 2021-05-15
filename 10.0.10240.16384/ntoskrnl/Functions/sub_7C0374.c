// sub_7C0374 
 
void sub_7C0374()
{
  _DWORD *v0; // r4
  int v1; // r1

  v1 = (v0[240] >> 9) & 7;
  if ( (*(_DWORD *)(v0[84] + 192) & 0x100000) != 0 )
    v1 = 0;
  if ( v1 < 2 && v0 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v0[250] )
    v1 = 2;
  IoBoostThreadIoPriority((int)v0, v1, 0);
  JUMPOUT(0x6A660C);
}
