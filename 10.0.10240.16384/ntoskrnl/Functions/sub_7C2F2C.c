// sub_7C2F2C 
 
void __fastcall sub_7C2F2C(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6

  SeReleaseSecurityDescriptor(a1, *(_BYTE *)(a4 + 8), 1);
  *(_DWORD *)(*(_DWORD *)(v4 - 8) + 24) = v5;
  JUMPOUT(0x6B1DF8);
}
