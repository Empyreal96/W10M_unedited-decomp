// PiCMCreateObject 
 
int __fastcall PiCMCreateObject(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r2
  char v14[4]; // [sp+10h] [bp-30h] BYREF
  int v15; // [sp+14h] [bp-2Ch]
  int v16; // [sp+18h] [bp-28h]
  int v17; // [sp+1Ch] [bp-24h]
  int v18; // [sp+24h] [bp-1Ch]
  int v19; // [sp+28h] [bp-18h]

  *a6 = 0;
  v11 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v14);
  if ( v11 >= 0 )
  {
    if ( !PiAuDoesClientHaveAccess(2, v8, v9, v10) )
    {
      v11 = -1073741790;
LABEL_29:
      v11 = PiCMReturnBasicResultData(v11, v19, a3, a4, a6);
      goto LABEL_30;
    }
    if ( !v17 || v15 || v18 || !a3 || a4 < 8 || (v16 & 0x7FFF0000) != 0 )
      goto LABEL_28;
    if ( (v16 & 0x80000000) == 0x80000000 )
    {
      v12 = (unsigned __int16)v16;
      if ( (unsigned __int16)v16 >= 0xBu )
        v12 = 0;
    }
    else
    {
      if ( (unsigned __int16)v16 != 1 )
      {
        switch ( (unsigned __int16)v16 )
        {
          case 2u:
            v12 = 2;
            goto LABEL_26;
          case 3u:
            v12 = 4;
            goto LABEL_26;
          case 4u:
            v12 = 3;
            goto LABEL_25;
        }
LABEL_28:
        v11 = -1073741811;
        goto LABEL_29;
      }
      v12 = 1;
    }
    if ( v12 )
    {
      if ( v12 != 1 && v12 != 3 && v12 != 5 )
      {
LABEL_26:
        if ( v11 >= 0 )
          v11 = PnpCreateObject(PiPnpRtlCtx, v17, v12, 0, 0);
        goto LABEL_29;
      }
LABEL_25:
      v11 = -1073741637;
      goto LABEL_26;
    }
    goto LABEL_28;
  }
LABEL_30:
  PiCMReleaseObjectInputData((int)v14);
  return v11;
}
