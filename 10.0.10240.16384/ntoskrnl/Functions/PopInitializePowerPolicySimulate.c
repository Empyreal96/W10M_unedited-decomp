// PopInitializePowerPolicySimulate 
 
int PopInitializePowerPolicySimulate()
{
  int result; // r0
  int v1; // r4
  int v2; // r4
  int v3; // [sp+14h] [bp-54h]
  char v4[8]; // [sp+18h] [bp-50h] BYREF
  int v5; // [sp+20h] [bp-48h]
  int v6; // [sp+24h] [bp-44h]
  char *v7; // [sp+28h] [bp-40h]
  int v8; // [sp+2Ch] [bp-3Ch]
  int v9; // [sp+30h] [bp-38h]
  int v10; // [sp+34h] [bp-34h]
  int v11; // [sp+48h] [bp-20h]
  int v12; // [sp+4Ch] [bp-1Ch]

  PopSimulate = PopSimulateManual;
  v5 = 24;
  v6 = 0;
  v7 = (char *)&CmRegistryMachineSystemCurrentControlSet;
  v8 = 576;
  v9 = 0;
  v10 = 0;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v4, L"Control\\Session Manager");
    v5 = 24;
    v6 = v3;
    v7 = v4;
    v8 = 576;
    v9 = 0;
    v10 = 0;
    v1 = ZwCreateKey();
    result = ZwClose();
    if ( v1 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v4, L"PowerSimulateHiberBugcheck");
      if ( ZwQueryValueKey() < 0 )
      {
        RtlInitUnicodeString((unsigned int)v4, L"PowerPolicySimulate");
        v2 = ZwQueryValueKey();
        result = ZwClose();
        if ( v2 >= 0 && v11 == 4 )
          PopSimulate |= v12;
      }
      else
      {
        result = sub_7F1478();
      }
    }
  }
  return result;
}
