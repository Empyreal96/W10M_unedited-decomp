// BcdSetElementDataWithFlags 
 
int __fastcall BcdSetElementDataWithFlags(int a1, unsigned int a2, int a3, int a4, int a5)
{
  BOOL v9; // r9
  int v10; // r4
  int v11; // r8
  int v12; // r5
  unsigned int v13; // r6
  int v14; // r0
  char v15[4]; // [sp+8h] [bp-60h] BYREF
  int v16; // [sp+Ch] [bp-5Ch] BYREF
  unsigned int v17; // [sp+10h] [bp-58h]
  int v18; // [sp+14h] [bp-54h] BYREF
  char v19[80]; // [sp+18h] [bp-50h] BYREF

  if ( !a4 )
    return sub_8137E4();
  v17 = 0;
  v18 = 0;
  v15[0] = 0;
  v16 = 0;
  if ( a5 )
  {
    v9 = BiIsOfflineHandle(a1);
    v10 = BiAcquireBcdSyncMutant(v9);
    if ( v10 >= 0 )
    {
      v10 = BiOpenKey(a1, L"Elements", 131101, &v18);
      v11 = v18;
      if ( v10 >= 0 )
      {
        if ( ultow_s() )
        {
          v10 = -1073741823;
        }
        else
        {
          v10 = BiCreateKey(v11, v19, 65538, 1, &v16, v15);
          v12 = v16;
          if ( v10 < 0 )
            goto LABEL_21;
          v10 = BiConvertElementToRegistryData(a2, a4, a5);
          v13 = v17;
          if ( v10 >= 0 )
          {
            v14 = BiConvertElementFormatToValueType(HIBYTE(a2) & 0xF);
            v10 = BiSetRegistryValue(v12, L"Element", 0, v14, v13, v16);
          }
          if ( v13 )
            ExFreePoolWithTag(v13);
          if ( v10 < 0 )
          {
LABEL_21:
            if ( v15[0] )
            {
              BiDeleteKey(v12);
              v12 = 0;
            }
          }
          if ( v12 )
            BiCloseKey(v12);
        }
      }
      if ( v11 )
        BiCloseKey(v11);
      BiReleaseBcdSyncMutant(v9);
    }
  }
  else
  {
    BcdDeleteElement(a1);
    v10 = 0;
  }
  return v10;
}
