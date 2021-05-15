// sub_8061A4 
 
void sub_8061A4()
{
  int v0; // r5
  char v1; // r8
  _BYTE *v2; // r3

  v2 = *(_BYTE **)(v0 + 116);
  __dmb(0xBu);
  *v2 = v1;
  *(_DWORD *)(v0 + 8) &= 0xFFFFFFFB;
  JUMPOUT(0x7532BE);
}
