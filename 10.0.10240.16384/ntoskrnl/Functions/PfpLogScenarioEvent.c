// PfpLogScenarioEvent 
 
__int64 __fastcall PfpLogScenarioEvent(int a1, int a2, int a3, int a4, char a5)
{
  unsigned __int16 v6; // r6
  char v7; // r5
  char v8; // r7
  int v9; // r8
  __int64 v11; // [sp+0h] [bp-28h] BYREF
  unsigned int v12; // [sp+8h] [bp-20h] BYREF
  unsigned int v13; // [sp+Ch] [bp-1Ch]

  v12 = a3;
  v13 = a4;
  v6 = a4;
  v7 = a3;
  v8 = a2;
  MmPerformMemoryListCommand(1, a2, a3, a4);
  v9 = PfTSetTraceWorkerPriority(0x10u);
  PfGenerateTrace(&dword_643940, 1);
  LODWORD(v11) = a1;
  HIDWORD(v11) = v8 & 3 | (4 * (v6 | ((v7 & 3) << 16)));
  KeQueryTickCount((int *)&v12);
  PfLogEvent(
    27,
    ((__int64)(((v12 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((v13 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
  + dword_63728C,
    (int)&v11,
    8u);
  if ( (a5 & 1) != 0 )
    PfGenerateTrace(&dword_643940, 0);
  if ( v9 <= 31 )
    PfTSetTraceWorkerPriority(v9);
  return v11;
}
