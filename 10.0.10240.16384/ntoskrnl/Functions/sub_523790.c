// sub_523790 
 
void __fastcall sub_523790(int a1)
{
  _DWORD *v1; // r5
  _DWORD *v2; // r6
  unsigned int v3; // r3
  int v4; // r2

  IoGetActivityIdIrp(a1, v1);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD *)(v3 + 1036);
  *(_DWORD *)(v3 + 1036) = v1;
  *v2 = v4;
  JUMPOUT(0x45A518);
}
