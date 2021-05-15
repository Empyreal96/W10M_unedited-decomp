// _PnpGetGenericStorePropertyKeys 
 
int __fastcall PnpGetGenericStorePropertyKeys(int *a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int *v7; // r8
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r9
  int i; // r4
  int v13; // r8
  int v14; // r4
  int v15; // r5
  bool v16; // zf
  int v17; // r0
  int v18; // lr
  _DWORD *v19; // r5
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // [sp+4h] [bp-18Ch]
  unsigned int v24[2]; // [sp+10h] [bp-180h] BYREF
  int v25; // [sp+18h] [bp-178h] BYREF
  int v26; // [sp+1Ch] [bp-174h]
  int *v27; // [sp+20h] [bp-170h]
  int v28; // [sp+24h] [bp-16Ch]
  int v29; // [sp+28h] [bp-168h]
  unsigned __int16 v30[4]; // [sp+30h] [bp-160h] BYREF
  int v31; // [sp+38h] [bp-158h] BYREF
  int v32; // [sp+3Ch] [bp-154h] BYREF
  int v33; // [sp+40h] [bp-150h]
  _DWORD v34[4]; // [sp+48h] [bp-148h] BYREF
  unsigned __int16 v35[12]; // [sp+58h] [bp-138h] BYREF
  unsigned __int16 v36[40]; // [sp+70h] [bp-120h] BYREF
  char v37[208]; // [sp+C0h] [bp-D0h] BYREF

  v33 = a4;
  v29 = a5;
  v7 = a1;
  v27 = a1;
  *a7 = 0;
  if ( a3 )
    return sub_7E53A8();
  v9 = PnpOpenPropertiesKey(a1, a2, 0, 9, 0, v23, &v25);
  v10 = v9;
  if ( v9 == -1073741772 )
    return 0;
  if ( v9 >= 0 )
  {
    v10 = -1073741789;
    v11 = a6;
    for ( i = 0; ; i = v28 )
    {
      while ( 1 )
      {
        do
        {
          v24[0] = 39;
          v9 = PnpCtxRegEnumKey(v9);
          v28 = ++i;
        }
        while ( v9 == -1073741789 );
        if ( v9 )
        {
          ZwClose();
          if ( *a7 <= v11 )
            return 0;
          return v10;
        }
        v9 = RtlInitUnicodeStringEx((int)v30, v36);
        if ( v9 >= 0 )
        {
          v9 = RtlGUIDFromString(v30, v34);
          if ( v9 >= 0 )
          {
            v9 = PnpCtxRegOpenKey(v7, v25, (int)v36, 0);
            if ( v9 >= 0 )
              break;
          }
        }
      }
      v13 = 0;
      while ( 1 )
      {
        do
        {
          v24[0] = 9;
          v9 = PnpCtxRegEnumKey(v9);
          ++v13;
        }
        while ( v9 == -1073741789 );
        if ( v9 )
          break;
        v9 = RtlInitUnicodeStringEx((int)v30, v35);
        if ( v9 >= 0 )
        {
          v9 = RtlUnicodeStringToInteger(v30, 0x10u, &v32);
          if ( v9 >= 0 )
          {
            v9 = PnpCtxRegOpenKey(v27, v24[1], (int)v35, 0);
            if ( v9 >= 0 )
            {
              v14 = 0;
              if ( v33 )
              {
                v15 = 0;
                do
                {
                  v24[0] = 85;
                  v9 = PnpCtxRegEnumValue(v9, v26, v15++, (int)v37, (int)v24, (int)&v31, 0, 0);
                }
                while ( v9 == -1073741789 );
                v11 = a6;
                v16 = v9 == 0;
LABEL_25:
                if ( !v16 )
                  goto LABEL_28;
                goto LABEL_27;
              }
              v24[0] = 0;
              v17 = PnpCtxRegQueryValue(v9, v26, 0, &v31, 0, v24);
              if ( v17 )
              {
                v16 = v17 == -1073741789;
                goto LABEL_25;
              }
LABEL_27:
              v14 = 1;
LABEL_28:
              v9 = ZwClose();
              if ( v14 )
              {
                if ( *a7 < v11 )
                {
                  v18 = v29;
                  v19 = (_DWORD *)(v29 + 20 * *a7);
                  v9 = v34[0];
                  v20 = v34[1];
                  v21 = v34[2];
                  v22 = v34[3];
                  *v19 = v34[0];
                  v19[1] = v20;
                  v19[2] = v21;
                  v19[3] = v22;
                  *(_DWORD *)(v18 + 20 * *a7 + 16) = v32;
                }
                ++*a7;
              }
            }
          }
        }
      }
      v9 = ZwClose();
      v7 = v27;
    }
  }
  return v10;
}
