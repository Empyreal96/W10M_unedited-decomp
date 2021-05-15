// EtwpRegTraceCallback 
 
int __fastcall EtwpRegTraceCallback(int a1, int a2, int a3)
{
  int v3; // r7
  unsigned int v4; // r6
  char v5; // r8
  int v6; // r10
  int v7; // lr
  unsigned __int16 **v8; // r6
  int v9; // r9
  unsigned __int16 *v10; // r1
  int v11; // r3
  unsigned int v12; // r7
  int v13; // r4
  int v14; // r3
  int v15; // r6
  unsigned int v16; // r2
  int v17; // r3
  int v18; // r1
  int v19; // r0
  _DWORD *v20; // r6
  unsigned __int16 *v21; // r4
  unsigned int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // r6
  int *v26; // r5
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r6
  int *v31; // r5
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int v35; // r1
  int *v36; // r2
  int *v37; // r3
  int v38; // r1
  int *v39; // r2
  int *v40; // r2
  int *v41; // r2
  int *v42; // r2
  int v43; // r4
  int v44; // r2
  int *v45; // r3
  int *v46; // r3
  int v47; // r1
  int v48; // r4
  int v49; // r2
  int *v50; // r3
  int *v51; // r3
  int *v52; // r2
  int *v53; // r3
  unsigned int v54; // r2
  int *v55; // r2
  int v56; // r1
  int *v57; // r2
  int *v58; // r2
  int v59; // r1
  int *v60; // r2
  char v61; // r3
  unsigned __int16 *v63; // [sp+8h] [bp-158h] BYREF
  unsigned __int16 v64; // [sp+Ch] [bp-154h] BYREF
  unsigned __int16 v65; // [sp+Eh] [bp-152h] BYREF
  unsigned int v66; // [sp+10h] [bp-150h] BYREF
  unsigned int v67; // [sp+14h] [bp-14Ch] BYREF
  int v68; // [sp+18h] [bp-148h] BYREF
  unsigned __int16 *v69; // [sp+1Ch] [bp-144h]
  int v70; // [sp+20h] [bp-140h] BYREF
  unsigned __int16 *v71; // [sp+24h] [bp-13Ch] BYREF
  unsigned __int16 *v72; // [sp+28h] [bp-138h]
  int v73; // [sp+2Ch] [bp-134h] BYREF
  unsigned __int16 *v74; // [sp+30h] [bp-130h] BYREF
  unsigned int v75; // [sp+34h] [bp-12Ch] BYREF
  unsigned int v76; // [sp+38h] [bp-128h]
  int v77; // [sp+3Ch] [bp-124h] BYREF
  int v78; // [sp+40h] [bp-120h] BYREF
  int v79; // [sp+44h] [bp-11Ch]
  int v80; // [sp+48h] [bp-118h]
  int v81; // [sp+4Ch] [bp-114h]
  int v82[68]; // [sp+50h] [bp-110h] BYREF

  v3 = a3;
  v4 = 0;
  v5 = 0;
  v71 = 0;
  v72 = 0;
  v74 = 0;
  v75 = 0;
  v69 = 0;
  v70 = 0;
  v76 = 0;
  v77 = 0;
  v67 = 0;
  v68 = 0;
  v63 = 0;
  v66 = 0;
  v73 = 0;
  v6 = 0;
  v65 = 0;
  v7 = 0;
  v64 = 0;
  switch ( a2 )
  {
    case 1:
      if ( (EtwpRegTraceOptions & 4) != 0 )
        EtwpCapturePreviousRegistryData((__int64 *)a3);
      return 0;
    case 14:
      v31 = ETW_REGISTRY_EVENT_CLOSE_KEY;
      v9 = 1;
      goto LABEL_39;
    case 15:
      v9 = a3;
      v78 = 268435459;
      v79 = 8708;
      v80 = 0x4000;
      v81 = 0x80000000;
      v10 = **(unsigned __int16 ***)(a3 + 8);
      goto LABEL_14;
    case 16:
      v20 = *(_DWORD **)(a3 + 8);
      v9 = a3;
      v78 = 268435461;
      v79 = 9220;
      v80 = 256;
      v81 = 0x80000000;
      v10 = *(unsigned __int16 **)a3;
      v21 = (unsigned __int16 *)v20[1];
      v68 = v20[3];
      v69 = v21;
      v63 = v10;
      v22 = v20[5];
      v67 = v22;
      if ( (EtwpRegTraceOptions & 2) != 0 )
      {
        v23 = *(_DWORD *)(v3 + 4);
        if ( v23 >= 0 )
        {
          v24 = EtwpCaptureRegistryData((int *)&v66, v20[4], v22, v23);
          v10 = v63;
          v7 = v64;
          v76 = v66;
          v6 = v24;
          v65 = v24;
        }
      }
      v4 = *(_DWORD *)(v3 + 16);
      v12 = v76;
      v5 = -15;
      goto LABEL_8;
    case 17:
      v9 = a3;
      v78 = 268435462;
      v79 = 9476;
      v80 = 512;
      v81 = 0x80000000;
      v5 = 1;
      v69 = *(unsigned __int16 **)(*(_DWORD *)(a3 + 8) + 4);
      goto LABEL_27;
    case 18:
      v15 = *(_DWORD *)(a3 + 8);
      v78 = 268435467;
      v79 = 10756;
      v80 = 64;
      v81 = 0x80000000;
      v10 = *(unsigned __int16 **)a3;
      v63 = *(unsigned __int16 **)a3;
      v68 = *(_DWORD *)(v15 + 4);
      v16 = *(_DWORD *)(v15 + 12);
      goto LABEL_16;
    case 20:
      v26 = ETW_REGISTRY_EVENT_ENUMERATE_KEY;
      goto LABEL_33;
    case 21:
      v26 = ETW_REGISTRY_EVENT_ENUMERATE_VALUE_KEY;
LABEL_33:
      v25 = *(_DWORD *)(a3 + 8);
      v27 = v26[1];
      v28 = v26[2];
      v29 = v26[3];
      v78 = *v26;
      v79 = v27;
      v80 = v28;
      v81 = v29;
      v10 = *(unsigned __int16 **)v3;
      v5 = 120;
      v63 = *(unsigned __int16 **)v3;
      v70 = *(_DWORD *)(v25 + 4);
      goto LABEL_29;
    case 22:
      v15 = *(_DWORD *)(a3 + 8);
      v78 = 268435460;
      v79 = 8964;
      v80 = 0x8000;
      v81 = 0x80000000;
      v10 = *(unsigned __int16 **)a3;
      v63 = *(unsigned __int16 **)a3;
      v68 = *(_DWORD *)(v15 + 4);
      v16 = **(_DWORD **)(v15 + 16);
LABEL_16:
      v9 = v3;
      v67 = v16;
      v5 = 112;
      if ( (EtwpRegTraceOptions & 2) == 0 )
        goto LABEL_6;
      v17 = *(_DWORD *)(v3 + 4);
      if ( v17 < 0 )
        goto LABEL_6;
      v18 = *(_DWORD *)(v15 + 8);
      goto LABEL_19;
    case 23:
      v25 = *(_DWORD *)(a3 + 8);
      v78 = 268435463;
      v79 = 9732;
      v80 = 1024;
      v81 = 0x80000000;
      v10 = *(unsigned __int16 **)a3;
      v5 = 113;
      v69 = *(unsigned __int16 **)(v25 + 4);
      v63 = v10;
LABEL_29:
      v9 = v3;
      v68 = *(_DWORD *)(v25 + 8);
      v16 = **(_DWORD **)(v25 + 20);
      v67 = v16;
      if ( (EtwpRegTraceOptions & 2) == 0 )
        goto LABEL_6;
      v17 = *(_DWORD *)(v3 + 4);
      if ( v17 < 0 )
        goto LABEL_6;
      v18 = *(_DWORD *)(v25 + 12);
LABEL_19:
      v19 = EtwpCaptureRegistryData((int *)&v66, v18, v16, v17);
      v7 = v64;
      v10 = v63;
      v12 = v66;
      v6 = v19;
      v65 = v19;
      v4 = 0;
      goto LABEL_8;
    case 24:
      v30 = *(_DWORD *)(a3 + 8);
      v9 = a3;
      v78 = 268435466;
      v79 = 10500;
      v80 = 32;
      v81 = 0x80000000;
      v10 = *(unsigned __int16 **)a3;
      v5 = 40;
      v63 = *(unsigned __int16 **)a3;
      v70 = *(_DWORD *)(v30 + 8);
      v67 = **(_DWORD **)(v30 + 16);
      goto LABEL_6;
    case 27:
      v8 = *(unsigned __int16 ***)(a3 + 8);
      v9 = a3;
      v78 = 268435457;
      v79 = 8196;
      v80 = 4096;
      v81 = 0x80000000;
      v10 = v8[1];
      v11 = *(_DWORD *)(a3 + 4);
      v63 = v10;
      if ( v11 < 0 )
        goto LABEL_5;
      v77 = *(_DWORD *)v8[9];
LABEL_4:
      v71 = *(unsigned __int16 **)a3;
LABEL_5:
      v5 = 7;
      v69 = *v8;
LABEL_6:
      v4 = 0;
      goto LABEL_7;
    case 29:
      v8 = *(unsigned __int16 ***)(a3 + 8);
      v9 = a3;
      v78 = 268435458;
      v79 = 8452;
      v80 = 0x2000;
      v81 = 0x80000000;
      v10 = v8[1];
      v14 = *(_DWORD *)(a3 + 4);
      v63 = v10;
      if ( v14 >= 0 )
        goto LABEL_4;
      goto LABEL_5;
    case 31:
      v31 = ETW_REGISTRY_EVENT_FLUSH_KEY;
      goto LABEL_38;
    case 37:
      v31 = ETW_REGISTRY_EVENT_QUERY_SECURITY_KEY;
      goto LABEL_38;
    case 39:
      v31 = ETW_REGISTRY_EVENT_SET_SECURITY_KEY;
LABEL_38:
      v9 = a3;
LABEL_39:
      v32 = v31[1];
      v33 = v31[2];
      v34 = v31[3];
      v78 = *v31;
      v79 = v32;
      v80 = v33;
      v81 = v34;
LABEL_27:
      v10 = *(unsigned __int16 **)v3;
LABEL_14:
      v63 = v10;
LABEL_7:
      v12 = 0;
LABEL_8:
      if ( (EtwpRegTraceOptions & 1) != 0 )
      {
        v13 = 1;
        if ( v10 )
        {
          CmCallbackGetKeyObjectID((int)&EtwpRegTraceCookie, v10, 0, &v74);
          v6 = v65;
          v7 = v64;
          v72 = v74;
        }
      }
      else
      {
        v13 = 0;
      }
      v82[0] = (int)&v63;
      v82[1] = 0;
      v82[2] = 4;
      v35 = 1;
      v82[3] = 0;
      if ( (v5 & 4) != 0 )
      {
        v82[4] = (int)&v71;
        v82[5] = 0;
        v82[6] = 4;
        v82[7] = 0;
        v35 = 2;
      }
      if ( v9 == 1 )
      {
        v37 = &v82[4 * v35];
        *v37 = (int)&EtwpNull;
        v37[1] = 0;
        v37[2] = 4;
        v37[3] = 0;
      }
      else
      {
        v36 = &v82[4 * v35];
        *v36 = v9 + 4;
        v36[1] = 0;
        v36[2] = 4;
        v36[3] = 0;
      }
      v38 = v35 + 1;
      if ( (v5 & 8) != 0 )
      {
        v39 = &v82[4 * v38];
        *v39 = (int)&v70;
        v39[1] = 0;
        v39[2] = 4;
        v39[3] = 0;
        ++v38;
      }
      if ( (v5 & 0x10) != 0 )
      {
        v40 = &v82[4 * v38];
        *v40 = (int)&v68;
        v40[1] = 0;
        v40[2] = 4;
        v40[3] = 0;
        ++v38;
      }
      if ( (v5 & 2) != 0 )
      {
        v41 = &v82[4 * v38];
        *v41 = (int)&v77;
        v41[1] = 0;
        v41[2] = 4;
        v41[3] = 0;
        ++v38;
      }
      if ( (v5 & 0x20) != 0 )
      {
        v42 = &v82[4 * v38];
        *v42 = (int)&v67;
        v42[1] = 0;
        v42[2] = 4;
        v42[3] = 0;
        ++v38;
      }
      if ( v13 == 1 )
      {
        if ( v72 )
        {
          v43 = *((_DWORD *)v72 + 1);
          if ( v43 )
          {
            v44 = *v72;
            if ( *v72 )
            {
              v45 = &v82[4 * v38];
              *v45 = v43;
              v45[1] = 0;
              v45[2] = v44;
              v45[3] = 0;
              ++v38;
            }
          }
        }
      }
      v46 = &v82[4 * v38];
      v47 = v38 + 1;
      *v46 = (int)&EtwpNull;
      v46[1] = 0;
      v46[2] = 2;
      v46[3] = 0;
      if ( (v5 & 1) != 0 )
      {
        if ( v69 )
        {
          v48 = *((_DWORD *)v69 + 1);
          if ( v48 )
          {
            v49 = *v69;
            if ( *v69 )
            {
              v50 = &v82[4 * v47];
              *v50 = v48;
              v50[1] = 0;
              v50[2] = v49;
              v50[3] = 0;
              ++v47;
            }
          }
        }
        v51 = &v82[4 * v47];
        *v51 = (int)&EtwpNull;
        v51[1] = 0;
        v51[2] = 2;
        v51[3] = 0;
        ++v47;
      }
      if ( (v5 & 0x40) != 0 )
      {
        v52 = &v82[4 * v47++];
        *v52 = (int)&v65;
        v52[1] = 0;
        v52[2] = 2;
        v52[3] = 0;
        if ( v6 )
        {
          v53 = &v82[4 * v47];
          *v53 = v12;
          v53[1] = 0;
          v53[2] = v6;
          v53[3] = 0;
          ++v47;
        }
      }
      if ( (v5 & 0x80) != 0 )
      {
        if ( v4 )
        {
          v54 = *(_DWORD *)(v4 + 8);
          v7 = 2048;
          v75 = v54;
          v73 = *(_DWORD *)(v4 + 4);
          if ( v54 <= 0x800 )
            v7 = (unsigned __int16)v54;
          v64 = v7;
        }
        v55 = &v82[4 * v47];
        *v55 = (int)&v73;
        v55[1] = 0;
        v56 = v47 + 1;
        v55[2] = 4;
        v55[3] = 0;
        v57 = &v82[4 * v56];
        *v57 = (int)&v75;
        v57[1] = 0;
        ++v56;
        v57[2] = 4;
        v57[3] = 0;
        v58 = &v82[4 * v56];
        v59 = v56 + 1;
        *v58 = (int)&v64;
        v58[1] = 0;
        v58[2] = 2;
        v58[3] = 0;
        if ( v7 )
        {
          v60 = &v82[4 * v59];
          *v60 = v4 + 12;
          v60[1] = 0;
          v60[2] = v7;
          v60[3] = 0;
        }
      }
      if ( v9 == 1 || *(int *)(v9 + 4) >= 0 )
        v61 = 2;
      else
        v61 = 1;
      LOBYTE(v79) = v61;
      EtwWrite(EtwpRegTraceHandle, dword_92026C, (int)&v78, 0);
      if ( v12 )
        ExFreePoolWithTag(v12);
      if ( v4 )
        ExFreePoolWithTag(v4);
      break;
    default:
      return 0;
  }
  return 0;
}
