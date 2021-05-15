// NtSetDefaultLocale 
 
int __fastcall NtSetDefaultLocale(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r4
  int v6; // r3
  int v7; // r2
  int v8; // r3
  int *v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // t1
  unsigned int v13; // r3
  int v14; // r3
  _WORD *v15; // r2
  __int16 v16; // r3
  unsigned int i; // r1
  __int16 v18; // r3
  int v20; // [sp+Ch] [bp-144h] BYREF
  char v21[8]; // [sp+10h] [bp-140h] BYREF
  char v22[8]; // [sp+18h] [bp-138h] BYREF
  int v23; // [sp+20h] [bp-130h]
  int v24; // [sp+24h] [bp-12Ch]
  char *v25; // [sp+28h] [bp-128h]
  int v26; // [sp+2Ch] [bp-124h]
  int v27; // [sp+30h] [bp-120h]
  int v28; // [sp+34h] [bp-11Ch]
  _WORD v29[2]; // [sp+40h] [bp-110h] BYREF
  int v30; // [sp+44h] [bp-10Ch]
  unsigned int v31; // [sp+48h] [bp-108h]
  int v32; // [sp+4Ch] [bp-104h] BYREF

  v20 = 0;
  v4 = a2;
  if ( a1 )
  {
    v5 = OpenGlobalizationUserSettingsKey(a1, 3, a3, (int)&v20, (int)&v20);
    if ( v5 < 0 )
      return v5;
    RtlInitUnicodeString((unsigned int)v21, L"Locale");
    RtlInitUnicodeString((unsigned int)v22, L"Control Panel\\International");
    v6 = v20;
    v7 = 1600;
  }
  else
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = ExpCheckFullProcessInformationAccess(*(_BYTE *)(v8 + 346), a2, a3, v8);
    if ( v5 < 0 )
      return v5;
    RtlInitUnicodeString((unsigned int)v21, L"Default");
    RtlInitUnicodeString((unsigned int)v22, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language");
    v6 = 0;
    v20 = 0;
    v7 = 576;
  }
  v24 = v6;
  v25 = v22;
  v26 = v7;
  v27 = 0;
  v28 = 0;
  v23 = 24;
  if ( v4 )
  {
    v5 = ExpValidateLocale(v4);
    if ( v5 < 0 )
      goto LABEL_40;
    v5 = ZwOpenKey();
    if ( v5 < 0 )
      goto LABEL_40;
    if ( a1 )
      v14 = 8;
    else
      v14 = 4;
    v15 = &v29[v14];
    v16 = 0;
    for ( i = v4; ; i >>= 4 )
    {
      *v15-- = v16;
      if ( v15 < v29 )
        break;
      v18 = i & 0xF;
      if ( (i & 0xF) > 9 )
        v16 = v18 + 55;
      else
        v16 = v18 + 48;
    }
    v5 = ZwSetValueKey();
    goto LABEL_39;
  }
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
  {
    v5 = ZwQueryValueKey();
    if ( v5 >= 0 )
    {
      if ( v30 == 1 )
      {
        v9 = &v32;
        v10 = 0;
        if ( v31 )
        {
          while ( 1 )
          {
            v12 = *(unsigned __int16 *)v9;
            v9 = (int *)((char *)v9 + 2);
            v11 = v12;
            if ( v12 < 0x30 || v11 > 0x39 )
            {
              if ( v11 < 0x41 || v11 > 0x46 )
              {
                if ( v11 < 0x61 || v11 > 0x66 )
                  break;
                v13 = v11 - 87;
              }
              else
              {
                v13 = v11 - 55;
              }
            }
            else
            {
              v13 = v11 - 48;
            }
            if ( v13 < 0x10 )
            {
              v10 += 2;
              v4 = v13 | (16 * v4);
              if ( v10 < v31 )
                continue;
            }
            break;
          }
        }
      }
      else if ( v30 == 4 && v31 == 4 )
      {
        v4 = v32;
      }
      else
      {
        v5 = -1073741823;
      }
    }
LABEL_39:
    ZwClose();
  }
LABEL_40:
  if ( v20 )
    CloseGlobalizationUserSettingsKey(v20);
  if ( v5 >= 0 )
  {
    if ( a1 )
      MmSetSessionLocaleId(v4);
    else
      PsDefaultSystemLocaleId = v4;
  }
  return v5;
}
