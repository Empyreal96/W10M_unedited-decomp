// PiCMOpenClassKey 
 
int __fastcall PiCMOpenClassKey(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r8
  int v9; // r5
  unsigned __int16 *v11; // r6
  int v12; // r4
  int v13; // r2
  int v14; // r5
  int v15; // r1
  int v16; // r0
  int v17; // [sp+10h] [bp-50h] BYREF
  int v18; // [sp+14h] [bp-4Ch] BYREF
  char v19[8]; // [sp+18h] [bp-48h] BYREF
  char v20[4]; // [sp+20h] [bp-40h] BYREF
  int v21; // [sp+24h] [bp-3Ch]
  int v22; // [sp+28h] [bp-38h]
  unsigned __int16 *v23; // [sp+2Ch] [bp-34h]
  int v24; // [sp+34h] [bp-2Ch]
  int v25; // [sp+38h] [bp-28h]
  int v26; // [sp+3Ch] [bp-24h]
  int v27; // [sp+40h] [bp-20h]

  *a6 = 0;
  v17 = 0;
  v18 = 0;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = PiCMCaptureRegistryInputData(a1, a2, a3, v20);
  if ( v9 >= 0 )
  {
    if ( v21 || v26 || !a3 || a4 < 0x10 )
    {
      v12 = -1073741811;
    }
    else
    {
      if ( v22 != 2 )
        return sub_7E79F0();
      v11 = v23;
      if ( !v23 )
      {
        v14 = v24;
        v16 = PnpCtxOpenContextBaseKey(PiPnpRtlCtx, 7);
        goto LABEL_23;
      }
      v12 = RtlInitUnicodeStringEx((int)v19, v23);
      if ( v12 >= 0 )
      {
        v12 = RtlUpcaseUnicodeString(v19, v19, 0);
        if ( v12 >= 0 )
        {
          v14 = v24;
          v12 = CmOpenInstallerClassRegKey((int *)PiPnpRtlCtx, v11, v13, (int)&v17, v24, 0, (int)&v17, 0);
          if ( v12 != -1073741772 )
            goto LABEL_12;
          if ( v25 == 1 )
          {
            v16 = CmCreateInstallerClass(PiPnpRtlCtx, v11, v14, &v17, 0, 0);
LABEL_23:
            v12 = v16;
LABEL_12:
            if ( v12 >= 0 )
              v12 = PiCMDuplicateRegistryHandle(v17, v15, v14, v8, &v18);
            goto LABEL_14;
          }
        }
      }
    }
LABEL_14:
    v9 = PiCMReturnHandleResultData(v12, v18, v27, a3, a4, a6);
    if ( v17 )
      ZwClose();
    if ( v9 < 0 || v12 < 0 )
    {
      if ( v18 )
        ObCloseHandle(v18);
    }
  }
  PiCMReleaseObjectInputData(v20);
  return v9;
}
