// BcdGetElementDataWithFlags 
 
int __fastcall BcdGetElementDataWithFlags(int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  BOOL v8; // r10
  int v9; // r4
  int v10; // r8
  int v11; // r0
  int v12; // r7
  int v13; // r0
  unsigned int v14; // r5
  int v15; // [sp+10h] [bp-68h] BYREF
  unsigned int v16; // [sp+14h] [bp-64h]
  int v17; // [sp+18h] [bp-60h] BYREF
  unsigned int v18; // [sp+1Ch] [bp-5Ch] BYREF
  int v19; // [sp+20h] [bp-58h] BYREF
  int v20; // [sp+24h] [bp-54h]
  char v21[80]; // [sp+28h] [bp-50h] BYREF

  v16 = a2;
  v20 = a1;
  if ( !a5 || !a4 && *a5 )
    return sub_8138B8();
  v8 = BiIsOfflineHandle(a1);
  v9 = BiAcquireBcdSyncMutant(v8);
  if ( v9 >= 0 )
  {
    v18 = 0;
    v19 = 0;
    v17 = 0;
    v15 = 131097;
    v9 = BiOpenKey(a1, L"Elements", 131097, &v19);
    v10 = v19;
    if ( v9 >= 0 )
    {
      if ( ultow_s() )
      {
        v9 = -1073741823;
      }
      else
      {
        v11 = BiOpenKey(v10, v21, v15, &v17);
        v12 = v17;
        if ( v11 < 0 )
        {
          v9 = -1073741275;
        }
        else
        {
          v13 = BiConvertElementFormatToValueType(HIBYTE(v16) & 0xF);
          v9 = BiGetRegistryValue(v12, L"Element", 0, v13, &v18, &v15);
          v14 = v18;
          if ( v9 >= 0 )
            v9 = BiConvertRegistryDataToElement(v20, v18, v15, v16, 0, a4, a5);
          if ( v14 )
            ExFreePoolWithTag(v14);
        }
        if ( v12 )
          BiCloseKey(v12);
      }
    }
    if ( v10 )
      BiCloseKey(v10);
    BiReleaseBcdSyncMutant(v8);
  }
  return v9;
}
