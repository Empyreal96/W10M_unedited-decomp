// ObQueryNameStringMode 
 
int __fastcall ObQueryNameStringMode(int a1, int a2, int a3, _DWORD *a4, char a5)
{
  int v5; // r10
  int v6; // r2
  int v7; // r8
  int v8; // r4
  int (__fastcall *v9)(int, BOOL, int, unsigned int, _DWORD *, _DWORD); // r5
  BOOL v10; // r1
  int v11; // r6
  unsigned int v12; // lr
  int v13; // r1
  _DWORD *v14; // r3
  int v15; // r2
  unsigned int v16; // r2
  unsigned int *v17; // r10
  int v18; // r0
  int v19; // r5
  unsigned int v20; // r2
  int v21; // r5
  unsigned int v22; // r6
  unsigned int v23; // r2
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r10
  unsigned int v27; // r2
  int v28; // r5
  unsigned int *v29; // r0
  unsigned int v30; // r2
  int v31; // r3
  unsigned int *v32; // r10
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int *v37; // r4
  unsigned int v38; // r2
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r3
  unsigned int v43; // r0
  _WORD *v44; // r6
  unsigned int v45; // r2
  int v46; // r6
  unsigned int v47; // r1
  unsigned int *v48; // r5
  int v49; // r1
  unsigned int v50; // r2
  int v51; // r5
  unsigned int *v52; // r8
  unsigned int v53; // r2
  unsigned int v54; // r1
  __int16 v55; // r3
  _WORD *v56; // r8
  int v57; // r5
  int v58; // r6
  unsigned int v59; // r2
  unsigned int *v60; // r0
  unsigned int v61; // r2
  unsigned int v62; // r1
  unsigned int v63; // r2
  unsigned int *v64; // r6
  unsigned int v65; // r2
  unsigned int v66; // r1
  __int16 v67; // r3
  unsigned int *v68; // r5
  unsigned int v69; // r2
  int v70; // r0
  unsigned int v71; // r1
  __int16 v72; // r3
  unsigned int *v73; // r5
  unsigned int v74; // r2
  int v75; // r0
  unsigned int v76; // r1
  __int16 v77; // r3
  _WORD *v78; // r1
  int v79; // r2
  unsigned int v80; // r6
  char v82; // [sp+9h] [bp-77h]
  _DWORD *v83; // [sp+Ch] [bp-74h]
  unsigned int v84; // [sp+Ch] [bp-74h]
  int v85; // [sp+10h] [bp-70h]
  int v86; // [sp+14h] [bp-6Ch] BYREF
  unsigned int v87; // [sp+18h] [bp-68h]
  int v88; // [sp+1Ch] [bp-64h]
  int v89; // [sp+20h] [bp-60h]
  int v90; // [sp+24h] [bp-5Ch]
  int v91; // [sp+28h] [bp-58h]
  _WORD *v92; // [sp+2Ch] [bp-54h]
  int v93; // [sp+30h] [bp-50h]
  unsigned int v94; // [sp+34h] [bp-4Ch]
  unsigned int v95; // [sp+38h] [bp-48h]
  unsigned int v96; // [sp+3Ch] [bp-44h]
  unsigned int v97; // [sp+40h] [bp-40h]
  unsigned int v98; // [sp+44h] [bp-3Ch]
  int v99; // [sp+48h] [bp-38h]
  int v100; // [sp+4Ch] [bp-34h]
  int v101; // [sp+50h] [bp-30h]
  int v102; // [sp+54h] [bp-2Ch]
  int v103; // [sp+58h] [bp-28h]
  int v104; // [sp+5Ch] [bp-24h]
  int v105; // [sp+60h] [bp-20h]
  int varg_r0; // [sp+88h] [bp+8h]
  int varg_r1; // [sp+8Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+90h] [bp+10h]
  _DWORD *varg_r3; // [sp+94h] [bp+14h]

  v83 = a4;
  varg_r3 = a4;
  v87 = a3;
  varg_r2 = a3;
  v91 = a2;
  varg_r1 = a2;
  v89 = a1;
  varg_r0 = a1;
  v82 = 1;
  v95 = 0;
  v85 = 0;
  v88 = 0;
  v90 = -1073741823;
  v5 = a1 - 24;
  v99 = a1 - 24;
  v6 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)];
  if ( (*(_BYTE *)(a1 - 10) & 2) != 0 )
    v7 = v5 - ObpInfoMaskToOffset[*(_BYTE *)(a1 - 10) & 3];
  else
    v7 = 0;
  v8 = 0;
  v86 = 0;
  v9 = *(int (__fastcall **)(int, BOOL, int, unsigned int, _DWORD *, _DWORD))(v6 + 112);
  if ( !v9 )
  {
    if ( PsGetSiloObject(-1, &ObpDirectoryObjectType, &v86) >= 0 )
    {
      v8 = v86;
    }
    else
    {
      v8 = ObpRootDirectoryObject;
      if ( ObpRootDirectoryObject )
        ObfReferenceObject(ObpRootDirectoryObject);
    }
    v86 = v8;
    v12 = v87;
LABEL_15:
    v13 = v91;
    v14 = v83;
    v15 = v89;
    while ( 1 )
    {
      if ( !v7 )
      {
        v95 = 8;
        *v14 = 8;
        if ( v12 < 8 )
        {
          v11 = -1073741820;
          goto LABEL_173;
        }
        *(_WORD *)v13 = 0;
        *(_WORD *)(v13 + 2) = 0;
        *(_DWORD *)(v13 + 4) = 0;
        goto LABEL_20;
      }
      if ( v15 == v8 || v15 == ObpRootDirectoryObject )
      {
        v22 = 2;
        v98 = 2;
      }
      else
      {
        v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v16 + 308);
        v17 = (unsigned int *)(v5 + 8);
        v18 = KeAbPreAcquire((unsigned int)v17, 0, 0);
        v19 = v18;
        v96 = 0;
        v89 = 17;
        do
          v20 = __ldrex(v17);
        while ( !v20 && __strex(0x11u, v17) );
        __dmb(0xBu);
        v89 = v20;
        if ( v20 )
          ExfAcquirePushLockSharedEx(v17, v18, (unsigned int)v17);
        if ( v19 )
          *(_BYTE *)(v19 + 14) |= 1u;
        v21 = *(_DWORD *)v7;
        if ( *(_DWORD *)v7 )
        {
          ObfReferenceObject(*(_DWORD *)v7);
          v85 = v21;
          v88 = v21;
        }
        v22 = *(unsigned __int16 *)(v7 + 4) + 2;
        v98 = v22;
        v97 = 17;
        v91 = 0;
        __dmb(0xBu);
        do
          v23 = __ldrex(v17);
        while ( v23 == 17 && __strex(0, v17) );
        v91 = v23;
        if ( v23 != 17 )
          ExfReleasePushLockShared(v17);
        KeAbPostRelease((unsigned int)v17);
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(_WORD *)(v24 + 0x134) + 1;
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery(308);
        while ( v21 != v8 && v21 != ObpRootDirectoryObject && v21 )
        {
          v26 = v21 - 24;
          v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v27 + 308);
          v89 = v21 - 16;
          v28 = KeAbPreAcquire(v21 - 16, 0, 0);
          v100 = 0;
          v93 = 17;
          v29 = (unsigned int *)(v26 + 8);
          do
            v30 = __ldrex(v29);
          while ( !v30 && __strex(0x11u, v29) );
          __dmb(0xBu);
          v93 = v30;
          if ( v30 )
            ExfAcquirePushLockSharedEx(v29, v28, v26 + 8);
          if ( v28 )
            *(_BYTE *)(v28 + 14) |= 1u;
          if ( (*(_BYTE *)(v26 + 14) & 2) == 0
            || (v31 = v26 - ObpInfoMaskToOffset[*(_BYTE *)(v26 + 14) & 3]) == 0
            || (v21 = *(_DWORD *)v31) == 0 )
          {
            v37 = (unsigned int *)(v26 + 8);
            v102 = 17;
            __dmb(0xBu);
            do
              v38 = __ldrex(v37);
            while ( v38 == 17 && __strex(0, v37) );
            if ( v38 != 17 )
              ExfReleasePushLockShared((_DWORD *)(v26 + 8));
            v39 = KeAbPostRelease(v26 + 8);
            v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v41 = *(_WORD *)(v40 + 0x134) + 1;
            *(_WORD *)(v40 + 308) = v41;
            if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
              KiCheckForKernelApcDelivery(v39);
            v22 += 8;
            v98 = v22;
            break;
          }
          v22 += *(unsigned __int16 *)(v31 + 4) + 2;
          v98 = v22;
          ObfReferenceObject(v21);
          v101 = 17;
          v94 = 0;
          __dmb(0xBu);
          v32 = (unsigned int *)v89;
          do
            v33 = __ldrex(v32);
          while ( v33 == 17 && __strex(0, v32) );
          v94 = v33;
          if ( v33 != 17 )
            ExfReleasePushLockShared(v32);
          v34 = KeAbPostRelease((unsigned int)v32);
          v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v36 = *(_WORD *)(v35 + 0x134) + 1;
          *(_WORD *)(v35 + 308) = v36;
          if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
            KiCheckForKernelApcDelivery(v34);
          ObfDereferenceObject(v85);
          v85 = v21;
          v88 = v21;
          if ( v22 > 0xFFFF )
            break;
        }
        if ( v22 > 0xFFFF )
        {
          v42 = -1073741562;
          goto LABEL_80;
        }
      }
      v95 = v22 + 10;
      *v83 = v22 + 10;
      if ( v87 >= v22 + 10 )
        goto LABEL_81;
      v42 = -1073741820;
LABEL_80:
      v90 = v42;
      v82 = 0;
LABEL_81:
      v85 = v88;
      if ( v88 )
      {
        ObfDereferenceObject(v88);
        v85 = 0;
        v88 = 0;
      }
      if ( !v82 )
      {
        v11 = v90;
        v8 = v86;
        goto LABEL_173;
      }
      v5 = v99;
      if ( (*(_BYTE *)(v99 + 14) & 2) != 0 )
        v7 = v99 - ObpInfoMaskToOffset[*(_BYTE *)(v99 + 14) & 3];
      else
        v7 = 0;
      if ( v7 )
      {
        v91 = varg_r1;
        v43 = varg_r1 + 8;
        v84 = varg_r1 + 8;
        v44 = (_WORD *)(v95 + varg_r1 - 2);
        v92 = v44;
        *v44 = 0;
        v89 = varg_r0;
        v8 = v86;
        if ( varg_r0 != v86 && varg_r0 != ObpRootDirectoryObject )
        {
          v45 = *(unsigned __int16 *)(v7 + 4);
          v44 = (_WORD *)((char *)v44 - v45);
          v92 = v44;
          if ( (unsigned int)v44 <= v43 )
          {
            v46 = 1;
            v83 = varg_r3;
            goto LABEL_164;
          }
          memmove((int)v44, *(_DWORD *)(v7 + 8), v45);
          v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v47 + 308);
          v48 = (unsigned int *)(v5 + 8);
          v49 = KeAbPreAcquire(v5 + 8, 0, 0);
          v93 = v49;
          v102 = 0;
          v94 = 17;
          do
            v50 = __ldrex(v48);
          while ( !v50 && __strex(0x11u, v48) );
          __dmb(0xBu);
          v94 = v50;
          if ( v50 )
          {
            ExfAcquirePushLockSharedEx((_DWORD *)(v5 + 8), v49, v5 + 8);
            v49 = v93;
          }
          if ( v49 )
            *(_BYTE *)(v49 + 14) |= 1u;
          v51 = *(_DWORD *)v7;
          if ( *(_DWORD *)v7 )
          {
            ObfReferenceObject(*(_DWORD *)v7);
            v85 = v51;
            v88 = v51;
          }
          v101 = 17;
          v93 = 0;
          __dmb(0xBu);
          v52 = (unsigned int *)(v5 + 8);
          do
            v53 = __ldrex(v52);
          while ( v53 == 17 && __strex(0, v52) );
          v93 = v53;
          if ( v53 != 17 )
            ExfReleasePushLockShared((_DWORD *)(v5 + 8));
          KeAbPostRelease(v5 + 8);
          v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v55 = *(_WORD *)(v54 + 0x134) + 1;
          *(_WORD *)(v54 + 308) = v55;
          if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
            KiCheckForKernelApcDelivery(308);
          while ( 1 )
          {
            if ( v51 == v8 || v51 == ObpRootDirectoryObject || !v51 )
            {
              v43 = v84;
              goto LABEL_160;
            }
            v56 = v44 - 1;
            v92 = v44 - 1;
            *(v44 - 1) = 92;
            v57 = v51 - 24;
            v93 = v57;
            if ( (*(_BYTE *)(v57 + 14) & 2) != 0 )
              v58 = v57 - ObpInfoMaskToOffset[*(_BYTE *)(v57 + 14) & 3];
            else
              v58 = 0;
            v59 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v59 + 308);
            v94 = v57 + 8;
            v87 = KeAbPreAcquire(v57 + 8, 0, 0);
            v100 = 0;
            v97 = 17;
            v60 = (unsigned int *)(v57 + 8);
            do
              v61 = __ldrex(v60);
            while ( !v61 && __strex(0x11u, v60) );
            __dmb(0xBu);
            v97 = v61;
            v62 = v87;
            if ( v61 )
            {
              ExfAcquirePushLockSharedEx(v60, v87, v57 + 8);
              v62 = v87;
            }
            if ( v62 )
              *(_BYTE *)(v62 + 14) |= 1u;
            if ( !v58 || !*(_DWORD *)v58 )
              break;
            ObfDereferenceObject(v85);
            v51 = *(_DWORD *)v58;
            ObfReferenceObject(*(_DWORD *)v58);
            v85 = v51;
            v88 = v51;
            v63 = *(unsigned __int16 *)(v58 + 4);
            v97 = (unsigned int)v56 - v63;
            v92 = (_WORD *)((char *)v56 - v63);
            if ( (unsigned int)v56 - v63 <= v84 )
            {
              v46 = 1;
              v68 = (unsigned int *)(v93 + 8);
              v104 = 17;
              __dmb(0xBu);
              do
                v69 = __ldrex(v68);
              while ( v69 == 17 && __strex(0, v68) );
              if ( v69 != 17 )
                ExfReleasePushLockShared(v68);
              v70 = KeAbPostRelease((unsigned int)v68);
              v71 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v72 = *(_WORD *)(v71 + 0x134) + 1;
              *(_WORD *)(v71 + 308) = v72;
              if ( !v72 && *(_DWORD *)(v71 + 100) != v71 + 100 && !*(_WORD *)(v71 + 310) )
                KiCheckForKernelApcDelivery(v70);
              v83 = varg_r3;
              goto LABEL_164;
            }
            memmove((int)v56 - v63, *(_DWORD *)(v58 + 8), v63);
            v103 = 17;
            v87 = 0;
            __dmb(0xBu);
            v64 = (unsigned int *)v94;
            do
              v65 = __ldrex(v64);
            while ( v65 == 17 && __strex(0, v64) );
            v87 = v65;
            if ( v65 != 17 )
              ExfReleasePushLockShared(v64);
            KeAbPostRelease((unsigned int)v64);
            v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v67 = *(_WORD *)(v66 + 0x134) + 1;
            *(_WORD *)(v66 + 308) = v67;
            if ( !v67 && *(_DWORD *)(v66 + 100) != v66 + 100 && !*(_WORD *)(v66 + 310) )
              KiCheckForKernelApcDelivery(308);
            v44 = (_WORD *)v97;
          }
          v73 = (unsigned int *)(v57 + 8);
          v105 = 17;
          v96 = 0;
          __dmb(0xBu);
          do
            v74 = __ldrex(v73);
          while ( v74 == 17 && __strex(0, v73) );
          v96 = v74;
          if ( v74 != 17 )
            ExfReleasePushLockShared(v73);
          v75 = KeAbPostRelease((unsigned int)v73);
          v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v77 = *(_WORD *)(v76 + 0x134) + 1;
          *(_WORD *)(v76 + 308) = v77;
          if ( !v77 && *(_DWORD *)(v76 + 100) != v76 + 100 && !*(_WORD *)(v76 + 310) )
            KiCheckForKernelApcDelivery(v75);
          v44 = v56 - 3;
          v92 = v56 - 3;
          v43 = v84;
          if ( (unsigned int)(v56 - 3) < v84 )
          {
            v44 = (_WORD *)v84;
            v92 = (_WORD *)v84;
          }
          qmemcpy(v44, "...", 6);
          if ( v44 == (_WORD *)v84 )
            v92 = ++v44;
        }
LABEL_160:
        v78 = v44 - 1;
        v92 = v44 - 1;
        *v78 = 92;
        v79 = v91;
        v80 = (unsigned __int16)(v95 - ((_WORD)v44 - 2) + v91);
        *(_WORD *)(v91 + 2) = v80;
        *(_WORD *)v79 = v80 - 2;
        *(_DWORD *)(v79 + 4) = v43;
        if ( (_WORD *)v43 == v78 )
        {
          v83 = varg_r3;
        }
        else
        {
          memmove(v43, (int)v78, v80);
          v83 = varg_r3;
          *varg_r3 = v80 + 8;
        }
        v46 = 0;
LABEL_164:
        if ( v85 )
          ObfDereferenceObject(v85);
        if ( v46 )
        {
          if ( (*(_BYTE *)(v5 + 14) & 2) != 0 )
            v7 = v5 - ObpInfoMaskToOffset[*(_BYTE *)(v5 + 14) & 3];
          else
            v7 = 0;
          v12 = varg_r2;
          v87 = varg_r2;
          goto LABEL_15;
        }
LABEL_20:
        v11 = 0;
        goto LABEL_173;
      }
      v14 = varg_r3;
      v83 = varg_r3;
      v12 = varg_r2;
      v87 = varg_r2;
      v13 = varg_r1;
      v15 = varg_r0;
      v8 = v86;
    }
  }
  v10 = v7 && *(_WORD *)(v7 + 4);
  v11 = v9(a1, v10, v91, v87, a4, a5);
  v90 = v11;
LABEL_173:
  if ( v8 )
    ObfDereferenceObject(v8);
  return v11;
}
