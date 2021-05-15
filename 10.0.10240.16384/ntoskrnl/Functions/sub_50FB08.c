// sub_50FB08 
 
void __fastcall sub_50FB08(_DWORD *a1)
{
  int v1; // r6
  int v2; // r8

  __dmb(0xBu);
  *a1 = 0;
  KfLowerIrql(v2);
  ExFreePoolWithTag(v1, 1950639443);
  JUMPOUT(0x4261AC);
}
