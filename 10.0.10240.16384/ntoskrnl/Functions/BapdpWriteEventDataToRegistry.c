// BapdpWriteEventDataToRegistry 
 
int BapdpWriteEventDataToRegistry()
{
  int result; // r0
  int v1; // r4
  char v2[8]; // [sp+18h] [bp-30h] BYREF
  int v3; // [sp+20h] [bp-28h]
  int v4; // [sp+24h] [bp-24h]
  char *v5; // [sp+28h] [bp-20h]
  int v6; // [sp+2Ch] [bp-1Ch]
  int v7; // [sp+30h] [bp-18h]
  int v8; // [sp+34h] [bp-14h]

  RtlInitUnicodeString((unsigned int)v2, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control");
  v3 = 24;
  v4 = 0;
  v5 = v2;
  v7 = 0;
  v8 = 0;
  v6 = 576;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v2, L"Session Manager\\Power");
    v3 = 24;
    v4 = 0;
    v5 = v2;
    v6 = 576;
    v7 = 0;
    v8 = 0;
    v1 = ZwCreateKey();
    result = ZwClose();
    if ( v1 >= 0 )
    {
      ZwSetValueKey();
      result = ZwClose();
    }
  }
  return result;
}
