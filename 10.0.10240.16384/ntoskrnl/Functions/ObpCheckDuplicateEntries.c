// ObpCheckDuplicateEntries 
 
BOOL __fastcall ObpCheckDuplicateEntries(int a1)
{
  _DWORD v2[3]; // [sp+0h] [bp-20h] BYREF
  int v3; // [sp+Ch] [bp-14h]
  int v4; // [sp+10h] [bp-10h]
  int v5; // [sp+14h] [bp-Ch]

  v2[0] = a1;
  v2[1] = a1;
  v4 = 0;
  v5 = 0;
  v3 = 0;
  return RtlEnumerateBoundaryDescriptorEntries(a1 + 24, ObpCompareEntryLevel1, v2) >= 0 && v5 >= 0 && v4 == v3;
}
