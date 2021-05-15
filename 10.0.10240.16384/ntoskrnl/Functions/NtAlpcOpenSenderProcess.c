// NtAlpcOpenSenderProcess 
 
int __fastcall NtAlpcOpenSenderProcess(_DWORD *a1, int a2, int *a3, int a4, int a5, _DWORD *a6)
{
  int *v6; // r5
  int v8; // r3
  int v9; // r10
  int v10; // r0
  int v11; // r4
  _DWORD *v12; // r2
  int v13; // r1
  int v14; // r6
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int *v19; // r5
  int v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r3
  int v25; // r4
  int v26; // r9
  unsigned int *v27; // r8
  unsigned int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v32; // r5
  int v33; // r9
  unsigned int *v34; // r8
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r0
  int v39; // r9
  int *v40; // r10
  int v41; // r9
  unsigned int *v42; // r8
  unsigned int v43; // r1
  unsigned int *v44; // r2
  unsigned int v45; // r0
  int v46; // r0
  unsigned int *v47; // r5
  int v48; // r0
  int v49; // r9
  unsigned int v50; // r2
  unsigned int v51; // r2
  int v52; // r9
  unsigned int *v53; // r8
  unsigned int v54; // r1
  unsigned int *v55; // r2
  unsigned int v56; // r0
  int v57; // r0
  unsigned int v58; // r2
  int v59; // r9
  unsigned int *v60; // r8
  unsigned int v61; // r1
  unsigned int *v62; // r2
  unsigned int v63; // r0
  int v64; // r0
  unsigned int v65; // r2
  char v66; // r2
  unsigned int *v67; // r10
  unsigned int v68; // r1
  _DWORD *v69; // r3
  unsigned int *v70; // r2
  unsigned int v71; // r0
  int v72; // r0
  unsigned int v73; // r1
  __int16 v74; // r3
  _DWORD *v76; // [sp+Ch] [bp-64h] BYREF
  int v77; // [sp+10h] [bp-60h]
  _DWORD *v78; // [sp+14h] [bp-5Ch]
  int v79; // [sp+18h] [bp-58h] BYREF
  _DWORD v80[2]; // [sp+20h] [bp-50h] BYREF
  int v81[2]; // [sp+28h] [bp-48h] BYREF
  int v82; // [sp+30h] [bp-40h]
  int v83; // [sp+34h] [bp-3Ch]
  _DWORD _38[20]; // [sp+38h] [bp-38h] BYREF

  _38[17] = a2;
  _38[18] = a3;
  _38[19] = a4;
  v6 = a3;
  v78 = a1;
  _38[16] = a1;
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v77 = v9;
  v10 = ObReferenceObjectByHandle(a2, 0x20000, AlpcPortObjectType, v9, &v76);
  v11 = v10;
  if ( v10 < 0 )
    goto LABEL_144;
  if ( v9 )
  {
    v12 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
    if ( (unsigned int)v6 >= MmUserProbeAddress )
      v6 = (int *)MmUserProbeAddress;
    memmove((int)v80, (int)v6, 0x18u);
    v13 = (int)a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v13 = MmUserProbeAddress;
    memmove((int)_38, v13, 0x18u);
    v14 = (int)v76;
  }
  else
  {
    v15 = *v6;
    v16 = v6[1];
    v17 = v6[2];
    v18 = v6[3];
    v19 = v6 + 4;
    v80[0] = v15;
    v80[1] = v16;
    v81[0] = v17;
    v81[1] = v18;
    v20 = v19[1];
    v82 = *v19;
    v83 = v20;
    v21 = a6[1];
    v22 = a6[2];
    v23 = a6[3];
    _38[0] = *a6;
    _38[1] = v21;
    _38[2] = v22;
    _38[3] = v23;
    v24 = a6[5];
    _38[4] = a6[4];
    _38[5] = v24;
    v14 = (int)v76;
  }
  v11 = AlpcpLookupMessage(v14, v82, v83, &v76);
  if ( v11 < 0 )
  {
    v10 = ObfDereferenceObject(v14);
    goto LABEL_144;
  }
  v25 = (int)v76;
  if ( (v76[5] & 0x80) != 0 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v76);
    v26 = 0;
    if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
    {
      v26 = 0x10000 - *(__int16 *)(v25 - 14);
      *(_BYTE *)(v25 - 16) &= 0xFEu;
      *(_WORD *)(v25 - 14) = 0;
    }
    v27 = (unsigned int *)(v25 - 4);
    __dmb(0xBu);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 - 1, v27) );
    if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v25 - 4));
    KeAbPostRelease(v25 - 4);
    if ( v26 > 0 )
    {
      __dmb(0xBu);
      v29 = (unsigned int *)(v25 - 12);
      do
      {
        v30 = __ldrex(v29);
        v31 = v30 - v26;
      }
      while ( __strex(v31, v29) );
      __dmb(0xBu);
      if ( v31 <= 0 )
      {
        if ( v31 )
          KeBugCheckEx(24, 0, v25, 40, v31);
        AlpcpDestroyBlob(v25);
      }
    }
    v10 = ObfDereferenceObject(v14);
    v11 = -1073740029;
    goto LABEL_144;
  }
  v32 = v76[4];
  if ( v32 )
  {
    if ( RtlCompareMemory((unsigned __int8 *)(v32 + 876), (int)v81, 8) != 8 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v25);
      v33 = 0;
      if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
      {
        v33 = 0x10000 - *(__int16 *)(v25 - 14);
        *(_BYTE *)(v25 - 16) &= 0xFEu;
        *(_WORD *)(v25 - 14) = 0;
      }
      v34 = (unsigned int *)(v25 - 4);
      __dmb(0xBu);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 - 1, v34) );
      if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v25 - 4));
      KeAbPostRelease(v25 - 4);
      if ( v33 > 0 )
      {
        __dmb(0xBu);
        v36 = (unsigned int *)(v25 - 12);
        do
        {
          v37 = __ldrex(v36);
          v38 = v37 - v33;
        }
        while ( __strex(v38, v36) );
        __dmb(0xBu);
        if ( v38 <= 0 )
        {
          if ( v38 )
            KeBugCheckEx(24, 0, v25, 40, v38);
          AlpcpDestroyBlob(v25);
        }
      }
      v10 = ObfDereferenceObject(v14);
      v11 = -1073741813;
      goto LABEL_144;
    }
    v39 = *(_DWORD *)(v32 + 336);
    ObfReferenceObjectWithTag(v39);
    goto LABEL_126;
  }
  v40 = (int *)v76[3];
  if ( !v40 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v76);
    v41 = 0;
    if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
    {
      v41 = 0x10000 - *(__int16 *)(v25 - 14);
      *(_BYTE *)(v25 - 16) &= 0xFEu;
      *(_WORD *)(v25 - 14) = 0;
    }
    v42 = (unsigned int *)(v25 - 4);
    __dmb(0xBu);
    do
      v43 = __ldrex(v42);
    while ( __strex(v43 - 1, v42) );
    if ( (v43 & 2) != 0 && (v43 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v25 - 4));
    KeAbPostRelease(v25 - 4);
    if ( v41 <= 0 )
      goto LABEL_68;
    __dmb(0xBu);
    v44 = (unsigned int *)(v25 - 12);
    do
    {
      v45 = __ldrex(v44);
      v46 = v45 - v41;
    }
    while ( __strex(v46, v44) );
    __dmb(0xBu);
    if ( v46 > 0 )
      goto LABEL_68;
    if ( v46 )
      KeBugCheckEx(24, 0, v25, 40, v46);
    goto LABEL_67;
  }
  v47 = (unsigned int *)(v40 + 52);
  v48 = KeAbPreAcquire((unsigned int)(v40 + 52), 0, 0);
  v49 = v48;
  do
    v50 = __ldrex(v47);
  while ( !v50 && __strex(0x11u, v47) );
  __dmb(0xBu);
  if ( v50 )
    ExfAcquirePushLockSharedEx(v40 + 52, v48, (unsigned int)(v40 + 52));
  if ( v49 )
    *(_BYTE *)(v49 + 14) |= 1u;
  if ( (v40[61] & 0x40) == 0 )
  {
    v39 = v40[3];
    if ( *(_DWORD *)(v39 + 176) == v81[0] )
    {
      ObfReferenceObjectWithTag(v40[3]);
      __dmb(0xBu);
      do
        v65 = __ldrex(v47);
      while ( v65 == 17 && __strex(0, v47) );
      if ( v65 != 17 )
        ExfReleasePushLockShared(v40 + 52);
      KeAbPostRelease((unsigned int)(v40 + 52));
LABEL_126:
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v25);
      v76 = 0;
      v66 = *(_BYTE *)(v25 - 16);
      if ( (v66 & 1) != 0 )
      {
        v76 = (_DWORD *)(0x10000 - *(__int16 *)(v25 - 14));
        *(_BYTE *)(v25 - 16) = v66 & 0xFE;
        *(_WORD *)(v25 - 14) = 0;
      }
      v67 = (unsigned int *)(v25 - 4);
      __dmb(0xBu);
      do
        v68 = __ldrex(v67);
      while ( __strex(v68 - 1, v67) );
      if ( (v68 & 2) != 0 && (v68 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v25 - 4));
      KeAbPostRelease(v25 - 4);
      v69 = v76;
      if ( (int)v76 > 0 )
      {
        __dmb(0xBu);
        v70 = (unsigned int *)(v25 - 12);
        do
        {
          v71 = __ldrex(v70);
          v72 = v71 - (_DWORD)v69;
        }
        while ( __strex(v72, v70) );
        __dmb(0xBu);
        if ( v72 <= 0 )
        {
          if ( v72 )
            KeBugCheckEx(24, 0, v25, 40, v72);
          AlpcpDestroyBlob(v25);
        }
      }
      v11 = PsOpenProcess((unsigned int)&v79, a5, (int)_38, v81, 0, v77);
      ObfDereferenceObjectWithTag(v39);
      v10 = ObfDereferenceObject(v14);
      if ( v11 >= 0 )
        *v78 = v79;
      goto LABEL_144;
    }
    __dmb(0xBu);
    do
      v58 = __ldrex(v47);
    while ( v58 == 17 && __strex(0, v47) );
    if ( v58 != 17 )
      ExfReleasePushLockShared(v40 + 52);
    KeAbPostRelease((unsigned int)(v40 + 52));
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v25);
    v59 = 0;
    if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
    {
      v59 = 0x10000 - *(__int16 *)(v25 - 14);
      *(_BYTE *)(v25 - 16) &= 0xFEu;
      *(_WORD *)(v25 - 14) = 0;
    }
    v60 = (unsigned int *)(v25 - 4);
    __dmb(0xBu);
    do
      v61 = __ldrex(v60);
    while ( __strex(v61 - 1, v60) );
    if ( (v61 & 2) != 0 && (v61 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v25 - 4));
    KeAbPostRelease(v25 - 4);
    if ( v59 <= 0 )
      goto LABEL_68;
    __dmb(0xBu);
    v62 = (unsigned int *)(v25 - 12);
    do
    {
      v63 = __ldrex(v62);
      v64 = v63 - v59;
    }
    while ( __strex(v64, v62) );
    __dmb(0xBu);
    if ( v64 > 0 )
    {
LABEL_68:
      v10 = ObfDereferenceObject(v14);
      v11 = -1073741790;
      goto LABEL_144;
    }
    if ( v64 )
      KeBugCheckEx(24, 0, v25, 40, v64);
LABEL_67:
    AlpcpDestroyBlob(v25);
    goto LABEL_68;
  }
  __dmb(0xBu);
  do
    v51 = __ldrex(v47);
  while ( v51 == 17 && __strex(0, v47) );
  if ( v51 != 17 )
    ExfReleasePushLockShared(v40 + 52);
  KeAbPostRelease((unsigned int)(v40 + 52));
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v25);
  v52 = 0;
  if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
  {
    v52 = 0x10000 - *(__int16 *)(v25 - 14);
    *(_BYTE *)(v25 - 16) &= 0xFEu;
    *(_WORD *)(v25 - 14) = 0;
  }
  v53 = (unsigned int *)(v25 - 4);
  __dmb(0xBu);
  do
    v54 = __ldrex(v53);
  while ( __strex(v54 - 1, v53) );
  if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v25 - 4));
  KeAbPostRelease(v25 - 4);
  if ( v52 > 0 )
  {
    __dmb(0xBu);
    v55 = (unsigned int *)(v25 - 12);
    do
    {
      v56 = __ldrex(v55);
      v57 = v56 - v52;
    }
    while ( __strex(v57, v55) );
    __dmb(0xBu);
    if ( v57 <= 0 )
    {
      if ( v57 )
        KeBugCheckEx(24, 0, v25, 40, v57);
      AlpcpDestroyBlob(v25);
    }
  }
  v10 = ObfDereferenceObject(v14);
  v11 = -1073741769;
LABEL_144:
  v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v74 = *(_WORD *)(v73 + 0x134) + 1;
  *(_WORD *)(v73 + 308) = v74;
  if ( !v74 && *(_DWORD *)(v73 + 100) != v73 + 100 && !*(_WORD *)(v73 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v11;
}
