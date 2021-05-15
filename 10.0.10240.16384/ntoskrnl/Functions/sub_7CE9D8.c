// sub_7CE9D8 
 
void sub_7CE9D8()
{
  int v0; // r4
  _DWORD *v1; // r5
  int v2; // r8
  unsigned int v3; // r2

  v3 = v1[4];
  if ( v3 < v1[2] )
    v3 = v1[2];
  MiUnlockCodePage(
    (v2 & ((unsigned int)(v1[3] + v0) >> 10)) - 0x40000000,
    (v2 & ((v1[3] + v0 + v3 + 4095) >> 10)) - 1073741828);
  JUMPOUT(0x773F8E);
}
