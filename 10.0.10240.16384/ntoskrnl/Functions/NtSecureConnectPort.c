// NtSecureConnectPort 
 
int __fastcall NtSecureConnectPort(int *a1, int a2, int *a3, unsigned int a4, int a5, unsigned int a6, int *a7, int a8, int *a9)
{
  int v11; // r9
  _BYTE *v12; // r0
  unsigned int v13; // r2
  int *v14; // r2
  int *v15; // r2
  int v16; // r1
  int v17; // r5
  _DWORD *v18; // r3
  int v19; // r8
  int v20; // r2
  int v21; // lr
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int *v28; // r3
  int *v29; // r2
  int v30; // r8
  int v31; // r0
  int v32; // r10
  unsigned int *v33; // r4
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r0
  int *v38; // r2
  int *v39; // r3
  int v40; // r8
  int v41; // r0
  int v42; // r1
  int v43; // r2
  int v44; // r3
  _DWORD *v45; // r6
  int v46; // r3
  int v47; // r2
  int v48; // r3
  unsigned int *v49; // r2
  unsigned int v50; // r1
  int v51; // r1
  unsigned int v52; // r1
  __int16 v53; // r3
  int v55; // [sp+0h] [bp-100h]
  int v56; // [sp+20h] [bp-E0h] BYREF
  int v57; // [sp+24h] [bp-DCh] BYREF
  int v58; // [sp+28h] [bp-D8h]
  char v59; // [sp+2Ch] [bp-D4h]
  int v60; // [sp+30h] [bp-D0h] BYREF
  int v61; // [sp+34h] [bp-CCh] BYREF
  int *v62; // [sp+38h] [bp-C8h]
  int v63; // [sp+3Ch] [bp-C4h]
  int v64; // [sp+40h] [bp-C0h]
  int v65; // [sp+44h] [bp-BCh]
  int v66; // [sp+48h] [bp-B8h]
  int *v67; // [sp+4Ch] [bp-B4h] BYREF
  int *v68; // [sp+50h] [bp-B0h]
  int *v69; // [sp+54h] [bp-ACh]
  int *v70; // [sp+58h] [bp-A8h]
  int *v71; // [sp+5Ch] [bp-A4h]
  int v72; // [sp+60h] [bp-A0h]
  int *v73; // [sp+64h] [bp-9Ch]
  int *v74; // [sp+68h] [bp-98h]
  int v75; // [sp+6Ch] [bp-94h]
  unsigned int v76; // [sp+70h] [bp-90h]
  int v77; // [sp+74h] [bp-8Ch]
  unsigned int v78; // [sp+78h] [bp-88h]
  int v79; // [sp+80h] [bp-80h] BYREF
  int v80; // [sp+84h] [bp-7Ch]
  int v81; // [sp+88h] [bp-78h]
  int v82; // [sp+90h] [bp-70h] BYREF
  _DWORD v83[5]; // [sp+94h] [bp-6Ch] BYREF
  int v84[10]; // [sp+A8h] [bp-58h] BYREF
  int v85; // [sp+D0h] [bp-30h] BYREF
  int v86; // [sp+D4h] [bp-2Ch]
  int v87; // [sp+D8h] [bp-28h]

  v62 = a3;
  v57 = a2;
  v68 = a1;
  v74 = a1;
  v77 = a2;
  v73 = a3;
  v78 = a4;
  v11 = a5;
  v66 = a5;
  v75 = a5;
  v76 = a6;
  v69 = a7;
  v71 = a7;
  v64 = a8;
  v72 = a8;
  v70 = a9;
  v67 = a9;
  LOWORD(v84[0]) = 0;
  memset((_BYTE *)v84 + 2, 0, 22);
  v65 = 0;
  v60 = 0;
  v82 = 0;
  v12 = memset(v83, 0, sizeof(v83));
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v61 = 0;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 0x134);
  v58 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v59 = v58;
  if ( v58 )
  {
    v14 = v68;
    if ( (unsigned int)v68 >= MmUserProbeAddress )
      v14 = (int *)MmUserProbeAddress;
    *v14 = *v14;
    if ( a9 )
    {
      v15 = a9;
      if ( (unsigned int)a9 >= MmUserProbeAddress )
        v15 = (int *)MmUserProbeAddress;
      v65 = *v15;
      v60 = v65;
      v12 = (_BYTE *)ProbeForWrite(v64, v65, 1);
      v11 = v66;
    }
    if ( a4 )
    {
      v16 = a4;
      if ( a4 >= MmUserProbeAddress )
        v16 = MmUserProbeAddress;
      v12 = (_BYTE *)memmove((int)&v82, v16, 0x18u);
      if ( v82 != 24 )
      {
        v17 = -1073741811;
        v63 = -1073741811;
        goto LABEL_108;
      }
      if ( (a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      if ( a4 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a4 = *(_BYTE *)a4;
      *(_BYTE *)(a4 + 20) = *(_BYTE *)(a4 + 20);
    }
    if ( a6 )
    {
      v18 = (_DWORD *)a6;
      v14 = (int *)MmUserProbeAddress;
      if ( a6 >= MmUserProbeAddress )
        v18 = (_DWORD *)MmUserProbeAddress;
      if ( *v18 != 12 )
      {
        v17 = -1073741811;
        v63 = -1073741811;
        goto LABEL_108;
      }
      if ( (a6 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      if ( a6 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a6 = *(_BYTE *)a6;
      *(_BYTE *)(a6 + 8) = *(_BYTE *)(a6 + 8);
    }
    if ( v69 )
    {
      v14 = v69;
      if ( (unsigned int)v69 >= MmUserProbeAddress )
        v14 = (int *)MmUserProbeAddress;
      *v14 = *v14;
    }
    if ( a3 )
    {
      v14 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v14 = (int *)MmUserProbeAddress;
      v85 = *v14;
      v86 = v14[1];
      v87 = v14[2];
    }
    v19 = v11;
    v56 = v11;
    if ( v11 )
    {
      v12 = (_BYTE *)SeCaptureSid(v66, v58, (int)v14, (int)&v56, v55, 1, &v56);
      v17 = (int)v12;
      v63 = (int)v12;
      if ( (int)v12 < 0 )
        goto LABEL_108;
      v19 = v56;
    }
    v20 = (int)v62;
    v21 = v57;
  }
  else
  {
    if ( a9 )
    {
      v65 = *a9;
      v60 = v65;
    }
    if ( a4 )
    {
      v22 = *(_DWORD *)(a4 + 4);
      v23 = *(_DWORD *)(a4 + 8);
      v24 = *(_DWORD *)(a4 + 12);
      v82 = *(_DWORD *)a4;
      v83[0] = v22;
      v83[1] = v23;
      v83[2] = v24;
      v25 = *(_DWORD *)(a4 + 20);
      v83[3] = *(_DWORD *)(a4 + 16);
      v83[4] = v25;
    }
    if ( a3 )
    {
      v26 = a3[1];
      v27 = a3[2];
      v85 = *a3;
      v86 = v26;
      v87 = v27;
    }
    v19 = a5;
    v20 = (int)v62;
    v21 = v57;
  }
  if ( v20 )
    v28 = &v85;
  else
    v28 = 0;
  v12 = (_BYTE *)AlpcpCreateClientPort((int)&v56, &v57, 0, v21, 0, 0, 0, 0, v19, (int)v28, 1u);
  v17 = (int)v12;
  if ( v19 != v66 )
    v12 = (_BYTE *)SeReleaseSid(v19, v58, 1);
  if ( v17 >= 0 )
  {
    LOWORD(v84[0]) = v65;
    if ( a4 )
      v29 = &v82;
    else
      v29 = 0;
    v17 = AlpcpFormatConnectionRequest((int *)&v67, 0, v57, v64, (__int16 *)v84, 0, v29, &v61, 1u, v58);
    if ( v17 >= 0 )
    {
      v30 = (int)v67;
      v58 = v67[34];
      if ( AlpcpLogEnabled )
        AlpcpLogConnectRequest(v67);
      v84[0] = v57;
      v84[1] = v30;
      v84[6] = 0x20000;
      v31 = AlpcpDispatchConnectionRequest(v84);
      v17 = v31;
      if ( v31 >= 0 )
      {
        if ( a6 )
          v38 = &v79;
        else
          v38 = 0;
        if ( a4 )
          v39 = &v82;
        else
          v39 = 0;
        v40 = v61;
        v41 = AlpcpReceiveLegacyConnectionReply(v84, v64, &v60, v61, v39, v38);
        v17 = v41;
        if ( v41 )
        {
          if ( AlpcpLogEnabled )
            AlpcpLogConnectFail(v58, v41);
        }
        else
        {
          if ( AlpcpLogEnabled )
            AlpcpLogConnectSuccess(v58);
          *v68 = v56;
          if ( a4 )
          {
            v42 = v83[0];
            v43 = v83[1];
            v44 = v83[2];
            *(_DWORD *)a4 = v82;
            *(_DWORD *)(a4 + 4) = v42;
            *(_DWORD *)(a4 + 8) = v43;
            *(_DWORD *)(a4 + 12) = v44;
            v45 = (_DWORD *)(a4 + 16);
            v46 = v83[4];
            *v45 = v83[3];
            v45[1] = v46;
          }
          if ( a6 )
          {
            v47 = v80;
            v48 = v81;
            *(_DWORD *)a6 = v79;
            *(_DWORD *)(a6 + 4) = v47;
            *(_DWORD *)(a6 + 8) = v48;
          }
          if ( v70 )
            *v70 = v60;
          if ( v69 )
            *v69 = *(_DWORD *)(v57 + 168);
        }
        goto LABEL_99;
      }
      if ( AlpcpLogEnabled )
        AlpcpLogConnectFail(v58, v31);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v30);
      v32 = 0;
      if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
      {
        v32 = 0x10000 - *(__int16 *)(v30 - 14);
        *(_BYTE *)(v30 - 16) &= 0xFEu;
        *(_WORD *)(v30 - 14) = 0;
      }
      v33 = (unsigned int *)(v30 - 4);
      __dmb(0xBu);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 - 1, v33) );
      if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v30 - 4));
      KeAbPostRelease(v30 - 4);
      if ( v32 > 0 )
      {
        __dmb(0xBu);
        v35 = (unsigned int *)(v30 - 12);
        do
        {
          v36 = __ldrex(v35);
          v37 = v36 - v32;
        }
        while ( __strex(v37, v35) );
        __dmb(0xBu);
        if ( v37 <= 0 )
        {
          if ( v37 )
            KeBugCheckEx(24, 0, v30, 40, v37);
          AlpcpDestroyBlob(v30);
        }
      }
    }
    v40 = v61;
LABEL_99:
    v12 = (_BYTE *)ObfDereferenceObject(v57);
    if ( v40 )
    {
      __dmb(0xBu);
      v49 = (unsigned int *)(v40 - 12);
      do
      {
        v50 = __ldrex(v49);
        v51 = v50 - 1;
      }
      while ( __strex(v51, v49) );
      __dmb(0xBu);
      if ( v51 <= 0 )
      {
        if ( v51 )
          KeBugCheckEx(24, 0, v40, 33, v51);
        v12 = (_BYTE *)AlpcpDestroyBlob(v40);
      }
    }
    if ( v17 )
      v12 = (_BYTE *)NtClose();
  }
LABEL_108:
  v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v53 = *(_WORD *)(v52 + 0x134) + 1;
  *(_WORD *)(v52 + 308) = v53;
  if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
    KiCheckForKernelApcDelivery((int)v12);
  return v17;
}
