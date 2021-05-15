// sub_7C6E38 
 
void sub_7C6E38()
{
  int v0; // r5

  *(_DWORD *)(v0 + 24) = -1073741811;
  IofCompleteRequest(v0, 0);
  JUMPOUT(0x6CADEA);
}
