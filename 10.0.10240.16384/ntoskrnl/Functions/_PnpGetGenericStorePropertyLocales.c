// _PnpGetGenericStorePropertyLocales 
 
int __fastcall PnpGetGenericStorePropertyLocales(int *a1, int a2, int a3, _WORD *a4, unsigned int a5, unsigned int *a6)
{
  _WORD *v6; // r6
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r8
  int v12; // r10
  int v13; // r5
  unsigned int v14; // r3
  int v16; // [sp+4h] [bp-174h]
  int v17; // [sp+38h] [bp-140h] BYREF
  int v18; // [sp+3Ch] [bp-13Ch] BYREF
  int v19; // [sp+40h] [bp-138h]
  unsigned __int16 v20[48]; // [sp+48h] [bp-130h] BYREF
  char v21[208]; // [sp+A8h] [bp-D0h] BYREF

  v6 = a4;
  *a6 = 0;
  if ( a5 )
    *a4 = 0;
  v9 = RtlStringCchPrintfExW((int)v20, 48, 0, 0, 2048, L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}\\%04lX");
  if ( v9 >= 0 )
  {
    v10 = PnpOpenPropertiesKey(a1, a2, v20, 1, 0, v16, &v18);
    v9 = v10;
    v19 = v10;
    if ( v10 == -1073741772 )
    {
      v9 = 0;
    }
    else if ( v10 >= 0 )
    {
      v11 = a5;
      v12 = 0;
      while ( 1 )
      {
        do
        {
          v17 = 85;
          v10 = PnpCtxRegEnumValue(v10, v18, v12++, (int)v21, (int)&v17, 0, 0, 0);
        }
        while ( v10 == -1073741789 );
        if ( v10 )
          break;
        v10 = IsNeutralLocale(v21);
        if ( !v10 )
        {
          v13 = v17 + 1;
          if ( v17 + 1 < v11 )
          {
            v10 = RtlStringCchCopyExW(v6, v11, v21, 0, 0, 2304);
            v6 += v13;
            v11 -= v13;
          }
          *a6 += v13;
        }
      }
      ZwClose();
      v9 = v19;
      v14 = *a6 + 1;
      *a6 = v14;
      if ( v6 && a5 >= v14 )
        *v6 = 0;
      else
        v9 = -1073741789;
    }
  }
  return v9;
}
