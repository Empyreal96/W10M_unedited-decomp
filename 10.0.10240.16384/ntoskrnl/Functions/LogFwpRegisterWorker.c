// LogFwpRegisterWorker 
 
int LogFwpRegisterWorker()
{
  int result; // r0
  char v1[8]; // [sp+20h] [bp-38h] BYREF
  int v2; // [sp+28h] [bp-30h]
  int v3; // [sp+2Ch] [bp-2Ch]
  char *v4; // [sp+30h] [bp-28h]
  int v5; // [sp+34h] [bp-24h]
  int v6; // [sp+38h] [bp-20h]
  int v7; // [sp+3Ch] [bp-1Ch]

  RtlInitUnicodeString((unsigned int)v1, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control");
  v2 = 24;
  v3 = 0;
  v4 = v1;
  v6 = 0;
  v7 = 0;
  v5 = 576;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v1, L"BGFX");
    v2 = 24;
    v3 = 0;
    v4 = v1;
    v5 = 576;
    v6 = 0;
    v7 = 0;
    if ( ZwCreateKey() >= 0 )
    {
      if ( (dword_641980 & 0x100000) != 0 )
        return sub_8DFD3C();
      ZwClose();
      RtlInitUnicodeString((unsigned int)v1, L"Resume");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"Width");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"Height");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"BPP");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"LogoSize");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressFrames");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressMemory");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressProlog");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000i64 * *(_QWORD *)&dword_64A5C0);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressLow");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_6180E8);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressHigh");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_64A5A0);
      ZwSetValueKey();
      if ( dword_619048 )
      {
        RtlInitUnicodeString((unsigned int)v1, L"ResidentSize");
        ZwSetValueKey();
      }
      RtlInitUnicodeString((unsigned int)v1, L"ProgressTotal");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_64A5D8);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"ProgressManual");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000i64 * *(_QWORD *)&dword_64A5B0);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeProlog");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000i64 * *(_QWORD *)&dword_64A5A8);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeOverlap");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeIo");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeCpu");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeFrames");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeMemory");
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeLow");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_6180F0);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeHigh");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_64A5C8);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"FadeTotal");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_64A588);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"AnimationTotal");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000 * qword_64A5D0);
      ZwSetValueKey();
      RtlInitUnicodeString((unsigned int)v1, L"CompressBitmaps");
      if ( !qword_617930 )
        __brkdiv0();
      _rt_sdiv64(qword_617930, 1000000i64 * *(_QWORD *)&dword_64A5E8);
      ZwSetValueKey();
    }
    result = ZwClose();
  }
  return result;
}
