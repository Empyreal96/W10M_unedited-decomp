// sub_8061C0 
 
void sub_8061C0()
{
  _BYTE *v0; // r5
  char v1; // r8
  int v2; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  UNLOCK_ADDRESS_SPACE(v2, *(_DWORD *)(v2 + 0x74));
  *v0 = v1;
  JUMPOUT(0x753344);
}
