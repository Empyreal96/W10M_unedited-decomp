// InitSafeBoot 
 
int __fastcall InitSafeBoot(int a1)
{
  int result; // r0
  int v3; // r4
  int v4; // [sp+10h] [bp-70h]
  int v5; // [sp+14h] [bp-6Ch]
  _DWORD v6[2]; // [sp+18h] [bp-68h] BYREF
  int v7; // [sp+20h] [bp-60h]
  int v8; // [sp+24h] [bp-5Ch]
  _DWORD *v9; // [sp+28h] [bp-58h]
  int v10; // [sp+2Ch] [bp-54h]
  int v11; // [sp+30h] [bp-50h]
  int v12; // [sp+34h] [bp-4Ch]
  int v13; // [sp+38h] [bp-48h] BYREF
  char v14[4]; // [sp+3Ch] [bp-44h] BYREF
  char v15[56]; // [sp+48h] [bp-38h] BYREF

  v7 = 24;
  v8 = 0;
  v10 = 64;
  v9 = &CmRegistryMachineSystemCurrentControlSetControlSafeBoot;
  v11 = 0;
  v12 = 0;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    if ( a1 )
    {
      RtlInitUnicodeString((unsigned int)v6, L"AlternateShell");
      memset(v15, 0, 44);
      if ( NtQueryValueKey(v5, v6, 2, (int)v15, 44, (unsigned int)v14) < 0 )
        a1 = 0;
    }
    RtlInitUnicodeString((unsigned int)v6, L"Option");
    v7 = 24;
    v8 = v5;
    v10 = 64;
    v9 = v6;
    v11 = 0;
    v12 = 0;
    v3 = ZwCreateKey();
    result = NtClose();
    if ( v3 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v6, L"OptionValue");
      NtSetValueKey(v4, (int)v6, 0, 4, (int)&InitSafeBootMode, 4u);
      if ( a1 == 1 )
      {
        RtlInitUnicodeString((unsigned int)v6, L"UseAlternateShell");
        v13 = 1;
        NtSetValueKey(v4, (int)v6, 0, 4, (int)&v13, 4u);
      }
      result = NtClose();
    }
  }
  return result;
}
