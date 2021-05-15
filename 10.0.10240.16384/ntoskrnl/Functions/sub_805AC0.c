// sub_805AC0 
 
void sub_805AC0()
{
  unsigned int v0; // r6
  int v1; // r8
  int v2; // r9
  int v3; // r10

  memmove(v2, v1, v0);
  (*(void (__fastcall **)(int, unsigned int))(v3 + 16))(v1, v0);
  JUMPOUT(0x7516C0);
}
