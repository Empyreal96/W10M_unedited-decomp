// PiCMOpenObjectKey 
 
int __fastcall PiCMOpenObjectKey(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  char v8; // r8
  int v9; // r5
  int v10; // r7
  int v11; // r4
  int v12; // r1
  int v14; // [sp+10h] [bp-48h] BYREF
  int v15; // [sp+14h] [bp-44h] BYREF
  char v16[4]; // [sp+18h] [bp-40h] BYREF
  int v17; // [sp+1Ch] [bp-3Ch]
  int v18; // [sp+20h] [bp-38h]
  int v19; // [sp+24h] [bp-34h]
  int v20; // [sp+2Ch] [bp-2Ch]
  int v21; // [sp+30h] [bp-28h]
  int v22; // [sp+34h] [bp-24h]
  int v23; // [sp+38h] [bp-20h]

  *a6 = 0;
  v14 = 0;
  v15 = 0;
  v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = PiCMCaptureRegistryInputData(a1, a2, a3, (int)v16);
  if ( v9 < 0 )
    goto LABEL_36;
  v10 = v19;
  if ( !v19 || v17 || v22 || !a3 || a4 < 0x10 || (v18 & 0x7FFF0000) != 0 )
    goto LABEL_30;
  if ( (v18 & 0x80000000) == 0x80000000 )
  {
    v11 = (unsigned __int16)v18;
    if ( (unsigned __int16)v18 >= 0xBu )
      v11 = 0;
  }
  else
  {
    if ( (unsigned __int16)v18 != 1 )
    {
      switch ( (unsigned __int16)v18 )
      {
        case 2u:
          v11 = 2;
          goto LABEL_24;
        case 3u:
          v11 = 4;
          goto LABEL_24;
        case 4u:
          v11 = 3;
LABEL_23:
          v9 = -1073741637;
          goto LABEL_24;
      }
LABEL_30:
      v9 = -1073741811;
      goto LABEL_31;
    }
    v11 = 1;
  }
  if ( !v11 )
    goto LABEL_30;
  if ( v11 == 1 || v11 == 3 || v11 == 5 )
    goto LABEL_23;
LABEL_24:
  if ( v9 >= 0 )
  {
    v9 = PnpOpenObjectRegKey(PiPnpRtlCtx, v19, v11, v20, 0, (int)&v14, 0, 0);
    if ( v9 != -1073741772 )
      goto LABEL_28;
    if ( v21 == 1 )
    {
      v9 = PnpCreateObject(PiPnpRtlCtx, v10, v11, v20, &v14);
LABEL_28:
      if ( v9 >= 0 )
        v9 = PiCMDuplicateRegistryHandle(v14, v12, v20, v8, (int)&v15);
      goto LABEL_31;
    }
  }
LABEL_31:
  v9 = PiCMReturnHandleResultData(v9, v15, v23, a3, a4, a6);
  if ( v14 )
    ZwClose();
  if ( v9 < 0 && v15 )
    ObCloseHandle(v15);
LABEL_36:
  PiCMReleaseObjectInputData((int)v16);
  return v9;
}
