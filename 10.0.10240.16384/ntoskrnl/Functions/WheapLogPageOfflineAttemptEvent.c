// WheapLogPageOfflineAttemptEvent 
 
int __fastcall WheapLogPageOfflineAttemptEvent(int a1, int a2, int a3, int a4, char a5, char a6)
{
  bool v7; // [sp+8h] [bp-60h] BYREF
  bool v8; // [sp+9h] [bp-5Fh] BYREF
  bool v9; // [sp+Ah] [bp-5Eh] BYREF
  bool v10; // [sp+Bh] [bp-5Dh] BYREF
  int *v11; // [sp+10h] [bp-58h]
  int v12; // [sp+14h] [bp-54h]
  int v13; // [sp+18h] [bp-50h]
  int v14; // [sp+1Ch] [bp-4Ch]
  bool *v15; // [sp+20h] [bp-48h]
  int v16; // [sp+24h] [bp-44h]
  int v17; // [sp+28h] [bp-40h]
  int v18; // [sp+2Ch] [bp-3Ch]
  bool *v19; // [sp+30h] [bp-38h]
  int v20; // [sp+34h] [bp-34h]
  int v21; // [sp+38h] [bp-30h]
  int v22; // [sp+3Ch] [bp-2Ch]
  bool *v23; // [sp+40h] [bp-28h]
  int v24; // [sp+44h] [bp-24h]
  int v25; // [sp+48h] [bp-20h]
  int v26; // [sp+4Ch] [bp-1Ch]
  bool *v27; // [sp+50h] [bp-18h]
  int v28; // [sp+54h] [bp-14h]
  int v29; // [sp+58h] [bp-10h]
  int v30; // [sp+5Ch] [bp-Ch]
  int varg_r0[4]; // [sp+70h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  v8 = a3 != 0;
  v10 = a6 != 0;
  v7 = a4 != 0;
  v9 = a5 != 0;
  v11 = varg_r0;
  v12 = 0;
  v13 = 8;
  v14 = 0;
  v15 = &v8;
  v16 = 0;
  v17 = 1;
  v18 = 0;
  v19 = &v10;
  v20 = 0;
  v21 = 1;
  v22 = 0;
  v23 = &v7;
  v24 = 0;
  v25 = 1;
  v26 = 0;
  v27 = &v9;
  v28 = 0;
  v29 = 1;
  v30 = 0;
  return EtwWrite(WheapEtwHandle, unk_6197CC, (int)EVENT_WHEA_MEMORY_OFFLINE, 0);
}
