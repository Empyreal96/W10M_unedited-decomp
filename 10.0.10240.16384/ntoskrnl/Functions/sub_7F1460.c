// sub_7F1460 
 
void sub_7F1460()
{
  int v0; // r4
  unsigned int v1; // r6
  int v2; // r8

  *(_DWORD *)(v0 + 20) = v1;
  memmove(v0 + 24, v2, v1);
  JUMPOUT(0x78C17E);
}
