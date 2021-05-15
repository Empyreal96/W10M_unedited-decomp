// -SmStEtwFillStoreEvent@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@PAU_SMKM_EVENT_DESCRIPTOR@@@Z 
 
_DWORD *__fastcall SMKM_STORE<SM_TRAITS>::SmStEtwFillStoreEvent(int a1, int *a2)
{
  int *v3; // r4
  int v4; // r2
  int v5; // r3
  int **v7; // r3
  int v8; // r2
  int v9; // r3
  int *v10; // r1
  int **v11; // r3
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r1
  _DWORD *v15; // r3
  int v16; // r2
  int v17; // r3
  _DWORD *v18; // r1
  _DWORD *v19; // r3
  int v20; // r2
  int v21; // r3
  _DWORD *v22; // r0
  _DWORD *v23; // r1
  _DWORD *v24; // r3
  int v25; // r1
  _DWORD *v26; // r1
  _DWORD *v27; // r3
  int v28; // r2
  int v29; // r3
  _DWORD *v30; // r1
  _DWORD *v31; // r3
  int v32; // r2
  int v33; // r3
  _DWORD *v34; // r1
  _DWORD *v35; // r3
  int v36; // r2
  _DWORD *v37; // r1
  _DWORD *v38; // r3
  int v39; // r2
  _WORD *v40; // r1
  _DWORD *v41; // r3
  int v42; // r2
  int v43; // r3
  _WORD *v44; // r1
  _DWORD *v45; // r3
  int v46; // r2
  int v47; // r3
  _DWORD *v48; // r1
  _DWORD *v49; // r3
  int v50; // r4
  _DWORD *v51; // r1
  _DWORD *v52; // r3
  int v53; // r2
  int v54; // r3
  _DWORD *v55; // r1
  _DWORD *v56; // r3
  int v57; // r2
  _DWORD *v58; // r1
  _DWORD *v59; // r3
  int v60; // r2
  int v61; // r3
  _DWORD *v62; // r1
  _DWORD *v63; // r3
  int v64; // r2
  int v65; // r3
  _DWORD *v66; // r1
  _DWORD *v67; // r3
  int v68; // r2
  int v69; // r3
  _DWORD *v70; // r1
  _DWORD *v71; // r3
  int v72; // r2
  int v73; // r3
  _DWORD *result; // r0
  _DWORD *v75; // r1
  _DWORD *v76; // r3
  int v77; // [sp+8h] [bp-48h] BYREF
  int v78[2]; // [sp+Ch] [bp-44h] BYREF
  int v79; // [sp+14h] [bp-3Ch] BYREF
  int v80[2]; // [sp+18h] [bp-38h] BYREF
  int v81; // [sp+20h] [bp-30h]
  int v82; // [sp+24h] [bp-2Ch]
  int v83; // [sp+28h] [bp-28h]
  int v84; // [sp+2Ch] [bp-24h]

  v3 = (int *)(a2[4] + a2[1]);
  *v3 = a1;
  v4 = a2[2];
  v5 = *a2;
  v80[1] = a1;
  v7 = (int **)(v5 + 16 * v4);
  *v7 = v3;
  v7[1] = 0;
  v7[2] = (int *)4;
  v7[3] = 0;
  ++a2[2];
  v8 = a2[4] + 4;
  a2[4] = v8;
  if ( *(_BYTE *)(a1 + 3516) == 1 )
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 3664) + 12);
  else
    v9 = 0;
  v78[1] = v9;
  v10 = (int *)(v8 + a2[1]);
  *v10 = v9;
  v11 = (int **)(*a2 + 16 * a2[2]);
  *v11 = v10;
  v11[1] = 0;
  v11[2] = (int *)4;
  v11[3] = 0;
  ++a2[2];
  v12 = a2[4] + 4;
  v13 = a2[1];
  a2[4] = v12;
  v14 = (_DWORD *)(v12 + v13);
  *v14 = a1 + 56;
  v15 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v15 = v14;
  v15[1] = 0;
  v15[2] = 4;
  v15[3] = 0;
  ++a2[2];
  v16 = a2[4] + 4;
  v17 = a2[1];
  a2[4] = v16;
  v18 = (_DWORD *)(v16 + v17);
  *v18 = a1 + 824;
  v19 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v19 = v18;
  v19[1] = 0;
  v19[2] = 4;
  v19[3] = 0;
  ++a2[2];
  v20 = a2[4] + 4;
  v21 = a2[1];
  a2[4] = v20;
  v22 = (_DWORD *)(a1 + 3652);
  v23 = (_DWORD *)(v20 + v21);
  if ( a1 != -3652 )
    *v23 = *v22;
  v24 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v24 = v23;
  v24[1] = 0;
  v24[2] = 4;
  v24[3] = 0;
  ++a2[2];
  v25 = a2[4] + 4;
  a2[4] = v25;
  v81 = *(_DWORD *)(a1 + 184) + *(_DWORD *)(a1 + 952);
  v26 = (_DWORD *)(v25 + a2[1]);
  *v26 = v81;
  v27 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v27 = v26;
  v27[1] = 0;
  v27[2] = 4;
  v27[3] = 0;
  ++a2[2];
  v28 = a2[4] + 4;
  v82 = 4096;
  v29 = a2[1];
  a2[4] = v28;
  v30 = (_DWORD *)(v28 + v29);
  *v30 = v82;
  v31 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v31 = v30;
  v31[1] = 0;
  v31[2] = 4;
  v31[3] = 0;
  ++a2[2];
  v32 = a2[4] + 4;
  v33 = a2[1];
  a2[4] = v32;
  v34 = (_DWORD *)(v32 + v33);
  if ( a1 != -16 )
    *v34 = *(_DWORD *)(a1 + 16);
  v35 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v35 = v34;
  v35[1] = 0;
  v35[2] = 4;
  v35[3] = 0;
  ++a2[2];
  v36 = a2[4] + 4;
  a2[4] = v36;
  v83 = 8 * *(_DWORD *)(a1 + 1684);
  v37 = (_DWORD *)(v36 + a2[1]);
  *v37 = v83;
  v38 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v38 = v37;
  v38[1] = 0;
  v38[2] = 4;
  v38[3] = 0;
  ++a2[2];
  v39 = a2[4] + 4;
  a2[4] = v39;
  v40 = (_WORD *)(v39 + a2[1]);
  *v40 = *(unsigned __int8 *)(a1 + 3516);
  v41 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v41 = v40;
  v41[1] = 0;
  v41[2] = 2;
  v41[3] = 0;
  ++a2[2];
  v42 = a2[4] + 2;
  v43 = a2[1];
  a2[4] = v42;
  v44 = (_WORD *)(v42 + v43);
  if ( a1 != -3512 )
    *v44 = *(_WORD *)(a1 + 3512);
  v45 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v45 = v44;
  v45[1] = 0;
  v45[2] = 2;
  v45[3] = 0;
  ++a2[2];
  v46 = a2[4] + 2;
  v47 = a2[1];
  a2[4] = v46;
  v48 = (_DWORD *)(v46 + v47);
  if ( a1 != -60 )
    *v48 = *(_DWORD *)(a1 + 60);
  v49 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v49 = v48;
  v49[1] = 0;
  v49[2] = 4;
  v49[3] = 0;
  ++a2[2];
  v50 = a2[4] + 4;
  a2[4] = v50;
  ST_STORE<SM_TRAITS>::StDmGetSpaceStats(a1 + 56, &v77, v78);
  ST_STORE<SM_TRAITS>::StDmGetSpaceStats(a1 + 824, &v79, v80);
  v77 += v79;
  v78[0] += v80[0];
  v51 = (_DWORD *)(v50 + a2[1]);
  *v51 = v77;
  v52 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v52 = v51;
  v52[1] = 0;
  v52[2] = 4;
  v52[3] = 0;
  ++a2[2];
  v53 = a2[4] + 4;
  v54 = a2[1];
  a2[4] = v53;
  v55 = (_DWORD *)(v53 + v54);
  *v55 = v78[0];
  v56 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v56 = v55;
  v56[1] = 0;
  v56[2] = 4;
  v56[3] = 0;
  ++a2[2];
  v57 = a2[4] + 4;
  a2[4] = v57;
  v84 = *(_DWORD *)(a1 + 128);
  v58 = (_DWORD *)(v57 + a2[1]);
  *v58 = v84;
  v59 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v59 = v58;
  v59[1] = 0;
  v59[2] = 4;
  v59[3] = 0;
  ++a2[2];
  v60 = a2[4] + 4;
  v61 = a2[1];
  a2[4] = v60;
  v62 = (_DWORD *)(v60 + v61);
  if ( a1 != -952 )
    *v62 = *(_DWORD *)(a1 + 952);
  v63 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v63 = v62;
  v63[1] = 0;
  v63[2] = 4;
  v63[3] = 0;
  ++a2[2];
  v64 = a2[4] + 4;
  v65 = a2[1];
  a2[4] = v64;
  v66 = (_DWORD *)(v64 + v65);
  *v66 = v79;
  v67 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v67 = v66;
  v67[1] = 0;
  v67[2] = 4;
  v67[3] = 0;
  ++a2[2];
  v68 = a2[4] + 4;
  v69 = a2[1];
  a2[4] = v68;
  v70 = (_DWORD *)(v68 + v69);
  *v70 = v80[0];
  v71 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v71 = v70;
  v71[1] = 0;
  v71[2] = 4;
  v71[3] = 0;
  ++a2[2];
  v72 = a2[4] + 4;
  v73 = a2[1];
  a2[4] = v72;
  result = (_DWORD *)(a1 + 372);
  v75 = (_DWORD *)(v72 + v73);
  if ( a1 != -372 )
    *v75 = *result;
  v76 = (_DWORD *)(*a2 + 16 * a2[2]);
  *v76 = v75;
  v76[1] = 0;
  v76[2] = 4;
  v76[3] = 0;
  ++a2[2];
  a2[4] += 4;
  return result;
}
