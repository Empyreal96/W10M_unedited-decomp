// PspProcessDelete 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspProcessDelete(int a1)
{
  int v1; // r7
  unsigned int v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  __int64 v5; // r0
  unsigned int v6; // r1
  int v7; // r0
  __int16 v8; // r3
  unsigned int v9; // r0
  int v10; // r3
  int v11; // r0
  int v12; // r3
  int v13; // r0
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r0
  unsigned int v17; // r1 OVERLAPPED
  unsigned int v18; // r2 OVERLAPPED
  unsigned int v19; // r0
  unsigned int v20; // r5
  unsigned int v21; // r1
  unsigned int v22; // r2
  int v23; // r7
  int v24; // r10
  int *v25; // r9
  int v26; // r1
  int v27; // r0
  int v28; // r6
  char v29; // lr
  char v30; // r8
  char v31; // r4
  __int64 v32; // kr10_8
  unsigned int v33; // r1
  unsigned int v34; // r5
  int v35; // r4
  unsigned int v36; // t1
  unsigned int v37; // r1
  unsigned int v38; // r5
  int v39; // r4
  int v40; // r8
  int v41; // lr
  char v42; // r0
  int v43; // r5
  int v44; // r4
  unsigned int v45; // r10
  char *v46; // r3
  unsigned __int8 *v47; // r1
  char v48; // r9
  unsigned int v49; // r7
  char v50; // r6
  unsigned __int64 v51; // kr30_8
  char v52; // r6
  unsigned int v53; // r5
  unsigned int v54; // kr38_4
  int v55; // r1
  char v56; // r3
  int v57; // r0
  int *v58; // r7
  char v59; // r10
  char v60; // r9
  char v61; // r4
  int v62; // r6
  int v63; // r8
  unsigned int v64; // r1
  unsigned int v65; // r5
  int v66; // r4
  int v67; // r8
  int v68; // lr
  char v69; // r6
  int v70; // r9
  int *v71; // r7
  unsigned int v72; // t1
  unsigned int v73; // r1
  unsigned int v74; // r5
  int v75; // r4
  __int64 v76; // kr58_8
  unsigned int v77; // r8
  unsigned int v78; // r9
  unsigned __int64 v79; // r0
  __int64 v80; // r2
  int v82; // r0
  int v83; // [sp+0h] [bp-70h]
  __int64 v84; // [sp+4h] [bp-6Ch]
  int v86; // [sp+10h] [bp-60h]
  int *v87; // [sp+10h] [bp-60h]
  char v88; // [sp+14h] [bp-5Ch]
  int v89; // [sp+18h] [bp-58h]
  int v90; // [sp+1Ch] [bp-54h]
  char v91[56]; // [sp+38h] [bp-38h] BYREF

  v1 = a1;
  *(_DWORD *)(a1 + 192) &= 0xFBFFFFFF;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !*(_DWORD *)(a1 + 180) )
    goto LABEL_15;
  --*(_WORD *)(v2 + 310);
  v3 = KeAbPreAcquire((unsigned int)&PspActiveProcessLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&PspActiveProcessLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&PspActiveProcessLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
  {
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    v5 = *(_QWORD *)(v1 + 180);
    if ( *(_DWORD *)(v5 + 4) != v1 + 180 || *(_DWORD *)HIDWORD(v5) != v1 + 180 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v5) = v5;
    *(_DWORD *)(v5 + 4) = HIDWORD(v5);
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&PspActiveProcessLock);
    while ( __strex(v6 - 1, (unsigned int *)&PspActiveProcessLock) );
    if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PspActiveProcessLock);
    v7 = KeAbPostRelease((unsigned int)&PspActiveProcessLock);
    v8 = *(_WORD *)(v2 + 310) + 1;
    *(_WORD *)(v2 + 310) = v8;
    if ( !v8 && *(_DWORD *)(v2 + 100) != v2 + 100 )
      KiCheckForKernelApcDelivery(v7);
LABEL_15:
    v9 = *(_DWORD *)(v1 + 380);
    if ( v9 )
    {
      ExFreePoolWithTag(v9);
      *(_DWORD *)(v1 + 380) = 0;
    }
    v10 = *(_DWORD *)(v1 + 288);
    __dmb(0xBu);
    if ( v10 )
    {
      PspRemoveProcessFromJobChain(v1, 0, 1, 0);
      v82 = *(_DWORD *)(v1 + 288);
      __dmb(0xBu);
      ObDereferenceObjectDeferDelete(v82);
      __dmb(0xBu);
      *(_DWORD *)(v1 + 288) = 0;
      __dmb(0xBu);
      *(_DWORD *)(v1 + 268) = 0;
    }
    if ( *(_DWORD *)(v1 + 804) )
      PspRemoveProcessFromSilo();
    v11 = *(_DWORD *)(v1 + 340);
    if ( v11 )
    {
      ObfDereferenceObject(v11);
      *(_DWORD *)(v1 + 340) = 0;
    }
    v12 = *(_DWORD *)(v1 + 240);
    if ( v12 )
    {
      ObfDereferenceObject(v12 & 0xFFFFFFF8);
      *(_DWORD *)(v1 + 240) = 0;
    }
    if ( (*(_DWORD *)(v1 + 192) & 0x40000) != 0 )
    {
      KiStackAttachProcess(v1, 0, (int)v91);
      if ( *(_DWORD *)(v1 + 780) )
        dword_61D9CC(v1);
      PspExitProcess(0, v1);
      KiUnstackDetachProcess((unsigned int)v91, 0);
      MmDeleteProcessAddressSpace(v1);
    }
    if ( *(_DWORD *)(v1 + 176) )
    {
      --*(_WORD *)(v2 + 310);
      if ( !ExMapHandleToPointer(PspCidTable, *(_DWORD *)(v1 + 176)) )
        KeBugCheck(23);
      v13 = ExDestroyHandle(PspCidTable, *(_DWORD *)(v1 + 176));
      v14 = (__int16)(*(_WORD *)(v2 + 310) + 1);
      *(_WORD *)(v2 + 310) = v14;
      if ( !v14 && *(_DWORD *)(v2 + 100) != v2 + 100 )
        KiCheckForKernelApcDelivery(v13);
    }
    if ( *(_DWORD *)(v1 + 244) )
      SeDeassignPrimaryToken(v1);
    v15 = *(_DWORD *)(v1 + 304);
    if ( v15 )
    {
      ExFreePoolWithTag(v15);
      PsReturnProcessNonPagedPoolQuota(v1, 0x3018u);
    }
    SmProcessDeleteNotification(v1);
    EtwExitProcess(v1);
    LpcExitProcess(v1);
    ExWnfExitProcess(v1, 1);
    v16 = *(_DWORD *)(v1 + 800);
    if ( v16 )
      ExFreePoolWithTag(v16);
    do
    {
      *(_QWORD *)&v17 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v19 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v20 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v19 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v17 != MEMORY[0xFFFF93B0] || v18 != MEMORY[0xFFFF93B4] );
    v22 = (__PAIR64__(v19, v20) - __PAIR64__(v18, v17)) >> 32;
    v21 = v20 - v17;
    v23 = a1;
    if ( __PAIR64__(v22, v21) < qword_641C60 )
      goto LABEL_82;
    __pld(&KeServiceDescriptorTable);
    v24 = 32;
    v25 = &KeServiceDescriptorTable;
    v86 = qword_641C50;
    v26 = qword_641C50;
    v90 = MEMORY[0x641C54];
    v27 = MEMORY[0x641C54];
    v28 = 4;
    v29 = dword_641C58 & 0x3F;
    v30 = 64 - (dword_641C58 & 0x3F);
    v31 = 32 - (dword_641C58 & 0x3F);
    v88 = dword_641C58;
    do
    {
      v32 = *(_QWORD *)v25;
      v25 += 2;
      v24 -= 8;
      v34 = (__PAIR64__(v27, v26) - v32) >> 32;
      v33 = v26 - v32;
      v35 = (v34 << v30) | (v33 >> ((dword_641C58 & 0x3F) - 32)) | (v33 << v31);
      v26 = (v33 << v30) | (__PAIR64__(v34, v33) >> v29);
      v27 = v35 | (v34 >> v29);
      v31 = 32 - (dword_641C58 & 0x3F);
      --v28;
    }
    while ( v28 );
    for ( ; v24; --v24 )
    {
      v36 = *(unsigned __int8 *)v25;
      v25 = (int *)((char *)v25 + 1);
      v38 = (__PAIR64__(v27, v26) - v36) >> 32;
      v37 = v26 - v36;
      v39 = __PAIR64__(v38, v37) << v30 >> 32;
      v26 = (v37 << v30) | (__PAIR64__(v38, v37) >> v29);
      v27 = v39 | (v38 >> v29);
    }
    if ( dword_641C68 == v26 && unk_641C6C == v27 )
    {
      v41 = unk_641C24;
      v40 = dword_641C20;
      v84 = *(_QWORD *)&dword_641C20;
    }
    else
    {
      v84 = *(_QWORD *)&dword_641C20;
      v41 = unk_641C24;
      v40 = dword_641C20;
      if ( !*(_QWORD *)&dword_641C20 )
      {
        v41 = 0;
        v40 = __ROR4__(-2147483516, 31);
        dword_641C20 = v40;
        unk_641C24 = 0;
        unk_641C28 = 0;
        unk_641C2C = 0;
        unk_641C30 = 0;
        unk_641C34 = 0;
        dword_641C38 = 267;
        dword_641C3C = 0;
        dword_641C40 = (int)&KeServiceDescriptorTable;
        dword_641C44 = 0;
        v42 = dword_641C58;
        v44 = MEMORY[0x641C54];
        v43 = qword_641C50;
        v84 = (unsigned int)v40;
        v86 = qword_641C50;
        v88 = dword_641C58;
        v90 = MEMORY[0x641C54];
LABEL_52:
        v45 = 4 * dword_682088;
        v83 = KeServiceDescriptorTable;
        v46 = (char *)KeServiceDescriptorTable;
        if ( KeServiceDescriptorTable < (unsigned int)(KeServiceDescriptorTable + 4 * dword_682088) )
        {
          do
          {
            __pld(v46);
            v46 += 128;
          }
          while ( (unsigned int)v46 < KeServiceDescriptorTable + 4 * dword_682088 );
        }
        v47 = (unsigned __int8 *)KeServiceDescriptorTable;
        if ( v45 >= 8 )
        {
          v48 = 64 - (v42 & 0x3F);
          v49 = v45 >> 3;
          v50 = v42 & 0x3F;
          do
          {
            v45 -= 8;
            v51 = __PAIR64__(v44, v43) - *(_QWORD *)v47;
            v47 = (unsigned __int8 *)(v83 + 8);
            v44 = (HIDWORD(v51) << v48) | ((unsigned int)v51 >> ((v42 & 0x3F) - 32)) | ((_DWORD)v51 << (32 - (v42 & 0x3F))) | (HIDWORD(v51) >> v50);
            --v49;
            v43 = ((_DWORD)v51 << v48) | (v51 >> v50);
            v83 += 8;
          }
          while ( v49 );
          v41 = HIDWORD(v84);
          v40 = v84;
        }
        if ( v45 )
        {
          v52 = 64 - (v88 & 0x3F);
          do
          {
            v54 = v43 - *v47;
            v53 = (__PAIR64__(v44, v43) - *v47++) >> 32;
            v44 = (v53 << v52) | (v54 >> ((v88 & 0x3F) - 32)) | (v54 << (32 - (v88 & 0x3F))) | (v53 >> (v88 & 0x3F));
            --v45;
            v43 = (v54 << v52) | (__PAIR64__(v53, v54) >> (v88 & 0x3F));
          }
          while ( v45 );
          v41 = HIDWORD(v84);
          v40 = v84;
        }
        if ( dword_641C70 == v43 && unk_641C74 == v44 || v40 | v41 )
        {
          v55 = v86;
          v56 = v88;
          v57 = v90;
        }
        else
        {
          dword_641C20 = __ROR4__(271360, 10);
          unk_641C24 = 0;
          unk_641C28 = 0;
          unk_641C2C = 0;
          unk_641C30 = 0;
          unk_641C34 = 0;
          dword_641C38 = 267;
          dword_641C3C = 0;
          v84 = (unsigned int)dword_641C20;
          dword_641C40 = KeServiceDescriptorTable;
          dword_641C44 = 0;
          v56 = dword_641C58;
          v57 = MEMORY[0x641C54];
          v55 = qword_641C50;
        }
        v58 = &KeServiceDescriptorTableShadow;
        __pld(&KeServiceDescriptorTableShadow);
        v59 = v56 & 0x3F;
        v60 = 64 - (v56 & 0x3F);
        v61 = 32 - (v56 & 0x3F);
        v62 = 16;
        v63 = 2;
        do
        {
          v65 = (__PAIR64__(v57, v55) - *(_QWORD *)v58) >> 32;
          v64 = v55 - *v58;
          v66 = (v65 << v60) | (v64 >> ((v56 & 0x3F) - 32)) | (v64 << v61);
          v55 = (v64 << v60) | (__PAIR64__(v65, v64) >> v59);
          v57 = v66 | (v65 >> v59);
          v58 += 2;
          v62 -= 8;
          v61 = 32 - (v56 & 0x3F);
          --v63;
        }
        while ( v63 );
        v68 = HIDWORD(v84);
        v67 = v84;
        v87 = v58;
        v23 = a1;
        v89 = v62;
        if ( v62 )
        {
          v69 = 64 - v59;
          v70 = v89;
          v71 = v87;
          do
          {
            v72 = *(unsigned __int8 *)v71;
            v71 = (int *)((char *)v71 + 1);
            v74 = (__PAIR64__(v57, v55) - v72) >> 32;
            v73 = v55 - v72;
            v75 = (v74 << v69) | (v73 >> (v59 - 32)) | (v73 << (32 - v59));
            v55 = (v73 << v69) | (__PAIR64__(v74, v73) >> v59);
            v57 = v75 | (v74 >> v59);
            --v70;
          }
          while ( v70 );
          v68 = HIDWORD(v84);
          v23 = a1;
          v67 = v84;
        }
        if ( (dword_641C78 != v55 || unk_641C7C != v57) && !(v67 | v68) )
        {
          v68 = 0;
          v67 = __ROR4__(4341760, 14);
          dword_641C20 = v67;
          unk_641C24 = 0;
          unk_641C28 = 0;
          unk_641C2C = 0;
          unk_641C30 = 0;
          unk_641C34 = 0;
          dword_641C38 = 267;
          dword_641C3C = 0;
          dword_641C40 = (int)&KeServiceDescriptorTableShadow;
          dword_641C44 = 0;
        }
        if ( KeServiceDescriptorTableShadow != KeServiceDescriptorTable || dword_682008 != dword_682088 )
        {
          if ( v67 | v68 )
            goto LABEL_85;
          v67 = 265;
          v68 = 0;
          dword_641C20 = 265;
          unk_641C24 = 0;
          unk_641C28 = 0;
          unk_641C2C = 0;
          unk_641C30 = 0;
          unk_641C34 = 0;
          dword_641C38 = 267;
          dword_641C3C = 0;
          dword_641C40 = KeServiceDescriptorTableShadow;
          dword_641C44 = 0;
        }
        if ( !(v67 | v68) )
        {
          do
          {
LABEL_77:
            v76 = MEMORY[0xFFFF93B0];
            while ( 1 )
            {
              v77 = MEMORY[0xFFFF900C];
              __dmb(0xBu);
              v78 = MEMORY[0xFFFF9008];
              __dmb(0xBu);
              if ( v77 == MEMORY[0xFFFF9010] )
                break;
              __dmb(0xAu);
              __yield();
            }
          }
          while ( v76 != MEMORY[0xFFFF93B0] );
          LODWORD(v79) = ReadTimeStampCounter();
          _rt_udiv64(80000000000i64, 41929663 * (v79 >> 4));
          v21 = (v80 - v76 + __PAIR64__(v77, v78)) >> 32;
          LODWORD(v80) = v80 - v76 + v78;
          LODWORD(qword_641C60) = v80 + 237191168;
          HIDWORD(qword_641C60) = __CFADD__((_DWORD)v80, 237191168) + v21 + 67;
LABEL_82:
          ObDereferenceDeviceMap(v23, v21);
          return PspReleaseProcessQuota(v23);
        }
LABEL_85:
        if ( (int (__fastcall *)(int, int))dword_641C0C != sub_5C46B4 )
          KeInitializeDpc((int)&unk_641C00, (int)sub_5C46B4, (int)&unk_641C00);
        dword_641C48 = 1743610;
        dword_641C4C = 0;
        KeInsertQueueDpc((int)&unk_641C00);
        goto LABEL_77;
      }
    }
    v43 = qword_641C50;
    v42 = dword_641C58;
    v44 = MEMORY[0x641C54];
    goto LABEL_52;
  }
  return sub_7C03D4(v3);
}
