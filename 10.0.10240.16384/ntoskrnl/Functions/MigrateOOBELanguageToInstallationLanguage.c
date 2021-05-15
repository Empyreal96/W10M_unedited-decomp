// MigrateOOBELanguageToInstallationLanguage 
 
int MigrateOOBELanguageToInstallationLanguage()
{
  int v0; // r4
  int v1; // r0
  int *v2; // r1
  unsigned int v3; // r2
  unsigned int v4; // r3
  __int16 v5; // r3
  char v7[8]; // [sp+10h] [bp-258h] BYREF
  int v8; // [sp+18h] [bp-250h]
  int v9; // [sp+20h] [bp-248h]
  int v10; // [sp+24h] [bp-244h]
  char *v11; // [sp+28h] [bp-240h]
  int v12; // [sp+2Ch] [bp-23Ch]
  int v13; // [sp+30h] [bp-238h]
  int v14; // [sp+34h] [bp-234h]
  char v15[8]; // [sp+38h] [bp-230h] BYREF
  __int16 v16; // [sp+40h] [bp-228h]
  int v17; // [sp+42h] [bp-226h]
  int v18; // [sp+46h] [bp-222h] BYREF
  char v19; // [sp+50h] [bp-218h]
  char v20[527]; // [sp+51h] [bp-217h] BYREF

  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  memset(v20, 0, sizeof(v20));
  v8 = 0;
  RtlInitUnicodeString((unsigned int)v7, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\NLS\\Language");
  v9 = 24;
  v10 = 0;
  v12 = 576;
  v11 = v7;
  v13 = 0;
  v14 = 0;
  v0 = ZwOpenKey();
  if ( v0 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v7, L"InstallLanguage");
    v1 = 3;
    v2 = &v18;
    v3 = (unsigned __int16)PsInstallUILanguageId;
    do
    {
      v4 = (unsigned __int16)((int)v3 % 16);
      if ( v4 <= 9 )
        v5 = v4 + 48;
      else
        v5 = v4 + 55;
      *(_WORD *)v2 = v5;
      --v1;
      v2 = (int *)((char *)v2 - 2);
      v3 = (unsigned __int16)(v3 >> 4);
    }
    while ( v1 >= 0 );
    if ( ZwQueryValueKey() >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v15, L"PreviousInstallLanguage");
      ZwSetValueKey();
    }
    v0 = ZwSetValueKey();
    if ( v0 >= 0 )
      v0 = 0;
  }
  return v0;
}
