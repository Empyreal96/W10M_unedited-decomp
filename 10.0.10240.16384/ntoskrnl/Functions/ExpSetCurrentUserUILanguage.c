// ExpSetCurrentUserUILanguage 
 
int __fastcall ExpSetCurrentUserUILanguage(unsigned __int16 *a1, unsigned int a2)
{
  unsigned int v4; // r6
  _BYTE *v5; // r0
  int v6; // r10
  _BYTE *v7; // r5
  int v8; // r2
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r4
  int v13; // r0
  int v14; // r3
  int v15; // r4
  int v16; // r5
  unsigned int v17; // r1
  _WORD *i; // r2
  __int16 v19; // r3
  __int16 v20; // r3
  int v21; // r3
  _BYTE v23[961]; // [sp+2Fh] [bp-459h] BYREF
  int v24; // [sp+400h] [bp-88h]
  int v25; // [sp+404h] [bp-84h] BYREF
  unsigned __int16 v26[4]; // [sp+408h] [bp-80h] BYREF
  int v27; // [sp+410h] [bp-78h]
  int v28; // [sp+418h] [bp-70h]
  int v29; // [sp+41Ch] [bp-6Ch]
  _BYTE *v30; // [sp+420h] [bp-68h]
  int v31; // [sp+424h] [bp-64h]
  int v32; // [sp+428h] [bp-60h]
  int v33; // [sp+42Ch] [bp-5Ch]
  int v34; // [sp+430h] [bp-58h]
  _BYTE v35[8]; // [sp+440h] [bp-48h] BYREF
  int v36; // [sp+448h] [bp-40h]
  int v37; // [sp+44Ch] [bp-3Ch]
  int v38; // [sp+450h] [bp-38h] BYREF
  int v39; // [sp+454h] [bp-34h] BYREF
  unsigned int v40; // [sp+458h] [bp-30h]
  int v41; // [sp+45Ch] [bp-2Ch]
  int v42; // [sp+460h] [bp-28h] BYREF

  v4 = (unsigned int)v23 & 0xFFFFFFE0;
  v40 = (unsigned int)v23 & 0xFFFFFFE0;
  *(_WORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x320) = 0;
  v5 = memset((_BYTE *)(((unsigned int)v23 & 0xFFFFFFE0) + 802), 0, 168);
  v27 = 0;
  v36 = 0;
  v24 = 0;
  v34 = 0;
  v41 = 1;
  v6 = 0;
  v39 = 0;
  v7 = (_BYTE *)(((unsigned int)v23 & 0xFFFFFFE0) + 544);
  v9 = OpenGlobalizationUserSettingsKey((int)v5, 3, v8, (int)&v38, (int)&v38);
  if ( v9 < 0 )
    return v9;
  RtlInitUnicodeString((unsigned int)v26, a1);
  RtlInitUnicodeString((unsigned int)v35, L"Control Panel\\Desktop");
  v28 = 24;
  v29 = v38;
  v31 = 1600;
  v30 = v35;
  v32 = 0;
  v33 = 0;
  if ( !a2 )
  {
    v9 = ZwOpenKey();
    v25 = v9;
    if ( v9 < 0 )
      goto LABEL_75;
    v37 = 1;
    RtlInitUnicodeString((unsigned int)v26, L"MultiUILanguageId");
    if ( ZwQueryValueKey() >= 0
      && *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) > 4u
      && *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x224) == 1 )
    {
      RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)(v4 + 556));
      if ( RtlUnicodeStringToInteger(v26, 0x10u, &v39) >= 0
        && DownLevelLangIDToLanguageName((unsigned __int16)v39, (unsigned __int16 *)(v4 + 800), 85, 0) > 1 )
      {
        RtlInitUnicodeString((unsigned int)v26, L"PreferredUILanguages");
        wcslen((unsigned __int16 *)(v4 + 800));
        ZwSetValueKey();
      }
      RtlInitUnicodeString((unsigned int)v26, L"MultiUILanguageId");
      ZwDeleteValueKey();
      v39 = 1;
    }
    RtlInitUnicodeString((unsigned int)v26, L"PreferredUILanguagesPending");
    if ( ZwQueryValueKey() >= 0
      && *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) >= 4u
      && *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x224) == 7 )
    {
      RtlInitUnicodeString((unsigned int)v26, L"PreferredUILanguages");
      if ( ZwSetValueKey() >= 0 )
      {
        v39 = 1;
        v10 = *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228);
        if ( v10 + 12 < 0x100 )
        {
          *(_WORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x220 + 2 * (v10 >> 1) + 10) = 0;
          RtlInitUnicodeString((unsigned int)v26, L"PreferredUILanguagesPending");
          ZwDeleteValueKey();
          RtlInitUnicodeString((unsigned int)&v42, (unsigned __int16 *)(v4 + 556));
          RtlInitUnicodeString((unsigned int)v35, L"Control Panel\\Desktop\\LanguageConfigurationPending");
          v28 = 24;
          v29 = v38;
          v31 = 1600;
          v30 = v35;
          v32 = 0;
          v33 = 0;
          if ( ZwOpenKey() >= 0 && ZwQueryValueKey() >= 0 && *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 4) == 7 )
          {
            RtlInitUnicodeString((unsigned int)v35, L"Control Panel\\Desktop\\LanguageConfiguration");
            v28 = 24;
            v29 = v38;
            v31 = 1600;
            v30 = v35;
            v32 = 0;
            v33 = 0;
            if ( ZwCreateKey() >= 0 )
            {
              if ( ZwSetValueKey() >= 0 )
                ZwDeleteValueKey();
              ZwClose();
            }
          }
        }
      }
    }
    RtlInitUnicodeString((unsigned int)v35, L"Control Panel\\Desktop\\MuiCached");
    v28 = 24;
    v29 = v38;
    v31 = 1600;
    v30 = v35;
    v32 = 0;
    v33 = 0;
    ZwOpenKey();
    RtlInitUnicodeString((unsigned int)v35, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings");
    v28 = 24;
    v29 = 0;
    v31 = 1600;
    v30 = v35;
    v32 = 0;
    v33 = 0;
    if ( ZwOpenKey() < 0 )
    {
      v11 = v24;
      if ( !v24 )
      {
LABEL_43:
        RtlInitUnicodeString((unsigned int)v35, L"MachineLanguageConfiguration");
        v28 = 24;
        v29 = v11;
        v31 = 1600;
        v30 = v35;
        v32 = 0;
        v33 = 0;
        if ( ZwOpenKey() >= 0 )
        {
          v15 = 0;
          while ( 1 )
          {
            memset(v7, 0, 256);
            if ( ZwEnumerateValueKey() < 0 )
              break;
            RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)(((unsigned int)v23 & 0xFFFFFFE0) + 556));
            if ( ZwDeleteValueKey() < 0 )
            {
              DbgPrint(
                "*** MUI: Failed to delete value %S from MachineLanguageConfiguration!\n",
                (const void *)(((unsigned int)v23 & 0xFFFFFFE0) + 556));
              ++v15;
            }
          }
          v4 = v40;
        }
        RtlInitUnicodeString(
          (unsigned int)v35,
          L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings\\LanguageConfiguration");
        v28 = 24;
        v29 = 0;
        v31 = 1600;
        v30 = v35;
        v32 = 0;
        v33 = 0;
        if ( ZwOpenKey() >= 0 )
        {
          v16 = 0;
          while ( 1 )
          {
            memset((_BYTE *)v4, 0, 528);
            ++v16;
            v9 = ZwEnumerateValueKey();
            v25 = v9;
            if ( v9 < 0 )
              break;
            v17 = *(_DWORD *)(v4 + 16);
            if ( v17 + 24 <= 0x210
              && (unsigned int)(*(_DWORD *)(v4 + 8) + *(_DWORD *)(v4 + 12)) <= 0x210
              && *(_DWORD *)(v4 + 4) == 7
              && v17 < 0xAA )
            {
              memset((_BYTE *)(v4 + 800), 0, 170);
              memmove(v4 + 800, v4 + 20, *(_DWORD *)(v4 + 16));
              RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)(v4 + 800));
              if ( !v34 )
              {
                RtlInitUnicodeString((unsigned int)v35, L"MachineLanguageConfiguration");
                v28 = 24;
                v29 = v24;
                v31 = 1600;
                v30 = v35;
                v32 = 0;
                v33 = 0;
                v9 = ZwCreateKey();
                v25 = v9;
                if ( v9 < 0 )
                  goto LABEL_74;
                v41 = 0;
              }
              v25 = ZwSetValueKey();
              if ( v25 < 0 )
              {
                DbgPrint("*** MUI: Can't copy language name for LanguageConfig item %S\n", (const void *)(v4 + 800));
                v25 = 0;
              }
            }
            else
            {
              DbgPrint("*** MUI: Can't copy language name for LanguageConfig item %u\n", v16 - 1);
            }
          }
          ZwClose();
        }
        else
        {
          v9 = 0;
          v25 = 0;
        }
        goto LABEL_74;
      }
      RtlInitUnicodeString((unsigned int)v26, L"MachinePreferredUILanguages");
      ZwDeleteValueKey();
LABEL_42:
      v11 = v24;
      goto LABEL_43;
    }
    RtlInitUnicodeString((unsigned int)v26, L"PreferredUILanguages");
    if ( ZwQueryValueKey() < 0
      || *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) < 4u
      || *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x224) != 7 )
    {
      LOWORD(v25) = 0;
      *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) = 0;
      v12 = NtQueryInstallUILanguage(&v25);
      if ( v12 < 0 )
        goto LABEL_34;
      v13 = DownLevelLangIDToLanguageName((unsigned __int16)v25, (unsigned __int16 *)(v4 + 556), 128, 0);
      *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) = v13;
      if ( !v13 )
      {
        v12 = -1073741823;
LABEL_34:
        DbgPrintEx(-1, 0, (int)"sysinfo: Can't set MachinePreferredUILanguages due to error %d\n", v12);
        if ( v24 )
          ZwDeleteValueKey();
LABEL_41:
        ZwClose();
        goto LABEL_42;
      }
      *(_DWORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x228) = 2 * v13;
    }
    if ( !v24 )
    {
      RtlInitUnicodeString((unsigned int)v35, L"Control Panel\\Desktop\\MuiCached");
      v28 = 24;
      v29 = v38;
      v31 = 1600;
      v30 = v35;
      v32 = 0;
      v33 = 0;
      v9 = ZwCreateKey();
      v25 = v9;
      if ( v9 < 0 )
      {
LABEL_74:
        v6 = v37;
        goto LABEL_75;
      }
    }
    RtlInitUnicodeString((unsigned int)v26, L"MachinePreferredUILanguages");
    if ( ZwSetValueKey() < 0 )
      DbgPrintEx(-1, 0, (int)"sysinfo: Can't set MachinePreferredUILanguages\n", v14);
    goto LABEL_41;
  }
  v9 = ExpValidateLocale(a2);
  v25 = v9;
  if ( v9 >= 0 )
  {
    v9 = ZwOpenKey();
    v25 = v9;
    if ( v9 >= 0 )
    {
      v37 = 1;
      *(_WORD *)(((unsigned int)v23 & 0xFFFFFFE0) + 0x230) = 0;
      for ( i = (_WORD *)(v4 + 558); i >= (_WORD *)v7; --i )
      {
        v19 = a2 & 0xF;
        if ( (a2 & 0xF) > 9 )
          v20 = v19 + 55;
        else
          v20 = v19 + 48;
        *i = v20;
        a2 >>= 4;
      }
      v9 = ZwSetValueKey();
      v25 = v9;
      v6 = v37;
    }
  }
LABEL_75:
  if ( v6 )
    ZwClose();
  if ( v36 )
  {
    if ( ZwEnumerateValueKey() == -2147483622 )
      ZwDeleteKey();
    ZwClose();
  }
  if ( !v24 )
    goto LABEL_90;
  if ( !v34 )
    goto LABEL_87;
  if ( v41 && ZwEnumerateValueKey() == -2147483622 )
  {
    if ( v34 )
      ZwDeleteKey();
LABEL_87:
    if ( ZwEnumerateValueKey() == -2147483622 )
      ZwDeleteKey();
  }
  ZwClose();
LABEL_90:
  if ( v34 )
    ZwClose();
  CloseGlobalizationUserSettingsKey(v38);
  if ( v39 == 1 )
  {
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
      || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    {
      v21 = 0;
    }
    else
    {
      v21 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
    }
    if ( v21 )
      *(_DWORD *)(v21 + 4036) = 0;
  }
  return v9;
}
