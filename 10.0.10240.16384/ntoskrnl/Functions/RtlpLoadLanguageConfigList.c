// RtlpLoadLanguageConfigList 
 
int __fastcall RtlpLoadLanguageConfigList(int a1, unsigned int *a2, int a3)
{
  unsigned int v4; // r6
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r0
  int v10; // r0
  char v11[8]; // [sp+8h] [bp-38h] BYREF
  int v12; // [sp+10h] [bp-30h]
  int v13; // [sp+14h] [bp-2Ch]
  char *v14; // [sp+18h] [bp-28h]
  int v15; // [sp+1Ch] [bp-24h]
  int v16; // [sp+20h] [bp-20h]
  int v17; // [sp+24h] [bp-1Ch]

  v4 = 0;
  if ( a2 && a3 )
  {
    v4 = *a2;
    RtlInitUnicodeString((unsigned int)v11, L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\MUI\\Settings");
    v12 = 24;
    v13 = 0;
    v14 = v11;
    v16 = 0;
    v17 = 0;
    v15 = 576;
    if ( ZwOpenKey() >= 0 )
      return sub_817F78();
    RtlInitUnicodeString(
      (unsigned int)v11,
      L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings\\LanguageConfiguration");
    v12 = 24;
    v13 = 0;
    v14 = v11;
    v15 = 576;
    v16 = 0;
    v17 = 0;
    v7 = ZwOpenKey();
    v8 = v7;
    if ( v7 < 0 )
    {
      if ( v7 == -1073741772 )
        v8 = 0;
    }
    else
    {
      v8 = RtlpPopulateLanguageConfigList(0, a2, a3);
    }
  }
  else
  {
    v8 = -1073741811;
  }
  if ( v8 < 0 )
  {
    if ( !a2 )
      return v8;
    v9 = *a2;
    if ( *a2 == v4 )
      return v8;
    if ( v9 )
      ExFreePoolWithTag(v9);
  }
  else
  {
    if ( *a2 )
      return v8;
    v10 = RtlpMuiRegCreateLanguageConfigList(1);
    *a2 = v10;
    if ( v10 )
      return v8;
    v8 = -1073741801;
  }
  *a2 = v4;
  return v8;
}
