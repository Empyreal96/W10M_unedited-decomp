// sub_817954 
 
void sub_817954()
{
  int v0; // r5
  int v1; // r6
  int v2; // r0

  v2 = *(_DWORD *)(v0 + 12);
  *(_DWORD *)(v0 + 20) |= v1;
  (*(void (__fastcall **)(int))(v0 + 8))(v2);
  JUMPOUT(0x7B0472);
}
