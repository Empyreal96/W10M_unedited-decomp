// PfSnPopulateReadList 
 
unsigned __int8 *__fastcall PfSnPopulateReadList(int a1)
{
  unsigned int *v1; // r4
  int v2; // r7
  int v3; // r9
  unsigned int *v4; // r5
  unsigned int v5; // r10
  unsigned int v6; // r6
  unsigned int v7; // r3
  int v8; // r0
  unsigned int v9; // r0
  int v10; // r8
  int v11; // r1
  int v12; // lr
  unsigned int v13; // r1
  int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r0
  unsigned int v18; // r3
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v22; // r4
  unsigned __int8 *result; // r0
  unsigned int v24; // r1
  int v25; // r4
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r0
  int v29; // r9
  bool v30; // zf
  _WORD *v31; // r6
  int *v32; // r5
  _DWORD *v33; // r0
  int *v34; // r1
  int v35; // r7
  int v36; // r0
  int v37; // lr
  int v38; // r5
  int v39; // r1
  __int64 v40; // r2
  int v41; // r4
  unsigned int *v42; // r0
  unsigned int v43; // r2
  __int64 v44; // kr00_8
  int v45; // r2
  unsigned int *v46; // r1
  unsigned int v47; // r2
  unsigned int v48; // r2
  unsigned int v49; // r1
  unsigned int *v50; // r0
  unsigned int v51; // r2
  unsigned int *v52; // r1
  unsigned int v53; // r2
  unsigned int v54; // r2
  unsigned int v55; // r1
  unsigned int v56; // r3
  char v57[4]; // [sp+18h] [bp-A0h] BYREF
  int v58; // [sp+1Ch] [bp-9Ch]
  unsigned int *v59; // [sp+20h] [bp-98h]
  unsigned int v60; // [sp+24h] [bp-94h]
  int v61; // [sp+28h] [bp-90h] BYREF
  unsigned int *v62; // [sp+2Ch] [bp-8Ch]
  int v63; // [sp+30h] [bp-88h] BYREF
  int v64; // [sp+34h] [bp-84h]
  int v65; // [sp+38h] [bp-80h]
  unsigned int v66; // [sp+3Ch] [bp-7Ch]
  unsigned int *v67; // [sp+40h] [bp-78h]
  int v68; // [sp+44h] [bp-74h]
  int v69; // [sp+48h] [bp-70h]
  unsigned int *v70; // [sp+4Ch] [bp-6Ch]
  int v71; // [sp+50h] [bp-68h]
  unsigned int *v72; // [sp+54h] [bp-64h]
  int v73; // [sp+58h] [bp-60h]
  unsigned int v74; // [sp+5Ch] [bp-5Ch]
  int v75[6]; // [sp+60h] [bp-58h] BYREF
  char v76[8]; // [sp+78h] [bp-40h] BYREF
  char v77[56]; // [sp+80h] [bp-38h] BYREF

  v1 = *(unsigned int **)(a1 + 16);
  v2 = 0;
  v3 = a1;
  v4 = (unsigned int *)v1[1];
  v69 = a1;
  v59 = v4;
  v62 = v1;
  v5 = 0;
  v57[0] = 0;
  __mrc(15, 0, 13, 0, 3);
  v63 = 0;
  v6 = 0;
  KiStackAttachProcess(v1[2], 0, (int)v77);
  PsSetCurrentThreadPrefetching(1);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v75[1] = 0;
  v75[3] = 512;
  v75[4] = 0;
  v75[0] = 24;
  v75[2] = 0;
  v75[5] = 0;
  v8 = NtCreateEvent((unsigned int)&v63, 2031619, (int)v75, 0, 0);
  if ( v8 >= 0 )
  {
    v9 = *v4;
    v10 = *(_DWORD *)(v3 + 20);
    v11 = *(_DWORD *)(*v4 + 100);
    v12 = *(_DWORD *)(*v4 + 84) + *v4;
    v66 = *(_DWORD *)(*v4 + 92) + *v4;
    v68 = v11 + v9;
    v13 = v4[32];
    v74 = v4[27];
    v14 = v4[28];
    v61 = 0;
    v71 = v12;
    v64 = v14;
    v65 = 0;
    v73 = v4[31] & 7 | (8 * (v13 & 7 | 8));
    __dmb(0xBu);
    v15 = v1 + 4;
    v67 = v1 + 4;
    do
    {
      v16 = __ldrex(v15);
      v17 = v16 + 1;
    }
    while ( __strex(v17, v15) );
    __dmb(0xBu);
    v18 = v1[5];
    v6 = v17 - 1;
    v60 = v17 - 1;
    if ( v17 - 1 >= v18 )
      goto LABEL_5;
    v70 = v1 + 3;
    v72 = v1 + 6;
    while ( 1 )
    {
      v25 = v12 + 32 * v6;
      v26 = *(_DWORD *)(v25 + 20);
      if ( (v26 & 1) != 0 )
        goto LABEL_50;
      v27 = *(_DWORD *)(v3 + 24);
      v28 = 0;
      v58 = 0;
      v29 = v27 & 1;
      if ( (v27 & 1) != 0 )
        break;
      v55 = __clz(__rbit((v26 >> 8) & 0x7F));
      if ( 1 == (unsigned __int8)(v55 >> 5) )
        LOBYTE(v55) = 7;
      if ( ((1 << v55) & v10) != 0 )
      {
        v28 = 1;
        v58 = 1;
      }
      if ( (v10 & (v26 >> 1) & 0x7F) == 0 )
      {
        v30 = v28 == 0;
LABEL_19:
        if ( v30 )
          goto LABEL_50;
      }
      v31 = (_WORD *)(*(_DWORD *)(v25 + 12) + v68);
      v32 = PfSnFindPrefetchVolumeInfoInList(v31, (int **)v4 + 24, 0);
      if ( v32 )
      {
        v33 = (_DWORD *)ExAllocatePoolWithTag(512, 8 * (*(_DWORD *)(v25 + 8) + 3), 1280336707);
        v5 = (unsigned int)v33;
        if ( !v33 )
        {
          v8 = -1073741670;
          v4 = v59;
          v6 = v60;
          v1 = v62;
          goto LABEL_76;
        }
        *v33 = 0;
        v33[1] = 0;
        v33[2] = v29;
        RtlInitUnicodeString((unsigned int)v76, &v31[v32[3] + 1]);
        v6 = v60;
        v34 = v32;
        v4 = v59;
        if ( PfSnGetSectionObject(v59, v34, (int)v76, v25, v10, v60, v29, v63, &v61, v57) >= 0 )
        {
          v35 = v58;
          v36 = v61;
          v37 = 1;
          if ( v58 )
          {
            v38 = 1;
            v56 = v5 + 8 * *(_DWORD *)(v5 + 4);
            *(_DWORD *)(v56 + 16) = 0;
            *(_DWORD *)(v56 + 20) = 0;
            ++*(_DWORD *)(v5 + 4);
            if ( !*(_DWORD *)(*(_DWORD *)(v36 + 20) + 8) )
              v37 = 0;
          }
          else
          {
            v38 = v65;
          }
          v40 = *(_QWORD *)v25;
          v39 = 0;
          v58 = 0;
          HIDWORD(v40) += v40;
          if ( (int)v40 < SHIDWORD(v40) )
          {
            v41 = HIDWORD(v40) - v40;
            v42 = (unsigned int *)(v66 + 8 * v40);
            while ( 1 )
            {
              v43 = v42[1];
              if ( (v43 & 1) == 0 )
              {
                if ( (v43 & 8) == 0 || v37 )
                {
                  if ( ((1 << ((v43 >> 4) & 7)) & v10) == 0 )
                    goto LABEL_34;
                  if ( v29 )
                  {
                    if ( (v43 & 2) == 0 )
                      goto LABEL_34;
                  }
                  else if ( (v43 & 4) == 0 )
                  {
                    goto LABEL_34;
                  }
                }
                if ( !*v42 && v35 )
                  return (unsigned __int8 *)sub_801504();
                *(_QWORD *)(v5 + 8 * (*(_DWORD *)(v5 + 4))++ + 16) = (unsigned __int64)*v42 << 9;
                ++v38;
              }
LABEL_34:
              v39 = v58;
              v42 += 2;
              if ( !--v41 )
              {
                v6 = v60;
                v36 = v61;
                break;
              }
            }
          }
          if ( *(_DWORD *)(v5 + 4) != 1 || !v35 || !v37 || v39 )
          {
            v44 = *(_QWORD *)(v5 + 16);
            v45 = v73;
            *(_DWORD *)(v5 + 20) = HIDWORD(v44);
            *(_DWORD *)(v5 + 16) = v45 | v44;
            *(_DWORD *)v5 = v36;
            __dmb(0xBu);
            v46 = v70;
            do
            {
              v47 = __ldrex(v46);
              v48 = v47 + 1;
            }
            while ( __strex(v48, v46) );
            __dmb(0xBu);
            v49 = v48 - 1;
            *(_DWORD *)(v74 + 4 * (v48 - 1)) = v5;
            v5 = 0;
            __dmb(0xBu);
            v50 = v72;
            do
              v51 = __ldrex(v50);
            while ( __strex(v51 + v38, v50) );
            __dmb(0xBu);
            v2 = (unsigned __int8)v57[0];
            if ( v57[0] )
            {
              v2 = 0;
              v57[0] = 0;
              *(_DWORD *)(v64 + 4 * v49) = v6;
            }
            else
            {
              *(_DWORD *)(v64 + 4 * v49) = -1;
            }
            goto LABEL_54;
          }
          v4 = v59;
        }
        v2 = (unsigned __int8)v57[0];
      }
      else
      {
        v4 = v59;
        v6 = v60;
      }
LABEL_50:
      if ( v2 )
      {
        PfSnCleanupPrefetchSectionInfo(v4[26] + 32 * v6, v4, 1);
        v2 = 0;
        v57[0] = 0;
      }
      if ( v5 )
      {
        ExFreePoolWithTag(v5);
        v5 = 0;
      }
LABEL_54:
      v65 = 0;
      __dmb(0xBu);
      v52 = v67;
      do
      {
        v53 = __ldrex(v52);
        v54 = v53 + 1;
      }
      while ( __strex(v54, v52) );
      __dmb(0xBu);
      v1 = v62;
      v6 = v54 - 1;
      v4 = v59;
      v60 = v54 - 1;
      if ( v54 - 1 >= v62[5] )
        goto LABEL_70;
      v3 = v69;
      v12 = v71;
    }
    v30 = (v10 & (v26 >> 8) & 0x7F) == 0;
    goto LABEL_19;
  }
LABEL_76:
  v1[7] = v8;
LABEL_70:
  if ( v2 )
    PfSnCleanupPrefetchSectionInfo(v4[26] + 32 * v6, v4, 1);
LABEL_5:
  v19 = v63;
  if ( v63 )
    v19 = NtClose();
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  PsSetCurrentThreadPrefetching(0);
  KiUnstackDetachProcess((unsigned int)v77, 0);
  __pld(v1);
  v22 = *v1 & 0xFFFFFFFE;
  __dmb(0xBu);
  result = (unsigned __int8 *)v62;
  do
    v24 = __ldrex((unsigned int *)result);
  while ( v24 == v22 && __strex(v22 - 2, (unsigned int *)result) );
  if ( v24 != v22 )
    result = ExfReleaseRundownProtection(result);
  return result;
}
