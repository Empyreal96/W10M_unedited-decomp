// MiAllocateChildVads 
 
int __fastcall MiAllocateChildVads(int a1, _DWORD *a2)
{
  int v2; // r8
  _DWORD *v3; // r7
  _DWORD *i; // r3
  _DWORD *v5; // r3
  int v6; // r6
  _DWORD *v7; // r2
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r3
  int v11; // r0
  int v12; // r10
  int v13; // r0
  unsigned int v14; // r4
  int v15; // r9
  int v16; // r5
  unsigned int v17; // r1
  int v18; // r2
  int *v19; // r3
  int *v20; // r8
  int v21; // r0
  int v22; // r10
  int v23; // r0
  int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r10
  int v27; // r8
  unsigned int v28; // r1
  int v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  __int16 v32; // r3
  int *v33; // r3
  _DWORD *v34; // r8
  int v35; // r0
  unsigned int *v36; // r1
  unsigned int *v37; // r2
  unsigned int *v38; // r3
  int v40; // [sp+0h] [bp-40h]
  char v42[56]; // [sp+8h] [bp-38h] BYREF

  v40 = a1;
  *a2 = 0;
  v2 = a1;
  v3 = 0;
  for ( i = *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 636); i; i = (_DWORD *)*i )
    v3 = i;
  while ( v3 )
  {
    v5 = (_DWORD *)v3[1];
    v6 = (int)v3;
    v7 = v3;
    if ( v5 )
    {
      do
      {
        v3 = v5;
        v5 = (_DWORD *)*v5;
      }
      while ( v5 );
    }
    else
    {
      while ( 1 )
      {
        v3 = (_DWORD *)(v3[2] & 0xFFFFFFFC);
        if ( !v3 || (_DWORD *)*v3 == v7 )
          break;
        v7 = v3;
      }
    }
    v8 = *(_DWORD *)(v6 + 28);
    if ( ((1 << (v8 & 7)) & 0x35) == 0 )
      continue;
    v9 = (v8 >> 15) & 1;
    if ( !v9 && (*(_DWORD *)(v6 + 40) & 0x4000000) == 0 )
      continue;
    v10 = 1818517846;
    v11 = 76;
    if ( v9 && (v8 & 0x10000) == 0 )
      v11 = 40;
    v12 = 0;
    if ( (*(_DWORD *)(v6 + 28) & 7) == 2 && (v8 & 0x20000) != 0 )
    {
      v12 = 1;
      v11 = MiBytesForFixupVad(**(_DWORD **)(v6 + 44));
      v10 = 1231315286;
    }
    v13 = ExAllocatePoolWithTag(512, v11, v10);
    v14 = v13;
    if ( !v13 )
      return -1073741670;
    if ( (*(_DWORD *)(v6 + 28) & 0x8000) != 0 )
    {
      memmove(v13, v6, 0x28u);
      *(_DWORD *)(v14 + 28) &= 0xFFFFBFFF;
    }
    else
    {
      memmove(v13, v6, 0x4Cu);
      *(_DWORD *)(v14 + 64) = v2 | 1;
    }
    *(_DWORD *)(v14 + 36) = 0;
    *(_DWORD *)(v14 + 20) = 0;
    *(_DWORD *)(v14 + 24) = 0;
    v15 = 0;
    *(_DWORD *)(v14 + 8) = -2;
    v16 = 0;
    if ( (*(_DWORD *)(v6 + 28) & 7) == 4 )
    {
      v16 = MiCreateWriteWatchView(v2);
      if ( v16 < 0 )
        goto LABEL_69;
      v15 = 1;
    }
    else if ( MiVadMapsLargeImage(v6) || v18 == 5 )
    {
      v16 = MiCreateLargePageVad((_DWORD *)v2, v14, (v17 >> 8) & 0x3F);
      if ( v16 < 0 )
        goto LABEL_69;
      v15 = 2;
      if ( MiCopyLargeVad(v6, v14) == 1 )
        ++*a2;
      else
        v16 = -1073741670;
    }
    else
    {
      if ( v18 == 2 )
      {
        v19 = *(int **)(v6 + 44);
        v20 = (int *)*v19;
        if ( v12 == 1 )
        {
          v21 = MiBytesForFixupVad(*v19);
          memmove(v14 + 76, v6 + 76, v21 - 76);
          v22 = v40;
          *(_DWORD *)(v14 + 84) = v14 + 88;
          KiStackAttachProcess(v40, 0, (int)v42);
          ++MEMORY[0xC0402148];
          KiUnstackDetachProcess((unsigned int)v42, 0);
        }
        else
        {
          v22 = v40;
        }
        v16 = MiInsertSharedCommitNode(**(_DWORD ***)(v6 + 44), v22, 0);
        if ( v16 < 0 )
        {
LABEL_81:
          ExFreePoolWithTag(v14);
          return v16;
        }
        v15 = 16;
        if ( (v20[7] & 0x4000000) != 0 )
        {
          v23 = MmGetSessionIdEx(v22);
          v16 = MiCreatePerSessionProtos(v20, v23, v24, v25);
          v2 = v40;
          if ( v16 < 0 )
            goto LABEL_69;
          v15 = 20;
          goto LABEL_59;
        }
      }
      else
      {
        if ( (v17 & 0x8000) != 0 )
          goto LABEL_60;
        if ( *(int *)(v6 + 68) < 0 )
        {
          v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v26 + 310);
          v27 = KeAbPreAcquire((unsigned int)&dword_632E10, 0, 0);
          do
            v28 = __ldrex((unsigned __int8 *)&dword_632E10);
          while ( __strex(v28 | 1, (unsigned __int8 *)&dword_632E10) );
          __dmb(0xBu);
          if ( (v28 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_632E10, v27, (unsigned int)&dword_632E10);
          if ( v27 )
            *(_BYTE *)(v27 + 14) |= 1u;
          v29 = *(_DWORD *)(***(_DWORD ***)(v14 + 44) + 24);
          ++*(_DWORD *)(v29 + 8);
          __dmb(0xBu);
          do
            v30 = __ldrex((unsigned int *)&dword_632E10);
          while ( __strex(v30 - 1, (unsigned int *)&dword_632E10) );
          if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)&dword_632E10);
          v31 = KeAbPostRelease((unsigned int)&dword_632E10);
          v32 = *(_WORD *)(v26 + 310) + 1;
          *(_WORD *)(v26 + 310) = v32;
          if ( !v32 && *(_DWORD *)(v26 + 100) != v26 + 100 )
            KiCheckForKernelApcDelivery(v31);
LABEL_60:
          if ( (*(_DWORD *)(v6 + 28) & 0x8000) == 0 && *(_DWORD *)(v6 + 72) )
          {
            v15 |= 8u;
            ObfReferenceObject(*(_DWORD *)(v14 + 72));
          }
          if ( MiVadPureReserve(v14) )
          {
            *(_DWORD *)(v14 + 8) = 1;
            v35 = MiCloneReserveVadCommit(v14, v40);
            *(_DWORD *)(v14 + 8) = -2;
            v16 = v35;
          }
          if ( v16 >= 0 && (*(_DWORD *)(v6 + 28) & 0x4000) != 0 )
            v16 = MiCloneNoChange(v6, v14);
          v2 = v40;
          goto LABEL_69;
        }
        if ( v18 == 1 )
          goto LABEL_60;
        v33 = *(int **)(v6 + 44);
        if ( !v33 )
          goto LABEL_60;
        v34 = (_DWORD *)*v33;
        if ( !MiIncludeSharedCommit(*v33) )
          goto LABEL_60;
        v16 = MiInsertSharedCommitNode(v34, v40, 0);
        if ( v16 < 0 )
          goto LABEL_81;
        v15 = 16;
      }
      v2 = v40;
    }
LABEL_59:
    if ( v16 >= 0 )
      goto LABEL_60;
LABEL_69:
    KiStackAttachProcess(v2, 0, (int)v42);
    if ( v16 < 0 || (v16 = MiInsertVadCharges(v14, v2), v16 < 0) )
    {
      MiDeletePartialCloneVad(v14, v15);
      KiUnstackDetachProcess((unsigned int)v42, 0);
      return v16;
    }
    v38 = *(unsigned int **)(v14 + 28);
    if ( ((unsigned __int16)v38 & 0x8000) == 0 )
      MiUpControlAreaRefs(v14, v36, v37, v38);
    *(_DWORD *)(v14 + 8) = -2;
    MiGetWsAndInsertVad((_DWORD *)v14);
    KiUnstackDetachProcess((unsigned int)v42, 0);
  }
  return 0;
}
