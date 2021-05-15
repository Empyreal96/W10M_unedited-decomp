// PnprLogFailureEvent 
 
int PnprLogFailureEvent(int a1, int a2, ...)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r3
  int v7; // r3
  __int16 v9; // [sp+8h] [bp-88h] BYREF
  int v10; // [sp+Ch] [bp-84h] BYREF
  int var80[33]; // [sp+10h] [bp-80h] BYREF
  va_list varg_r2; // [sp+A0h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  v9 = 0;
  if ( a1 )
    v2 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v2 = 0;
  v3 = *(unsigned __int16 *)(v2 + 20);
  var80[2] = *(_DWORD *)(v2 + 24);
  var80[3] = 0;
  var80[4] = v3;
  var80[5] = 0;
  var80[6] = (int)&v9;
  var80[7] = 0;
  var80[8] = 2;
  var80[9] = 0;
  if ( a2 )
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  else
    v4 = 0;
  v5 = *(unsigned __int16 *)(v4 + 20);
  v6 = *(_DWORD *)(v4 + 24);
  var80[14] = (int)&v9;
  var80[15] = 0;
  var80[12] = v5;
  var80[10] = v6;
  var80[11] = 0;
  var80[13] = 0;
  var80[16] = 2;
  var80[17] = 0;
  if ( PnprContext )
  {
    v10 = *(_DWORD *)(PnprContext + 608);
    v7 = *(_DWORD *)(PnprContext + 612);
  }
  else
  {
    v10 = 0;
    v7 = 1;
  }
  var80[0] = v7;
  va_copy((va_list)&var80[18], varg_r2);
  var80[19] = 0;
  var80[20] = 4;
  var80[21] = 0;
  var80[22] = (int)&v10;
  var80[23] = 0;
  var80[24] = 4;
  var80[25] = 0;
  var80[26] = (int)var80;
  var80[27] = 0;
  var80[28] = 4;
  var80[29] = 0;
  return EtwWrite(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)PNP_EVT_DP_REPLACE_FAILURE, 0);
}
