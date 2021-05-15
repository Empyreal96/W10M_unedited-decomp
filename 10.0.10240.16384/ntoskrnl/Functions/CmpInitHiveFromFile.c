// CmpInitHiveFromFile 
 
int __fastcall CmpInitHiveFromFile(int a1, int a2, int *a3, int a4, int a5, int a6, int a7, int a8, _BYTE *a9)
{
  _BYTE *v9; // lr
  unsigned __int16 *v10; // r9
  int *v11; // r4
  int v12; // r6
  int v13; // r3
  int v14; // r8
  int v15; // r2
  int v16; // r0
  int v17; // r4
  int v18; // r7
  int v19; // r0
  int v20; // r0
  int v21; // r6
  int v23; // r2
  int v24; // r4
  int v25; // r10
  int v26; // r3
  unsigned int v27; // r9
  int v28; // r3
  int v29; // r3
  unsigned int v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // r1
  int v33; // r6
  int v34; // r0
  int v35; // r4
  _BYTE *v36; // r2
  int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r1
  __int16 v40; // r3
  int v41; // r3
  int v42; // r0
  unsigned int v43; // r1
  __int16 v44; // r3
  unsigned int v45; // r4
  unsigned int v46; // r1
  bool v47; // zf
  unsigned int v48; // r1
  int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r1
  __int16 v52; // r3
  unsigned int v53; // r1
  int v54; // r3
  int v55; // [sp+20h] [bp-B8h]
  int v56; // [sp+24h] [bp-B4h] BYREF
  unsigned __int16 *v57; // [sp+28h] [bp-B0h]
  int v58; // [sp+2Ch] [bp-ACh]
  int v59; // [sp+30h] [bp-A8h]
  int v60; // [sp+34h] [bp-A4h]
  int v61; // [sp+38h] [bp-A0h] BYREF
  int v62; // [sp+3Ch] [bp-9Ch] BYREF
  int v63; // [sp+40h] [bp-98h]
  unsigned int v64; // [sp+44h] [bp-94h] BYREF
  int v65; // [sp+48h] [bp-90h]
  int v66; // [sp+4Ch] [bp-8Ch] BYREF
  int *v67; // [sp+50h] [bp-88h]
  _BYTE *v68; // [sp+54h] [bp-84h]
  _BYTE *v69; // [sp+58h] [bp-80h]
  int v70; // [sp+5Ch] [bp-7Ch] BYREF
  int v71; // [sp+60h] [bp-78h] BYREF
  int v72; // [sp+64h] [bp-74h]
  int v73; // [sp+68h] [bp-70h]
  char v74[4]; // [sp+6Ch] [bp-6Ch] BYREF
  _DWORD v75[4]; // [sp+70h] [bp-68h] BYREF
  char v76[8]; // [sp+80h] [bp-58h] BYREF
  int v77; // [sp+A0h] [bp-38h]
  int v78; // [sp+A4h] [bp-34h]

  v9 = (_BYTE *)a4;
  v69 = (_BYTE *)a4;
  v10 = (unsigned __int16 *)a1;
  v57 = (unsigned __int16 *)a1;
  v73 = a8;
  v68 = a9;
  v11 = a3;
  v64 = 0;
  v67 = a3;
  v60 = a2;
  if ( (a5 & 0x40000000) != 0 )
    return sub_7C33A4();
  v12 = 0;
  v13 = 0;
  v58 = 0;
  v59 = 0;
  v14 = 0;
  if ( (a2 & 0x20000) == 0 )
    v13 = 1;
  v15 = v13;
  v65 = v13;
  if ( (a5 & 0x2000000) != 0 )
    v16 = 64;
  else
    v16 = 0;
  v55 = v16;
  while ( 1 )
  {
    *v11 = 0;
    v17 = 0;
    v18 = 0;
    v56 = 0;
    v63 = 0;
    v61 = 0;
    v71 = 0;
    v72 = 0;
    if ( (a2 & 0x8000) == 0 )
    {
      if ( v15 )
        v23 = 4;
      else
        v23 = 0;
      v21 = CmpOpenHiveFile(v10, 0, &v62, &v66, v23 | (*v9 != 0) | v16 | v12, &v71, 0, 0);
      if ( v21 < 0 )
      {
        if ( !v14 )
          return v21;
        __pld(&CmpShutdownRundown);
        v20 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v48 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v48 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_125:
        v47 = v48 == v20;
LABEL_126:
        if ( !v47 )
          v20 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v54 = (__int16)(*(_WORD *)(v53 + 0x134) + 1);
        *(_WORD *)(v53 + 308) = v54;
        if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
          KiCheckForKernelApcDelivery(v20);
        return v21;
      }
      if ( v66 == 2 )
      {
        v24 = 1;
        v59 = 1;
      }
      else
      {
        v24 = v59;
      }
      v25 = v62;
      v21 = CmpQueryFileSecurityDescriptor(v62, (int *)&v64);
      if ( v21 < 0 )
      {
        ZwClose();
        if ( !v14 )
          return v21;
LABEL_101:
        __pld(&CmpShutdownRundown);
        v20 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v48 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v48 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
        goto LABEL_125;
      }
      if ( (a5 & 0x10000000) != 0 )
      {
        if ( v24 )
          v41 = 16;
        else
          v41 = 0;
        v27 = v64;
        v21 = CmpOpenHiveFile(v57, 1, &v56, v74, v41 | v55 | v58, 0, v64, 0);
        if ( v21 >= 0 )
          v63 = 1;
      }
      else
      {
        if ( v24 )
          v26 = 16;
        else
          v26 = 0;
        v27 = v64;
        v21 = CmpOpenHiveFile(v57, 4, &v56, v74, v26 | v55 | v58, 0, v64, 0);
        if ( v21 >= 0 )
        {
          if ( v59 )
            v28 = 16;
          else
            v28 = 0;
          v21 = CmpOpenHiveFile(v57, 5, &v61, v76, v28 | v55 | v58, 0, v27, 0);
          if ( v21 < 0 )
          {
            ZwClose();
            v18 = v61;
            v17 = 0;
            goto LABEL_30;
          }
          v18 = v61;
          v63 = 2;
        }
      }
      v17 = v56;
LABEL_30:
      if ( v27 )
        ExFreePoolWithTag(v27);
      v10 = v57;
      goto LABEL_33;
    }
    v19 = v16 | 0x20;
    v55 = v19;
    if ( v15 )
    {
      v19 |= 4u;
      v55 = v19;
    }
    if ( (a2 & 0x40000) != 0 )
    {
      v19 |= 0x80u;
      v55 = v19;
    }
    v20 = CmpOpenHiveFile(v10, 0, &v62, &v66, v19, 0, 0, 0);
    v21 = v20;
    if ( v20 < 0 )
    {
      if ( !v14 )
        return v21;
      __pld(&CmpShutdownRundown);
      v45 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v46 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v46 == v45 && __strex(v45 - 2, (unsigned int *)&CmpShutdownRundown) );
      v47 = v46 == v45;
      goto LABEL_126;
    }
    v25 = v62;
LABEL_33:
    if ( !v14 )
    {
      v29 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v29 & 0xFFFFFFC0) + 0x134);
      __pld(&CmpShutdownRundown);
      v30 = CmpShutdownRundown & 0xFFFFFFFE;
      v31 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
      do
        v32 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v32 == v30 && __strex(v31, (unsigned int *)&CmpShutdownRundown) );
      __dmb(0xBu);
      if ( v32 == v30 )
      {
        v14 = 1;
      }
      else
      {
        v42 = ExfAcquireRundownProtection(&CmpShutdownRundown);
        v14 = v42;
        if ( !v42 )
        {
          v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v44 = *(_WORD *)(v43 + 0x134) + 1;
          *(_WORD *)(v43 + 308) = v44;
          if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
            KiCheckForKernelApcDelivery(0);
          goto LABEL_90;
        }
      }
    }
    if ( v21 < 0 )
      break;
    if ( v59 )
    {
      v33 = 0;
    }
    else if ( v65 )
    {
      v33 = 2;
      v60 &= 0xFFFDFFFF;
    }
    else
    {
      v33 = 5;
    }
    v75[0] = v25;
    v75[1] = v17;
    v75[2] = v18;
    v75[3] = 0;
    memset(v68, 0, 288);
    v21 = CmpInitializeHive(&v70, v33, v60, v63, 0, v75, v10, a5, 0, 0, v73, v68);
    if ( v21 >= 0 )
    {
      ZwSetInformationObject();
      if ( v17 )
        ZwSetInformationObject();
      if ( v18 )
        ZwSetInformationObject();
      v34 = ExAllocatePoolWithTag(1, *v10, 1649298755);
      v35 = v70;
      *(_DWORD *)(v70 + 1980) = v34;
      if ( v34 )
      {
        *(_WORD *)(v35 + 1976) = *v10;
        *(_WORD *)(v35 + 1978) = *v10;
        memmove(*(_DWORD *)(v35 + 1980), *((_DWORD *)v10 + 1), *v10);
      }
      if ( (*(_DWORD *)(*(_DWORD *)(v35 + 32) + 4088) & 4) != 0 )
        CmpLogEvent(REG_EVENT_SELFHEAL, -2147483606, v10);
      if ( ZwQueryInformationFile() >= 0 )
      {
        *(_DWORD *)(v35 + 3280) = v77;
        *(_DWORD *)(v35 + 3284) = v78;
      }
      v36 = v69;
      *(_DWORD *)(v35 + 116) = v72;
      *v67 = v35;
      *v36 = v59;
      __pld(&CmpShutdownRundown);
      v37 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v38 == v37 && __strex(v37 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v38 != v37 )
        v37 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        KiCheckForKernelApcDelivery(v37);
      return 0;
    }
    ZwClose();
    if ( v17 )
      ZwClose();
    if ( v18 )
      ZwClose();
    if ( v21 != -1073741267 || v65 )
      goto LABEL_101;
    v15 = 1;
    v16 = v55;
    a2 = v60;
    v12 = v58;
    v9 = v69;
    v11 = v67;
    v65 = 1;
  }
  if ( !v14 )
  {
LABEL_90:
    v21 = -1073741431;
    goto LABEL_117;
  }
  __pld(&CmpShutdownRundown);
  v49 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v50 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v50 == v49 && __strex(v49 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v50 != v49 )
    v49 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v52 = *(_WORD *)(v51 + 0x134) + 1;
  *(_WORD *)(v51 + 308) = v52;
  if ( !v52 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
    KiCheckForKernelApcDelivery(v49);
LABEL_117:
  ZwClose();
  if ( v17 )
    ZwClose();
  if ( v18 )
    ZwClose();
  return v21;
}
