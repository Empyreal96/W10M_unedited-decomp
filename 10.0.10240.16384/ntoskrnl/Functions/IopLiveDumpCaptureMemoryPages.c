// IopLiveDumpCaptureMemoryPages 
 
int __fastcall IopLiveDumpCaptureMemoryPages(int a1)
{
  int v2; // r8
  unsigned int v3; // r1
  unsigned int v4; // r7
  int v5; // r6
  __int64 v6; // r0
  int v7; // r1
  int v9[6]; // [sp+8h] [bp-68h] BYREF
  _DWORD v10[2]; // [sp+20h] [bp-50h] BYREF
  _DWORD v11[18]; // [sp+28h] [bp-48h] BYREF

  v9[3] = 0;
  v2 = KeQueryInterruptTime();
  v9[0] = (int)IopLiveDumpStartMirroringCallback;
  v4 = v3;
  v9[1] = (int)IopLiveDumpEndMirroringCallback;
  v9[2] = (int)IopLiveDumpMirrorPhysicalMemoryCallback;
  v9[4] = 17;
  v5 = MmDuplicateMemory(v9);
  if ( v5 < 0 && (*(_DWORD *)(a1 + 144) & 1) != 0 )
    IopLiveDumpUncorralProcessors(a1 + 140, 1);
  if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
  {
    LODWORD(v6) = KeQueryInterruptTime();
    v10[0] = _rt_udiv64(10000i64, v6 - __PAIR64__(v4, v2));
    v10[1] = v7;
    v11[8] = v10;
    v11[9] = 0;
    v11[10] = 8;
    v11[11] = 0;
    TlgWrite(&dword_617540, (unsigned __int8 *)dword_413944 + 1, a1 + 348, a1 + 332, 3, v11);
  }
  return v5;
}
