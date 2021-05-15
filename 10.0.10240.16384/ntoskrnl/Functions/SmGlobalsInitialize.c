// SmGlobalsInitialize 
 
int __fastcall SmGlobalsInitialize(_BYTE *a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int result; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10[2]; // [sp+0h] [bp-40h] BYREF
  int v11; // [sp+8h] [bp-38h]
  int v12; // [sp+Ch] [bp-34h]
  int v13; // [sp+10h] [bp-30h]
  int v14; // [sp+14h] [bp-2Ch]
  int v15; // [sp+18h] [bp-28h]
  int v16; // [sp+1Ch] [bp-24h]
  int v17; // [sp+20h] [bp-20h]
  int v18; // [sp+24h] [bp-1Ch]

  v11 = 400;
  v12 = 800;
  v13 = 1200;
  v14 = 1600;
  v15 = 2048;
  v16 = 3072;
  v17 = 4096;
  v18 = -1;
  v1 = (int)a1;
  memset(a1, 0, 6936);
  v10[0] = 27;
  v10[1] = (int)SmpStoreMgrCallback;
  SMKM_STORE_MGR<SM_TRAITS>::SmInitialize(v1, v10);
  *(_DWORD *)(v1 + 5936) = 0;
  SmKmGlobals = PsInitialSystemProcess;
  memset((_BYTE *)(v1 + 5956), 0, 24);
  *(_DWORD *)(v1 + 5956) = 0;
  *(_DWORD *)(v1 + 5960) = 0;
  *(_DWORD *)(v1 + 5964) = 0;
  *(_DWORD *)(v1 + 5968) = 0;
  *(_DWORD *)(v1 + 5980) = -1;
  *(_DWORD *)(v1 + 5984) = 0;
  *(_DWORD *)(v1 + 5940) = 5;
  SmcCacheManagerInitialize(v1 + 5988);
  SmRegistrationCtxInitialize((_DWORD *)(v1 + 6268));
  v2 = v1 + 6272;
  *(_DWORD *)(v1 + 6272) = 0;
  *(_DWORD *)(v1 + 6276) = 0;
  *(_DWORD *)(v1 + 6280) = 0;
  *(_DWORD *)(v1 + 6272) = 0;
  memset((_BYTE *)(v1 + 6284), 0, 64);
  *(_BYTE *)(v1 + 6288) = 1;
  *(_BYTE *)(v1 + 6290) = 4;
  *(_BYTE *)(v1 + 6289) = 0;
  *(_DWORD *)(v1 + 6292) = 0;
  *(_DWORD *)(v1 + 6296) = v1 + 6296;
  *(_DWORD *)(v1 + 6300) = v1 + 6296;
  memset((_BYTE *)(v1 + 6348), 0, 64);
  *(_BYTE *)(v1 + 6352) = 1;
  *(_BYTE *)(v1 + 6353) = 0;
  *(_BYTE *)(v1 + 6354) = 4;
  *(_DWORD *)(v1 + 6356) = 0;
  *(_DWORD *)(v1 + 6360) = v1 + 6360;
  *(_DWORD *)(v1 + 6364) = v1 + 6360;
  v1 += 6440;
  v3 = v12;
  v4 = v13;
  v5 = v14;
  *(_DWORD *)v1 = v11;
  *(_DWORD *)(v1 + 4) = v3;
  *(_DWORD *)(v1 + 8) = v4;
  *(_DWORD *)(v1 + 12) = v5;
  v1 += 16;
  result = v15;
  v7 = v16;
  v8 = v17;
  v9 = v18;
  *(_DWORD *)v1 = v15;
  *(_DWORD *)(v1 + 4) = v7;
  *(_DWORD *)(v1 + 8) = v8;
  *(_DWORD *)(v1 + 12) = v9;
  *(_DWORD *)(v2 + 584) = 0;
  return result;
}
