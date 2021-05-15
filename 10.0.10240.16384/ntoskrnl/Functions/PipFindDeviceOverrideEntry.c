// PipFindDeviceOverrideEntry 
 
int __fastcall PipFindDeviceOverrideEntry(unsigned __int16 *a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r3
  int v5; // r4
  int v6; // r4
  int v7; // r4
  int v8; // r0
  __int16 *v9; // r6
  unsigned __int16 *v10; // r8
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned __int16 *v13; // r5
  int v14; // r9
  unsigned int v16; // [sp+8h] [bp-50h] BYREF
  int v17; // [sp+Ch] [bp-4Ch]
  __int16 v18; // [sp+10h] [bp-48h] BYREF
  __int16 v19; // [sp+12h] [bp-46h]
  const __int16 *v20; // [sp+14h] [bp-44h]
  unsigned __int16 v21[4]; // [sp+18h] [bp-40h] BYREF
  int v22; // [sp+20h] [bp-38h]
  int v23; // [sp+24h] [bp-34h]
  __int16 *v24; // [sp+28h] [bp-30h]
  int v25; // [sp+2Ch] [bp-2Ch]
  int v26; // [sp+30h] [bp-28h]
  int v27; // [sp+34h] [bp-24h]

  v3 = (int)a1;
  v4 = *a1;
  v17 = a3;
  if ( !v4 )
    return -1073741772;
  v6 = 0;
  do
  {
    v6 += wcslen(a1) + 1;
    a1 = (unsigned __int16 *)(v3 + 2 * v6);
  }
  while ( *a1 );
  v7 = v6 + 1;
  v8 = ExAllocatePoolWithTag(1, 2 * v7, 1852403792);
  v9 = (__int16 *)v8;
  if ( v8 )
  {
    memmove(v8, v3, 2 * v7);
    v18 = 2 * v7;
    v19 = 2 * v7;
    v20 = v9;
    IopReplaceSeperatorWithPound(&v18, &v18);
    v5 = -1073741772;
    v10 = (unsigned __int16 *)v9;
    if ( *v9 )
    {
      while ( 2 )
      {
        RtlInitUnicodeString((unsigned int)v21, v10);
        if ( RtlHashUnicodeString(v21, 1, 0, &v16) >= 0 )
        {
          v11 = v16;
        }
        else
        {
          v11 = 0;
          v16 = 0;
        }
        if ( !PnpDeviceOverrideHashListSize )
          __brkdiv0();
        v12 = v11 % PnpDeviceOverrideHashListSize;
        v5 = -1073741772;
        v13 = *(unsigned __int16 **)(PnpDeviceOverrideHashList + 8 * v12);
        v14 = PnpDeviceOverrideHashList + 8 * v12;
        while ( v13 != (unsigned __int16 *)v14 )
        {
          if ( RtlEqualUnicodeString(v21, v13 + 4, 1) )
          {
            v19 = 134;
            v18 = 132;
            v20 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides";
            v22 = 24;
            v23 = 0;
            v24 = &v18;
            v25 = 576;
            v26 = 0;
            v27 = 0;
            v5 = ZwOpenKey();
            if ( v5 < 0 )
              goto LABEL_26;
            v23 = 0;
            v24 = (__int16 *)v21;
            v25 = 576;
            v22 = 24;
            v26 = 0;
            v27 = 0;
            v5 = ZwOpenKey();
            if ( v5 >= 0 )
            {
              if ( !PipCallbackHasDeviceOverrides || PipCallbackHasDeviceOverrides(0, v17) )
                goto LABEL_24;
              ZwClose();
              v5 = -1073741772;
            }
            break;
          }
          v13 = *(unsigned __int16 **)v13;
        }
        v10 += wcslen(v10) + 1;
        if ( *v10 )
          continue;
        break;
      }
LABEL_24:
      if ( v5 >= 0 )
        ZwClose();
    }
  }
  else
  {
    v5 = -1073741670;
  }
LABEL_26:
  if ( v9 )
    ExFreePoolWithTag((unsigned int)v9);
  return v5;
}
