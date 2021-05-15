// sub_54B0AC 
 
void sub_54B0AC()
{
  int v0; // r6
  _DWORD *v1; // r9

  *(_DWORD *)(v0 + 24) = 0;
  *(_DWORD *)(v0 + 28) = 0;
  pIofCompleteRequest(v0, 0);
  *v1 = 0;
  JUMPOUT(0x4D249C);
}
