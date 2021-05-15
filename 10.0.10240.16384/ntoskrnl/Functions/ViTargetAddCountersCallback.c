// ViTargetAddCountersCallback 
 
int __fastcall ViTargetAddCountersCallback(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r0
  int v4; // r2
  int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r3
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r2
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r2
  int v31; // r3
  int v32; // r2
  int v33; // r3
  int v34; // r2
  int v35; // r3
  int v36; // r2
  int v37; // r3
  int v38; // r2
  int v39; // r3
  int v40; // r2
  int v41; // r3
  int v42; // r2
  int v43; // r3
  int v44; // r2
  int v45; // r2
  int v46; // r2
  int v47; // r2
  int v48; // r2
  int v49; // r2

  v2 = *(_DWORD **)(a1 + 24);
  if ( v2 )
  {
    if ( *v2 == *a2 )
    {
      v3 = (_DWORD *)a2[1];
      v4 = v2[10];
      __dmb(0xBu);
      v3[18] += v4;
      v5 = v2[11];
      __dmb(0xBu);
      v6 = v3[19] + v5;
      v7 = v3[20];
      v3[19] = v6;
      v8 = v2[12] + v7;
      v9 = v3[21];
      v3[20] = v8;
      v3[21] = v2[13] + v9;
      v10 = v2[14];
      __dmb(0xBu);
      v3[22] += v10;
      v11 = v2[15];
      __dmb(0xBu);
      v12 = v3[23] + v11;
      v13 = v3[24];
      v3[23] = v12;
      v14 = v2[16] + v13;
      v15 = v3[25];
      v3[24] = v14;
      v3[25] = v2[17] + v15;
      if ( a2[2] )
      {
        v16 = v3[27];
        v3[26] += v2[18];
        v17 = v2[19] + v16;
        v18 = v3[28];
        v3[27] = v17;
        v19 = v2[20] + v18;
        v20 = v3[29];
        v3[28] = v19;
        v21 = v2[21] + v20;
        v22 = v3[30];
        v3[29] = v21;
        v23 = v2[22] + v22;
        v24 = v3[31];
        v3[30] = v23;
        v25 = v2[23] + v24;
        v26 = v3[32];
        v3[31] = v25;
        v27 = v2[24] + v26;
        v28 = v3[33];
        v3[32] = v27;
        v29 = v2[25] + v28;
        v30 = v3[34];
        v3[33] = v29;
        v31 = v2[26] + v30;
        v32 = v3[35];
        v3[34] = v31;
        v33 = v2[27] + v32;
        v34 = v3[36];
        v3[35] = v33;
        v35 = v2[28] + v34;
        v36 = v3[37];
        v3[36] = v35;
        v37 = v2[29] + v36;
        v38 = v3[38];
        v3[37] = v37;
        v39 = v2[30] + v38;
        v40 = v3[39];
        v3[38] = v39;
        v41 = v2[31] + v40;
        v42 = v3[40];
        v3[39] = v41;
        v43 = v2[32] + v42;
        v44 = v3[41];
        v3[40] = v43;
        v3[41] = v2[33] + v44;
        v45 = v2[36];
        __dmb(0xBu);
        v3[42] += v45;
        v46 = v2[37];
        __dmb(0xBu);
        v3[43] += v46;
        v47 = v2[38];
        __dmb(0xBu);
        v3[44] += v47;
        v48 = v2[39];
        __dmb(0xBu);
        v3[45] += v48;
        v49 = v2[40];
        __dmb(0xBu);
        v3[46] += v49;
      }
    }
  }
  return 1;
}
