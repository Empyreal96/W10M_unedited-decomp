// PerfDiagpSaveActiveDCLLogFileName 
 
__int64 __fastcall PerfDiagpSaveActiveDCLLogFileName(__int64 a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r3
  _DWORD v7[6]; // [sp+8h] [bp-18h] BYREF

  v7[0] = a2;
  v7[1] = a3;
  v3 = ExAllocatePoolWithTag(1, 522, 1682330192);
  if ( v3 )
  {
    memset(dword_61CB88, 0, 176);
    dword_61CBB4 = 0x20000;
    qmemcpy(word_61CB48, "WdiContextLog", 26);
    RtlInitUnicodeString((unsigned int)&unk_61CC18, word_61CB48);
    dword_61CC0C = v3;
    word_61CC0A = 520;
    dword_61CB88[0] = 176;
    if ( NtTraceControl(3, (unsigned int)dword_61CB88, 176, (int)dword_61CB88, 0xB0u, (unsigned int)v7) < 0
      || (unsigned __int16)word_61CC08 < 2u )
    {
      RtlDeleteRegistryValue(2, (int)L"Diagnostics\\Performance", L"ActiveShutdownDCL");
    }
    else
    {
      v4 = (unsigned __int16)word_61CC08 >> 1;
      *(_WORD *)(v3 + 2 * v4) = 0;
      HIDWORD(a1) = 2 * (unsigned __int16)(v4 + 1);
      LODWORD(a1) = v3;
      RtlWriteRegistryValue(2, (int)L"Diagnostics\\Performance", L"ActiveShutdownDCL");
    }
    ExFreePoolWithTag(v3);
  }
  else
  {
    RtlDeleteRegistryValue(2, (int)L"Diagnostics\\Performance", L"ActiveShutdownDCL");
  }
  return a1;
}
