// PnprLogStartEvent 
 
int __fastcall PnprLogStartEvent(int a1, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r3
  __int16 v8[4]; // [sp+8h] [bp-50h] BYREF
  int v9; // [sp+10h] [bp-48h]
  int v10; // [sp+14h] [bp-44h]
  int v11; // [sp+18h] [bp-40h]
  int v12; // [sp+1Ch] [bp-3Ch]
  __int16 *v13; // [sp+20h] [bp-38h]
  int v14; // [sp+24h] [bp-34h]
  int v15; // [sp+28h] [bp-30h]
  int v16; // [sp+2Ch] [bp-2Ch]
  int v17; // [sp+30h] [bp-28h]
  int v18; // [sp+34h] [bp-24h]
  int v19; // [sp+38h] [bp-20h]
  int v20; // [sp+3Ch] [bp-1Ch]
  __int16 *v21; // [sp+40h] [bp-18h]
  int v22; // [sp+44h] [bp-14h]
  int v23; // [sp+48h] [bp-10h]
  int v24; // [sp+4Ch] [bp-Ch]

  v8[0] = 0;
  if ( a1 )
    v2 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v2 = 0;
  v3 = *(unsigned __int16 *)(v2 + 20);
  v9 = *(_DWORD *)(v2 + 24);
  v10 = 0;
  v11 = v3;
  v12 = 0;
  v13 = v8;
  v14 = 0;
  v15 = 2;
  v16 = 0;
  if ( a2 )
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  else
    v4 = 0;
  v5 = *(unsigned __int16 *)(v4 + 20);
  v6 = *(_DWORD *)(v4 + 24);
  v21 = v8;
  v22 = 0;
  v17 = v6;
  v18 = 0;
  v19 = v5;
  v20 = 0;
  v23 = 2;
  v24 = 0;
  return EtwWrite(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)PNP_EVT_DP_REPLACE_START, 0);
}
