// AlpcpProcessConnectionRequest 
 
int __fastcall AlpcpProcessConnectionRequest(int a1, int a2, unsigned int a3, int *a4, int a5, unsigned int a6, unsigned int a7, char a8, char a9)
{
  _DWORD *v10; // r8
  int v12; // r5
  int v13; // r1
  _BYTE *v14; // r0
  int *v15; // r2
  int *v16; // r2
  unsigned int v17; // r9
  int *v18; // r3
  int v19; // r1
  unsigned int v20; // r2
  __int64 *v21; // r6
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r10
  int v27; // r0
  int v28; // r5
  int v29; // r0
  int v30; // r10
  int v31; // r8
  unsigned int *v32; // r6
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r4
  int v36; // r4
  int v37; // r0
  int v38; // r0
  int v39; // r1
  int v40; // r6
  unsigned int v41; // r2
  int v42; // r10
  unsigned int *v43; // r8
  unsigned int v44; // r1
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r0
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r3
  int v52; // r5
  unsigned int v53; // r2
  int v54; // r1
  int v55; // r0
  int v56; // r8
  unsigned int *v57; // r5
  unsigned int v58; // r1
  unsigned int *v59; // r2
  unsigned int v60; // r0
  int v61; // r0
  int v63; // [sp+18h] [bp-78h] BYREF
  unsigned int v64; // [sp+1Ch] [bp-74h]
  int v65; // [sp+20h] [bp-70h]
  _DWORD *v66; // [sp+28h] [bp-68h]
  unsigned int v67; // [sp+2Ch] [bp-64h]
  int v68; // [sp+30h] [bp-60h]
  int v69; // [sp+34h] [bp-5Ch]
  unsigned int v70; // [sp+38h] [bp-58h]
  __int64 v71; // [sp+40h] [bp-50h]
  __int64 v72; // [sp+48h] [bp-48h] BYREF
  _DWORD _50[22]; // [sp+50h] [bp-40h] BYREF

  v66 = a4;
  _50[21] = a4;
  v10 = (_DWORD *)a3;
  _50[20] = a3;
  v68 = a2;
  _50[19] = a2;
  v65 = a1;
  _50[18] = a1;
  if ( (a2 & 0x10000) != 0 )
    return -1073741811;
  v64 = 0;
  v69 = 0;
  v67 = -1;
  v70 = -1;
  v12 = a8;
  v63 = a8;
  if ( a8 )
  {
    if ( a3 )
    {
      if ( (a3 & 7) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a3 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a3 = *(_BYTE *)a3;
      *(_BYTE *)(a3 + 16) = *(_BYTE *)(a3 + 16);
      v13 = a3;
      if ( a3 >= MmUserProbeAddress )
        v13 = MmUserProbeAddress;
      v14 = (_BYTE *)memmove((int)_50, v13, 0x18u);
    }
    else
    {
      v14 = memset(_50, 0, 24);
    }
    if ( a4 )
    {
      v15 = a4;
      if ( (unsigned int)a4 >= MmUserProbeAddress )
        v15 = (int *)MmUserProbeAddress;
      v67 = *v15;
      v70 = v67;
      v16 = a4;
      if ( (unsigned int)a4 >= MmUserProbeAddress )
        v16 = (int *)MmUserProbeAddress;
      *v16 = *v16;
    }
    v17 = a6;
    if ( a6 )
    {
      v18 = (int *)a6;
      if ( a6 >= MmUserProbeAddress )
        v18 = (int *)MmUserProbeAddress;
      v19 = *v18;
      v20 = 8;
      if ( *v18 < 0 )
        v20 = 20;
      if ( (v19 & 0x40000000) != 0 )
        v20 += 16;
      if ( (v19 & 0x20000000) != 0 )
        v20 += 20;
      if ( (v19 & 0x10000000) != 0 )
        v20 += 16;
      if ( (v19 & 0x8000000) != 0 )
        v20 += 24;
      if ( (v19 & 0x4000000) != 0 )
        v20 += 4;
      if ( (a6 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v14);
      if ( a6 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a6 = *(_BYTE *)a6;
      if ( v20 > 4 )
        *(_BYTE *)(((v20 - 1) & 0xFFFFFFFC) + a6) = *(_BYTE *)(((v20 - 1) & 0xFFFFFFFC) + a6);
      v64 = v19;
      v69 = v19;
    }
    v21 = (__int64 *)a7;
    if ( a7 )
    {
      if ( a7 >= MmUserProbeAddress )
        v21 = (__int64 *)MmUserProbeAddress;
      v71 = *v21;
      v72 = v71;
      v21 = &v72;
    }
    v12 = v63;
  }
  else
  {
    if ( a3 )
    {
      v22 = *(_DWORD *)(a3 + 4);
      v23 = *(_DWORD *)(a3 + 8);
      v24 = v10[3];
      _50[0] = *v10;
      _50[1] = v22;
      _50[2] = v23;
      _50[3] = v24;
      v25 = v10[5];
      _50[4] = v10[4];
      _50[5] = v25;
      v12 = v63;
    }
    else
    {
      memset(_50, 0, 24);
    }
    if ( a4 )
      v67 = *a4;
    v17 = a6;
    v21 = (__int64 *)a7;
    if ( a6 )
      v64 = *(_DWORD *)a6;
  }
  v26 = v68;
  v27 = AlpcpFormatConnectionRequest(&v63, v68, v65, v10, _50, a5, 0, 0, 0, v12);
  if ( v27 < 0 )
    return v27;
  v28 = v63;
  LODWORD(v71) = *(_DWORD *)(v63 + 136);
  if ( AlpcpLogEnabled )
    AlpcpLogConnectRequest(v63);
  _50[0] = v65;
  _50[1] = v28;
  _50[6] = v26;
  v29 = AlpcpDispatchConnectionRequest(_50);
  v30 = v29;
  if ( v29 < 0 )
  {
    if ( AlpcpLogEnabled )
      AlpcpLogConnectFail(v71, v29);
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v28);
    v31 = 0;
    if ( (*(_BYTE *)(v28 - 16) & 1) != 0 )
    {
      v31 = 0x10000 - *(__int16 *)(v28 - 14);
      *(_BYTE *)(v28 - 16) &= 0xFEu;
      *(_WORD *)(v28 - 14) = 0;
    }
    v32 = (unsigned int *)(v28 - 4);
    __dmb(0xBu);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 - 1, v32) );
    if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v28 - 4));
    KeAbPostRelease(v28 - 4);
    if ( v31 <= 0 )
      return v30;
    __dmb(0xBu);
    v34 = (unsigned int *)(v28 - 12);
    do
    {
      v35 = __ldrex(v34);
      v36 = v35 - v31;
    }
    while ( __strex(v36, v34) );
    __dmb(0xBu);
    if ( v36 > 0 )
      return v30;
    if ( v36 )
      KeBugCheckEx(24, 0, v28, 40, v36);
    v37 = v28;
    goto LABEL_76;
  }
  if ( (v68 & 0x20000) == 0 )
    return v30;
  v63 = 0;
  v38 = AlpcpReceiveSynchronousReply(_50, a9, &v63, v64, v21);
  v30 = v38;
  if ( v38 )
  {
    if ( AlpcpLogEnabled )
      AlpcpLogConnectFail(v71, v38);
    if ( (*(_DWORD *)(v65 + 244) & 0x10) != 0 )
      v30 = -1073741759;
    return v30;
  }
  if ( AlpcpLogEnabled )
    AlpcpLogConnectSuccess(v71);
  v40 = v63;
  v41 = *(unsigned __int16 *)(v63 + 120) + 24;
  v64 = v41;
  if ( !v66 || v41 <= v67 )
  {
    if ( v10 )
    {
      v48 = *(_DWORD *)(v63 + 124);
      v49 = *(_DWORD *)(v63 + 128);
      v50 = *(_DWORD *)(v63 + 132);
      *v10 = *(_DWORD *)(v63 + 120);
      v10[1] = v48;
      v10[2] = v49;
      v10[3] = v50;
      v51 = *(_DWORD *)(v40 + 140);
      v10[4] = *(_DWORD *)(v40 + 136);
      v10[5] = v51;
      v52 = v65;
      if ( (*(_DWORD *)(v65 + 152) & 0x1000) != 0 )
        *((_WORD *)v10 + 2) &= 0xC00Fu;
      if ( *(_DWORD *)(v40 + 88) )
      {
        AlpcpGetDataFromUserVaSafe(v40, v10 + 6);
        v41 = v64;
LABEL_114:
        if ( v66 )
          *v66 = v41;
        if ( v17 )
          AlpcpExposeAttributes(v52, v39, v40, v17);
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v40);
        v56 = 0;
        if ( (*(_BYTE *)(v40 - 16) & 1) != 0 )
        {
          v56 = 0x10000 - *(__int16 *)(v40 - 14);
          *(_BYTE *)(v40 - 16) &= 0xFEu;
          *(_WORD *)(v40 - 14) = 0;
        }
        v57 = (unsigned int *)(v40 - 4);
        __dmb(0xBu);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 - 1, v57) );
        if ( (v58 & 2) != 0 && (v58 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v40 - 4));
        KeAbPostRelease(v40 - 4);
        if ( v56 <= 0 )
          return v30;
        __dmb(0xBu);
        v59 = (unsigned int *)(v40 - 12);
        do
        {
          v60 = __ldrex(v59);
          v61 = v60 - v56;
        }
        while ( __strex(v61, v59) );
        __dmb(0xBu);
        if ( v61 > 0 )
          return v30;
        if ( v61 )
          KeBugCheckEx(24, 0, v40, 40, v61);
        v37 = v40;
LABEL_76:
        AlpcpDestroyBlob(v37);
        return v30;
      }
      v53 = *(unsigned __int16 *)(v40 + 120);
      v54 = v40 + 144;
      v55 = (int)(v10 + 6);
      if ( v53 > 0x100 )
      {
        memmove(v55, v54, 0x100u);
        v53 = *(unsigned __int16 *)(v40 + 120) - 256;
        v54 = *(_DWORD *)(v40 + 108);
        v55 = (int)(v10 + 70);
      }
      memmove(v55, v54, v53);
      v41 = v64;
    }
    v52 = v65;
    goto LABEL_114;
  }
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v63);
  v42 = 0;
  if ( (*(_BYTE *)(v40 - 16) & 1) != 0 )
  {
    v42 = 0x10000 - *(__int16 *)(v40 - 14);
    *(_BYTE *)(v40 - 16) &= 0xFEu;
    *(_WORD *)(v40 - 14) = 0;
  }
  v43 = (unsigned int *)(v40 - 4);
  __dmb(0xBu);
  do
    v44 = __ldrex(v43);
  while ( __strex(v44 - 1, v43) );
  if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v40 - 4));
  KeAbPostRelease(v40 - 4);
  if ( v42 > 0 )
  {
    __dmb(0xBu);
    v45 = (unsigned int *)(v40 - 12);
    do
    {
      v46 = __ldrex(v45);
      v47 = v46 - v42;
    }
    while ( __strex(v47, v45) );
    __dmb(0xBu);
    if ( v47 <= 0 )
    {
      if ( v47 )
        KeBugCheckEx(24, 0, v40, 40, v47);
      AlpcpDestroyBlob(v40);
    }
  }
  *v66 = v64;
  return -1073741789;
}
