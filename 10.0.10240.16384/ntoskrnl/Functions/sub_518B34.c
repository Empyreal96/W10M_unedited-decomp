// sub_518B34 
 
void __fastcall sub_518B34(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(a1 + 128), a8);
  JUMPOUT(0x4D9BF2);
}
