// PiDevCfgMigrateDevice 
 
int __fastcall PiDevCfgMigrateDevice(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r5
  int v10; // [sp+40h] [bp-38h] BYREF
  char v11[24]; // [sp+44h] [bp-34h] BYREF

  v10 = 0;
  memset(v11, 0, sizeof(v11));
  if ( a5 )
    *a5 = 0;
  if ( a6 )
    *a6 = 0;
  v8 = PiDevCfgInitMigrationContext(a3, a4, &v10);
  if ( v8 >= 0 )
  {
    if ( v10 )
      return sub_7E3A98();
    v8 = 0;
  }
  PiDevCfgFreeMigrationContext(&v10);
  return v8;
}
