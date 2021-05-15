// sub_7F1EFC 
 
void sub_7F1EFC()
{
  int v0; // r4
  int v1; // r5
  _DWORD *v2; // r6
  unsigned int v3; // r7
  int v4; // r9

  if ( v4 != KeReadStateSemaphore(v3) )
  {
    ExDereferenceCallBackBlock(v2, v3);
    JUMPOUT(0x78DFF6);
  }
  ExDereferenceCallBackBlock((_DWORD *)(v1 + 8 * v0), v3);
  JUMPOUT(0x78E028);
}
