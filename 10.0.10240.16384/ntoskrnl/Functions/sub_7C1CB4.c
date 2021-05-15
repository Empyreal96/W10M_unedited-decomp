// sub_7C1CB4 
 
void __fastcall sub_7C1CB4(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6

  *(_BYTE *)(v3 + 375) = *(_BYTE *)(v4 + 424);
  PsSetProcessPriorityByClass(v3, *(unsigned __int8 *)(v3 + 606) == 2, a3, *(unsigned __int8 *)(v3 + 606));
  JUMPOUT(0x6AA656);
}
