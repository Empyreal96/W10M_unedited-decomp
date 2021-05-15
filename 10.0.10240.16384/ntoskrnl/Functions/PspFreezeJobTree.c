// PspFreezeJobTree 
 
int __fastcall PspFreezeJobTree(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r9
  int v9; // r10
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r6
  int v14; // r8
  int v15; // r3
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int *v21; // r1
  int v22; // r3
  _DWORD *v23; // t1
  int v24; // r2
  int v25; // lr
  unsigned int *v26; // r6
  unsigned int v27; // r4
  unsigned int v28; // r0
  unsigned int v29; // r1
  int v30; // r2
  int *v31; // r1
  _DWORD *v32; // t1
  bool v34; // zf
  unsigned __int8 *v35; // r3
  unsigned int v36; // r2
  unsigned __int8 *v37; // r3
  unsigned int v38; // r2
  unsigned int v39; // r4
  char *v40; // r6
  unsigned __int64 v41; // t1
  unsigned __int64 v42; // kr18_8
  char v43; // r2
  int v44; // r3
  unsigned int v45; // r2
  unsigned int v46; // r2
  int v47; // r2
  int *v48; // r1
  _DWORD *v49; // t1
  int v50; // [sp+10h] [bp-88h] BYREF
  int v51; // [sp+14h] [bp-84h]
  int v52[2]; // [sp+18h] [bp-80h] BYREF
  __int64 v53; // [sp+20h] [bp-78h] BYREF
  int v54; // [sp+28h] [bp-70h]
  int v55; // [sp+30h] [bp-68h] BYREF
  int v56; // [sp+38h] [bp-60h] BYREF
  char v57; // [sp+3Dh] [bp-5Bh]
  char v58[80]; // [sp+48h] [bp-50h] BYREF

  v8 = 0;
  v53 = 0i64;
  v9 = 0;
  memset(v58, 0, 48);
  v10 = *(_DWORD *)(a2 + 8);
  v11 = *(_DWORD *)a2;
  v12 = 0;
  v13 = 0;
  v54 = v10;
  v14 = 0;
  v55 = a2;
  v50 = 0;
  v52[0] = 0;
  if ( (v11 & 2) == 0 || (v10 & ~a1[125]) == 0 )
  {
LABEL_7:
    v20 = 0;
    v21 = v52;
    while ( 1 )
    {
      v23 = (_DWORD *)*v21++;
      v22 = (int)v23;
      if ( a1 == v23 )
        break;
      if ( ++v20 )
      {
        ExAcquireResourceExclusiveLite((int)(a1 + 8), 1, v20, v22);
        v12 = v50;
        break;
      }
    }
    v24 = *(_DWORD *)a2;
    if ( (*(_DWORD *)a2 & 1) != 0 )
    {
      if ( !*(_BYTE *)(a2 + 4) )
        goto LABEL_50;
      if ( (a1[186] & 0x200) != 0 )
        goto LABEL_43;
      if ( !*(_BYTE *)(a2 + 4) )
      {
LABEL_50:
        if ( (a1[186] & 0x200) == 0 )
          goto LABEL_43;
      }
    }
    if ( (v24 & 4) == 0 )
      goto LABEL_13;
    if ( !*(_BYTE *)(a2 + 5) )
      goto LABEL_42;
    if ( (a1[186] & 0x80000) != 0 )
    {
LABEL_43:
      v12 = -1073741811;
LABEL_69:
      v47 = 0;
      v48 = v52;
      v50 = v12;
      while ( 1 )
      {
        v49 = (_DWORD *)*v48++;
        if ( a1 == v49 )
          break;
        if ( ++v47 )
        {
          ExReleaseResourceLite((int)(a1 + 8));
          v12 = v50;
          break;
        }
      }
      if ( !v13 )
        return v12;
      ExReleaseResourceLite(v13 + 32);
      return v50;
    }
    if ( !*(_BYTE *)(a2 + 5) )
    {
LABEL_42:
      if ( (a1[186] & 0x80000) == 0 )
        goto LABEL_43;
    }
LABEL_13:
    if ( (v24 & 2) != 0 )
    {
      v25 = v54 & ~a1[125];
      if ( v25 )
      {
        v26 = (unsigned int *)(v13 + 748);
        v27 = *v26;
        __dmb(0xBu);
        while ( (v27 & v25) == 0 )
        {
          v28 = v27;
          __dmb(0xBu);
          do
            v29 = __ldrex(v26);
          while ( v29 == v27 && __strex(v27 | v25, v26) );
          v27 = v29;
          __dmb(0xBu);
          if ( v29 == v28 )
          {
            v9 = HIDWORD(v53);
            v8 = v53;
            v12 = v50;
            v13 = v52[0];
            a1[125] |= v25;
            goto LABEL_22;
          }
        }
        v12 = -1073741637;
        v13 = v52[0];
        goto LABEL_69;
      }
LABEL_22:
      if ( (a1[186] & 0x800) != 0 )
      {
        PspComputeReportWakeFilter(a1, &v53, a2 + 8, 1);
        v9 = HIDWORD(v53);
        v8 = v53;
        if ( v53 )
          memmove((int)v58, (int)(a1 + 108), 0x30u);
      }
      a1[122] = *(_DWORD *)(a2 + 8);
      a1[123] = *(_DWORD *)(a2 + 12);
    }
    if ( (*(_DWORD *)a2 & 1) != 0 )
    {
      v34 = *(_BYTE *)(a2 + 4) == 0;
      __dmb(0xBu);
      v37 = (unsigned __int8 *)a1 + 745;
      if ( v34 )
      {
        do
          v46 = __ldrex(v37);
        while ( __strex(v46 & 0xFD, v37) );
      }
      else
      {
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 | 2, v37) );
      }
      __dmb(0xBu);
      v12 = v50;
      v14 = 5;
    }
    if ( (*(_DWORD *)a2 & 4) != 0 )
    {
      v34 = *(_BYTE *)(a2 + 5) == 0;
      __dmb(0xBu);
      v35 = (unsigned __int8 *)a1 + 746;
      if ( v34 )
      {
        do
          v45 = __ldrex(v35);
        while ( __strex(v45 & 0xF7, v35) );
      }
      else
      {
        do
          v36 = __ldrex(v35);
        while ( __strex(v36 | 8, v35) );
      }
      __dmb(0xBu);
      v12 = v50;
      v14 = 5;
    }
    if ( v14 )
    {
      PspEnumJobsAndProcessesInJobHierarchy(
        a1,
        PspSetJobFreezeCountCallback,
        0,
        PspSetProcessFreezeStateCallback,
        &v55,
        v14);
      v12 = v50;
    }
    v30 = 0;
    v31 = v52;
    while ( 1 )
    {
      v32 = (_DWORD *)*v31++;
      if ( a1 == v32 )
        break;
      if ( ++v30 )
      {
        ExReleaseResourceLite((int)(a1 + 8));
        v12 = v50;
        break;
      }
    }
    if ( v13 )
    {
      ExReleaseResourceLite(v13 + 32);
      v12 = v50;
    }
    if ( v14 )
    {
      PspEnumJobsAndProcessesInJobHierarchy(a1, 0, PspExecuteJobFreezeThawCallback, 0, &v50, 0);
      v12 = v50;
      if ( v50 < 0 )
      {
        *(_DWORD *)a2 &= 0xFFFFFFFB;
        v56 = 4;
        v57 = 0;
        PspFreezeJobTree(a1, &v56);
        v12 = 262;
        v50 = 262;
      }
    }
    if ( !(v9 | v8) )
      return v12;
    v39 = 0;
    v40 = v58;
    do
    {
      v41 = *((_QWORD *)v40 + 1);
      v40 += 8;
      v42 = v41;
      v43 = 0;
      v44 = v41 | HIDWORD(v41);
      if ( v41 )
        v43 = 3;
      if ( PspSendWakeNotification((unsigned int)a1, v39, &v53, v44, v42, v43) )
        break;
      ++v39;
    }
    while ( v39 < 5 );
    return v50;
  }
  v15 = a1[144];
  __dmb(0xBu);
  v51 = v15;
  __dmb(0xBu);
  v16 = ExAcquireResourceExclusiveLite(v15 + 32, 1, v10, v15);
  v18 = v51;
  __dmb(0xBu);
  v19 = a1[144];
  __dmb(0xBu);
  if ( v18 == v19 )
  {
    v13 = v51;
    v52[0] = v51;
    __dmb(0xBu);
    if ( a1 != (_DWORD *)v13 )
      ExConvertExclusiveToSharedLite(v51 + 32);
    v12 = v50;
    v9 = HIDWORD(v53);
    v8 = v53;
    goto LABEL_7;
  }
  return sub_7C2574(v16, v17, v51, v19, a5, a6);
}
