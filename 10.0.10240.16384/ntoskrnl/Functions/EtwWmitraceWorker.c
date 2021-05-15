// EtwWmitraceWorker 
 
int EtwWmitraceWorker()
{
  int v0; // r3
  unsigned int v1; // r3
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r4
  int v6; // r3
  int v7; // r2
  int result; // r0
  const char *v9; // r2
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r0
  unsigned __int16 v19[4]; // [sp+20h] [bp-C8h] BYREF
  _DWORD v20[16]; // [sp+28h] [bp-C0h] BYREF
  int v21; // [sp+68h] [bp-80h]
  int v22; // [sp+6Ch] [bp-7Ch]
  unsigned __int16 v23[8]; // [sp+A8h] [bp-40h] BYREF
  unsigned __int16 v24[24]; // [sp+B8h] [bp-30h] BYREF

  v0 = (unsigned __int8)EtwWmitraceWork;
  __dmb(0xBu);
  if ( v0 == 1 )
  {
    EtwpPrepareWmitraceLoggerInfo(v20);
    RtlInitAnsiString((unsigned int)v19, (unsigned int)&dword_61AB08);
    RtlAnsiStringToUnicodeString(v24, v19, 1, v16);
    v20[13] = dword_61ABD0;
    v20[14] = dword_61ABD4;
    v20[12] = dword_61ABD8;
    v21 = dword_61ABDC;
    v22 = dword_61ABE0;
    v20[15] = dword_61ABCC;
    if ( byte_61AB49 )
    {
      RtlInitAnsiString((unsigned int)v19, (unsigned int)&byte_61AB49);
      RtlAnsiStringToUnicodeString(v23, v19, 1, v17);
    }
    v18 = EtwpStartTrace((int)v20);
    v5 = v18;
    if ( v18 < 0 )
      DbgPrintEx(23, 3, (int)"wmitrace: EtwpStartTrace failed: 0x%x\n", v18);
    result = RtlFreeAnsiString(v24);
    if ( byte_61AB49 )
      result = RtlFreeAnsiString(v23);
    goto LABEL_28;
  }
  if ( v0 == 2 )
  {
    EtwpPrepareWmitraceLoggerInfo(v20);
    v5 = EtwpQueryTrace(v20, v13, v14, v15);
    if ( v5 >= 0 )
    {
      result = EtwpStopTrace(v20, 0);
      v5 = result;
      if ( result >= 0 )
        goto LABEL_28;
      v9 = "wmitrace: EtwpStopTrace failed: 0x%x\n";
      goto LABEL_19;
    }
    goto LABEL_18;
  }
  if ( v0 != 3 )
  {
    v1 = v0 - 4;
    if ( v1 > 2 )
    {
      v5 = -1073741637;
      result = DbgPrintEx(23, 3, (int)"Unknown command passed to EtwWmitraceWorker.\n", v1);
      goto LABEL_28;
    }
    EtwpPrepareWmitraceLoggerInfo(v20);
    v5 = EtwpQueryTrace(v20, v2, v3, v4);
    if ( v5 >= 0 )
    {
      v6 = (unsigned __int8)EtwWmitraceWork;
      __dmb(0xBu);
      if ( v6 == 4 )
      {
        v7 = 1;
      }
      else if ( v6 == 5 )
      {
        v7 = 0;
      }
      else
      {
        v7 = 2;
      }
      result = EtwEnableTrace(
                 dword_61AB1C,
                 0,
                 EtwpWmitraceParams,
                 0,
                 v7,
                 byte_61AB2C,
                 dword_61AB08,
                 dword_61AB0C,
                 dword_61AB10,
                 dword_61AB14,
                 dword_61AB18);
      v5 = result;
      if ( result < 0 )
      {
        v9 = "wmitrace: EtwpEnableTraceEx failed: 0x%x\n";
LABEL_19:
        result = DbgPrintEx(23, 3, (int)v9, v5);
        goto LABEL_28;
      }
      goto LABEL_28;
    }
LABEL_18:
    v9 = "wmitrace: EtwpQueryTrace failed: 0x%x\n";
    goto LABEL_19;
  }
  EtwpPrepareWmitraceLoggerInfo(v20);
  v5 = EtwpQueryTrace(v20, v10, v11, v12);
  if ( v5 < 0 )
    goto LABEL_18;
  v21 |= 0x80000u;
  result = EtwpUpdateTrace((int)v20);
  v5 = result;
  if ( result < 0 )
  {
    v9 = "wmitrace: failed to enable KD_FILTER 0x%x\n";
    goto LABEL_19;
  }
LABEL_28:
  dword_61ABE8 = v5;
  __dmb(0xBu);
  EtwWmitraceWork = 0;
  return result;
}
