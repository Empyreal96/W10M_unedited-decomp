// SeAuditBootConfiguration 
 
int __fastcall SeAuditBootConfiguration(int a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r1
  int v5; // r3
  int v6; // r0
  int v7; // r3
  __int64 v8; // kr00_8
  int v10; // r4
  int v11; // r3
  int v12; // r5
  int v13; // r3
  int v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r7
  int v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r3
  int v28; // r3
  int v29; // r3
  int v30; // r3
  int v31; // r2
  int v32; // r0
  int v33; // r3
  int v34; // r2
  int v35; // r3
  char v36[8]; // [sp+0h] [bp-2E0h] BYREF
  int v37; // [sp+8h] [bp-2D8h]
  int v38; // [sp+Ch] [bp-2D4h]
  unsigned __int16 v39; // [sp+10h] [bp-2D0h] BYREF
  int v40; // [sp+12h] [bp-2CEh]
  __int16 v41; // [sp+16h] [bp-2CAh]
  unsigned __int16 v42; // [sp+18h] [bp-2C8h] BYREF
  int v43; // [sp+1Ah] [bp-2C6h]
  __int16 v44; // [sp+1Eh] [bp-2C2h]
  int v45[2]; // [sp+20h] [bp-2C0h] BYREF
  int v46; // [sp+28h] [bp-2B8h]
  int v47; // [sp+2Ch] [bp-2B4h]
  int v48; // [sp+30h] [bp-2B0h] BYREF
  int v49[165]; // [sp+34h] [bp-2ACh] BYREF

  v45[0] = 0;
  v45[1] = 0x80000000;
  v46 = 0;
  v47 = 0;
  memset(v49, 0, sizeof(v49));
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v48 = 6;
  v49[3] = 524431;
  v49[0] = 4826;
  SeCaptureSubjectContext(v45, v2, v3, 8);
  v4 = v45[0];
  if ( v45[0] )
    v5 = v45[0];
  else
    v5 = v46;
  v6 = **(_DWORD **)(v5 + 148);
  if ( !v45[0] )
    v4 = v46;
  v49[5] = 4;
  v7 = *(unsigned __int8 *)(v6 + 1);
  v8 = *(_QWORD *)(v4 + 24);
  v49[9] = v6;
  v49[6] = 4 * (v7 + 2);
  v49[10] = 1;
  v49[11] = 24;
  *(_QWORD *)&v49[17] = v8;
  v49[14] = (int)&SeSubsystemName;
  v49[15] = 5;
  v49[16] = 8;
  if ( BcdUtilGetBootOptionString(a1, 301989936, (int)&v39) < 0 )
    return sub_7DCEA0();
  v10 = v39;
  if ( !v39 )
    return sub_7DCEA0();
  if ( v39 == (unsigned __int16)v40 )
  {
    v10 = (unsigned __int16)(v39 - 2);
    v39 -= 2;
  }
  v49[20] = 1;
  v49[21] = v10 + 8;
  v49[24] = (int)&v39;
  if ( BcdUtilGetBootOptionBoolean(a1, 369098816, v36) < 0 )
  {
    v11 = 0;
    v36[0] = 0;
  }
  else
  {
    v11 = (unsigned __int8)v36[0];
  }
  v49[25] = 21;
  v49[26] = 4;
  v12 = 1842;
  if ( v11 )
    v13 = 1842;
  else
    v13 = 1843;
  v49[27] = v13;
  if ( BcdUtilGetBootOptionInteger(a1, 352321607) >= 0 )
  {
    v14 = v37;
    v15 = v38;
  }
  else
  {
    v14 = 0;
    v15 = 0;
    v37 = 0;
    v38 = 0;
  }
  if ( v14 == 1 && !v15 )
    v16 = 1847;
  else
    v16 = 1846;
  v49[30] = 21;
  v49[31] = 4;
  v49[32] = v16;
  if ( BcdUtilGetBootOptionBoolean(a1, 637534529, v36) >= 0 )
  {
    v17 = (unsigned __int8)v36[0];
  }
  else
  {
    v17 = 0;
    v36[0] = 0;
  }
  v49[35] = 21;
  v49[36] = 4;
  if ( v17 )
    v18 = 1842;
  else
    v18 = 1843;
  v49[37] = v18;
  if ( BcdUtilGetBootOptionBoolean(a1, 637534368, v36) < 0 )
  {
    v19 = 0;
    v36[0] = 0;
  }
  else
  {
    v19 = (unsigned __int8)v36[0];
  }
  v49[40] = 21;
  v49[41] = 4;
  if ( v19 )
    v20 = 1842;
  else
    v20 = 1843;
  v49[42] = v20;
  if ( BcdUtilGetBootOptionInteger(a1, 620757314) >= 0 )
  {
    v21 = v37;
    v22 = v38;
  }
  else
  {
    v21 = 0;
    v22 = 0;
    v37 = 0;
    v38 = 0;
  }
  v23 = 1849;
  if ( v21 == 1 && !v22 )
    v24 = 1849;
  else
    v24 = 1848;
  v49[45] = 21;
  v49[46] = 4;
  v49[47] = v24;
  if ( BcdUtilGetBootOptionBoolean(a1, 369098825, v36) >= 0 )
  {
    v25 = (unsigned __int8)v36[0];
  }
  else
  {
    v25 = 0;
    v36[0] = 0;
  }
  v49[50] = 21;
  v49[51] = 4;
  if ( v25 )
    v26 = 1842;
  else
    v26 = 1843;
  v49[52] = v26;
  if ( BcdUtilGetBootOptionBoolean(a1, 369098878, v36) >= 0 )
  {
    v27 = (unsigned __int8)v36[0];
  }
  else
  {
    v27 = 0;
    v36[0] = 0;
  }
  v49[55] = 21;
  v49[56] = 4;
  if ( v27 )
    v28 = 1842;
  else
    v28 = 1843;
  v49[57] = v28;
  if ( BcdUtilGetBootOptionBoolean(a1, 369098824, v36) >= 0 )
  {
    v29 = (unsigned __int8)v36[0];
  }
  else
  {
    v29 = 0;
    v36[0] = 0;
  }
  v49[60] = 21;
  v49[61] = 4;
  if ( v29 )
    v30 = 1842;
  else
    v30 = 1843;
  v49[62] = v30;
  if ( BcdUtilGetBootOptionString(a1, 570425623, (int)&v42) >= 0 && (v31 = v42) != 0 )
  {
    if ( v42 == (unsigned __int16)v43 )
      v39 = v10 - 2;
  }
  else
  {
    RtlInitUnicodeString((unsigned int)&v42, L"-");
    v31 = v42;
  }
  v49[65] = 1;
  v49[66] = v31 + 8;
  v49[69] = (int)&v42;
  v32 = BcdUtilGetBootOptionInteger(a1, 620757232);
  if ( v32 >= 0 )
  {
    v33 = v37;
    v34 = v38;
  }
  else
  {
    v33 = 0;
    v34 = 0;
  }
  if ( v33 != 1 || v34 )
    v23 = 1848;
  v49[70] = 21;
  v49[71] = 4;
  v49[72] = v23;
  if ( v32 < 0 )
    v36[0] = 0;
  if ( BcdUtilGetBootOptionBoolean(a1, 637534450, v36) >= 0 )
    v35 = (unsigned __int8)v36[0];
  else
    v35 = 0;
  v49[75] = 21;
  v49[76] = 4;
  if ( !v35 )
    v12 = 1843;
  v49[1] = 15;
  v49[77] = v12;
  SepAdtLogAuditRecord((int)&v48);
  return SeReleaseSubjectContext((int)v45);
}
