// WdipSemLoadNextEndEvent 
 
int __fastcall WdipSemLoadNextEndEvent(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r0
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r2
  unsigned __int16 *v11; // r0
  char *v12; // r1
  int v13; // r3
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // [sp+8h] [bp-1D8h] BYREF
  int v18; // [sp+Ch] [bp-1D4h] BYREF
  int v19; // [sp+10h] [bp-1D0h] BYREF
  int v20; // [sp+14h] [bp-1CCh] BYREF
  int v21; // [sp+18h] [bp-1C8h] BYREF
  __int64 v22; // [sp+20h] [bp-1C0h] BYREF
  unsigned __int16 v23[4]; // [sp+28h] [bp-1B8h] BYREF
  int v24[38]; // [sp+30h] [bp-1B0h] BYREF
  unsigned __int16 v25[64]; // [sp+C8h] [bp-118h] BYREF
  unsigned __int16 v26[76]; // [sp+148h] [bp-98h] BYREF

  v17 = 0;
  v18 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 0;
  v22 = 0i64;
  if ( !a1 || !a3 )
    return -1073741811;
  memset(v24, 0, sizeof(v24));
  v6 = ZwEnumerateKey();
  v5 = v6;
  if ( v6 != -2147483622 && v6 >= 0 )
  {
    if ( v24[3] >= 0x80u )
    {
      v5 = -2147483643;
      goto LABEL_8;
    }
    *((_WORD *)&v24[4] + ((unsigned int)v24[3] >> 1)) = 0;
    memset(v25, 0, sizeof(v25));
    memset(v26, 0, 128);
    v8 = 0;
    while ( 1 )
    {
      v9 = *((unsigned __int16 *)&v24[4] + v8);
      if ( v9 == 59 )
        break;
      v25[v8++] = v9;
      if ( v8 >= 0x40 )
        goto LABEL_17;
    }
    if ( 2 * v8 >= 0x80 )
      _report_rangecheckfailure();
    v25[v8] = 0;
LABEL_17:
    if ( v8 >= 0x40 )
      goto LABEL_18;
    v10 = v8 + 1;
    if ( v10 >= 0x40 )
      goto LABEL_18;
    v11 = v26;
    v12 = (char *)v24 + 2 * v10;
    do
    {
      v13 = *((unsigned __int16 *)v12 + 8);
      *v11++ = v13;
      if ( !v13 )
        break;
      ++v10;
      v12 += 2;
    }
    while ( v10 < 0x40 );
    if ( v10 >= 0x40 )
    {
LABEL_18:
      v5 = -1073741823;
      goto LABEL_8;
    }
    RtlInitUnicodeString((unsigned int)v23, v25);
    v5 = RtlGUIDFromString(v23, (_BYTE *)a3);
    if ( v5 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v23, v26);
      v5 = RtlUnicodeStringToInteger(v23, 0xAu, &v20);
      if ( v5 >= 0 )
      {
        *(_WORD *)(a3 + 16) = v20;
        v5 = WdipSemOpenRegistryKey(&v24[4], a1, &v17);
        if ( v5 >= 0 )
        {
          v14 = WdipSemQueryValueFromRegistry(v17, L"Level", 4, 4, &v21, &v18);
          v5 = v14;
          if ( v14 >= 0 )
          {
            if ( v21 )
            {
              *(_BYTE *)(a3 + 18) = v21;
              goto LABEL_33;
            }
          }
          else if ( v14 != -1073741772 )
          {
            goto LABEL_8;
          }
          *(_BYTE *)(a3 + 18) = -1;
LABEL_33:
          v15 = WdipSemQueryValueFromRegistry(v17, L"Keyword", 11, 8, &v22, &v18);
          v5 = v15;
          if ( v15 >= 0 )
          {
            if ( v22 )
            {
              *(_QWORD *)(a3 + 24) = v22;
LABEL_39:
              v16 = WdipSemQueryValueFromRegistry(v17, L"EnableProperty", 4, 4, &v19, &v18);
              v5 = v16;
              if ( v16 >= 0 )
              {
                *(_DWORD *)(a3 + 36) = v19;
              }
              else if ( v16 == -1073741772 )
              {
                v5 = 0;
                *(_DWORD *)(a3 + 36) = 0;
              }
              goto LABEL_8;
            }
LABEL_37:
            *(_DWORD *)(a3 + 24) = -1;
            *(_DWORD *)(a3 + 28) = -1;
            goto LABEL_39;
          }
          if ( v15 == -1073741772 )
            goto LABEL_37;
          goto LABEL_8;
        }
      }
    }
  }
LABEL_8:
  if ( v17 )
    ZwClose();
  return v5;
}
