// PfpPowerActionStartScenarioTracing 
 
__int64 __fastcall PfpPowerActionStartScenarioTracing(__int64 a1, unsigned int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r1
  int v5; // r2
  int v6; // r3
  __int64 v8; // [sp+0h] [bp-18h] BYREF
  unsigned int v9; // [sp+8h] [bp-10h] BYREF
  unsigned int v10; // [sp+Ch] [bp-Ch]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  v3 = a1;
  PfTAccessTracingCleanup(&PfTGlobals, HIDWORD(a1), 4);
  MmPerformMemoryListCommand(1, v4, v5, v6);
  PfTAccessTracingStart(&PfTGlobals, &PfKernelGlobals, 4);
  LODWORD(v8) = *(_DWORD *)(v3 + 28);
  HIDWORD(v8) = 4 * *(unsigned __int16 *)(v3 + 32);
  KeQueryTickCount((int *)&v9);
  PfLogEvent(
    27,
    ((__int64)(((v9 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((v10 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
  + dword_63728C,
    (int)&v8,
    8u);
  return v8;
}
