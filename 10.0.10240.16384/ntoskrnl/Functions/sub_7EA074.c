// sub_7EA074 
 
void __fastcall sub_7EA074(_DWORD *a1)
{
  int v1; // r4
  int v2; // r8

  AlpcDeleteBlobByHandle(a1, *(_DWORD *)(v1 + 12), v1);
  *(_DWORD *)(v1 + 8) = v2;
  JUMPOUT(0x70423E);
}
