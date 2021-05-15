// NtAlpcOpenSenderThread 
 
int __fastcall NtAlpcOpenSenderThread(_DWORD *a1, int a2, int *a3, int a4, int a5, _DWORD *a6)
{
  int *v6; // r5
  int v8; // r3
  int v9; // r9
  int v10; // r0
  int v11; // r4
  _DWORD *v12; // r2
  int v13; // r1
  int v14; // r5
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
  int v32; // r8
  int v33; // r9
  unsigned int *v34; // r8
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r0
  int v39; // r9
  unsigned int *v40; // r8
  unsigned int v41; // r1
  unsigned int *v42; // r2
  unsigned int v43; // r0
  int v44; // r0
  char v45; // r2
  unsigned int *v46; // r9
  unsigned int v47; // r1
  int v48; // r3
  unsigned int *v49; // r2
  unsigned int v50; // r0
  int v51; // r0
  unsigned int v52; // r1
  __int16 v53; // r3
  int v55; // [sp+Ch] [bp-64h] BYREF
  int v56; // [sp+10h] [bp-60h]
  _DWORD *v57; // [sp+14h] [bp-5Ch]
  int v58; // [sp+18h] [bp-58h] BYREF
  _DWORD v59[2]; // [sp+20h] [bp-50h] BYREF
  _DWORD v60[2]; // [sp+28h] [bp-48h] BYREF
  int v61; // [sp+30h] [bp-40h]
  int v62; // [sp+34h] [bp-3Ch]
  _DWORD _38[20]; // [sp+38h] [bp-38h] BYREF

  _38[17] = a2;
  _38[18] = a3;
  _38[19] = a4;
  v6 = a3;
  v57 = a1;
  _38[16] = a1;
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v56 = v9;
  v10 = ObReferenceObjectByHandle(a2, 0x20000, AlpcPortObjectType, v9, &v55);
  v11 = v10;
  if ( v10 < 0 )
    goto LABEL_83;
  if ( v9 )
  {
    v12 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
    if ( (unsigned int)v6 >= MmUserProbeAddress )
      v6 = (int *)MmUserProbeAddress;
    memmove((int)v59, (int)v6, 0x18u);
    v13 = (int)a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v13 = MmUserProbeAddress;
    memmove((int)_38, v13, 0x18u);
    v14 = v55;
  }
  else
  {
    v15 = *v6;
    v16 = v6[1];
    v17 = v6[2];
    v18 = v6[3];
    v19 = v6 + 4;
    v59[0] = v15;
    v59[1] = v16;
    v60[0] = v17;
    v60[1] = v18;
    v20 = v19[1];
    v61 = *v19;
    v62 = v20;
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
    v14 = v55;
  }
  v11 = AlpcpLookupMessage(v14, v61, v62, &v55);
  if ( v11 < 0 )
  {
    v10 = ObfDereferenceObject(v14);
    goto LABEL_83;
  }
  v25 = v55;
  if ( (*(_DWORD *)(v55 + 20) & 0x80) != 0 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v55);
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
    goto LABEL_83;
  }
  v32 = *(_DWORD *)(v55 + 16);
  if ( !v32 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v55);
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
    if ( v33 <= 0 )
      goto LABEL_48;
    __dmb(0xBu);
    v36 = (unsigned int *)(v25 - 12);
    do
    {
      v37 = __ldrex(v36);
      v38 = v37 - v33;
    }
    while ( __strex(v38, v36) );
    __dmb(0xBu);
    if ( v38 > 0 )
      goto LABEL_48;
    if ( v38 )
      KeBugCheckEx(24, 0, v25, 40, v38);
LABEL_47:
    AlpcpDestroyBlob(v25);
LABEL_48:
    v10 = ObfDereferenceObject(v14);
    v11 = -1073741790;
    goto LABEL_83;
  }
  if ( RtlCompareMemory((unsigned __int8 *)(v32 + 876), (int)v60, 8) != 8 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v25);
    v39 = 0;
    if ( (*(_BYTE *)(v25 - 16) & 1) != 0 )
    {
      v39 = 0x10000 - *(__int16 *)(v25 - 14);
      *(_BYTE *)(v25 - 16) &= 0xFEu;
      *(_WORD *)(v25 - 14) = 0;
    }
    v40 = (unsigned int *)(v25 - 4);
    __dmb(0xBu);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 - 1, v40) );
    if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v25 - 4));
    KeAbPostRelease(v25 - 4);
    if ( v39 <= 0 )
      goto LABEL_48;
    __dmb(0xBu);
    v42 = (unsigned int *)(v25 - 12);
    do
    {
      v43 = __ldrex(v42);
      v44 = v43 - v39;
    }
    while ( __strex(v44, v42) );
    __dmb(0xBu);
    if ( v44 > 0 )
      goto LABEL_48;
    if ( v44 )
      KeBugCheckEx(24, 0, v25, 40, v44);
    goto LABEL_47;
  }
  ObfReferenceObject(v32);
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v25);
  v55 = 0;
  v45 = *(_BYTE *)(v25 - 16);
  if ( (v45 & 1) != 0 )
  {
    v55 = 0x10000 - *(__int16 *)(v25 - 14);
    *(_BYTE *)(v25 - 16) = v45 & 0xFE;
    *(_WORD *)(v25 - 14) = 0;
  }
  v46 = (unsigned int *)(v25 - 4);
  __dmb(0xBu);
  do
    v47 = __ldrex(v46);
  while ( __strex(v47 - 1, v46) );
  if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v25 - 4));
  KeAbPostRelease(v25 - 4);
  v48 = v55;
  if ( v55 > 0 )
  {
    __dmb(0xBu);
    v49 = (unsigned int *)(v25 - 12);
    do
    {
      v50 = __ldrex(v49);
      v51 = v50 - v48;
    }
    while ( __strex(v51, v49) );
    __dmb(0xBu);
    if ( v51 <= 0 )
    {
      if ( v51 )
        KeBugCheckEx(24, 0, v25, 40, v51);
      AlpcpDestroyBlob(v25);
    }
  }
  v11 = PsOpenThread(&v58, a5, _38, v60, 0, v56);
  ObfDereferenceObject(v32);
  v10 = ObfDereferenceObject(v14);
  if ( v11 >= 0 )
    *v57 = v58;
LABEL_83:
  v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v53 = *(_WORD *)(v52 + 0x134) + 1;
  *(_WORD *)(v52 + 308) = v53;
  if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v11;
}
