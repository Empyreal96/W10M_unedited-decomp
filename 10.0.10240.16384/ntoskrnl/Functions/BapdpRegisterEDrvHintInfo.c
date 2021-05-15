// BapdpRegisterEDrvHintInfo 
 
_DWORD *__fastcall BapdpRegisterEDrvHintInfo(_DWORD *result)
{
  char v1[8]; // [sp+20h] [bp-28h] BYREF
  int v2; // [sp+28h] [bp-20h]
  int v3; // [sp+2Ch] [bp-1Ch]
  char *v4; // [sp+30h] [bp-18h]
  int v5; // [sp+34h] [bp-14h]
  int v6; // [sp+38h] [bp-10h]
  int v7; // [sp+3Ch] [bp-Ch]

  if ( result && *result >= 8u && (result[1] & 1) != 0 )
  {
    RtlInitUnicodeString((unsigned int)v1, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control");
    v2 = 24;
    v3 = 0;
    v4 = v1;
    v6 = 0;
    v7 = 0;
    v5 = 576;
    if ( ZwOpenKey() >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v1, L"BitLocker");
      v2 = 24;
      v3 = 0;
      v4 = v1;
      v5 = 576;
      v6 = 0;
      v7 = 0;
      if ( ZwCreateKey() >= 0 )
      {
        ZwClose();
        RtlInitUnicodeString((unsigned int)v1, L"EDriveSupportedInBoot");
        ZwSetValueKey();
      }
    }
    result = 0;
  }
  return result;
}
