// PnprLogSuccessEvent 
 
int PnprLogSuccessEvent()
{
  __int64 v0; // r1
  int v1; // r1
  int v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r3
  __int64 v9; // kr00_8
  int v10; // r3
  int v11; // r0
  int v12; // r3
  int *v13; // r2
  int v14; // r3
  int *v15; // r2
  int v16; // r3
  int *v17; // r2
  __int16 v19; // [sp+8h] [bp-168h] BYREF
  int v20; // [sp+Ch] [bp-164h] BYREF
  int v21; // [sp+10h] [bp-160h] BYREF
  int v22; // [sp+14h] [bp-15Ch] BYREF
  int v23; // [sp+18h] [bp-158h] BYREF
  int v24[2]; // [sp+20h] [bp-150h] BYREF
  int v25[82]; // [sp+28h] [bp-148h] BYREF

  v19 = 0;
  v0 = *(_QWORD *)(PnprContext + 652);
  v23 = *(_DWORD *)(PnprContext + 664);
  v22 = v0 - *(_DWORD *)(PnprContext + 648);
  v20 = HIDWORD(v0) - v0;
  v1 = *(_DWORD *)(PnprContext + 16);
  v21 = *(_DWORD *)(PnprContext + 660) - HIDWORD(v0);
  v24[0] = **(_DWORD **)v1;
  v24[1] = 0;
  if ( *(_DWORD *)PnprContext )
    v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)PnprContext + 176) + 20);
  else
    v2 = 0;
  v3 = *(unsigned __int16 *)(v2 + 20);
  v4 = *(_DWORD *)(PnprContext + 20);
  v25[0] = *(_DWORD *)(v2 + 24);
  v25[1] = 0;
  v25[2] = v3;
  v25[3] = 0;
  v25[4] = (int)&v19;
  v25[6] = 2;
  v25[7] = 0;
  v25[8] = (int)v24;
  v25[9] = 0;
  v25[10] = 8;
  v25[11] = 0;
  v25[12] = v1 + 12;
  v25[13] = 0;
  v25[14] = 4;
  v25[15] = 0;
  v25[16] = v4 + 4;
  v25[17] = 0;
  v25[18] = 4;
  v25[19] = 0;
  v25[20] = v4 + 8;
  v25[21] = 0;
  v25[22] = 8;
  v25[23] = 0;
  v5 = *(_DWORD *)(PnprContext + 24);
  v25[5] = 0;
  if ( v5 )
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 176) + 20);
  else
    v6 = 0;
  v7 = *(unsigned __int16 *)(v6 + 20);
  v8 = *(_DWORD *)(v6 + 24);
  v25[28] = (int)&v19;
  v25[29] = 0;
  v9 = *(_QWORD *)(PnprContext + 40);
  v25[24] = v8;
  v25[25] = 0;
  v25[26] = v7;
  v25[27] = 0;
  v25[30] = 2;
  v25[31] = 0;
  v25[32] = v9 + 12;
  v25[33] = 0;
  v25[34] = 4;
  v25[35] = 0;
  v25[36] = HIDWORD(v9) + 4;
  v25[37] = 0;
  v25[38] = 4;
  v25[39] = 0;
  v25[40] = HIDWORD(v9) + 8;
  v25[41] = 0;
  v25[42] = 8;
  v25[43] = 0;
  v25[44] = (int)&v23;
  v25[45] = 0;
  v25[46] = 4;
  v25[47] = 0;
  v25[48] = (int)&v22;
  v25[49] = 0;
  v25[50] = 4;
  v25[51] = 0;
  v25[52] = (int)&v20;
  v25[53] = 0;
  v25[54] = 4;
  v25[55] = 0;
  v25[56] = (int)&v21;
  v25[57] = 0;
  v25[58] = 4;
  v25[59] = 0;
  v10 = *(_DWORD *)(v1 + 12);
  v11 = 15;
  if ( v10 )
  {
    v25[60] = v1 + 16;
    v25[61] = 0;
    v25[62] = 4 * v10;
    v25[63] = 0;
    v11 = 16;
  }
  v12 = *(_DWORD *)(v4 + 4);
  if ( v12 )
  {
    v13 = &v25[4 * v11];
    *v13 = v4 + 16;
    v13[1] = 0;
    v13[2] = 16 * v12;
    v13[3] = 0;
    ++v11;
  }
  v14 = *(_DWORD *)(v9 + 12);
  if ( v14 )
  {
    v15 = &v25[4 * v11];
    *v15 = v9 + 16;
    v15[1] = 0;
    v15[2] = 4 * v14;
    v15[3] = 0;
    ++v11;
  }
  v16 = *(_DWORD *)(HIDWORD(v9) + 4);
  if ( v16 )
  {
    v17 = &v25[4 * v11];
    *v17 = HIDWORD(v9) + 16;
    v17[1] = 0;
    v17[2] = 16 * v16;
    v17[3] = 0;
  }
  return EtwWrite(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)PNP_EVT_DP_REPLACE_SUCCESS, 0);
}
