// MmAdjustWorkingSetSize 
 
int __fastcall MmAdjustWorkingSetSize(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v5; // [sp+8h] [bp-8h] BYREF

  v5 = a4;
  return MmAdjustWorkingSetSizeEx(a1, a2, a3, a4, 0, &v5);
}
