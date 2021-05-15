// PerfDiagpUpdateCKCLEnableFlags 
 
int __fastcall PerfDiagpUpdateCKCLEnableFlags(int a1, int a2)
{
  int result; // r0
  unsigned int v4; // r5
  int v5; // [sp+0h] [bp-88h]
  char v6[8]; // [sp+8h] [bp-80h] BYREF
  _DWORD v7[14]; // [sp+10h] [bp-78h] BYREF
  int v8[16]; // [sp+48h] [bp-40h] BYREF

  memset(v8, 0, 48);
  memset(v7, 0, sizeof(v7));
  v7[1] = 32;
  v7[2] = a2;
  v7[3] = v8;
  v7[4] = 3;
  v8[0] = 48;
  result = RtlpQueryRegistryValues(2, L"Diagnostics\\Performance\\BootCKCLSettings", v7, 0, v5, 1u);
  if ( result >= 0 )
  {
    if ( v8[1] == 3 )
    {
      v4 = v8[0];
      if ( v8[0] <= 0x28u )
      {
        memmove((int)&unk_61CC40, (int)&v8[2], v8[0]);
        PerfDiagpInitializeLoggerInfo(1, v4 >> 2);
        result = NtTraceControl(
                   4,
                   (unsigned int)dword_61CB88,
                   dword_61CB88[0],
                   (int)dword_61CB88,
                   dword_61CB88[0],
                   (unsigned int)v6);
      }
      else
      {
        result = -1073741789;
      }
    }
    else
    {
      result = -1073741811;
    }
  }
  return result;
}
