// PopConfigureHeteroProcessors 
 
int __fastcall PopConfigureHeteroProcessors(int a1)
{
  __int16 **v2; // r4
  int v3; // r5
  int v4; // [sp+8h] [bp-90h]
  char v5[16]; // [sp+18h] [bp-80h] BYREF
  int v6; // [sp+28h] [bp-70h]
  int v7; // [sp+2Ch] [bp-6Ch]
  char *v8; // [sp+30h] [bp-68h]
  int v9; // [sp+34h] [bp-64h]
  int v10; // [sp+38h] [bp-60h]
  int v11; // [sp+3Ch] [bp-5Ch]
  char v12[16]; // [sp+40h] [bp-58h] BYREF
  int v13; // [sp+50h] [bp-48h]
  int v14; // [sp+58h] [bp-40h]

  *(_WORD *)a1 = 1;
  *(_WORD *)(a1 + 2) = 1;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  RtlInitUnicodeString(
    (unsigned int)v5,
    L"\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\KGroups");
  v6 = 24;
  v7 = 0;
  v9 = 576;
  v8 = v5;
  v10 = 0;
  v11 = 0;
  if ( ZwOpenKey() >= 0 )
    return sub_7D0A74();
  v7 = 0;
  RtlInitUnicodeString((unsigned int)v5, L"\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control");
  if ( ZwOpenKey() >= 0 )
  {
    v2 = PopHeteroConfig;
    v3 = 7;
    v7 = v4;
    do
    {
      RtlInitUnicodeString((unsigned int)v5, (unsigned __int16 *)*v2);
      if ( ZwOpenKey() >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v12, (unsigned __int16 *)v2[1]);
        if ( ZwQueryValueKey() >= 0 && v13 == 4 )
          *(_DWORD *)v2[2] = v14;
        ZwClose();
      }
      v2 += 3;
      --v3;
    }
    while ( v3 );
    ZwClose();
  }
  return 0;
}
