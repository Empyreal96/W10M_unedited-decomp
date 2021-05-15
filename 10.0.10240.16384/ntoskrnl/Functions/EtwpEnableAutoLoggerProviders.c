// EtwpEnableAutoLoggerProviders 
 
int __fastcall EtwpEnableAutoLoggerProviders(int a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  unsigned int v6; // r6
  unsigned int v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r4
  int v12; // r0
  int v13; // r1
  __int16 v14; // r3
  int result; // r0
  int v16; // r0
  unsigned int v17; // r1
  char *v18; // r4
  int v19; // r5
  int *v20; // r5
  int v21; // r4
  int v22; // t1
  __int64 v23; // [sp+30h] [bp-2B8h] BYREF
  int v24; // [sp+38h] [bp-2B0h] BYREF
  int v25; // [sp+3Ch] [bp-2ACh] BYREF
  unsigned int v26; // [sp+40h] [bp-2A8h]
  int v27; // [sp+44h] [bp-2A4h] BYREF
  unsigned int v28; // [sp+48h] [bp-2A0h] BYREF
  int v29; // [sp+50h] [bp-298h] BYREF
  int v30; // [sp+54h] [bp-294h]
  _DWORD v31[2]; // [sp+58h] [bp-290h] BYREF
  int v32; // [sp+60h] [bp-288h]
  int v33; // [sp+68h] [bp-280h]
  int v34; // [sp+6Ch] [bp-27Ch]
  char *v35; // [sp+70h] [bp-278h]
  int v36; // [sp+74h] [bp-274h]
  int v37; // [sp+78h] [bp-270h]
  int v38; // [sp+7Ch] [bp-26Ch]
  unsigned __int16 v39[4]; // [sp+80h] [bp-268h] BYREF
  char v40[8]; // [sp+88h] [bp-260h] BYREF
  char v41[16]; // [sp+90h] [bp-258h] BYREF
  char v42[24]; // [sp+A0h] [bp-248h] BYREF
  int v43[140]; // [sp+B8h] [bp-230h] BYREF

  v6 = wcslen(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\");
  v7 = wcslen(a3);
  v8 = wcslen(L"\\");
  v9 = wcslen(a2) + v8 + v7 + v6 + 1;
  v27 = 0;
  v28 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 0i64;
  v29 = 0;
  v30 = 0;
  v26 = 0;
  RtlInitUnicodeString((unsigned int)v39, a2);
  memset(v43, 0, 532);
  memset(v42, 0, sizeof(v42));
  v31[0] = 0;
  v31[1] = 0;
  v10 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v9, 1350005829);
  v11 = v10;
  if ( !v10 )
    goto LABEL_16;
  if ( RtlStringCbPrintfW(
         v10,
         2 * v9,
         (int)L"%ws%ws\\%ws",
         (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\") )
  {
    goto LABEL_16;
  }
  RtlInitUnicodeString((unsigned int)v40, v11);
  v33 = 24;
  v34 = 0;
  v36 = 576;
  v35 = v40;
  v37 = 0;
  v38 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_16;
  v43[0] = (int)EtwpQueryRegistryCallback;
  v43[3] = (int)&v27;
  v43[2] = (int)L"Enabled";
  v43[4] = 4;
  v43[7] = (int)EtwpQueryRegistryCallback;
  v43[10] = (int)&v24;
  v43[9] = (int)L"EnableProperty";
  v43[11] = 4;
  v43[14] = (int)EtwpQueryRegistryCallback;
  v43[17] = (int)&v25;
  v43[16] = (int)L"EnableLevel";
  v43[18] = 4;
  v43[21] = (int)EtwpQueryRegistryCallback;
  v43[24] = (int)&v28;
  v43[23] = (int)L"EnableFlags";
  v43[25] = 4;
  v43[28] = (int)EtwpQueryRegistryCallback;
  v43[31] = (int)&v23;
  v43[30] = (int)L"MatchAnyKeyword";
  v43[32] = 11;
  v43[35] = (int)EtwpQueryRegistryCallback;
  v43[38] = (int)&v29;
  v43[37] = (int)L"MatchAllKeyword";
  v43[39] = 11;
  v12 = RtlpQueryRegistryValues(0x40000000, 0, v43, 0, (int)a3, 1u);
  if ( v12 < 0 )
    goto LABEL_25;
  if ( v27 )
  {
    v32 = 0;
    v14 = -1;
    if ( a1 )
      v14 = a1;
    LOWORD(v32) = v14;
    EtwpGetAutoLoggerProviderFilter(v11, v42, v31);
    v12 = RtlGUIDFromString(v39, v41);
    if ( v12 < 0 )
      goto LABEL_25;
    if ( !memcmp((unsigned int)v41, (unsigned int)dword_405930, 16) )
      return sub_810F20();
    v16 = HIDWORD(v23);
    v17 = v23;
    if ( !v23 )
    {
      v17 = v28;
      v16 = 0;
      v23 = v28;
    }
    v12 = EtwpEnableTrace(v41, 0, v32, 0, 1, (unsigned __int8)v25, v17, v16, v29, v30, v24, v42, v31);
  }
  if ( v12 < 0 )
LABEL_25:
    v26 = RtlNtStatusToDosError(v12, v13);
  RtlWriteRegistryValue(0x40000000, 0, L"Status");
LABEL_16:
  if ( v11 )
    ExFreePoolWithTag((unsigned int)v11);
  v18 = v42;
  v19 = 3;
  do
  {
    RtlFreeAnsiString(v18);
    v18 += 8;
    --v19;
  }
  while ( v19 );
  v20 = v31;
  v21 = 2;
  do
  {
    v22 = *v20++;
    result = v22;
    if ( v22 )
      result = ExFreePoolWithTag(result);
    --v21;
  }
  while ( v21 );
  return result;
}
