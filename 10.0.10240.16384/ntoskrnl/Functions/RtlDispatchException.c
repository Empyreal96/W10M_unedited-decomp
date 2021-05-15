// RtlDispatchException 
 
int __fastcall RtlDispatchException(int a1, int a2)
{
  int v5; // r10
  int v6; // r7
  int *v7; // r0
  int v8; // r4
  unsigned int v9; // r8
  int v10; // r4
  int v11; // r0
  int v12; // r5
  int v13; // r10
  int v14; // r8
  int v15; // r9
  int v16; // r6
  int v17; // r7
  bool v18; // zf
  int v19; // r8
  int v20; // r4
  int v21; // r3
  int v22; // r0
  int v23; // r9
  int v24; // r2
  int v25; // r3
  int v26; // r5
  int v27; // r8
  int v28; // r0
  unsigned int v29; // r2
  int v30; // r10
  bool v31; // cf
  int v32; // r6
  int v33; // r0
  int v34; // r2
  int v35; // [sp+10h] [bp-318h]
  int v36; // [sp+14h] [bp-314h]
  int *v37; // [sp+18h] [bp-310h]
  int v38; // [sp+20h] [bp-308h]
  unsigned int v39; // [sp+24h] [bp-304h] BYREF
  unsigned int v40; // [sp+28h] [bp-300h]
  int v41; // [sp+2Ch] [bp-2FCh]
  int v42; // [sp+30h] [bp-2F8h] BYREF
  int v43; // [sp+34h] [bp-2F4h]
  int *v44; // [sp+38h] [bp-2F0h]
  unsigned int v45; // [sp+3Ch] [bp-2ECh]
  int v46; // [sp+40h] [bp-2E8h] BYREF
  int v47; // [sp+44h] [bp-2E4h]
  char v48[4]; // [sp+48h] [bp-2E0h] BYREF
  int v49; // [sp+4Ch] [bp-2DCh] BYREF
  char v50[4]; // [sp+50h] [bp-2D8h] BYREF
  int v51; // [sp+54h] [bp-2D4h]
  BOOL v52; // [sp+58h] [bp-2D0h]
  int v53; // [sp+60h] [bp-2C8h] BYREF
  int v54; // [sp+64h] [bp-2C4h]
  int v55; // [sp+68h] [bp-2C0h]
  unsigned int v56; // [sp+6Ch] [bp-2BCh]
  int *v57; // [sp+74h] [bp-2B4h]
  int v58; // [sp+78h] [bp-2B0h]
  int v59; // [sp+7Ch] [bp-2ACh]
  int *v60; // [sp+80h] [bp-2A8h]
  int v61; // [sp+84h] [bp-2A4h]
  unsigned __int8 v62; // [sp+88h] [bp-2A0h]
  _DWORD *v63; // [sp+8Ch] [bp-29Ch]
  int v64[14]; // [sp+98h] [bp-290h] BYREF
  int v65; // [sp+D0h] [bp-258h]
  int v66; // [sp+D4h] [bp-254h]
  int v67; // [sp+D8h] [bp-250h]
  int v68; // [sp+128h] [bp-200h]
  int v69; // [sp+12Ch] [bp-1FCh]
  int v70; // [sp+130h] [bp-1F8h]
  int v71; // [sp+134h] [bp-1F4h]
  int v72; // [sp+138h] [bp-1F0h]
  int v73; // [sp+13Ch] [bp-1ECh]
  int v74; // [sp+140h] [bp-1E8h]
  int v75; // [sp+144h] [bp-1E4h]
  int v76; // [sp+148h] [bp-1E0h]
  int v77; // [sp+14Ch] [bp-1DCh]
  int v78; // [sp+150h] [bp-1D8h]
  int v79; // [sp+154h] [bp-1D4h]
  int v80; // [sp+158h] [bp-1D0h]
  int v81; // [sp+15Ch] [bp-1CCh]
  int v82; // [sp+160h] [bp-1C8h]
  int v83; // [sp+164h] [bp-1C4h]
  int v84; // [sp+238h] [bp-F0h] BYREF
  char v85; // [sp+23Ch] [bp-ECh]
  char v86; // [sp+23Dh] [bp-EBh]
  char v87; // [sp+23Eh] [bp-EAh]
  char v88; // [sp+23Fh] [bp-E9h]
  int v89; // [sp+240h] [bp-E8h]
  int v90; // [sp+244h] [bp-E4h]
  _DWORD v91[32]; // [sp+2A8h] [bp-80h] BYREF

  v51 = a2;
  v41 = a1;
  v47 = 0;
  if ( (NtGlobalFlag & 0x800000) != 0 )
    return sub_547D5C();
  v5 = *(_DWORD *)(a1 + 4) & 1;
  v38 = v5;
  if ( RtlpGetStackLimits(v50, v48) )
  {
    RtlpCopyContext(v64, a2);
    v6 = *(_DWORD *)(a2 + 64);
    v45 = 0;
    v85 = 0;
    v86 = 0;
    v7 = &v84;
    v8 = v64[0];
    v88 = 1;
    v89 = -1;
    v90 = 0;
    v43 = v6;
    v44 = &v84;
    v84 = 0;
    v87 = 0;
    v9 = 0;
    v40 = 0;
    while ( 1 )
    {
      v91[0] = v64[5];
      v91[1] = v64[6];
      v91[2] = v64[7];
      v91[3] = v64[8];
      v91[4] = v64[9];
      v91[5] = v64[10];
      v91[6] = v64[11];
      v91[7] = v64[12];
      v91[8] = v68;
      v91[9] = v69;
      v91[10] = v70;
      v91[11] = v71;
      v91[12] = v72;
      v91[13] = v73;
      v91[14] = v74;
      v91[15] = v75;
      v91[16] = v76;
      v91[17] = v77;
      v91[18] = v78;
      v91[19] = v79;
      v91[20] = v80;
      v91[21] = v81;
      v52 = (v8 & 0x20000000) != 0;
      v91[22] = v82;
      v91[23] = v83;
      if ( (v8 & 0x20000000) != 0 )
        v10 = 2;
      else
        v10 = 0;
      v11 = RtlLookupFunctionEntry(v6 - v10, &v49, v7);
      v12 = v11;
      if ( v11 )
      {
        v46 = 0;
        v36 = 0;
        v35 = 0;
        v13 = v49;
        v14 = v65;
        v37 = &v46;
        if ( RtlpxVirtualUnwind(v11, v49, v6 - v10, v11, v64, &v42, &v39) < 0 )
        {
          v15 = 0;
          v67 = 0;
        }
        else
        {
          v15 = v67;
        }
        v16 = v65;
        v17 = v46;
        v18 = v14 == v65;
        v19 = v43;
        if ( v18 && v43 == v15 )
        {
LABEL_29:
          v32 = v38;
LABEL_50:
          *(_DWORD *)(v41 + 4) = v32;
          return 0;
        }
        v20 = v39;
        if ( !RtlpIsFrameInBounds(v50, v39, v48) )
        {
          v32 = v38 | 8;
          goto LABEL_50;
        }
        if ( v17 )
        {
          v21 = v42;
          v22 = (int)v44;
          LOBYTE(v23) = v52;
          v24 = 0;
          while ( 1 )
          {
            v58 = v17;
            v59 = v21;
            v63 = v91;
            v25 = v47;
            *(_DWORD *)(v41 + 4) = v38;
            v54 = v13;
            v55 = v12;
            v26 = 0;
            v53 = v19;
            v56 = v20;
            v57 = v64;
            v60 = (int *)v22;
            v61 = v24;
            v62 = v23;
            if ( v25 )
            {
              v34 = v19;
              v27 = v41;
              v26 = RtlpLogExceptionHandler(v41, v64, v34, v17);
            }
            else
            {
              v27 = v41;
            }
            v28 = RtlpExecuteHandlerForException(v27, v20, v51, (int)&v53);
            if ( v26 )
              *(_DWORD *)(v26 + 500) = v28;
            v29 = v45;
            v30 = v38 | *(_DWORD *)(v27 + 4) & 1;
            v38 = v30;
            if ( v45 == v20 )
            {
              v30 &= 0xFFFFFFEF;
              v29 = 0;
              v38 = v30;
              v45 = 0;
            }
            if ( v28 == 1 )
              goto LABEL_21;
            if ( v28 == 2 )
            {
              v38 = v30 | 0x10;
              if ( v56 > v29 )
                v45 = v56;
LABEL_21:
              v15 = v67;
              v8 = v64[0];
              v9 = v40;
              goto LABEL_22;
            }
            if ( !v28 )
              break;
            if ( v28 != 3 )
              RtlRaiseStatus(-1073741786);
            v19 = v53;
            v13 = v54;
            v12 = v55;
            v23 = v62;
            v49 = v54;
            RtlpCopyContext(v64, v57);
            memmove((int)v91, (int)v63, 0x60u);
            if ( v23 )
              v33 = 2;
            else
              v33 = 0;
            RtlVirtualUnwind(0, v13, v19 - v33, v12, v64, &v42, &v39, 0, v35, v36, v37);
            v20 = v56;
            v21 = v59;
            v22 = (int)v60;
            v17 = v58;
            v24 = v61;
            v39 = v56;
            v42 = v59;
            v44 = v60;
          }
          if ( (v30 & 1) != 0 )
            RtlRaiseStatus(-1073741787);
          return 1;
        }
        v8 = v64[0];
        v9 = v40;
      }
      else
      {
        v15 = v66;
        if ( v6 == v66 )
          goto LABEL_29;
        v67 = v66;
        v8 = v64[0] | 0x20000000;
        v64[0] |= 0x20000000u;
LABEL_22:
        v16 = v65;
      }
      v6 = v15;
      v43 = v15;
      if ( RtlpIsFrameInBounds(v50, v16, v48) != 1 )
        goto LABEL_29;
      v31 = v9++ >= 0x3C00;
      v40 = v9;
      if ( v31 )
        goto LABEL_29;
      v7 = v44;
    }
  }
  *(_DWORD *)(a1 + 4) = v5 | 8;
  return 0;
}
