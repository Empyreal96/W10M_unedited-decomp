// PiCMDeleteObject 
 
int __fastcall PiCMDeleteObject(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r6
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r5
  int v13; // r1
  int v14; // r7
  int v15; // r3
  int v16; // r4
  int v18; // [sp+8h] [bp-40h] BYREF
  char v19[4]; // [sp+10h] [bp-38h] BYREF
  int v20; // [sp+14h] [bp-34h]
  int v21; // [sp+18h] [bp-30h]
  int v22; // [sp+1Ch] [bp-2Ch]
  int v23; // [sp+24h] [bp-24h]
  int v24; // [sp+28h] [bp-20h]

  *a6 = 0;
  v7 = 0;
  v18 = 0;
  v12 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v19);
  if ( v12 >= 0 )
  {
    if ( !PiAuDoesClientHaveAccess(2, v9, v10, v11) )
    {
      v12 = -1073741790;
LABEL_31:
      v12 = PiCMReturnBasicResultData(v12, v24, a3, a4, a6);
      goto LABEL_32;
    }
    v14 = v22;
    if ( !v22 || v20 || v23 || !a3 || a4 < 8 || (v21 & 0x7FFF0000) != 0 )
      goto LABEL_30;
    v15 = v21 & 0x80000000;
    if ( (v21 & 0x80000000) == 0x80000000 )
    {
      v16 = (unsigned __int16)v21;
      if ( (unsigned __int16)v21 >= 0xBu )
        v16 = 0;
    }
    else
    {
      v15 = (unsigned __int16)v21;
      if ( (unsigned __int16)v21 != 1 )
      {
        switch ( (unsigned __int16)v21 )
        {
          case 2u:
            v16 = 2;
            goto LABEL_26;
          case 3u:
            v16 = 4;
            goto LABEL_26;
          case 4u:
            v16 = 3;
            goto LABEL_25;
        }
LABEL_30:
        v12 = -1073741811;
        goto LABEL_31;
      }
      v16 = 1;
    }
    if ( v16 )
    {
      if ( v16 != 1 && v16 != 3 && v16 != 5 )
      {
LABEL_26:
        if ( v12 >= 0 )
        {
          v12 = PiPnpRtlBeginOperation(&v18, v13, v21, v15);
          if ( v12 >= 0 )
            v12 = PnpDeleteObject(PiPnpRtlCtx, v14, v16);
          v7 = v18;
        }
        goto LABEL_31;
      }
LABEL_25:
      v12 = -1073741637;
      goto LABEL_26;
    }
    goto LABEL_30;
  }
LABEL_32:
  PiCMReleaseObjectInputData((int)v19);
  if ( v7 )
    PiPnpRtlEndOperation(v7);
  return v12;
}
