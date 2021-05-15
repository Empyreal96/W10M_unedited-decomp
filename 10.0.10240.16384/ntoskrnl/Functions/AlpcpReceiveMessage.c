// AlpcpReceiveMessage 
 
int __fastcall AlpcpReceiveMessage(int a1, unsigned int a2, int *a3, unsigned int a4, unsigned int a5)
{
  unsigned int v8; // r0
  int v9; // r9
  __int64 *v10; // r2
  int *v11; // r2
  int v12; // r1
  unsigned int v13; // r2
  int *v14; // r2
  int *v15; // r2
  int v16; // r0
  int v17; // r2
  _DWORD *v18; // r6
  int v19; // lr
  bool v20; // zf
  int v21; // r0
  int v22; // r9
  int v23; // r6
  unsigned int v24; // r4
  _DWORD *v25; // lr
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r3
  unsigned int v30; // r2
  int v31; // r1
  int v32; // r0
  int v33; // r5
  int v34; // r4
  int v35; // r2
  int v36; // r0
  int v37; // r3
  _DWORD *v38; // r4
  int v39; // r3
  int v40; // r2
  int v41; // lr
  int v42; // r4
  unsigned int *v43; // r2
  unsigned int v44; // r0
  int v45; // r0
  unsigned int *v46; // r2
  unsigned int v47; // r1
  int v48; // r1
  int v49; // r2
  int v50; // r1
  int v51; // r3
  _DWORD *v52; // r2
  _DWORD *v53; // lr
  int v54; // r3
  int v55; // r3
  int v56; // r3
  int v57; // r3
  unsigned int v58; // r2
  int v59; // r3
  unsigned int v60; // r2
  _DWORD *v61; // r0
  int v62; // r4
  unsigned int *v63; // r5
  unsigned int v64; // r1
  unsigned int *v65; // r2
  unsigned int v66; // r0
  int v67; // r0
  bool v69; // [sp+8h] [bp-90h] BYREF
  int v70; // [sp+Ch] [bp-8Ch]
  _DWORD *v71; // [sp+10h] [bp-88h]
  int v72; // [sp+14h] [bp-84h]
  int v73; // [sp+18h] [bp-80h]
  int v74; // [sp+1Ch] [bp-7Ch] BYREF
  int v75; // [sp+20h] [bp-78h]
  int v76; // [sp+24h] [bp-74h]
  int v77; // [sp+28h] [bp-70h]
  int v78; // [sp+2Ch] [bp-6Ch]
  _DWORD *v79; // [sp+30h] [bp-68h]
  _DWORD *v80; // [sp+34h] [bp-64h]
  int v81; // [sp+38h] [bp-60h]
  int v82; // [sp+3Ch] [bp-5Ch]
  unsigned int v83; // [sp+40h] [bp-58h]
  __int64 v84; // [sp+48h] [bp-50h]
  int v85; // [sp+50h] [bp-48h]
  unsigned int v86; // [sp+54h] [bp-44h]
  _DWORD *v87; // [sp+58h] [bp-40h]
  int v88; // [sp+5Ch] [bp-3Ch]
  int v89; // [sp+60h] [bp-38h]
  __int64 v90; // [sp+68h] [bp-30h] BYREF
  int v91; // [sp+70h] [bp-28h]
  unsigned int v92; // [sp+74h] [bp-24h]
  int varg_r0; // [sp+A0h] [bp+8h]
  unsigned int varg_r1; // [sp+A4h] [bp+Ch]
  int *varg_r2; // [sp+A8h] [bp+10h]
  unsigned int varg_r3; // [sp+ACh] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v79 = (_DWORD *)a2;
  varg_r1 = a2;
  v80 = (_DWORD *)a1;
  varg_r0 = a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v81 = v8;
  v92 = v8;
  v9 = *(_DWORD *)(a1 + 24);
  v85 = v9;
  v71 = *(_DWORD **)a1;
  v87 = v71;
  v74 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v69 = v74;
  v90 = 0i64;
  v83 = -1;
  v86 = -1;
  v70 = 0;
  v89 = 0;
  v77 = 0;
  v88 = 0;
  if ( v74 )
  {
    v10 = (__int64 *)a5;
    LODWORD(v84) = a5;
    if ( a5 )
    {
      if ( a5 >= MmUserProbeAddress )
        v10 = (__int64 *)MmUserProbeAddress;
      v84 = *v10;
      v90 = v84;
      LODWORD(v84) = &v90;
    }
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(a2 + 16);
    if ( (v9 & 0x1000000) != 0 )
    {
      v70 = *(_DWORD *)(a2 + 16);
      v89 = v70;
      v77 = *(_DWORD *)(a2 + 20);
      v88 = v77;
    }
    if ( a4 )
    {
      v11 = (int *)a4;
      if ( a4 >= MmUserProbeAddress )
        v11 = (int *)MmUserProbeAddress;
      v12 = *v11;
      v13 = 8;
      v73 = 0x80000000;
      if ( v12 < 0 )
        v13 = 20;
      v72 = 0x40000000;
      if ( (v12 & 0x40000000) != 0 )
        v13 += 16;
      v75 = 0x20000000;
      if ( (v12 & 0x20000000) != 0 )
        v13 += 20;
      v76 = 0x10000000;
      if ( (v12 & 0x10000000) != 0 )
        v13 += 16;
      v78 = 0x8000000;
      if ( (v12 & 0x8000000) != 0 )
        v13 += 24;
      if ( (v12 & 0x4000000) != 0 )
        v13 += 4;
      if ( (a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
      if ( a4 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a4 = *(_BYTE *)a4;
      if ( v13 > 4 )
        *(_BYTE *)(((v13 - 1) & 0xFFFFFFFC) + a4) = *(_BYTE *)(((v13 - 1) & 0xFFFFFFFC) + a4);
      v82 = v12;
    }
    else
    {
      v12 = 0;
      v82 = 0;
      v73 = 0x80000000;
      v72 = 0x40000000;
      v75 = 0x20000000;
      v76 = 0x10000000;
      v78 = 0x8000000;
    }
    if ( a3 )
    {
      v14 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v14 = (int *)MmUserProbeAddress;
      v83 = *v14;
      v86 = v83;
      v15 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v15 = (int *)MmUserProbeAddress;
      *v15 = *v15;
    }
    v16 = v70;
    v17 = v77;
    v18 = v80;
    v19 = v74;
  }
  else
  {
    if ( (v9 & 0x1000000) != 0 )
    {
      v70 = *(_DWORD *)(a2 + 16);
      v77 = *(_DWORD *)(a2 + 20);
    }
    if ( a4 )
      v12 = *(_DWORD *)a4;
    else
      v12 = 0;
    if ( a3 )
    {
      v83 = *a3;
      v86 = v83;
    }
    v20 = (*(_DWORD *)(v8 + 76) & 0x400) == 0;
    v16 = v70;
    v18 = v80;
    v73 = 0x80000000;
    v72 = 0x40000000;
    v75 = 0x20000000;
    v76 = 0x10000000;
    v78 = 0x8000000;
    v17 = v77;
    LODWORD(v84) = a5;
    if ( v20 )
      v19 = v74;
    else
      v19 = 1;
  }
  if ( (v9 & 0x1000000) != 0 )
    v21 = AlpcpReceiveDirectMessagePort(v18, v16, v17, &v74, v12);
  else
    v21 = AlpcpReceiveMessagePort(v18, v19, v84, &v74, v12);
  v22 = v21;
  if ( !v21 )
  {
    v23 = v74;
    v24 = (unsigned __int16)(*(_WORD *)(v74 + 120) + 24);
    if ( a3 && v24 > v83 )
    {
      v22 = AlpcpReturnMessageOnInsufficientBuffer(v71, v74);
      v91 = v22;
      if ( v22 == -1073741789 )
        *a3 = v24;
    }
    else
    {
      *(_DWORD *)(v74 + 100) = v81;
      v25 = v79;
      v26 = *(_DWORD *)(v23 + 124);
      v27 = *(_DWORD *)(v23 + 128);
      v28 = *(_DWORD *)(v23 + 132);
      *v79 = *(_DWORD *)(v23 + 120);
      v25[1] = v26;
      v25[2] = v27;
      v25[3] = v28;
      v29 = *(_DWORD *)(v23 + 140);
      v25[4] = *(_DWORD *)(v23 + 136);
      v25[5] = v29;
      if ( (v71[38] & 0x1000) != 0 )
        *((_WORD *)v25 + 2) &= 0xC00Fu;
      if ( *(_DWORD *)(v23 + 88) )
      {
        AlpcpGetDataFromUserVaSafe(v23, v25 + 6);
      }
      else
      {
        v30 = *(unsigned __int16 *)(v23 + 120);
        v31 = v23 + 144;
        v32 = (int)(v25 + 6);
        if ( v30 > 0x100 )
        {
          memmove(v32, v31, 0x100u);
          v30 = *(unsigned __int16 *)(v23 + 120) - 256;
          v31 = *(_DWORD *)(v23 + 108);
          v32 = (int)(v25 + 70);
        }
        memmove(v32, v31, v30);
      }
      if ( a4 )
      {
        v33 = *(_DWORD *)a4;
        *(_DWORD *)(a4 + 4) = 0;
        v34 = v73;
        v35 = v33 & v73;
        if ( (v33 & v73) != 0 && *(_DWORD *)(v23 + 72) )
        {
          *(_DWORD *)(a4 + 8) = 0;
          *(_DWORD *)(a4 + 16) = *(_DWORD *)(*(_DWORD *)(v23 + 72) + 4);
          *(_DWORD *)(a4 + 4) |= v34;
        }
        v36 = v72;
        if ( (v33 & v72) != 0 )
        {
          v37 = 8;
          if ( (v35 & v34) != 0 )
            v37 = 20;
          v38 = (_DWORD *)(v37 + a4);
          v79 = (_DWORD *)(v37 + a4);
          v39 = *(_DWORD *)(v23 + 76);
          if ( v39 )
          {
            v40 = *(_DWORD *)(v39 + 8);
            v81 = v40;
            v41 = *(_DWORD *)(v40 - 12);
            while ( v41 > 0 )
            {
              v42 = v41;
              __dmb(0xBu);
              v43 = (unsigned int *)(v40 - 12);
              do
                v44 = __ldrex(v43);
              while ( v44 == v41 && __strex(v41 + 1, v43) );
              v41 = v44;
              __dmb(0xBu);
              if ( v44 == v42 )
              {
                v38 = v79;
                goto LABEL_86;
              }
              v38 = v79;
              v40 = v81;
            }
            if ( v41 )
              KeBugCheckEx(24, 0, v40, 32, v41);
LABEL_86:
            v85 = AlpcpReceiveView((int)v71, v23, &v69);
            __dmb(0xBu);
            v45 = v81;
            v46 = (unsigned int *)(v81 - 12);
            do
            {
              v47 = __ldrex(v46);
              v48 = v47 - 1;
            }
            while ( __strex(v48, v46) );
            __dmb(0xBu);
            if ( v48 <= 0 )
            {
              if ( v48 )
                KeBugCheckEx(24, 0, v45, 33, v48);
              AlpcpDestroyBlob(v45);
            }
            if ( v85 < 0 )
            {
              v36 = v72;
            }
            else
            {
              v49 = *(_DWORD *)(v23 + 76);
              *v38 = 0;
              v38[1] = 0;
              v38[2] = 0;
              v38[3] = 0;
              v38[2] = *(_DWORD *)(v49 + 20);
              v38[3] = *(_DWORD *)(v49 + 24);
              if ( v69 )
                *v38 = 0x40000;
              v36 = v72;
              *(_DWORD *)(a4 + 4) |= v72;
            }
          }
          v34 = v73;
        }
        v50 = v75;
        if ( (v33 & v75) != 0 )
        {
          v51 = 8;
          if ( (v33 & 0xC0000000 & v34) != 0 )
            v51 = 20;
          if ( (v33 & 0xC0000000 & v36) != 0 )
            v51 += 16;
          v52 = (_DWORD *)(v51 + a4);
          v53 = v71;
          if ( *(_DWORD **)(v23 + 32) == v71 || *(_DWORD **)(v23 + 36) == v71 )
            v54 = *(_DWORD *)(v23 + 68);
          else
            v54 = *(_DWORD *)(v23 + 64);
          *v52 = v54;
          if ( *(_DWORD **)(v23 + 32) == v53 || *(_DWORD **)(v23 + 36) == v53 )
            v55 = *(_DWORD *)(v23 + 40);
          else
            v55 = *(_DWORD *)(v23 + 24);
          v52[2] = v55;
          if ( (v53[61] & 6) == 4 )
            v56 = *(_DWORD *)(v23 + 56);
          else
            v56 = *(_DWORD *)(v23 + 60);
          v52[1] = v56;
          v52[3] = *(_DWORD *)(v23 + 136);
          v52[4] = *(_DWORD *)(v23 + 140);
          if ( *v52 )
            *(_DWORD *)(a4 + 4) |= v50;
        }
        else
        {
          v53 = v71;
        }
        if ( (v33 & v76) != 0 )
        {
          v57 = 8;
          v58 = v33 & 0xE0000000;
          if ( (v33 & 0xE0000000 & v34) != 0 )
            v57 = 20;
          if ( (v58 & v36) != 0 )
            v57 += 16;
          if ( (v58 & v50) != 0 )
            v57 += 20;
          AlpcpExposeHandleAttribute(v53, v23, v57 + a4, a4 + 4);
          v50 = v75;
        }
        if ( (v33 & v78) != 0 )
        {
          v59 = 8;
          v60 = v33 & 0xF0000000;
          if ( (v33 & 0xF0000000 & v34) != 0 )
            v59 = 20;
          if ( (v60 & v72) != 0 )
            v59 += 16;
          if ( (v60 & v50) != 0 )
            v59 += 20;
          if ( (v60 & v76) != 0 )
            v59 += 16;
          AlpcpExposeTokenAttribute(v71, v23, v59 + a4, a4 + 4);
        }
      }
    }
    v61 = v71;
    if ( v22 != -1073741789 && *(_DWORD **)(v23 + 36) == v71 )
    {
      *(_DWORD *)(v23 + 36) = 0;
      *(_DWORD *)(v23 + 32) = 0;
    }
    if ( v22 >= 0 || v22 == -1073741789 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v23);
      v62 = 0;
      if ( (*(_BYTE *)(v23 - 16) & 1) != 0 )
      {
        v62 = 0x10000 - *(__int16 *)(v23 - 14);
        *(_BYTE *)(v23 - 16) &= 0xFEu;
        *(_WORD *)(v23 - 14) = 0;
      }
      v63 = (unsigned int *)(v23 - 4);
      __dmb(0xBu);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 - 1, v63) );
      if ( (v64 & 2) != 0 && (v64 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v23 - 4));
      KeAbPostRelease(v23 - 4);
      if ( v62 > 0 )
      {
        __dmb(0xBu);
        v65 = (unsigned int *)(v23 - 12);
        do
        {
          v66 = __ldrex(v65);
          v67 = v66 - v62;
        }
        while ( __strex(v67, v65) );
        __dmb(0xBu);
        if ( v67 <= 0 )
        {
          if ( v67 )
            KeBugCheckEx(24, 0, v23, 40, v67);
          AlpcpDestroyBlob(v23);
        }
      }
    }
    else
    {
      *(_DWORD *)(v23 + 100) = 0;
      AlpcpCancelMessage(v61, v23, 0x10000);
    }
  }
  return v22;
}
