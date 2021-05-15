// BapdpRegisterWmdResult 
 
int __fastcall BapdpRegisterWmdResult(int result)
{
  char v1[8]; // [sp+20h] [bp-30h] BYREF
  int v2; // [sp+28h] [bp-28h]
  int v3; // [sp+2Ch] [bp-24h]
  char *v4; // [sp+30h] [bp-20h]
  int v5; // [sp+34h] [bp-1Ch]
  int v6; // [sp+38h] [bp-18h]
  int v7; // [sp+3Ch] [bp-14h]

  if ( result )
  {
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
      RtlInitUnicodeString((unsigned int)v1, L"MemoryDiagnostic");
      v2 = 24;
      v3 = 0;
      v4 = v1;
      v5 = 576;
      v6 = 0;
      v7 = 0;
      if ( ZwCreateKey() >= 0 )
      {
        ZwClose();
        RtlInitUnicodeString((unsigned int)v1, L"Results");
        if ( ZwSetValueKey() >= 0 )
        {
          RtlInitUnicodeString((unsigned int)v1, L"RunMemDiag");
          ZwSetValueKey();
        }
      }
      result = ZwClose();
    }
  }
  return result;
}
