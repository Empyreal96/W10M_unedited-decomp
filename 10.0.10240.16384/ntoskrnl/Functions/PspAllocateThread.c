// PspAllocateThread 
 
int __fastcall PspAllocateThread(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6, int a7, int a8, int *a9, _DWORD *a10, int a11, int a12)
{
  int v13; // lr
  _DWORD *v15; // r10
  int v16; // r3
  int v17; // r4
  int v18; // r1
  int v19; // r5
  int v20; // r3
  unsigned __int16 *v21; // r0
  int v22; // r3
  int v23; // r4
  unsigned int v24; // r0
  unsigned int v25; // r6
  int v26; // r2
  _DWORD *v27; // r4
  unsigned __int8 *v28; // r3
  unsigned int v29; // r2
  bool v30; // zf
  __int64 *v31; // r0
  unsigned __int8 *v32; // r6
  int v33; // r0
  int v34; // r8
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v37; // r1
  int v38; // r8
  int v39; // r3
  _BYTE *v40; // r6
  int v41; // r5
  int v42; // r2
  char v43; // r5
  unsigned int v44; // r6
  int v45; // r3
  int v46; // r2
  unsigned __int8 *v47; // r3
  unsigned int v48; // r2
  unsigned int v49; // r0
  char v50; // r3
  int v51; // r2
  char v52; // r3
  int v53; // r3
  __int16 v54; // r2
  int v55; // r0
  unsigned int *v56; // r6
  unsigned int v57; // r1
  int v59; // [sp+0h] [bp-D8h]
  int v60; // [sp+20h] [bp-B8h]
  int v61; // [sp+24h] [bp-B4h]
  unsigned int v62; // [sp+2Ch] [bp-ACh]
  _BYTE *v63; // [sp+38h] [bp-A0h] BYREF
  _DWORD *v64; // [sp+3Ch] [bp-9Ch]
  _DWORD *v65; // [sp+40h] [bp-98h]
  int v66; // [sp+44h] [bp-94h]
  _DWORD *v67; // [sp+48h] [bp-90h]
  int v68; // [sp+4Ch] [bp-8Ch]
  BOOL v69; // [sp+50h] [bp-88h]
  int v70; // [sp+54h] [bp-84h]
  _DWORD *v71; // [sp+58h] [bp-80h]
  int v72; // [sp+5Ch] [bp-7Ch]
  unsigned int v73; // [sp+60h] [bp-78h]
  unsigned int v74; // [sp+64h] [bp-74h]
  int v75; // [sp+68h] [bp-70h]
  int v76; // [sp+6Ch] [bp-6Ch]
  _BYTE v77[24]; // [sp+70h] [bp-68h] BYREF
  _BYTE v78[24]; // [sp+88h] [bp-50h] BYREF
  _DWORD _A0[18]; // [sp+A0h] [bp-38h] BYREF
  int varg_r2; // [sp+E8h] [bp+10h]
  int varg_r3; // [sp+ECh] [bp+14h]

  _A0[16] = a1;
  _A0[17] = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v13 = (char)a3;
  v68 = (char)a3;
  LOBYTE(varg_r2) = a3;
  v15 = (_DWORD *)a1;
  v70 = a1;
  v76 = a2;
  v65 = a5;
  v71 = a6;
  v69 = (BOOL)a6;
  v64 = a10;
  v67 = a10;
  v66 = a11;
  v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v74 = v73;
  v60 = 0;
  if ( a6 )
    v16 = *a6;
  else
    v16 = 0;
  v61 = v16;
  if ( a4 )
  {
    v17 = 0;
    v18 = 0;
    a1 = *(_DWORD *)(a4 + 4);
    if ( (a1 & 0x1000) != 0 )
      v17 = a4 + 192;
    if ( (a1 & 0x4000) != 0 )
      v18 = (int)*(&KiProcessorBlock + *(_DWORD *)(a4 + 148));
    if ( v18 )
    {
      if ( v17 )
      {
        if ( *(unsigned __int8 *)(v18 + 1052) != *(unsigned __int16 *)(v17 + 4)
          || *(_DWORD *)v17 && (*(_DWORD *)(v18 + 1048) & *(_DWORD *)v17) == 0 )
        {
          v19 = -1073741776;
LABEL_38:
          ObfDereferenceObjectWithTag((int)v15);
          return v19;
        }
      }
      else
      {
        *(_DWORD *)(a4 + 4) = a1 | 0x1000;
        *(_WORD *)(a4 + 196) = *(unsigned __int8 *)(v18 + 1052);
        v20 = dword_681D78[*(unsigned __int8 *)(v18 + 1052)];
        __dmb(0xBu);
        *(_DWORD *)(a4 + 192) = v20;
      }
      v60 = *(unsigned __int16 *)(*(_DWORD *)(v18 + 2360) + 266) + 1;
    }
    else if ( v17 && *(_DWORD *)v17 )
    {
      v21 = (unsigned __int16 *)KeSelectNodeForAffinity();
      v60 = v21[133] + 1;
      *(_DWORD *)(a4 + 4) |= 0x4000u;
      a1 = KeSelectIdealProcessor((int)v21, v17, 0);
      *(_DWORD *)(a4 + 148) = a1;
      v13 = v68;
    }
  }
  *(_DWORD *)(a12 + 312) = 0;
  *(_BYTE *)(a12 + 316) = v13;
  if ( a5 )
  {
    if ( v15 == (_DWORD *)PsInitialSystemProcess )
    {
      v19 = -1073741811;
      goto LABEL_38;
    }
    if ( a2 )
    {
      if ( v13 == 1 && (a2 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( v13 )
        v22 = 3570;
      else
        v22 = 69618;
      *(_DWORD *)(a12 + 312) = v22 & *(_DWORD *)(a2 + 12);
    }
  }
  else if ( a2 )
  {
    *(_DWORD *)(a12 + 312) = *(_DWORD *)(a2 + 12) & 0x10FF2;
  }
  v23 = 1104;
  v69 = PoEnergyEstimationEnabled();
  if ( v69 )
    v23 = 1168;
  v24 = KeQueryMaximumGroupCount();
  v25 = 0;
  if ( v24 > 1 )
  {
    v25 = (v23 + 3) & 0xFFFFFFFC;
    v23 = v25 + 4 * v24;
  }
  v19 = ObCreateObjectEx(v68, (_DWORD *)PsThreadType, a2, v68, v59, v23, 0, v23, &v63, 0);
  if ( v19 < 0 )
    goto LABEL_38;
  v26 = v23;
  v27 = v63;
  memset(v63, 0, v26);
  if ( v69 )
  {
    v27[271] = v27 + 276;
    __dmb(0xBu);
    v28 = (unsigned __int8 *)v27 + 2;
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 | 0x20, v28) );
    __dmb(0xBu);
  }
  if ( v25 )
  {
    v27[240] |= 0x20000u;
    v27[273] = (char *)v27 + v25;
  }
  v27[235] = 0;
  v27[219] = v15[44];
  if ( (*a9 & 4) != 0 )
    v27[240] |= 4u;
  v27[236] = 0;
  v27[237] = 7;
  KeInitializeSemaphore((int)(v27 + 221), 0, 1);
  v27[211] = v27 + 210;
  v27[210] = v27 + 210;
  v27[252] = v27 + 251;
  v27[251] = v27 + 251;
  v27[254] = v27 + 253;
  v27[253] = v27 + 253;
  v27[255] = 0;
  v27[266] = v27 + 265;
  v27[265] = v27 + 265;
  v27[267] = 0;
  v27[228] = v27 + 227;
  v27[227] = v27 + 227;
  v27[256] = 0;
  v27[216] = 0;
  v27[218] = v27 + 217;
  v27[217] = v27 + 217;
  v27[274] = -3;
  v30 = KeQuerySystemTimeUnsafe() == 0;
  v31 = (__int64 *)(v27 + 208);
  if ( v30 )
    KeQuerySystemTime(v31);
  else
    KeQuerySystemTimePrecise(v31);
  v32 = (unsigned __int8 *)(v27 + 236);
  v33 = KeAbPreAcquire((unsigned int)(v27 + 236), 0, 0);
  v34 = v33;
  do
    v35 = __ldrex(v32);
  while ( __strex(v35 | 1, v32) );
  __dmb(0xBu);
  if ( (v35 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v27 + 236, v33, (unsigned int)(v27 + 236));
  if ( v34 )
    *(_BYTE *)(v34 + 14) |= 1u;
  v36 = ExCreateHandleEx(PspCidTable, (int)v27, 0, 0);
  v27[220] = v36;
  if ( !v36 )
  {
    __dmb(0xBu);
    do
      v37 = __ldrex((unsigned int *)v32);
    while ( __strex(v37 - 1, (unsigned int *)v32) );
    if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
      ExfTryToWakePushLock(v27 + 236);
    KeAbPostRelease((unsigned int)(v27 + 236));
    v19 = -1073741670;
    goto LABEL_107;
  }
  if ( !a5 )
  {
    v44 = 0;
    v27[214] = a7;
    v27[231] = a7;
    v55 = KeInitThread(v27, 0, (int)PspSystemThreadStartup, a7, a8, 0, 0, (int)v15, v60);
    goto LABEL_103;
  }
  v38 = 0;
  v39 = *a9;
  if ( (*a9 & 0x40) != 0 )
    v38 = 1024;
  if ( (v39 & 2) != 0 )
    v38 |= 8u;
  if ( (v39 & 0x80) != 0 )
    v38 |= 0x2000u;
  v40 = (_BYTE *)a11;
  if ( !a11 )
  {
    if ( v15[195] )
    {
      v44 = 0;
      v45 = a5[16];
      v27[214] = v45;
      v27[231] = v45;
      v46 = (int)v71;
      v27[269] = v71[1];
      v27[270] = *(_DWORD *)(v46 + 8);
      __dmb(0xBu);
      v47 = (unsigned __int8 *)v27 + 3;
      do
        v48 = __ldrex(v47);
      while ( __strex(v48 | 4, v47) );
      __dmb(0xBu);
      goto LABEL_101;
    }
    v49 = v73;
    v44 = *(_DWORD *)(v73 + 156);
    if ( (*(_DWORD *)(v73 + 76) & 0x400) != 0 )
    {
      v51 = *(_DWORD *)(v73 + 924);
    }
    else
    {
      v50 = *(_BYTE *)(v73 + 968);
      __dmb(0xBu);
      if ( (v50 & 8) != 0
        || (v51 = *(_DWORD *)(v49 + 856), __dmb(0xFu), v52 = *(_BYTE *)(v49 + 968), __dmb(0xBu), (v52 & 8) != 0) )
      {
        v51 = 0;
      }
      v27 = v63;
    }
    v27[214] = v51;
    v27[231] = *(_DWORD *)(v49 + 924);
    v27[241] |= 4u;
    KiStackAttachProcess((int)v15, 0, (int)v77);
    if ( MmSecureVirtualMemory(v44, 4096, 4, v53) )
    {
      *(_DWORD *)(v44 + 32) = v27[219];
      *(_DWORD *)(v44 + 36) = v27[220];
      *(_DWORD *)(v44 + 1716) = v27[219];
      *(_DWORD *)(v44 + 1720) = v27[220];
      *(_DWORD *)(v44 + 3996) = 0;
      *(_DWORD *)(v44 + 4036) = 0;
      v54 = *(_WORD *)(v44 + 4042);
      *(_WORD *)(v44 + 4042) = v54 & 0x62C;
      *(_WORD *)(v44 + 4042) = v54 & 0x62C | v38 | 0x40;
    }
    else
    {
      v19 = -1073741503;
    }
    goto LABEL_100;
  }
  if ( (*(_BYTE *)a11 & 1) != 0 )
  {
    v43 = 0;
  }
  else
  {
    v41 = 4096;
    if ( v60 )
      v41 = (v60 << 24) | 0x1000;
    KiStackAttachProcess((int)v15, 0, (int)v78);
    v19 = RtlCreateUserStack(*(_DWORD *)(a11 + 8), *(_DWORD *)(a11 + 12), *(_DWORD *)(a11 + 4), v41, 0, v61);
    if ( v19 < 0 )
    {
      KiUnstackDetachProcess((unsigned int)v78, 0);
      goto LABEL_82;
    }
    if ( (v15[47] & 0x20000) != 0 )
      v42 = 0;
    else
      v42 = 8 * (unsigned __int8)ExGenRandom(1);
    v43 = 1;
    a5[14] = *(_DWORD *)(v61 + 8) - v42;
    KiUnstackDetachProcess((unsigned int)v78, 0);
  }
  *(_BYTE *)a11 ^= (*(_BYTE *)a11 ^ (2 * v43)) & 2;
  v19 = 0;
LABEL_82:
  if ( v19 < 0 )
    goto LABEL_108;
  v19 = MmCreateTeb(v15, v61, v27 + 219);
  if ( v19 < 0 )
    goto LABEL_108;
  v27[214] = a5[16];
  v27[231] = a5[1];
  if ( !v38 )
  {
    v44 = v62;
LABEL_101:
    v55 = KeInitThread(v27, 0, (int)PspUserThreadStartup, a7, v27[214], (int)a5, v44, (int)v15, v60);
LABEL_103:
    v19 = v55;
    if ( v55 >= 0 )
    {
      *v64 = v27;
      return 0;
    }
    if ( v44 && a11 )
      MmDeleteTeb((int)v15, v44);
    goto LABEL_107;
  }
  KiStackAttachProcess((int)v15, 0, (int)v77);
  v44 = v62;
  *(_WORD *)(v62 + 4042) = v38;
  v19 = 0;
LABEL_100:
  KiUnstackDetachProcess((unsigned int)v77, 0);
  if ( v19 >= 0 )
    goto LABEL_101;
LABEL_107:
  v40 = (_BYTE *)a11;
LABEL_108:
  if ( v40 && *v40 )
  {
    KiStackAttachProcess((int)v15, 0, (int)_A0);
    if ( (*v40 & 2) != 0 )
    {
      v72 = *(_DWORD *)(v61 + 16);
      v75 = 0;
      ZwFreeVirtualMemory();
    }
    KiUnstackDetachProcess((unsigned int)_A0, 0);
  }
  if ( v27[220] )
  {
    v56 = v27 + 236;
    __dmb(0xBu);
    do
      v57 = __ldrex(v56);
    while ( __strex(v57 - 1, v56) );
    if ( (v57 & 2) != 0 && (v57 & 4) == 0 )
      ExfTryToWakePushLock(v27 + 236);
    KeAbPostRelease((unsigned int)(v27 + 236));
  }
  if ( !v27[84] )
    ObfDereferenceObjectWithTag((int)v15);
  ObfDereferenceObject((int)v27);
  return v19;
}
