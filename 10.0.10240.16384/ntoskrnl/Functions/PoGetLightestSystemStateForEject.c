// PoGetLightestSystemStateForEject 
 
int __fastcall PoGetLightestSystemStateForEject(int a1, int a2, int a3, int *a4)
{
  int v5; // r6
  int v7; // r3
  int v8; // r4
  unsigned int v9; // r0
  int v10; // r3
  int v12; // [sp+8h] [bp-70h] BYREF
  char v13[8]; // [sp+10h] [bp-68h] BYREF
  unsigned int v14; // [sp+28h] [bp-50h]
  int v15; // [sp+2Ch] [bp-4Ch]
  int v16; // [sp+30h] [bp-48h]
  unsigned int v17; // [sp+34h] [bp-44h]
  unsigned int v18; // [sp+38h] [bp-40h]
  unsigned int v19; // [sp+48h] [bp-30h]
  unsigned int v20; // [sp+4Ch] [bp-2Ch]

  v5 = a2;
  *a4 = 0;
  if ( !a2 && !a3 )
    v5 = 1;
  if ( a1 )
  {
    v8 = PopOpenPowerKey((int)&v12);
    if ( v8 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v13, L"UndockPowerPolicy");
      v8 = ZwQueryValueKey();
      ZwClose();
      if ( v8 >= 0 )
      {
        if ( v14 < 8 )
          return -1073741492;
        if ( v15 != 1 )
          return -1073741823;
        if ( v14 < 0x10 || v16 != v14 )
          return -1073741492;
      }
      else
      {
        if ( v8 != -1073741772 )
          return v8;
        v17 = 10;
        v18 = 0;
      }
      v8 = ZwPowerInformation();
      if ( v8 >= 0 )
      {
        if ( v19 && 100 * v20 > v20 )
          v9 = 100 * v20 / v19;
        else
          v9 = 0;
        if ( v9 >= v17 && v5 )
        {
          v10 = 1;
        }
        else
        {
          if ( !a3 )
            return -1073741090;
          if ( v9 < v18 )
            v10 = 5;
          else
            v10 = 2;
        }
        *a4 = v10;
      }
    }
  }
  else
  {
    if ( v5 )
      v7 = 1;
    else
      v7 = 2;
    *a4 = v7;
    v8 = 0;
  }
  return v8;
}
