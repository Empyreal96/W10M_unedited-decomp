// sub_555A60 
 
void __fastcall sub_555A60(int a1, int a2)
{
  int v2; // r4
  void (__fastcall *v3)(unsigned int); // r5

  v3(bswap32(__ROR4__(a1 ^ *(_DWORD *)(v2 + 92), -(char)a1) ^ v2) ^ a2);
  JUMPOUT(0x4F89EC);
}
