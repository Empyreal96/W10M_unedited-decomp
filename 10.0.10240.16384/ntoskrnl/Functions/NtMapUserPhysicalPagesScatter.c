// NtMapUserPhysicalPagesScatter 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall NtMapUserPhysicalPagesScatter(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r7
  unsigned int v16; // r4
  unsigned int v17; // r0
  unsigned int v18; // r6
  _BYTE *v19; // r8
  int v20; // r10
  int *v21; // r9
  int v22; // r1
  unsigned int v23; // r5
  int v24; // r4
  _DWORD *v25; // r4
  unsigned int *v26; // r7
  unsigned int *v27; // r10
  unsigned __int64 v28; // r2
  unsigned int v29; // r4
  unsigned int v30; // t1
  int v31; // r1
  _DWORD *v32; // r0
  int v33; // r1
  unsigned int *v34; // r1
  unsigned int v35; // lr
  unsigned int v36; // r4
  unsigned int v37; // t1
  unsigned int v38; // r0
  unsigned int v39; // r1
  unsigned int *v40; // r5
  int v41; // r2
  int v42; // t1
  int v43; // r1
  unsigned int v44; // lr
  unsigned int v45; // t1
  unsigned __int64 v46; // r2
  unsigned int v47; // r0
  int v48; // r3
  unsigned int *v49; // r2
  unsigned int v50; // r4
  int *i; // r7
  int v52; // t1
  unsigned int v53; // r0
  int v54; // r0
  int v55; // r3
  unsigned int v56; // r8
  unsigned int v57; // lr
  unsigned int v58; // t1
  unsigned int v59; // r0
  int v60; // r3
  unsigned int *v61; // r2
  unsigned int v62; // r4
  __int64 v63; // r0
  __int16 v64; // r3
  __int16 v65; // r3
  unsigned int *v66; // [sp-C6Ch] [bp-10BCh]
  unsigned int *v67; // [sp-C6Ch] [bp-10BCh]
  unsigned int *v68; // [sp-C6Ch] [bp-10BCh]
  int v69; // [sp-C68h] [bp-10B8h]
  unsigned int v70; // [sp-C64h] [bp-10B4h]
  _BYTE *v71; // [sp-C60h] [bp-10B0h]
  int *v72; // [sp-C5Ch] [bp-10ACh]
  unsigned int *v73; // [sp-C58h] [bp-10A8h]
  unsigned int v74; // [sp-C58h] [bp-10A8h]
  unsigned int v75; // [sp-C54h] [bp-10A4h]
  unsigned __int16 v76; // [sp-C4Ch] [bp-109Ch]
  _DWORD *v77; // [sp-C48h] [bp-1098h]
  _BYTE v78[152]; // [sp-C44h] [bp-1094h] BYREF
  _BYTE v79[2048]; // [sp-BACh] [bp-FFCh] BYREF
  int v80; // [sp-3ACh] [bp-7FCh] BYREF

  _chkstk();
  v15 = v14;
  v16 = v13;
  v75 = v14;
  v18 = v17;
  if ( v13 > 0xFFFFF )
    goto LABEL_71;
  v19 = v79;
  v20 = 4 * v13;
  v21 = &v80;
  v71 = v79;
  v22 = 4 * v13;
  if ( v16 > 0x200 )
  {
    if ( v14 )
      v22 = 8 * v16;
    v19 = (_BYTE *)ExAllocatePoolWithTag(512, v22, 2001890637);
    v71 = v19;
    if ( !v19 )
      goto LABEL_71;
  }
  if ( MiCaptureUlongPtrArray((int)v19, v18, v16) < 0 )
    goto LABEL_69;
  if ( !v16 )
    goto LABEL_71;
  if ( v15 )
  {
    if ( v16 > 0x200 )
      v21 = (int *)&v19[v20];
    if ( MiCaptureUlongPtrArray((int)v21, v15, v16) < 0 )
      goto LABEL_69;
  }
  v72 = &v21[v20 / 4u];
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_DWORD *)(v23 + 0x74);
  v70 = v23;
  MiInitializeTbFlushList((int)v78, 1, 33);
  v66 = (unsigned int *)&v19[v20];
  v25 = *(_DWORD **)(v24 + 328);
  v26 = (unsigned int *)v21;
  v76 = dword_681120 & 0x1CD;
  v77 = v25;
  if ( !v25 || !*v25 )
    goto LABEL_69;
  --*(_WORD *)(v23 + 310);
  v69 = ExAcquireAutoExpandPushLockShared((int)(v25 + 1), 0);
  v73 = (unsigned int *)*v25;
  v27 = (unsigned int *)v19;
  LODWORD(v28) = 0;
  do
  {
    v30 = *v27++;
    v29 = v30;
    if ( (_DWORD)v28 )
    {
      v31 = *(_DWORD *)(v28 + 12);
      if ( v29 >= *(_DWORD *)(v31 + 12) << 12 && v29 <= ((*(_DWORD *)(v31 + 16) << 12) | 0xFFFu) )
        continue;
    }
    v32 = MiLocatePhysicalViewInTree(v29 >> 12, v77 + 4);
    LODWORD(v28) = v32;
    if ( v32 )
    {
      v33 = v32[3];
      HIDWORD(v28) = *(_DWORD *)(v33 + 12);
      if ( v29 >= HIDWORD(v28) << 12 )
      {
        HIDWORD(v28) = (*(_DWORD *)(v33 + 16) << 12) | 0xFFF;
        if ( v29 <= HIDWORD(v28) )
          continue;
      }
    }
    v54 = ExReleaseAutoExpandPushLockShared((unsigned int)v69, v28);
    v65 = *(_WORD *)(v23 + 310) + 1;
    *(_WORD *)(v23 + 310) = v65;
    if ( !v65 && *(_DWORD *)(v23 + 100) != v23 + 100 )
      goto LABEL_68;
    goto LABEL_69;
  }
  while ( v27 < v66 );
  v34 = (unsigned int *)v19;
  if ( v75 )
  {
    v35 = *v73;
    v74 = v73[1];
    HIDWORD(v28) = v72;
    do
    {
      v37 = *v26++;
      v36 = v37;
      if ( v37 )
      {
        if ( v36 >= v35 )
          goto LABEL_46;
        LODWORD(v28) = v36 & 0x1F;
        v23 = v70;
        HIDWORD(v28) = *(_DWORD *)(v74 + 4 * (v36 >> 5)) >> (v36 & 0x1F);
        if ( (v28 & 0x100000000i64) == 0 )
          goto LABEL_46;
        v38 = ((*v34 >> 10) & 0x3FFFFC) - 0x40000000;
        v67 = v34 + 1;
        HIDWORD(v28) = MmPfnDatabase + 24 * v36;
        LODWORD(v28) = HIDWORD(v28) + 4;
        do
        {
          v39 = __ldrex((unsigned int *)v28);
          if ( v39 )
            break;
          HIDWORD(v28) = __strex(v38, (unsigned int *)v28);
        }
        while ( HIDWORD(v28) );
        if ( v39 )
        {
LABEL_46:
          for ( i = (int *)(v26 - 1); i > v21; --i )
          {
            v52 = *(i - 1);
            HIDWORD(v28) = v52;
            if ( v52 )
            {
              HIDWORD(v28) = MmPfnDatabase + 24 * HIDWORD(v28);
              __dmb(0xBu);
              LODWORD(v28) = HIDWORD(v28) + 4;
              do
              {
                v53 = __ldrex((unsigned int *)v28);
                HIDWORD(v28) = __strex(0, (unsigned int *)v28);
              }
              while ( HIDWORD(v28) );
            }
          }
          v54 = ExReleaseAutoExpandPushLockShared((unsigned int)v69, v28);
          v55 = (__int16)(*(_WORD *)(v23 + 310) + 1);
          *(_WORD *)(v23 + 310) = v55;
          if ( !v55 && *(_DWORD *)(v23 + 100) != v23 + 100 )
LABEL_68:
            KiCheckForKernelApcDelivery(v54);
LABEL_69:
          if ( v19 != v79 )
            ExFreePoolWithTag((unsigned int)v19);
LABEL_71:
          __asm { POP.W           {R4-R11,PC} }
        }
        v34 = v67;
        HIDWORD(v28) = v72;
      }
      else
      {
        ++v34;
      }
    }
    while ( (unsigned int)v26 < HIDWORD(v28) );
    v40 = (unsigned int *)v19;
    do
    {
      v42 = *v21++;
      v41 = v42;
      if ( v42 )
        v43 = (v76 | 0xF832) & 0xFFF | (v41 << 12);
      else
        v43 = 0;
      v45 = *v40++;
      v44 = v45;
      __dmb(0xBu);
      LODWORD(v46) = ((v45 >> 10) & 0x3FFFFC) - 0x40000000;
      do
        v47 = __ldrex((unsigned int *)v46);
      while ( __strex(v43, (unsigned int *)v46) );
      __dmb(0xBu);
      if ( (v47 & 2) != 0 )
      {
        v48 = MmPfnDatabase + 24 * (v47 >> 12);
        __dmb(0xBu);
        v49 = (unsigned int *)(v48 + 4);
        do
          v50 = __ldrex(v49);
        while ( __strex(0, v49) );
        MiInsertTbFlushEntry((int)v78, v44 & 0xFFFFF000, 1, 0);
      }
      HIDWORD(v46) = v72;
    }
    while ( v21 < v72 );
  }
  else
  {
    v56 = (unsigned int)v66;
    do
    {
      v58 = *v34++;
      v57 = v58;
      v68 = v34;
      __dmb(0xBu);
      LODWORD(v46) = ((v58 >> 10) & 0x3FFFFC) - 0x40000000;
      do
      {
        v59 = __ldrex((unsigned int *)v46);
        HIDWORD(v46) = __strex(0, (unsigned int *)v46);
      }
      while ( HIDWORD(v46) );
      __dmb(0xBu);
      if ( (v59 & 2) != 0 )
      {
        v60 = MmPfnDatabase + 24 * (v59 >> 12);
        __dmb(0xBu);
        v61 = (unsigned int *)(v60 + 4);
        do
          v62 = __ldrex(v61);
        while ( __strex(0, v61) );
        MiInsertTbFlushEntry((int)v78, v57 & 0xFFFFF000, 1, 0);
        v34 = v68;
      }
    }
    while ( (unsigned int)v34 < v56 );
  }
  v19 = v71;
  v63 = ExReleaseAutoExpandPushLockShared((unsigned int)v69, v46);
  v64 = *(_WORD *)(v70 + 310) + 1;
  *(_WORD *)(v70 + 310) = v64;
  if ( !v64 && *(_DWORD *)(v70 + 100) != v70 + 100 )
    KiCheckForKernelApcDelivery(v63);
  MiFlushTbList((unsigned int)v78, SHIDWORD(v63));
  goto LABEL_69;
}
