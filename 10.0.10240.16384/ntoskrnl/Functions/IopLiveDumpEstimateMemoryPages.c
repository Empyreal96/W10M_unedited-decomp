// IopLiveDumpEstimateMemoryPages 
 
int __fastcall IopLiveDumpEstimateMemoryPages(_DWORD *a1)
{
  int v2; // r5
  unsigned int v3; // r0
  int result; // r0
  int (*v5)(); // [sp+0h] [bp-20h] BYREF
  int (__fastcall *v6)(int); // [sp+4h] [bp-1Ch]
  int (*v7)(); // [sp+8h] [bp-18h]
  int v8; // [sp+Ch] [bp-14h]
  int v9; // [sp+10h] [bp-10h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  a1[12] |= 1u;
  IopLiveDumpCallRemovePagesCallbacks(a1);
  v5 = IopLiveDumpStartMirroringCallback;
  v6 = IopLiveDumpEndMirroringCallback;
  v7 = IopLiveDumpMirrorPhysicalMemoryCallback;
  v9 = 17;
  v2 = MmDuplicateMemory(&v5);
  if ( v2 < 0 )
  {
    if ( (a1[36] & 1) != 0 )
      IopLiveDumpUncorralProcessors(a1 + 35, 1);
    a1[14] = 0;
    a1[16] = 0;
    a1[17] = 0;
  }
  else
  {
    v3 = RtlNumberOfSetBits(a1 + 55);
    a1[14] = v3 + (v3 >> 4);
    a1[16] = 0;
    a1[17] = 0;
    IopLiveDumpTraceBufferEstimation();
  }
  RtlClearAllBits((int)(a1 + 55));
  RtlClearAllBits((int)(a1 + 62));
  RtlClearAllBits((int)(a1 + 65));
  result = v2;
  a1[12] &= 0xFFFFFFFE;
  return result;
}
