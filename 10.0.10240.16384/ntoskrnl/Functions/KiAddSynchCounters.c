// KiAddSynchCounters 
 
_DWORD *__fastcall KiAddSynchCounters(_DWORD *result, _DWORD *a2)
{
  int v2; // r2
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
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
  int v45; // r3
  int v46; // r2
  int v47; // r3
  int v48; // r2
  int v49; // r3
  int v50; // r2
  int v51; // r3
  int v52; // r2
  int v53; // r3
  int v54; // r2
  int v55; // r3
  int v56; // r2
  int v57; // r3
  int v58; // r2
  int v59; // r3
  int v60; // r2
  int v61; // r3
  int v62; // r2
  int v63; // r3
  int v64; // r2
  int v65; // r3
  int v66; // r2
  int v67; // r3
  int v68; // r2
  int v69; // r3
  int v70; // r2
  int v71; // r3
  int v72; // r2
  int v73; // r3
  int v74; // r2
  int v75; // r3
  int v76; // r2
  int v77; // r3
  int v78; // r2
  int v79; // r3
  int v80; // r2
  int v81; // r3
  int v82; // r2

  v2 = result[1];
  *result += *a2;
  v3 = a2[1] + v2;
  v4 = result[2];
  result[1] = v3;
  v5 = a2[2] + v4;
  v6 = result[3];
  result[2] = v5;
  v7 = a2[3] + v6;
  v8 = result[4];
  result[3] = v7;
  v9 = a2[4] + v8;
  v10 = result[5];
  result[4] = v9;
  v11 = a2[5] + v10;
  v12 = result[6];
  result[5] = v11;
  v13 = a2[6] + v12;
  v14 = result[7];
  result[6] = v13;
  v15 = a2[7] + v14;
  v16 = result[8];
  result[7] = v15;
  v17 = a2[8] + v16;
  v18 = result[9];
  result[8] = v17;
  v19 = a2[9] + v18;
  v20 = result[10];
  result[9] = v19;
  v21 = a2[10] + v20;
  v22 = result[11];
  result[10] = v21;
  v23 = a2[11] + v22;
  v24 = result[12];
  result[11] = v23;
  v25 = a2[12] + v24;
  v26 = result[13];
  result[12] = v25;
  v27 = a2[13] + v26;
  v28 = result[14];
  result[13] = v27;
  v29 = a2[14] + v28;
  v30 = result[15];
  result[14] = v29;
  v31 = a2[15] + v30;
  v32 = result[16];
  result[15] = v31;
  v33 = a2[16] + v32;
  v34 = result[17];
  result[16] = v33;
  v35 = a2[17] + v34;
  v36 = result[18];
  result[17] = v35;
  v37 = a2[18] + v36;
  v38 = result[19];
  result[18] = v37;
  v39 = a2[19] + v38;
  v40 = result[20];
  result[19] = v39;
  v41 = a2[20] + v40;
  v42 = result[21];
  result[20] = v41;
  v43 = a2[21] + v42;
  v44 = result[22];
  result[21] = v43;
  v45 = a2[22] + v44;
  v46 = result[23];
  result[22] = v45;
  v47 = a2[23] + v46;
  v48 = result[24];
  result[23] = v47;
  v49 = a2[24] + v48;
  v50 = result[25];
  result[24] = v49;
  v51 = a2[25] + v50;
  v52 = result[26];
  result[25] = v51;
  v53 = a2[26] + v52;
  v54 = result[27];
  result[26] = v53;
  v55 = a2[27] + v54;
  v56 = result[28];
  result[27] = v55;
  v57 = a2[28] + v56;
  v58 = result[29];
  result[28] = v57;
  v59 = a2[29] + v58;
  v60 = result[30];
  result[29] = v59;
  v61 = a2[30] + v60;
  v62 = result[31];
  result[30] = v61;
  v63 = a2[31] + v62;
  v64 = result[32];
  result[31] = v63;
  v65 = a2[32] + v64;
  v66 = result[33];
  result[32] = v65;
  v67 = a2[33] + v66;
  v68 = result[34];
  result[33] = v67;
  v69 = a2[34] + v68;
  v70 = result[35];
  result[34] = v69;
  v71 = a2[35] + v70;
  v72 = result[36];
  result[35] = v71;
  v73 = a2[36] + v72;
  v74 = result[37];
  result[36] = v73;
  v75 = a2[37] + v74;
  v76 = result[38];
  result[37] = v75;
  v77 = a2[38] + v76;
  v78 = result[39];
  result[38] = v77;
  v79 = a2[39] + v78;
  v80 = result[42];
  result[39] = v79;
  v81 = a2[42] + v80;
  v82 = result[43];
  result[42] = v81;
  result[43] = a2[43] + v82;
  return result;
}
