// BapdpRegisterResumeInformation 
 
int __fastcall BapdpRegisterResumeInformation(int result, int a2)
{
  char v2[8]; // [sp+20h] [bp-30h] BYREF
  int v3; // [sp+28h] [bp-28h]
  int v4; // [sp+2Ch] [bp-24h]
  char *v5; // [sp+30h] [bp-20h]
  int v6; // [sp+34h] [bp-1Ch]
  int v7; // [sp+38h] [bp-18h]
  int v8; // [sp+3Ch] [bp-14h]

  if ( result )
  {
    if ( a2 )
    {
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
        RtlInitUnicodeString((unsigned int)v2, L"Winresume");
        v3 = 24;
        v4 = 0;
        v5 = v2;
        v6 = 576;
        v7 = 0;
        v8 = 0;
        if ( ZwCreateKey() >= 0 )
        {
          ZwClose();
          RtlInitUnicodeString((unsigned int)v2, L"ResumeContext");
          ZwSetValueKey();
        }
        result = ZwClose();
      }
    }
  }
  return result;
}
