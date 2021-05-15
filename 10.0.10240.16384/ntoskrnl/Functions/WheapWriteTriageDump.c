// WheapWriteTriageDump 
 
int WheapWriteTriageDump()
{
  int v0; // r4
  unsigned __int16 *v1; // r5
  int v2; // r10
  char v4[8]; // [sp+30h] [bp-50h] BYREF
  int v5; // [sp+38h] [bp-48h] BYREF
  int v6; // [sp+48h] [bp-38h]
  int v7; // [sp+4Ch] [bp-34h]
  char *v8; // [sp+50h] [bp-30h]
  int v9; // [sp+54h] [bp-2Ch]
  int v10; // [sp+58h] [bp-28h]
  int v11; // [sp+5Ch] [bp-24h]

  RtlInitUnicodeString(
    (unsigned int)v4,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\MachineCrash");
  v6 = 24;
  v7 = 0;
  v8 = v4;
  v10 = 0;
  v11 = 0;
  v9 = 576;
  v0 = ZwOpenKey();
  if ( v0 < 0 )
  {
    v1 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 512, 1634035799);
    if ( v1 )
    {
      KeQuerySystemTime(&v5);
      v2 = (unsigned __int16)v5;
      swprintf_s((int)v1, 256, (int)L"\\SystemRoot\\DUMP%04x.DMP", (unsigned __int16)v5);
      RtlInitUnicodeString((unsigned int)v4, v1);
      v6 = 24;
      v7 = 0;
      v8 = v4;
      v9 = 576;
      v10 = 0;
      v11 = 0;
      v0 = ZwCreateFile();
      if ( v0 >= 0 )
      {
        v0 = ZwWriteFile();
        if ( v0 >= 0 )
        {
          RtlInitUnicodeString(
            (unsigned int)v4,
            L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\MachineCrash");
          v6 = 24;
          v7 = 0;
          v8 = v4;
          v9 = 576;
          v10 = 0;
          v11 = 0;
          v0 = ZwCreateKey();
          if ( v0 >= 0 )
          {
            RtlInitUnicodeString((unsigned int)v4, L"DumpFile");
            swprintf_s((int)v1, 256, (int)L"%s\\DUMP%04x.DMP", dword_63282C, v2, 1, 0, 0, 0, 0, 0);
            wcslen(v1);
            v0 = ZwSetValueKey();
            if ( v0 >= 0 )
            {
              RtlInitUnicodeString((unsigned int)v4, L"TempDestination");
              v0 = ZwSetValueKey();
            }
          }
        }
      }
      ExFreePoolWithTag((unsigned int)v1);
    }
    else
    {
      v0 = -1073741670;
    }
  }
  return v0;
}
