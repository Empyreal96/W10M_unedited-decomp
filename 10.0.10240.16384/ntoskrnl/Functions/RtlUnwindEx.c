// RtlUnwindEx 
 
int __fastcall RtlUnwindEx(unsigned int a1, int a2, int a3, int a4, int a5, int a6)
{
  char *v8; // r7
  char *v9; // r9
  unsigned int v10; // r6
  unsigned int v11; // r10
  BOOL v12; // lr
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r4
  int v32; // r5
  int v33; // r0
  int v34; // r4
  unsigned int v35; // r0
  unsigned int v36; // r1
  int v37; // r2
  int v38; // r1
  unsigned int v39; // lr
  int v40; // r0
  int v41; // r3
  int v42; // r0
  char *v43; // r3
  int v44; // r2
  char *v46; // r3
  int *v47; // r6
  int v48; // r4
  int v49; // r6
  int v50; // r0
  int v51; // r3
  int v53; // [sp+10h] [bp-2F8h]
  int v54; // [sp+14h] [bp-2F4h]
  int *v55; // [sp+18h] [bp-2F0h]
  int v56; // [sp+20h] [bp-2E8h]
  int v57; // [sp+24h] [bp-2E4h]
  int v58; // [sp+28h] [bp-2E0h] BYREF
  unsigned int v59; // [sp+2Ch] [bp-2DCh] BYREF
  int *v60; // [sp+30h] [bp-2D8h]
  unsigned int v61; // [sp+34h] [bp-2D4h] BYREF
  int v62; // [sp+38h] [bp-2D0h]
  int v63; // [sp+3Ch] [bp-2CCh]
  int v64; // [sp+40h] [bp-2C8h] BYREF
  int v65; // [sp+44h] [bp-2C4h]
  unsigned int v66; // [sp+48h] [bp-2C0h] BYREF
  int v67; // [sp+4Ch] [bp-2BCh] BYREF
  int v68; // [sp+50h] [bp-2B8h]
  int v69; // [sp+54h] [bp-2B4h]
  char *v70; // [sp+58h] [bp-2B0h]
  int v71; // [sp+5Ch] [bp-2ACh]
  int v72; // [sp+60h] [bp-2A8h] BYREF
  int v73; // [sp+64h] [bp-2A4h]
  int v74; // [sp+68h] [bp-2A0h]
  unsigned int v75; // [sp+6Ch] [bp-29Ch]
  int v76; // [sp+70h] [bp-298h]
  char *v77; // [sp+74h] [bp-294h]
  int v78; // [sp+78h] [bp-290h]
  int v79; // [sp+7Ch] [bp-28Ch]
  int v80; // [sp+80h] [bp-288h]
  int v81; // [sp+84h] [bp-284h]
  unsigned __int8 v82; // [sp+88h] [bp-280h]
  _DWORD *v83; // [sp+8Ch] [bp-27Ch]
  int v84[20]; // [sp+98h] [bp-270h] BYREF
  char v85[416]; // [sp+E8h] [bp-220h] BYREF
  _DWORD v86[32]; // [sp+288h] [bp-80h] BYREF

  v69 = a4;
  v70 = (char *)a5;
  v63 = a6;
  v60 = (int *)a3;
  v68 = a2;
  __mrc(15, 0, 13, 0, 3);
  if ( !RtlpGetStackLimits(&v66, &v61) )
    sub_547DD4();
  v8 = (char *)a5;
  v9 = v85;
  RtlpCaptureContext(a5);
  if ( a6 )
    *(_BYTE *)(a6 + 6) = 1;
  if ( !a3 )
  {
    v60 = v84;
    v84[0] = -1073741785;
    v84[2] = 0;
    v84[3] = *(_DWORD *)(a5 + 64);
    v84[4] = 0;
  }
  v57 = 2;
  if ( !a1 )
    v57 = 6;
  v10 = 0;
  v59 = 0;
  v11 = 0;
  while ( 1 )
  {
    v12 = (*(_DWORD *)v8 & 0x20000000) != 0;
    v62 = v12;
    v13 = *((_DWORD *)v8 + 6);
    v14 = *((_DWORD *)v8 + 7);
    v15 = *((_DWORD *)v8 + 8);
    v86[0] = *((_DWORD *)v8 + 5);
    v86[1] = v13;
    v86[2] = v14;
    v86[3] = v15;
    v16 = *((_DWORD *)v8 + 10);
    v17 = *((_DWORD *)v8 + 11);
    v18 = *((_DWORD *)v8 + 12);
    v86[4] = *((_DWORD *)v8 + 9);
    v86[5] = v16;
    v86[6] = v17;
    v86[7] = v18;
    v19 = *((_DWORD *)v8 + 37);
    v20 = *((_DWORD *)v8 + 38);
    v21 = *((_DWORD *)v8 + 39);
    v86[8] = *((_DWORD *)v8 + 36);
    v86[9] = v19;
    v86[10] = v20;
    v86[11] = v21;
    v22 = *((_DWORD *)v8 + 41);
    v23 = *((_DWORD *)v8 + 42);
    v24 = *((_DWORD *)v8 + 43);
    v86[12] = *((_DWORD *)v8 + 40);
    v86[13] = v22;
    v86[14] = v23;
    v86[15] = v24;
    v25 = *((_DWORD *)v8 + 45);
    v26 = *((_DWORD *)v8 + 46);
    v27 = *((_DWORD *)v8 + 47);
    v86[16] = *((_DWORD *)v8 + 44);
    v86[17] = v25;
    v86[18] = v26;
    v86[19] = v27;
    v28 = *((_DWORD *)v8 + 49);
    v29 = *((_DWORD *)v8 + 50);
    v30 = *((_DWORD *)v8 + 51);
    v86[20] = *((_DWORD *)v8 + 48);
    v86[21] = v28;
    v86[22] = v29;
    v86[23] = v30;
    v56 = *((_DWORD *)v8 + 16);
    v31 = v12 ? 2 : 0;
    v32 = RtlLookupFunctionEntry(*((_DWORD *)v8 + 16) - v31, &v67, v63);
    if ( v32 )
      break;
    v51 = *((_DWORD *)v8 + 15);
    v44 = v56;
    if ( v56 == v51 )
      RtlRaiseStatus(-1073741569);
    *((_DWORD *)v8 + 16) = v51;
    v36 = v61;
    v35 = v66;
    *(_DWORD *)v8 |= 0x20000000u;
LABEL_30:
    if ( (v10 & 3) == 0 && v10 >= v35 && v10 < v36 )
    {
      if ( v10 == a1 )
        goto LABEL_40;
      if ( v11++ < 0x3C00 )
        continue;
    }
    goto LABEL_54;
  }
  v33 = RtlpCopyContext(v9, v8);
  v58 = 0;
  v55 = &v58;
  v54 = 0;
  v53 = 0;
  v71 = v67;
  if ( RtlpxVirtualUnwind(v33, v67, v56 - v31, v32, v9, &v64, &v59) < 0 )
    *((_DWORD *)v9 + 16) = 0;
  v34 = v58;
  if ( *((_DWORD *)v9 + 14) != *((_DWORD *)v8 + 14) || *((_DWORD *)v9 + 16) != *((_DWORD *)v8 + 16) )
  {
    v10 = v59;
    if ( (v59 & 3) != 0 || (v35 = v66, v59 < v66) || (v36 = v61, v59 >= v61) || a1 < v59 && a1 )
      RtlRaiseStatus(-1073741784);
    if ( v58 )
    {
      v37 = v64;
      v38 = 0;
      v39 = v57;
      v76 = v68;
      v65 = v64;
      v58 = 0;
      do
      {
        if ( a1 == v10 )
        {
          v39 |= 0x20u;
          v57 = v39;
        }
        v40 = (int)v60;
        v41 = v69;
        v78 = v34;
        v79 = v37;
        v60[1] = v39;
        *((_DWORD *)v8 + 1) = v41;
        v81 = v38;
        v72 = v56;
        v73 = v71;
        v74 = v32;
        v75 = v10;
        v77 = v8;
        v80 = v63;
        v82 = v62;
        v83 = v86;
        v42 = RtlpExecuteHandlerForUnwind(v40, v10, (int)v8, (int)&v72);
        v39 = v57 & 0xFFFFFF9F;
        v57 &= 0xFFFFFF9F;
        if ( v42 == 1 )
        {
          v37 = v65;
          v38 = v58;
          if ( v10 != a1 )
          {
            v43 = v8;
            v8 = v9;
            v9 = v43;
          }
        }
        else
        {
          if ( v42 != 3 )
            RtlRaiseStatus(-1073741786);
          v49 = v72;
          v48 = v73;
          v32 = v74;
          v56 = v72;
          v71 = v73;
          v67 = v73;
          v62 = v82;
          RtlpCopyContext(v70, v77);
          memmove((int)v86, (int)v83, 0x60u);
          v9 = v85;
          v8 = v70;
          RtlpCopyContext(v85, v70);
          if ( v62 )
            v50 = 2;
          else
            v50 = 0;
          RtlVirtualUnwind(0, v48, v49 - v50, v32, v85, &v64, &v59, 0, v53, v54, v55);
          v37 = v79;
          v10 = v75;
          v38 = v81;
          v63 = v80;
          v64 = v79;
          v39 = v57 | 0x40;
          v34 = v78;
          v57 |= 0x40u;
          v58 = v81;
          v59 = v75;
          v65 = v79;
        }
      }
      while ( (v39 & 0x40) != 0 );
      v36 = v61;
      v35 = v66;
    }
    else if ( v59 != a1 )
    {
      v46 = v8;
      v8 = v9;
      v9 = v46;
    }
    v44 = v56;
    goto LABEL_30;
  }
  v10 = v59;
  v44 = v56;
LABEL_54:
  if ( v10 == a1 )
  {
LABEL_40:
    v47 = v60;
    *((_DWORD *)v8 + 1) = v69;
    if ( *v47 == -2147483607 )
    {
      if ( v47[15] == -1 )
        v47[15] = (int)v86;
    }
    else
    {
      *((_DWORD *)v8 + 16) = v68;
    }
    RtlRestoreContext((int)v8, v47);
  }
  if ( v44 == *((_DWORD *)v8 + 16) )
    RtlRaiseStatus(-1073741569);
  return ZwRaiseException();
}
