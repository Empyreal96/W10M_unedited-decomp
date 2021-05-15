// PiDcInitUpdateProperties 
 
int PiDcInitUpdateProperties()
{
  int v0; // r6
  int v2; // r0
  int v3; // r4
  int v4; // r2
  int i; // r9
  int v6; // r0
  unsigned int v7; // r3
  unsigned __int16 v8; // [sp+10h] [bp-68h] BYREF
  unsigned __int16 v9; // [sp+12h] [bp-66h]
  int v10; // [sp+14h] [bp-64h]
  int v11; // [sp+18h] [bp-60h]
  int v12; // [sp+20h] [bp-58h]
  int v13; // [sp+28h] [bp-50h]
  int v14; // [sp+2Ch] [bp-4Ch]
  unsigned __int16 *v15; // [sp+30h] [bp-48h]
  int v16; // [sp+34h] [bp-44h]
  int v17; // [sp+38h] [bp-40h]
  int v18; // [sp+3Ch] [bp-3Ch]
  char v19[16]; // [sp+40h] [bp-38h] BYREF
  int v20[10]; // [sp+50h] [bp-28h] BYREF

  v11 = 0;
  v0 = ExAllocatePoolWithTag(1, 536, 1198550608);
  if ( !v0 )
    return sub_818BA0();
  RtlInitUnicodeString(
    (unsigned int)&v8,
    L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\DeviceContainerPropertyUpdateEvents");
  v11 = 0;
  v13 = 24;
  v14 = 0;
  v15 = &v8;
  v17 = 0;
  v18 = 0;
  v16 = 576;
  v2 = ZwOpenKey();
  v3 = v2;
  if ( v2 == -1073741772 )
  {
LABEL_22:
    v3 = 0;
    goto LABEL_23;
  }
  if ( v2 >= 0 )
  {
    v12 = 0;
    v3 = ZwEnumerateKey();
    if ( v3 != -2147483622 )
    {
      v4 = v0 + 16;
      while ( v3 >= 0 )
      {
        v10 = v4;
        v8 = *(_DWORD *)(v0 + 12);
        v9 = v8;
        v14 = v11;
        v15 = &v8;
        v17 = 0;
        v18 = 0;
        v13 = 24;
        v16 = 576;
        v3 = ZwOpenKey();
        if ( v3 < 0 )
          break;
        for ( i = 0; ; ++i )
        {
          v6 = ZwEnumerateValueKey();
          v3 = v6;
          if ( v6 == -2147483622 )
          {
            v3 = 0;
            goto LABEL_20;
          }
          if ( v6 != -2147483643 )
          {
            if ( v6 < 0 )
              goto LABEL_20;
            v7 = *(_DWORD *)(v0 + 8);
            if ( v7 >= 0x50 && v7 <= 0x62 )
            {
              v10 = v0 + 12;
              v8 = 76;
              v9 = 76;
              if ( RtlGUIDFromString(&v8, v19) >= 0 )
              {
                v10 = v0 + 90;
                v8 = *(_WORD *)(v0 + 8) - 78;
                v9 = v8;
                if ( RtlUnicodeStringToInteger(&v8, 0xAu, v20) >= 0
                  && !RtlInsertElementGenericTableAvl((int)&PiDcUpdateProperties, (int)v19, 20, 0) )
                {
                  break;
                }
              }
            }
          }
        }
        v3 = -1073741670;
LABEL_20:
        ZwClose();
        if ( v3 < 0 )
          break;
        ++v12;
        v3 = ZwEnumerateKey();
        v4 = v0 + 16;
        if ( v3 == -2147483622 )
          goto LABEL_22;
      }
      goto LABEL_23;
    }
    goto LABEL_22;
  }
LABEL_23:
  if ( v11 )
    ZwClose();
  ExFreePoolWithTag(v0);
  return v3;
}
