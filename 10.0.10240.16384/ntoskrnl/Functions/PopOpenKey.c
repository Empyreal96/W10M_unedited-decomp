// PopOpenKey 
 
int __fastcall PopOpenKey(_DWORD *a1, unsigned __int16 *a2)
{
  int v4; // r4
  char v6[8]; // [sp+18h] [bp-38h] BYREF
  int v7; // [sp+20h] [bp-30h]
  int v8; // [sp+24h] [bp-2Ch]
  char *v9; // [sp+28h] [bp-28h]
  int v10; // [sp+2Ch] [bp-24h]
  int v11; // [sp+30h] [bp-20h]
  int v12; // [sp+34h] [bp-1Ch]

  v7 = 24;
  v8 = 0;
  v9 = (char *)&CmRegistryMachineSystemCurrentControlSet;
  v11 = 0;
  v12 = 0;
  v10 = 576;
  v4 = ZwOpenKey();
  if ( v4 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v6, a2);
    v7 = 24;
    v8 = 0;
    v9 = v6;
    v10 = 576;
    v11 = 0;
    v12 = 0;
    if ( ZwCreateKey() < 0 )
      return sub_50B9D4();
    v4 = 0;
    *a1 = 0;
  }
  return v4;
}
