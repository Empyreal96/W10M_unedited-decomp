// EtwpInitializeAutoLoggers 
 
int EtwpInitializeAutoLoggers()
{
  unsigned int v0; // r4
  _WORD *v1; // r5
  int v2; // r6
  int v3; // r0
  int v4; // r1
  int v5; // r4
  int v7; // [sp+8h] [bp-1A0h] BYREF
  int v8; // [sp+Ch] [bp-19Ch] BYREF
  unsigned int v9; // [sp+10h] [bp-198h]
  unsigned int v10; // [sp+18h] [bp-190h]
  int v11; // [sp+20h] [bp-188h]
  int v12; // [sp+24h] [bp-184h]
  char *v13; // [sp+28h] [bp-180h]
  int v14; // [sp+2Ch] [bp-17Ch]
  int v15; // [sp+30h] [bp-178h]
  int v16; // [sp+34h] [bp-174h]
  char v17[8]; // [sp+40h] [bp-168h] BYREF
  char v18[12]; // [sp+48h] [bp-160h] BYREF
  unsigned int v19; // [sp+54h] [bp-154h]
  _WORD v20[136]; // [sp+58h] [bp-150h] BYREF
  char v21[64]; // [sp+168h] [bp-40h] BYREF

  v9 = 0;
  qmemcpy(v21, "GlobalLogger", 24);
  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, &v7);
  EtwpStartAutoLogger(v21, L"WMI\\GlobalLogger", &v8, v7);
  v0 = wcslen(L"WMI\\AutoLogger");
  v10 = wcslen(L"\\") + v0 + 129;
  v1 = (_WORD *)ExAllocatePoolWithTag(1, 2 * v10, 1350005829);
  if ( v1 )
  {
    RtlInitUnicodeString((unsigned int)v17, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\AutoLogger");
    v11 = 24;
    v12 = 0;
    v14 = 576;
    v13 = v17;
    v15 = 0;
    v16 = 0;
    if ( ZwOpenKey() >= 0 )
    {
      v2 = 0;
      do
      {
        v3 = ZwEnumerateKey();
        v5 = v3;
        if ( v3 < 0 )
        {
          if ( v3 == -2147483622 )
            v3 = 0;
          v9 = RtlNtStatusToDosError(v3, v4);
          RtlWriteRegistryValue(2, (int)L"WMI\\AutoLogger", L"Status");
          if ( v5 == -2147483643 || v5 == -1073741789 )
            v5 = 0;
        }
        else if ( v19 < 0x102 )
        {
          v20[v19 >> 1] = 0;
          if ( !RtlStringCbPrintfW(v1, 2 * v10, (int)L"%ws\\%ws", (int)L"WMI\\AutoLogger")
            && EtwpStartAutoLogger(v20, v1, &v8, v7) >= 0
            && v8 )
          {
            EtwpEnableKeyProviders(v8, v1, v18);
          }
        }
        ++v2;
      }
      while ( v5 >= 0 );
      ZwClose();
    }
    ExFreePoolWithTag((unsigned int)v1);
  }
  return PsDereferenceMonitorContextServerSilo(v7);
}
