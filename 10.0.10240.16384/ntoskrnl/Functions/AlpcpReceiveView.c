// AlpcpReceiveView 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AlpcpReceiveView(int a1, int a2, bool *a3)
{
  _DWORD *v3; // r5 OVERLAPPED
  int v5; // r7
  unsigned __int8 *v6; // r9
  int v7; // r0
  unsigned int v8; // r4
  unsigned int *v10; // r1
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r0
  int *v14; // r6 OVERLAPPED
  int v15; // r0
  int v16; // r3
  int v17; // r4
  bool v18; // zf
  unsigned int *v19; // lr
  int v20; // r0
  int v21; // r1
  int v22; // r9
  int v23; // r2
  int v24; // r3
  unsigned int *v25; // r2
  unsigned int v26; // r1
  int v27; // r1
  int v28; // r6
  char v29; // r2
  int v30; // r3
  unsigned int *v31; // r4
  unsigned int v32; // r1
  unsigned int *v33; // r2
  unsigned int v34; // r0
  int v35; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r1
  int v38; // r1
  int v39; // r0
  bool v40; // zf
  unsigned int *v41; // lr
  int v42; // r4
  int v43; // r1
  int v44; // r6
  unsigned int *v45; // r4
  unsigned int v46; // r1
  unsigned int *v47; // r2
  unsigned int v48; // r0
  int v49; // r0
  unsigned __int8 *v50; // r6
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r2
  unsigned int *v54; // r2
  unsigned int v55; // r1
  int v56; // r1
  int v57; // r0
  int v58; // r3
  unsigned int *v59; // r2
  unsigned int v60; // r1
  int v61; // r1
  int v62; // r3
  int v63; // r3
  int v64; // r2
  bool v65; // zf
  unsigned int *v66; // lr
  int v67; // r4
  int v68; // r0
  int v69; // r3
  unsigned int *v70; // r2
  unsigned int v71; // r1
  int v72; // r1
  unsigned int *v73; // r2
  unsigned int v74; // r1
  int v75; // r1
  int *v76; // [sp+8h] [bp-48h] BYREF
  int v77; // [sp+Ch] [bp-44h]
  bool *v78; // [sp+10h] [bp-40h]
  char v79[56]; // [sp+18h] [bp-38h] BYREF

  v3 = *(_DWORD **)(a2 + 76);
  v77 = a2;
  v78 = a3;
  v5 = v3[2];
  v6 = (unsigned __int8 *)(v5 - 4);
  v7 = KeAbPreAcquire(v5 - 4, 0, 0);
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 | 1, v6) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7F5E38(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *(_BYTE *)(v5 - 16) |= 1u;
  __dmb(0xBu);
  v10 = (unsigned int *)(v5 - 12);
  do
  {
    v11 = __ldrex(v10);
    v12 = v11 + 0x10000;
  }
  while ( __strex(v12, v10) );
  __dmb(0xBu);
  if ( v12 <= 0 )
    KeBugCheckEx(24, 0, v5, 38, v12);
  while ( 1 )
  {
    v13 = AlpcpLocateView(v5, a1);
    v14 = (int *)v13;
    v76 = (int *)v13;
    if ( !v13 )
      break;
    v39 = *(_DWORD *)(v13 - 12);
    v40 = v39 == 0;
    if ( v39 <= 0 )
    {
LABEL_62:
      if ( !v40 )
        KeBugCheckEx(24, 0, (int)v14, 32, v39);
    }
    else
    {
      v41 = (unsigned int *)(v14 - 3);
      while ( 1 )
      {
        v42 = v39;
        __dmb(0xBu);
        do
          v43 = __ldrex(v41);
        while ( v43 == v39 && __strex(v39 + 1, v41) );
        v39 = v43;
        __dmb(0xBu);
        if ( v43 == v42 )
          break;
        if ( v43 <= 0 )
        {
          v40 = v43 == 0;
          goto LABEL_62;
        }
      }
      if ( v43 + 1 > 0 )
        break;
    }
    v44 = 0;
    if ( (*(_BYTE *)(v5 - 16) & 1) != 0 )
    {
      v44 = 0x10000 - *(__int16 *)(v5 - 14);
      *(_BYTE *)(v5 - 16) &= 0xFEu;
      *(_WORD *)(v5 - 14) = 0;
    }
    v45 = (unsigned int *)(v5 - 4);
    __dmb(0xBu);
    do
      v46 = __ldrex(v45);
    while ( __strex(v46 - 1, v45) );
    if ( (v46 & 2) != 0 && (v46 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v5 - 4));
    KeAbPostRelease(v5 - 4);
    if ( v44 > 0 )
    {
      __dmb(0xBu);
      v47 = (unsigned int *)(v5 - 12);
      do
      {
        v48 = __ldrex(v47);
        v49 = v48 - v44;
      }
      while ( __strex(v49, v47) );
      __dmb(0xBu);
      if ( v49 <= 0 )
      {
        if ( v49 )
          KeBugCheckEx(24, 0, v5, 40, v49);
        AlpcpDestroyBlob(v5);
      }
    }
    v50 = (unsigned __int8 *)(v5 - 4);
    v51 = KeAbPreAcquire(v5 - 4, 0, 0);
    v52 = v51;
    do
      v53 = __ldrex(v50);
    while ( __strex(v53 | 1, v50) );
    __dmb(0xBu);
    if ( (v53 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 - 4), v51, v5 - 4);
    if ( v52 )
      *(_BYTE *)(v52 + 14) |= 1u;
    *(_BYTE *)(v5 - 16) |= 1u;
    __dmb(0xBu);
    v54 = (unsigned int *)(v5 - 12);
    do
    {
      v55 = __ldrex(v54);
      v56 = v55 + 0x10000;
    }
    while ( __strex(v56, v54) );
    __dmb(0xBu);
    if ( v56 <= 0 )
      KeBugCheckEx(24, 0, v5, 38, v56);
  }
  if ( (*(_DWORD *)(v5 + 24) & 1) == 0 )
  {
    if ( !v14 )
    {
      v22 = AlpcpCreateView(v5, a1, &v76);
      if ( v22 >= 0 )
      {
        v14 = v76;
        goto LABEL_24;
      }
      goto LABEL_48;
    }
LABEL_52:
    v22 = 0;
    goto LABEL_24;
  }
  if ( v14 == *(int **)(v5 + 44) )
    goto LABEL_52;
  if ( v14 && v14 == *(int **)(v5 + 40) )
  {
    v57 = MmSecureVirtualMemoryAgainstWrites(v3[4], v3[5], v3[6]);
    if ( v57 )
    {
      v63 = v3[9];
      v3[8] = v57;
      v3[9] = v63 & 0xFFFFFFFE;
      v64 = *(v3 - 3);
      v65 = v64 == 0;
      if ( v64 <= 0 )
      {
LABEL_108:
        if ( !v65 )
          KeBugCheckEx(24, 0, (int)v3, 32, v64);
      }
      else
      {
        v66 = v3 - 3;
        while ( 1 )
        {
          v67 = v64;
          __dmb(0xBu);
          do
            v68 = __ldrex(v66);
          while ( v68 == v64 && __strex(v64 + 1, v66) );
          v64 = v68;
          __dmb(0xBu);
          if ( v68 == v67 )
            break;
          if ( v68 <= 0 )
          {
            v65 = v68 == 0;
            goto LABEL_108;
          }
        }
      }
      KiStackAttachProcess(v14[4], 0, (int)v79);
      MmUnsecureVirtualMemory(v14[8]);
      KiUnstackDetachProcess((unsigned int)v79, 0);
      v69 = v14[9] | 1;
      v14[8] = 0;
      v14[9] = v69;
      *(_QWORD *)(v5 + 40) = *(_QWORD *)&v3;
      __dmb(0xBu);
      v70 = (unsigned int *)(v14 - 3);
      do
      {
        v71 = __ldrex(v70);
        v72 = v71 - 1;
      }
      while ( __strex(v72, v70) );
      __dmb(0xBu);
      if ( v72 <= 0 )
      {
        if ( v72 )
          KeBugCheckEx(24, 0, (int)v14, 33, v72);
        AlpcpDestroyBlob(v14);
      }
    }
    else
    {
      KiStackAttachProcess(v14[4], 0, (int)v79);
      MmUnsecureVirtualMemory(v14[8]);
      KiUnstackDetachProcess((unsigned int)v79, 0);
      v58 = v14[9] | 1;
      v14[8] = 0;
      v14[9] = v58;
      __dmb(0xBu);
      v59 = (unsigned int *)(v14 - 3);
      do
      {
        v60 = __ldrex(v59);
        v61 = v60 - 1;
      }
      while ( __strex(v61, v59) );
      __dmb(0xBu);
      if ( v61 <= 0 )
      {
        if ( v61 )
          KeBugCheckEx(24, 0, (int)v14, 33, v61);
        AlpcpDestroyBlob(v14);
      }
      v62 = *(_DWORD *)(v5 + 24);
      *(_DWORD *)(v5 + 40) = 0;
      *(_DWORD *)(v5 + 44) = 0;
      *(_DWORD *)(v5 + 24) = v62 & 0xFFFFFFFE;
    }
    goto LABEL_99;
  }
  v15 = MmSecureVirtualMemoryAgainstWrites(v3[4], v3[5], v3[6]);
  if ( v15 )
  {
    v16 = v3[9];
    v3[8] = v15;
    v3[9] = v16 & 0xFFFFFFFE;
    v17 = *(v3 - 3);
    v18 = v17 == 0;
    if ( v17 <= 0 )
    {
LABEL_117:
      if ( !v18 )
        KeBugCheckEx(24, 0, (int)v3, 32, v17);
    }
    else
    {
      v19 = v3 - 3;
      while ( 1 )
      {
        v20 = v17;
        __dmb(0xBu);
        do
          v21 = __ldrex(v19);
        while ( v21 == v17 && __strex(v17 + 1, v19) );
        v17 = v21;
        __dmb(0xBu);
        if ( v21 == v20 )
          break;
        if ( v21 <= 0 )
        {
          v18 = v21 == 0;
          goto LABEL_117;
        }
      }
    }
    *(_DWORD *)(v5 + 40) = v3;
    *(_DWORD *)(v5 + 44) = 0;
    if ( v14 )
    {
      *(_DWORD *)(v5 + 44) = v14;
LABEL_99:
      v22 = 0;
      goto LABEL_24;
    }
    v22 = AlpcpCreateView(v5, a1, &v76);
    if ( v22 >= 0 )
      goto LABEL_23;
    AlpcpRestoreWriteAccess(v3);
    __dmb(0xBu);
    v73 = v3 - 3;
    do
    {
      v74 = __ldrex(v73);
      v75 = v74 - 1;
    }
    while ( __strex(v75, v73) );
    __dmb(0xBu);
    if ( v75 <= 0 )
    {
      if ( v75 )
        KeBugCheckEx(24, 0, (int)v3, 33, v75);
      AlpcpDestroyBlob(v3);
    }
LABEL_48:
    *(_DWORD *)(v77 + 76) = 0;
    goto LABEL_25;
  }
  *(_DWORD *)(v5 + 24) &= 0xFFFFFFFE;
  *(_DWORD *)(v5 + 40) = 0;
  *(_DWORD *)(v5 + 44) = 0;
  v22 = AlpcpCreateView(v5, a1, &v76);
  if ( v22 < 0 )
    goto LABEL_48;
LABEL_23:
  v14 = v76;
LABEL_24:
  v23 = v77;
  v24 = *(_DWORD *)(v77 + 20);
  *(_DWORD *)(v77 + 76) = v14;
  *(_DWORD *)(v23 + 20) = v24 | 0x8000;
  ++v14[10];
LABEL_25:
  --v3[10];
  if ( (v3[9] & 2) != 0 )
  {
    if ( AlpcpDeleteBlob(v3) )
    {
      __dmb(0xBu);
      v25 = v3 - 3;
      do
      {
        v26 = __ldrex(v25);
        v27 = v26 - 1;
      }
      while ( __strex(v27, v25) );
      __dmb(0xBu);
      if ( v27 <= 0 )
      {
        if ( v27 )
          KeBugCheckEx(24, 0, (int)v3, 33, v27);
        AlpcpDestroyBlob(v3);
      }
    }
    v3[9] &= 0xFFFFFFFD;
  }
  v28 = 0;
  *v78 = (*(_DWORD *)(v5 + 24) & 1) != 0;
  v29 = *(_BYTE *)(v5 - 16);
  if ( (v29 & 1) != 0 )
  {
    v30 = *(__int16 *)(v5 - 14);
    *(_WORD *)(v5 - 14) = 0;
    v28 = 0x10000 - v30;
    *(_BYTE *)(v5 - 16) = v29 & 0xFE;
  }
  v31 = (unsigned int *)(v5 - 4);
  __dmb(0xBu);
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 - 1, v31) );
  if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v5 - 4));
  KeAbPostRelease(v5 - 4);
  if ( v28 > 0 )
  {
    __dmb(0xBu);
    v33 = (unsigned int *)(v5 - 12);
    do
    {
      v34 = __ldrex(v33);
      v35 = v34 - v28;
    }
    while ( __strex(v35, v33) );
    __dmb(0xBu);
    if ( v35 <= 0 )
    {
      if ( v35 )
        KeBugCheckEx(24, 0, v5, 40, v35);
      AlpcpDestroyBlob(v5);
    }
  }
  __dmb(0xBu);
  v36 = v3 - 3;
  do
  {
    v37 = __ldrex(v36);
    v38 = v37 - 1;
  }
  while ( __strex(v38, v36) );
  __dmb(0xBu);
  if ( v38 <= 0 )
  {
    if ( v38 )
      KeBugCheckEx(24, 0, (int)v3, 33, v38);
    AlpcpDestroyBlob(v3);
  }
  return v22;
}
