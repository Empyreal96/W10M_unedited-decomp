// CmpMoveBiosAliasTable 
 
int CmpMoveBiosAliasTable(int a1, int a2, int a3, ...)
{
  int v5; // r4
  unsigned int i; // r7
  int v7; // r3
  unsigned __int16 *v8; // r4
  unsigned __int16 *v9; // r4
  __int16 v11[2]; // [sp+10h] [bp-88h] BYREF
  _DWORD *v12; // [sp+14h] [bp-84h]
  char v13[4]; // [sp+18h] [bp-80h] BYREF
  int v14; // [sp+1Ch] [bp-7Ch]
  int v15; // [sp+20h] [bp-78h]
  int v16; // [sp+24h] [bp-74h]
  __int16 *v17; // [sp+28h] [bp-70h]
  int v18; // [sp+2Ch] [bp-6Ch]
  int v19; // [sp+30h] [bp-68h]
  int v20; // [sp+34h] [bp-64h]
  unsigned __int16 *v21; // [sp+38h] [bp-60h]
  int v22; // [sp+3Ch] [bp-5Ch]
  int v23; // [sp+40h] [bp-58h]
  int v24; // [sp+44h] [bp-54h]
  unsigned int v25; // [sp+5Ch] [bp-3Ch]
  int varg_r3; // [sp+ACh] [bp+14h] BYREF
  va_list varg_r3a; // [sp+ACh] [bp+14h]
  int v28; // [sp+B0h] [bp+18h]
  int v29; // [sp+B4h] [bp+1Ch]
  _DWORD *v30; // [sp+B8h] [bp+20h]
  va_list va1; // [sp+BCh] [bp+24h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v28 = va_arg(va1, _DWORD);
  v29 = va_arg(va1, _DWORD);
  v30 = va_arg(va1, _DWORD *);
  v21 = (unsigned __int16 *)v28;
  v14 = 0;
  v23 = a1;
  RtlInitUnicodeString((unsigned int)v11, L"SerialNumber");
  if ( ZwQueryValueKey() >= 0
    && v30[1] == 4
    && (v24 = *(_DWORD *)((char *)v30 + v30[2]),
        RtlInitUnicodeString((unsigned int)v11, L"DockID"),
        ZwQueryValueKey() >= 0)
    && v30[1] == 4 )
  {
    v22 = *(_DWORD *)((char *)v30 + v30[2]);
    RtlInitUnicodeString((unsigned int)v11, L"Alias");
    v15 = 24;
    v16 = a1;
    v17 = v11;
    v19 = 0;
    v20 = 0;
    v18 = 576;
    if ( ZwOpenKey() < 0 )
    {
      v5 = 0;
      v14 = 0;
      return v5;
    }
    v5 = ZwQueryKey();
    if ( v5 >= 0 )
    {
      for ( i = 0; i < v25; ++i )
      {
        v5 = ZwEnumerateKey();
        if ( v5 < 0 )
          break;
        *((_WORD *)v30 + (v30[3] >> 1) + 8) = 0;
        v7 = v30[3];
        v11[0] = v7;
        v11[1] = v7 + 2;
        v12 = v30 + 4;
        v15 = 24;
        v18 = 576;
        v16 = v14;
        v17 = v11;
        v19 = 0;
        v20 = 0;
        v5 = ZwOpenKey();
        if ( v5 < 0 )
          break;
        RtlInitUnicodeString((unsigned int)v11, L"ProfileNumber");
        v5 = ZwQueryValueKey();
        if ( v5 < 0 || v30[1] != 4 )
          goto LABEL_34;
        if ( a3 != *(_DWORD *)((char *)v30 + v30[2]) )
          goto LABEL_14;
        RtlInitUnicodeString((unsigned int)v11, L"DockID");
        v5 = ZwQueryValueKey();
        if ( v5 < 0 || v30[1] != 4 )
          goto LABEL_34;
        if ( v22 != *(_DWORD *)((char *)v30 + v30[2]) )
          goto LABEL_14;
        RtlInitUnicodeString((unsigned int)v11, L"SerialNumber");
        v5 = ZwQueryValueKey();
        if ( v5 < 0 || v30[1] != 4 )
          goto LABEL_34;
        if ( v24 == *(_DWORD *)((char *)v30 + v30[2]) )
        {
          RtlInitUnicodeString((unsigned int)v11, L"ProfileNumber");
          ZwSetValueKey();
          ZwClose();
          RtlInitUnicodeString((unsigned int)v11, L"Hardware Profiles");
          v15 = 24;
          v16 = v23;
          v17 = v11;
          v18 = 576;
          v19 = 0;
          v20 = 0;
          if ( ZwOpenKey() < 0 )
            goto LABEL_34;
          v8 = v21;
          swprintf_s((int)v21, 128, (int)L"%04d", a3, varg_r3a, 4);
          RtlInitUnicodeString((unsigned int)v11, v8);
          v15 = 24;
          v16 = 0;
          v17 = v11;
          v18 = 576;
          v19 = 0;
          v20 = 0;
          if ( ZwOpenKey() < 0 )
            goto LABEL_34;
          RtlInitUnicodeString((unsigned int)v11, L"Cloned");
          v5 = ZwQueryValueKey();
          if ( v5 < 0 || v30[1] != 4 )
            goto LABEL_34;
          if ( *(_DWORD *)((char *)v30 + v30[2]) )
          {
            ZwDeleteKey();
            ZwClose();
            ZwClose();
            RtlInitUnicodeString(
              (unsigned int)v11,
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles");
            v15 = 24;
            v16 = 0;
            v17 = v11;
            v18 = 576;
            v19 = 0;
            v20 = 0;
            if ( ZwOpenKey() < 0 )
              goto LABEL_34;
            v9 = v21;
            swprintf_s((int)v21, 128, (int)L"%04d", a3, 256, v13);
            v5 = CmDeleteKeyRecursive(0, v9, (int)v30, 256);
            ZwClose();
          }
          else
          {
            ZwClose();
            ZwClose();
          }
        }
        else
        {
LABEL_14:
          ZwClose();
        }
      }
    }
  }
  else
  {
LABEL_34:
    v5 = -1073741492;
  }
  if ( v14 )
    ZwClose();
  return v5;
}
