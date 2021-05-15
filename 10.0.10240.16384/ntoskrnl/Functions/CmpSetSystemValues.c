// CmpSetSystemValues 
 
int __fastcall CmpSetSystemValues(unsigned int *a1)
{
  int v2; // r4
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r3
  BOOL v8; // [sp+Ch] [bp-14Ch] BYREF
  int v9; // [sp+10h] [bp-148h] BYREF
  int v10; // [sp+14h] [bp-144h]
  int v11; // [sp+20h] [bp-138h]
  int v12; // [sp+24h] [bp-134h]
  int (**v13)[2]; // [sp+28h] [bp-130h]
  int v14; // [sp+2Ch] [bp-12Ch]
  int v15; // [sp+30h] [bp-128h]
  int v16; // [sp+34h] [bp-124h]

  v10 = 0;
  v11 = 24;
  v12 = 0;
  v14 = 64;
  v13 = &CmpControlPathString;
  v15 = 0;
  v16 = 0;
  v2 = NtOpenKey();
  if ( v2 >= 0 )
  {
    v2 = NtSetValueKey(0, (int)&CmpSystemStartOptionsString, 0, 1, dword_98223C, (unsigned __int16)CmpLoadOptions);
    if ( v2 >= 0 )
    {
      if ( !RtlCreateUnicodeStringFromAsciiz((unsigned __int16 *)&v9, a1[26], v3, v4) )
        goto LABEL_17;
      v2 = NtSetValueKey(0, (int)&CmpSystemBootDeviceString, 0, 1, v10, (unsigned __int16)v9 + 2);
      if ( v2 < 0 )
        goto LABEL_14;
      v6 = v10;
      if ( v10 )
      {
        RtlFreeAnsiString(&v9);
        v6 = 0;
        v10 = 0;
      }
      if ( !RtlCreateUnicodeStringFromAsciiz((unsigned __int16 *)&v9, a1[27], v5, v6) )
      {
LABEL_17:
        v2 = -1073741823;
        goto LABEL_14;
      }
      v2 = NtSetValueKey(0, (int)&CmpFirmwareBootDeviceString, 0, 1, v10, (unsigned __int16)v9 + 2);
      if ( v2 >= 0 )
      {
        v8 = (*(_DWORD *)(a1[33] + 68) & 1) != 0;
        v2 = NtSetValueKey(0, (int)&CmpLastBootSucceededString, 0, 4, (int)&v8, 4u);
        if ( v2 >= 0 )
        {
          v8 = (*(_DWORD *)(a1[33] + 68) & 2) != 0;
          v2 = NtSetValueKey(0, (int)&CmpLastBootShutdownString, 0, 4, (int)&v8, 4u);
          if ( v2 >= 0 )
          {
            if ( (*(_DWORD *)(a1[33] + 68) & 2) == 0 )
              return sub_966FDC();
            v2 = 0;
          }
        }
      }
    }
  }
LABEL_14:
  if ( v10 )
    RtlFreeAnsiString(&v9);
  return v2;
}
