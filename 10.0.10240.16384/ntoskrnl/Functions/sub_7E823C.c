// sub_7E823C 
 
void __fastcall sub_7E823C(int a1, unsigned int a2)
{
  int v2; // r6
  unsigned int v3; // r8
  unsigned int *v4; // r9
  char v5; // [sp+18h] [bp-30h] BYREF

  HvFreeCell(v2, a2);
  (*(void (__fastcall **)(int, char *))(v2 + 8))(v2, &v5);
  HvFreeCell(v2, *v4);
  *v4 = v3;
  JUMPOUT(0x6FAFF2);
}
