// MmWriteTriageInformation 
 
int __fastcall MmWriteTriageInformation(int a1, int a2, int a3)
{
  int v5[16]; // [sp+0h] [bp-40h] BYREF

  v5[0] = 1;
  v5[1] = 52;
  v5[2] = MmSpecialPoolTag;
  v5[3] = VfTriageActionTaken(a1, a2, a3);
  v5[4] = MmVerifierData;
  v5[5] = ((unsigned int)MiFlags >> 1) & 1;
  v5[6] = dword_634D50;
  v5[7] = dword_632A90;
  __dmb(0xBu);
  v5[8] = dword_634D54;
  v5[9] = dword_634D4C;
  v5[10] = dword_640604;
  v5[11] = dword_640380;
  v5[12] = dword_640384;
  return memmove(a1, (int)v5, 0x34u);
}
