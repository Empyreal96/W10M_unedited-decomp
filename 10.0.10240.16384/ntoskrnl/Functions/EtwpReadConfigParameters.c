// EtwpReadConfigParameters 
 
unsigned int EtwpReadConfigParameters()
{
  int v1; // r3
  int v2; // [sp+8h] [bp-98h] BYREF
  int v3; // [sp+Ch] [bp-94h]
  unsigned int v4; // [sp+10h] [bp-90h] BYREF
  __int16 v5; // [sp+14h] [bp-8Ch] BYREF
  int v6; // [sp+18h] [bp-88h]
  int v7; // [sp+20h] [bp-80h]
  int v8; // [sp+24h] [bp-7Ch]
  char *v9; // [sp+28h] [bp-78h]
  int v10; // [sp+2Ch] [bp-74h]
  int v11; // [sp+30h] [bp-70h]
  int v12; // [sp+34h] [bp-6Ch]
  char v13[8]; // [sp+38h] [bp-68h] BYREF
  int v14[24]; // [sp+40h] [bp-60h] BYREF

  v5 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 10;
  RtlInitUnicodeString((unsigned int)v13, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI");
  v7 = 24;
  v8 = 0;
  v10 = 576;
  v9 = v13;
  v11 = 0;
  v12 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_10;
  memset(v14, 0, 84);
  v14[0] = (int)EtwpQueryRegistryCallback;
  v14[3] = (int)&v2;
  v14[2] = (int)L"RTBacklogRoot";
  v14[4] = 1;
  v14[5] = (int)&v5;
  v14[7] = (int)EtwpQueryRegistryCallback;
  v14[10] = (int)&v4;
  v14[9] = (int)L"MaxNonPagedPoolUsage";
  v14[11] = 4;
  if ( RtlQueryRegistryValuesEx(0x40000000, v6, (int)v14, 0) < 0 )
  {
LABEL_10:
    v1 = v4;
    goto LABEL_7;
  }
  if ( v3 )
    return sub_96F540();
  v1 = v4;
  if ( v4 > 0x32 )
  {
    v1 = 50;
LABEL_13:
    v4 = v1;
    goto LABEL_7;
  }
  if ( v4 < 0xA )
  {
    v1 = 10;
    goto LABEL_13;
  }
LABEL_7:
  EtwpMaxNonPagedPoolUsage = v1;
  if ( v6 )
    ZwClose();
  return RtlFreeAnsiString(&v2);
}
