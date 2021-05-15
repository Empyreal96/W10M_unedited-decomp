// ExpRecordShutdownTime 
 
int ExpRecordShutdownTime()
{
  int result; // r0
  char v1[8]; // [sp+10h] [bp-38h] BYREF
  int v2; // [sp+18h] [bp-30h] BYREF
  char v3[8]; // [sp+20h] [bp-28h] BYREF
  int v4; // [sp+28h] [bp-20h]
  int v5; // [sp+2Ch] [bp-1Ch]
  char *v6; // [sp+30h] [bp-18h]
  int v7; // [sp+34h] [bp-14h]
  int v8; // [sp+38h] [bp-10h]
  int v9; // [sp+3Ch] [bp-Ch]

  KeQuerySystemTime(&v2);
  RtlInitUnicodeString((unsigned int)v1, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Windows");
  v4 = 24;
  v5 = 0;
  v7 = 576;
  v6 = v1;
  v8 = 0;
  v9 = 0;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"ShutdownTime");
    ZwSetValueKey();
    ZwFlushKey();
    result = ZwClose();
  }
  return result;
}
