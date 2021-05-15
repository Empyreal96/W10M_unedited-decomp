// CmpReportAuditVirtualizationEvent 
 
int __fastcall CmpReportAuditVirtualizationEvent(int a1)
{
  unsigned __int16 *v2; // r6
  unsigned __int16 *v3; // r5
  int v4; // r1
  int v5; // r2
  int v6; // r2
  int v7; // r4
  int v8; // r8
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r8
  int v13; // r0
  unsigned __int16 *v14; // r9
  unsigned __int16 *v15; // r7
  int v16; // r2
  _DWORD v18[2]; // [sp+8h] [bp-2F0h] BYREF
  unsigned __int16 *v19; // [sp+10h] [bp-2E8h]
  int v20[2]; // [sp+18h] [bp-2E0h] BYREF
  int v21; // [sp+20h] [bp-2D8h]
  int v22; // [sp+24h] [bp-2D4h]
  int v23[2]; // [sp+28h] [bp-2D0h] BYREF
  _DWORD v24[2]; // [sp+30h] [bp-2C8h] BYREF
  unsigned __int16 v25[4]; // [sp+38h] [bp-2C0h] BYREF
  int v26[2]; // [sp+40h] [bp-2B8h] BYREF
  int v27; // [sp+48h] [bp-2B0h]
  __int16 v28; // [sp+52h] [bp-2A6h]

  v2 = 0;
  v3 = 0;
  v19 = 0;
  v20[0] = 0;
  v20[1] = 0;
  v21 = 0;
  v22 = 0;
  RtlInitUnicodeString((unsigned int)v25, L"Security");
  v26[1] = 5039;
  v26[0] = 3;
  v28 = 8;
  v27 = 0;
  SeCaptureSubjectContext(v20, v4, v5, 0);
  v6 = v20[0];
  if ( !v20[0] )
    v6 = v21;
  v23[0] = *(_DWORD *)(v6 + 24);
  v23[1] = *(_DWORD *)(v6 + 28);
  v7 = SeSetAuditParameter((int)v26, 5, 0, (unsigned __int16 *)v23);
  v8 = ++v27;
  if ( v7 >= 0 )
  {
    if ( CmpVEEnabled && (*(_WORD *)(a1 + 106) & 0x100) != 0 )
    {
      v3 = (unsigned __int16 *)CmpConstructName(a1);
      if ( !v3 )
      {
LABEL_7:
        v7 = -1073741670;
        goto LABEL_22;
      }
      v7 = CmVirtualKCBToRealPath(a1, (int)v18, v9, v10);
      if ( v7 >= 0 )
      {
        v2 = (unsigned __int16 *)v18;
LABEL_13:
        v7 = SeSetAuditParameter((int)v26, 1, v8, v2);
        v11 = ++v27;
        if ( v7 >= 0 )
        {
          v7 = SeSetAuditParameter((int)v26, 1, v11, v3);
          v12 = ++v27;
          if ( v7 >= 0 )
          {
            v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
            v14 = *(unsigned __int16 **)(v13 + 176);
            v7 = SeLocateProcessImageName(v13);
            v15 = v19;
            if ( v7 >= 0 )
            {
              v7 = SeSetAuditParameter((int)v26, 11, v12, v14);
              v16 = ++v27;
              if ( v7 >= 0 )
              {
                v7 = SeSetAuditParameter((int)v26, 2, v16, v15);
                ++v27;
                if ( v7 >= 0 )
                {
                  v7 = SeReportSecurityEventWithSubCategory(0, v25, 0, (int)v26, 117);
                  if ( v7 >= 0 )
                    v7 = 0;
                }
              }
            }
            if ( v15 )
              ExFreePoolWithTag((unsigned int)v15);
          }
        }
        goto LABEL_22;
      }
    }
    else
    {
      v2 = (unsigned __int16 *)CmpConstructName(a1);
      if ( !v2 )
        goto LABEL_7;
      RtlInitUnicodeString((unsigned int)v24, 0);
      v7 = CmRealKCBToVirtualPath(a1, v24, (int)v18);
      if ( v7 >= 0 )
      {
        v3 = (unsigned __int16 *)v18;
        goto LABEL_13;
      }
    }
  }
LABEL_22:
  if ( v2 == (unsigned __int16 *)v18 )
  {
    RtlFreeAnsiString(v18);
  }
  else if ( v2 )
  {
    ExFreePoolWithTag((unsigned int)v2);
  }
  if ( v3 == (unsigned __int16 *)v18 )
  {
    RtlFreeAnsiString(v18);
  }
  else if ( v3 )
  {
    ExFreePoolWithTag((unsigned int)v3);
  }
  SeReleaseSubjectContext((int)v20);
  return v7;
}
