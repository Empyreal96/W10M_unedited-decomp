// BapdRegisterSiData 
 
_DWORD *__fastcall BapdRegisterSiData(_DWORD *result, unsigned int a2, int a3)
{
  _DWORD *v3; // r4
  char *v6; // r4
  char v7[8]; // [sp+18h] [bp-38h] BYREF
  int v8; // [sp+20h] [bp-30h]
  int v9; // [sp+24h] [bp-2Ch]
  char *v10; // [sp+28h] [bp-28h]
  int v11; // [sp+2Ch] [bp-24h]
  int v12; // [sp+30h] [bp-20h]
  int v13; // [sp+34h] [bp-1Ch]

  v3 = result;
  if ( result )
  {
    RtlInitUnicodeString((unsigned int)v7, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control");
    v8 = 24;
    v9 = 0;
    v10 = v7;
    v12 = 0;
    v13 = 0;
    v11 = 576;
    if ( ZwOpenKey() >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v7, L"IntegrityServices");
      v8 = 24;
      v9 = 0;
      v10 = v7;
      v11 = 576;
      v12 = 0;
      v13 = 0;
      if ( ZwCreateKey() >= 0 )
      {
        ZwClose();
        if ( v3 != (_DWORD *)-4 && *v3 )
        {
          RtlInitUnicodeString((unsigned int)v7, L"WBCL");
          ZwSetValueKey();
        }
        if ( a2 >= *v3 + 36 )
        {
          v6 = (char *)v3 + *v3;
          if ( *((_DWORD *)v6 + 1) == 32 && *((_DWORD *)v6 + 2) == 1 )
          {
            RtlInitUnicodeString((unsigned int)v7, L"EventCount");
            ZwSetValueKey();
            RtlInitUnicodeString((unsigned int)v7, L"BootCount");
            ZwSetValueKey();
            RtlInitUnicodeString((unsigned int)v7, L"CounterId");
            ZwSetValueKey();
            if ( !a3 )
            {
              RtlInitUnicodeString((unsigned int)v7, L"InitialEventCount");
              ZwSetValueKey();
              RtlInitUnicodeString((unsigned int)v7, L"InitialBootCount");
              ZwSetValueKey();
              RtlInitUnicodeString((unsigned int)v7, L"InitialCounterId");
              ZwSetValueKey();
            }
          }
        }
      }
    }
    result = 0;
  }
  return result;
}
