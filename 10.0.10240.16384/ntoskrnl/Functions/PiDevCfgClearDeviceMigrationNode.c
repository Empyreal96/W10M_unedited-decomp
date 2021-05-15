// PiDevCfgClearDeviceMigrationNode 
 
int __fastcall PiDevCfgClearDeviceMigrationNode(int *a1, unsigned __int16 *a2)
{
  int v4; // r0
  int v5; // r6
  int v6; // r1
  unsigned __int16 *v7; // r5
  int v8; // r0
  int v10; // [sp+10h] [bp-B8h] BYREF
  unsigned __int16 *v11; // [sp+14h] [bp-B4h]
  int v12; // [sp+18h] [bp-B0h] BYREF
  int v13; // [sp+1Ch] [bp-ACh]
  int v14; // [sp+20h] [bp-A8h]
  int v15; // [sp+24h] [bp-A4h]
  int v16; // [sp+28h] [bp-A0h] BYREF
  char v17[8]; // [sp+30h] [bp-98h] BYREF
  int v18[36]; // [sp+38h] [bp-90h] BYREF

  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v16 = 0;
  v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, a1[1], (int)a2, 0);
  v5 = v4;
  if ( v4 == -1073741772 )
  {
LABEL_2:
    v5 = 0;
    goto LABEL_36;
  }
  if ( v4 >= 0 )
  {
    memset(v18, 0, 112);
    v18[2] = (int)L"ClassGuid";
    v18[3] = (int)&v12;
    v18[4] = 0x1000000;
    v18[1] = 288;
    v18[9] = (int)L"LocationPaths";
    v18[11] = 117440512;
    v18[10] = (int)&v10;
    v18[8] = 304;
    v18[15] = 288;
    v18[16] = (int)L"Persist";
    v18[18] = 0x4000000;
    v18[17] = (int)&v16;
    v5 = RtlpQueryRegistryValues(-1073741824, 0, v18, 0, 131097, 1u);
    if ( v5 >= 0 )
    {
      if ( !(_WORD)v12 && v13 )
        RtlFreeAnsiString(&v12);
      if ( (unsigned __int16)v10 <= 2u && v11 )
        RtlFreeAnsiString(&v10);
      if ( v16 )
        goto LABEL_2;
      ZwClose();
      PnpCtxRegDeletePath(PiPnpRtlCtx, a1[1], a2, 1);
      if ( a1[3] && RtlInitUnicodeStringEx((int)v17, a2) >= 0 )
        ZwDeleteValueKey();
      v6 = a1[2];
      if ( v6 && v13 )
      {
        if ( PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v6, v13, 0) >= 0 )
        {
          if ( RtlInitUnicodeStringEx((int)v17, a2) >= 0 )
            ZwDeleteValueKey();
          ZwClose();
        }
        PnpCtxRegDeletePath(PiPnpRtlCtx, a1[2], v13, 0);
      }
      v7 = v11;
      if ( v11 )
      {
        if ( !a1[4] )
        {
          v8 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, *a1, (int)L"Locations", 0);
          if ( v8 == -1073741772 )
          {
            a1[4] = 0;
            goto LABEL_36;
          }
          if ( v8 < 0 )
          {
            v5 = v8;
            goto LABEL_36;
          }
          if ( !a1[4] )
            goto LABEL_36;
          v7 = v11;
        }
        while ( *v7 )
        {
          if ( PnpCtxRegOpenKey((int *)PiPnpRtlCtx, a1[4], (int)v7, 0) >= 0 )
          {
            if ( RtlInitUnicodeStringEx((int)v17, a2) >= 0 )
              ZwDeleteValueKey();
            ZwClose();
          }
          PnpCtxRegDeletePath(PiPnpRtlCtx, a1[4], v7, 0);
          v7 += wcslen(v7) + 1;
        }
      }
    }
  }
LABEL_36:
  RtlFreeAnsiString(&v12);
  RtlFreeAnsiString(&v10);
  return v5;
}
