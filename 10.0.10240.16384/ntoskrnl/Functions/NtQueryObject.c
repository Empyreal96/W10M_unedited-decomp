// NtQueryObject 
 
int __fastcall NtQueryObject(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int v6; // r6
  int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r1
  _DWORD *v12; // r2
  int v13; // r5
  _DWORD *v14; // r8
  int v15; // r4
  int v16; // r3
  int v17; // r3
  _DWORD *v18; // r9
  char v19; // r2
  char *v20; // r3
  _DWORD *v21; // r2
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r2
  unsigned int *v25; // r10
  int v26; // r0
  int v27; // r4
  unsigned int v28; // r2
  int *v29; // r3
  int v30; // r3
  unsigned int *v31; // r1
  unsigned int v32; // r2
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  int v36; // r2
  int v37; // r1
  unsigned int v38; // r2
  int v39; // r1
  unsigned int v40; // r2
  int v41; // r3
  char *v42; // r1
  unsigned int v43; // r2
  int v44; // r0
  unsigned int v45; // r1
  __int16 v46; // r3
  unsigned int *v47; // r4
  unsigned int v48; // r2
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r3
  unsigned int *v53; // r4
  unsigned int v54; // r2
  int v55; // r0
  unsigned int v56; // r1
  __int16 v57; // r3
  int v58; // r3
  int v59; // r1
  int v60; // r2
  int v61; // r3
  _DWORD *v62; // r6
  int v63; // r1
  int v64; // r2
  int v65; // r3
  int v66; // r1
  int v67; // r2
  int v68; // r3
  int v69; // r3
  int v70; // r4
  int *v71; // r3
  unsigned int v72; // r9
  unsigned int v73; // r2
  int v74; // r0
  int v75; // r0
  int v77; // [sp+18h] [bp-A0h] BYREF
  int v78; // [sp+1Ch] [bp-9Ch]
  int *v79; // [sp+20h] [bp-98h]
  int v80; // [sp+24h] [bp-94h]
  int v81; // [sp+28h] [bp-90h]
  char v82; // [sp+2Ch] [bp-8Ch]
  int v83; // [sp+30h] [bp-88h]
  char *v84; // [sp+34h] [bp-84h]
  int v85; // [sp+38h] [bp-80h]
  int v86; // [sp+3Ch] [bp-7Ch] BYREF
  int v87; // [sp+40h] [bp-78h] BYREF
  int v88; // [sp+44h] [bp-74h]
  unsigned int v89; // [sp+48h] [bp-70h]
  int v90; // [sp+50h] [bp-68h]
  int v91; // [sp+54h] [bp-64h]
  int v92; // [sp+58h] [bp-60h]
  int v93; // [sp+5Ch] [bp-5Ch] BYREF
  _DWORD _60[28]; // [sp+60h] [bp-58h] BYREF

  _60[27] = a4;
  v6 = a3;
  _60[26] = a3;
  _60[25] = a2;
  _60[24] = a1;
  v77 = 0;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v83 = v9;
  v82 = v9;
  if ( v9 )
  {
    if ( a2 == 4 )
    {
      if ( a4 )
      {
        v10 = a3 + a4 - 1;
        if ( a3 > v10 || v10 >= MmUserProbeAddress )
          ExRaiseAccessViolation();
        v11 = (v10 & 0xFFFFF000) + 4096;
        do
        {
          *(_BYTE *)a3 = *(_BYTE *)a3;
          a3 = (a3 & 0xFFFFF000) + 4096;
        }
        while ( a3 != v11 );
        v9 = v83;
      }
    }
    else
    {
      ProbeForWrite(a3, a4, 4);
      v9 = v83;
    }
    v79 = (int *)a5;
    if ( a5 )
    {
      v12 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v12 = (_DWORD *)MmUserProbeAddress;
      *v12 = *v12;
    }
  }
  else
  {
    v79 = (int *)a5;
  }
  if ( a2 == 3 )
  {
    v16 = 0;
    v88 = 0;
    v14 = 0;
    v85 = 0;
    v84 = 0;
    v15 = 0;
    v13 = 0;
    v78 = 0;
  }
  else
  {
    v13 = ObReferenceObjectByHandle(a1, 0, 0, v9, &v86);
    v14 = (_DWORD *)v86;
    v85 = v86;
    v78 = v13;
    if ( v13 < 0 )
      return v13;
    v88 = v91;
    v84 = (char *)(v86 - 24);
    v15 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v86 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v86 - 12)];
    v16 = v90;
  }
  v80 = v16;
  v86 = v15;
  if ( a2 == 4 )
  {
    v70 = 2;
    v77 = 2;
    if ( a4 >= 2 )
    {
      *(_BYTE *)v6 = 0;
      if ( (v16 & 2) != 0 )
        *(_BYTE *)v6 = 1;
      *(_BYTE *)(v6 + 1) = 0;
      if ( (v16 & 1) != 0 )
        *(_BYTE *)(v6 + 1) = 1;
      v70 = v77;
    }
    else
    {
      v13 = -1073741820;
      v78 = -1073741820;
    }
    v71 = v79;
  }
  else
  {
    switch ( a2 )
    {
      case 0:
        if ( a4 != 56 )
        {
          ObfDereferenceObject((int)v14);
          return -1073741820;
        }
        memset(_60, 0, 56);
        v17 = v80;
        _60[0] = v80;
        v18 = v84;
        v19 = v84[15];
        if ( (v19 & 0x10) != 0 )
        {
          v17 = v80 | 0x10;
          _60[0] = v80 | 0x10;
        }
        if ( (v19 & 8) != 0 )
          _60[0] = v17 | 0x20;
        _60[1] = v88;
        _60[2] = *((_DWORD *)v84 + 1);
        _60[3] = *(_DWORD *)v84;
        if ( (v84[14] & 8) == 0
          || (v20 = (char *)ObpInfoMaskToOffset[v84[14] & 0xF], v21 = (_DWORD *)(v84 - v20), v84 == v20) )
        {
          v22 = 0;
          _60[4] = 0;
        }
        else
        {
          _60[4] = *v21;
          v22 = v21[1];
        }
        _60[5] = v22;
        if ( v15 == ObpSymbolicLinkObjectType )
        {
          _60[12] = *v14;
          v23 = v14[1];
        }
        else
        {
          v23 = 0;
          _60[12] = 0;
        }
        _60[13] = v23;
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v24 + 308);
        v25 = v18 + 2;
        v26 = KeAbPreAcquire((unsigned int)(v18 + 2), 0, 0);
        v27 = v26;
        do
          v28 = __ldrex(v25);
        while ( !v28 && __strex(0x11u, v25) );
        __dmb(0xBu);
        if ( v28 )
          ExfAcquirePushLockSharedEx(v18 + 2, v26, (unsigned int)(v18 + 2));
        if ( v27 )
          *(_BYTE *)(v27 + 14) |= 1u;
        if ( (*((_BYTE *)v18 + 14) & 2) != 0 )
        {
          v29 = (_DWORD *)((char *)v18 - ObpInfoMaskToOffset[*((_BYTE *)v18 + 14) & 3]);
          v80 = (int)v29;
          if ( v29 )
          {
            v30 = *v29;
            v81 = v30;
            if ( v30 )
            {
              ObfReferenceObject(v30);
              __dmb(0xBu);
              v31 = v18 + 2;
              do
                v32 = __ldrex(v31);
              while ( v32 == 17 && __strex(0, v31) );
              if ( v32 != 17 )
              {
                ExfReleasePushLockShared(v18 + 2);
                v31 = v18 + 2;
              }
              v33 = KeAbPostRelease((unsigned int)v31);
              v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v35 = *(_WORD *)(v34 + 0x134) + 1;
              *(_WORD *)(v34 + 308) = v35;
              if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
                KiCheckForKernelApcDelivery(v33);
              v36 = v81;
              v92 = v81;
              v80 = *(unsigned __int16 *)(v80 + 4) + 2;
              while ( 1 )
              {
                if ( !v36 )
                  goto LABEL_88;
                v37 = v36 - 24;
                v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                --*(_WORD *)(v38 + 308);
                v84 = (char *)(v37 + 8);
                v39 = KeAbPreAcquire(v37 + 8, 0, 0);
                v90 = v39;
                do
                  v40 = __ldrex((unsigned int *)v84);
                while ( !v40 && __strex(0x11u, (unsigned int *)v84) );
                __dmb(0xBu);
                if ( v40 )
                {
                  ExfAcquirePushLockSharedEx(v84, v39, (unsigned int)v84);
                  v39 = v90;
                }
                if ( v39 )
                  *(_BYTE *)(v39 + 14) |= 1u;
                if ( (*(_BYTE *)(v81 - 10) & 2) == 0 )
                  break;
                v41 = v81 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(v81 - 10) & 3];
                if ( !v41 )
                  break;
                v90 = *(_DWORD *)v41;
                if ( !v90 )
                  break;
                v80 += *(unsigned __int16 *)(v41 + 4) + 2;
                v81 = v90;
                ObfReferenceObject(v90);
                __dmb(0xBu);
                v42 = v84;
                do
                  v43 = __ldrex((unsigned int *)v84);
                while ( v43 == 17 && __strex(0, (unsigned int *)v84) );
                if ( v43 != 17 )
                {
                  ExfReleasePushLockShared(v84);
                  v42 = v84;
                }
                v44 = KeAbPostRelease((unsigned int)v42);
                v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v46 = *(_WORD *)(v45 + 0x134) + 1;
                *(_WORD *)(v45 + 308) = v46;
                if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
                  KiCheckForKernelApcDelivery(v44);
                ObfDereferenceObject(v92);
                v92 = v90;
                v36 = v81;
              }
              v47 = (unsigned int *)(v81 - 16);
              __dmb(0xBu);
              do
                v48 = __ldrex(v47);
              while ( v48 == 17 && __strex(0, v47) );
              if ( v48 != 17 )
                ExfReleasePushLockShared(v47);
              v49 = KeAbPostRelease((unsigned int)v47);
              v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v51 = *(_WORD *)(v50 + 0x134) + 1;
              *(_WORD *)(v50 + 308) = v51;
              if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
                KiCheckForKernelApcDelivery(v49);
              if ( v81 )
                ObfDereferenceObject(v81);
LABEL_88:
              v52 = v80 + 10;
              goto LABEL_99;
            }
          }
        }
        __dmb(0xBu);
        v53 = v18 + 2;
        do
          v54 = __ldrex(v53);
        while ( v54 == 17 && __strex(0, v53) );
        if ( v54 != 17 )
          ExfReleasePushLockShared(v18 + 2);
        v55 = KeAbPostRelease((unsigned int)(v18 + 2));
        v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v57 = *(_WORD *)(v56 + 0x134) + 1;
        *(_WORD *)(v56 + 308) = v57;
        if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
          KiCheckForKernelApcDelivery(v55);
        v52 = 0;
LABEL_99:
        _60[9] = v52;
        _60[10] = *(unsigned __int16 *)(v86 + 8) + 98;
        if ( (v88 & 0x20000) != 0 && v18[5] )
        {
          v93 = 15;
          v87 = 0;
          (*(void (__fastcall **)(_DWORD *, int, int *, _DWORD, int *, _DWORD *, _DWORD, int, int))(v86 + 108))(
            v14,
            1,
            &v93,
            0,
            &v87,
            v18 + 5,
            *(_DWORD *)(v86 + 76),
            v86 + 52,
            v83);
          v58 = v87;
        }
        else
        {
          v58 = 0;
          v87 = 0;
        }
        _60[11] = v58;
        v59 = _60[1];
        v60 = _60[2];
        v61 = _60[3];
        *(_DWORD *)v6 = _60[0];
        *(_DWORD *)(v6 + 4) = v59;
        *(_DWORD *)(v6 + 8) = v60;
        *(_DWORD *)(v6 + 12) = v61;
        v62 = (_DWORD *)(v6 + 16);
        v63 = _60[5];
        v64 = _60[6];
        v65 = _60[7];
        *v62 = _60[4];
        v62[1] = v63;
        v62[2] = v64;
        v62[3] = v65;
        v62 += 4;
        v66 = _60[9];
        v67 = _60[10];
        v68 = _60[11];
        *v62 = _60[8];
        v62[1] = v66;
        v62[2] = v67;
        v62[3] = v68;
        v62 += 4;
        v69 = _60[13];
        *v62 = _60[12];
        v62[1] = v69;
        v70 = 56;
        v77 = 56;
        v71 = v79;
        break;
      case 1:
        v13 = ObQueryNameStringMode((int)v14, v6, a4, &v77, v83);
        v78 = v13;
        v70 = v77;
        v71 = v79;
        break;
      case 2:
        v13 = ObQueryTypeInfo(v15, v6, a4, &v77);
        v78 = v13;
        v70 = v77;
        v71 = v79;
        break;
      case 3:
        v70 = 4;
        v77 = 4;
        if ( a4 < 4 )
        {
          v13 = -1073741820;
          v78 = -1073741820;
          goto LABEL_118;
        }
        v72 = 0;
        *(_DWORD *)v6 = 0;
        v73 = 0;
        v89 = 0;
        while ( v73 < 0x30 && ObpObjectTypes[v73] )
        {
          ++*(_DWORD *)v6;
          v89 = ++v73;
        }
        while ( 2 )
        {
          v89 = v72;
          if ( v72 >= 0x30 )
            goto LABEL_117;
          v70 = v77;
          v74 = ObpObjectTypes[v72];
          if ( v74 )
          {
            v75 = ObQueryTypeInfo(v74, v6 + v77, a4, &v77);
            v13 = v75;
            v78 = v75;
            if ( v75 >= 0 || v75 == -1073741820 )
            {
              ++v72;
              continue;
            }
LABEL_117:
            v70 = v77;
          }
          break;
        }
LABEL_118:
        v71 = v79;
        break;
      default:
        ObfDereferenceObject((int)v14);
        return -1073741821;
    }
  }
  if ( v71 )
    *v71 = v70;
  if ( v14 )
    ObfDereferenceObject((int)v14);
  return v13;
}
