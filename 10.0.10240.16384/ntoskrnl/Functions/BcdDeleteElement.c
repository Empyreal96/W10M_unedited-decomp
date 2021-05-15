// BcdDeleteElement 
 
int __fastcall BcdDeleteElement(int a1)
{
  BOOL v2; // r7
  int v3; // r4
  int v4; // r6
  int v5; // r0
  int v6; // r5
  int v8; // [sp+0h] [bp-50h] BYREF
  int v9; // [sp+4h] [bp-4Ch] BYREF
  char v10[72]; // [sp+8h] [bp-48h] BYREF

  v2 = BiIsOfflineHandle(a1);
  v3 = BiAcquireBcdSyncMutant(v2);
  if ( v3 >= 0 )
  {
    v8 = 0;
    v9 = 0;
    v3 = BiOpenKey(a1, L"Elements", 131097, &v9);
    v4 = v9;
    if ( v3 >= 0 )
    {
      if ( ultow_s() )
      {
        v3 = -1073741823;
      }
      else
      {
        v5 = BiOpenKey(v4, v10, 0x10000, &v8);
        v6 = v8;
        if ( v5 < 0 )
        {
          v3 = -1073741275;
        }
        else
        {
          v3 = BiDeleteKey(v8);
          if ( v3 >= 0 )
            v6 = 0;
        }
        if ( v6 )
          return sub_8137D8();
      }
    }
    if ( v4 )
      BiCloseKey(v4);
    BiReleaseBcdSyncMutant(v2);
  }
  return v3;
}
