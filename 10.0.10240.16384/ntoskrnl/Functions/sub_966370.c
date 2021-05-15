// sub_966370 
 
int __fastcall sub_966370(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r3
  unsigned int i; // r10
  unsigned int v6; // r2
  void **v7; // r9
  unsigned int v8; // t1
  unsigned int v9; // r6
  int v10; // r5
  int v11; // r8
  unsigned int v12; // r2
  unsigned int j; // lr
  unsigned int v14; // r6
  int *v15; // r8
  unsigned int v16; // r2
  unsigned int v18; // r10
  int v19; // r7
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r2
  unsigned int v24; // r3
  int v25; // r8
  unsigned int v26; // r7
  int v27; // r1
  _DWORD *v28; // r7
  void **v29; // r3
  void **v30; // r2
  unsigned int v31; // r2
  int *v32; // r4
  unsigned int v33; // r6
  unsigned int v34; // r5
  unsigned int v35; // r7
  void *v36; // r5
  unsigned int v37; // r5
  unsigned int v38; // r10
  char *v39; // r8
  void **v40; // r6
  _BYTE *v41; // r0
  int v42; // r5
  unsigned int v43; // r0
  unsigned int v44; // r1
  int v45; // r2
  int v46; // r3
  unsigned int v47; // r3
  unsigned __int16 v48; // [sp+20h] [bp-3F0h] BYREF
  unsigned int v49; // [sp+24h] [bp-3ECh]
  int v50; // [sp+28h] [bp-3E8h] BYREF
  unsigned int v51; // [sp+2Ch] [bp-3E4h]
  int v52; // [sp+30h] [bp-3E0h]
  int v53; // [sp+34h] [bp-3DCh] BYREF
  int v54; // [sp+38h] [bp-3D8h]
  unsigned int v55; // [sp+3Ch] [bp-3D4h]
  void *v56; // [sp+40h] [bp-3D0h]
  char v57[964]; // [sp+48h] [bp-3C8h] BYREF
  int (*v58)(void); // [sp+40Ch] [bp-4h]

  if ( a4 < v33 )
    v33 = a4;
  if ( *v32 && *v32 < v33 )
    v33 = *v32;
  v18 = 0;
  v19 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( KiInitializePrcbContext(v19) < 0 )
    goto LABEL_25;
  v20 = MmAllocateIsrStack((int *)(v19 + 4084), 0);
  if ( !v20 )
    goto LABEL_25;
  v55 = HalQueryMaximumProcessorCount(v20, v21, v22);
  v34 = v55;
  if ( v55 > 0x20 )
    v34 = 32;
  v23 = *(unsigned __int8 *)(v19 + 1043) * *(unsigned __int8 *)(v19 + 1042);
  if ( v34 > v23 * v32[4] )
    v34 = v23 * v32[4];
  v24 = v32[5];
  if ( v24 && v24 < v34 )
    v34 = v32[5];
  if ( v34 > v33 && !*((_BYTE *)v32 + 9) )
    v34 = v33;
  if ( !KiAllocateCpuSetData(v34) )
    goto LABEL_25;
  v35 = KiComputeProcessorDataSize(v34);
  v7 = &KeNodeBlock;
  v49 = v35;
  v25 = 0;
  while ( v32[1] < v33 )
  {
    ++v18;
    v53 = -1;
    v48 = -1;
    if ( !KiQueryProcessorNode(v18, (int)&v53, &v48) )
    {
      ++v25;
      v52 = MmAllocateIndependentPages(v35, v48);
      if ( !v52 )
        goto LABEL_25;
      if ( !ExCreatePoolTagTable(v25, v48) )
        goto LABEL_25;
      v54 = MmCreateKernelStack(0, v48, 0);
      if ( !v54 )
        goto LABEL_25;
      v26 = MmCreateKernelStack(0, v48, 0);
      v51 = v26;
      if ( !v26 )
        goto LABEL_25;
      v50 = 0;
      if ( !MmAllocateIsrStack(&v50, v48) )
        goto LABEL_25;
      v27 = v32[13];
      v56 = *(&KeNodeBlock + v48);
      v28 = (_DWORD *)KiInitializeProcessorState((int)v57, v27, v52, 0, v49, v48, v25, v34, v54, v26, v50);
      v50 = (int)*(&KeNodeBlock + v48);
      if ( !MmInitializeProcessor(v28) || KiInitializePrcbContext((int)v28) < 0 || KeInitializeTimerTable((int)v28) < 0 )
        goto LABEL_25;
      if ( !HalStartNextProcessor(v57, v25, v53) )
      {
        KiRemoveProcessorFromGroupDatabase((int)v28);
        v36 = v56;
        memmove((int)v56, v50, 0x180u);
        *(&KeNodeBlock + v48) = v36;
        MmDeleteProcessor((int)v28);
        ExDeletePoolTagTable(v25);
        MmFreeIndependentPages(v52, v49);
        MmDeleteKernelStack(v54, 0);
        MmDeleteKernelStack(v51, 0);
        break;
      }
      while ( *(_DWORD *)(v32[13] + 76) )
      {
        __dmb(0xAu);
        __yield();
      }
      KiConfigureProcessorBlock(v28);
      KiUpdateProcessorCount();
      v35 = v49;
    }
    if ( v18 >= 0x1F )
      break;
  }
  v37 = (unsigned __int16)KeNumberNodes;
  if ( (unsigned __int16)KeNumberNodes <= 1u )
  {
    if ( (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*((_DWORD *)KeNodeBlock + 65) >> 24))
                         + *((_BYTE *)RtlpBitsClearTotal
                           + (unsigned __int8)((unsigned int)~*((_DWORD *)KeNodeBlock + 65) >> 16))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*((_BYTE *)KeNodeBlock + 260))
                         + *((_BYTE *)RtlpBitsClearTotal
                           + (unsigned __int8)((unsigned __int16)~*((_WORD *)KeNodeBlock + 130) >> 8))) == v32[1] )
      goto LABEL_72;
LABEL_25:
    KeBugCheckEx(50, 0, 0, 20, 0);
  }
  v38 = 0;
  if ( KeNumberNodes )
  {
    v39 = (char *)&KiNodeInit;
    v40 = &KeNodeBlock;
    do
    {
      if ( *v40 == v39 )
      {
        v41 = (_BYTE *)ExAllocatePoolWithTag(512, 1024, 538993995);
        v42 = (int)v41;
        if ( !v41 )
          goto LABEL_25;
        memset(v41, 0, 1024);
        memmove(v42, (int)v39, 0x180u);
        *v40 = (void *)v42;
        v37 = (unsigned __int16)KeNumberNodes;
      }
      ++v38;
      ++v40;
      v39 += 384;
    }
    while ( v38 < v37 );
  }
LABEL_72:
  if ( v37 < 0x10 )
  {
    v29 = &KeNodeBlock + v37;
    v30 = &v29[16 - v37];
    do
      *v29++ = 0;
    while ( v29 != v30 );
  }
  KiAdjustProcessorAffinity();
  v4 = (unsigned __int16)KeNumberNodes;
  for ( i = 0; i < v4; ++i )
  {
    v8 = (unsigned int)*v7++;
    v6 = v8;
    v9 = v32[1];
    v51 = v8;
    if ( v9 > 0x20 )
      v9 = 32;
    v10 = *(_DWORD *)(v6 + 260);
    v11 = v10;
    if ( v10 )
    {
      v12 = (unsigned int)(v32 + 14);
      v49 = (unsigned int)(v32 + 14);
      for ( j = 0; j < 0x20; ++j )
      {
        if ( !v11 )
          break;
        if ( ((1 << j) & v11) != 0 )
        {
          v31 = ~(*(_DWORD *)(v51 + 260) & *(_DWORD *)(*(_DWORD *)v12
                                                     + 4 * *(unsigned __int8 *)(*(_DWORD *)v12 + 1052)
                                                     + 3384));
          v11 &= v31;
          if ( (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + HIBYTE(v31))
                               + *((_BYTE *)RtlpBitsClearTotal + BYTE2(v31))
                               + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v31)
                               + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v31))) < v9 )
            v9 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + HIBYTE(v31))
                                 + *((_BYTE *)RtlpBitsClearTotal + BYTE2(v31))
                                 + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v31)
                                 + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v31)));
        }
        v49 += 4;
        v12 = v49;
      }
      v32 = &KeBootprocSpecified;
      *(_BYTE *)(v51 + 270) = v9;
      v14 = 0;
      v15 = (int *)&KiProcessorBlock;
      do
      {
        if ( !v10 )
          break;
        if ( ((1 << v14) & v10) != 0 )
        {
          v10 &= ~(1 << v14);
          KiConfigureSchedulingInformation(*v15, 0);
        }
        ++v14;
        ++v15;
      }
      while ( v14 < 0x20 );
      v4 = (unsigned __int16)KeNumberNodes;
    }
  }
  off_617A00(1, 0);
  if ( !v32[8] )
  {
    v16 = v32[1];
    if ( *((_BYTE *)v32 + 9) && (v43 = v55, v55 > v16) )
    {
      v44 = *(unsigned __int8 *)(v32[14] + 1043) * *(unsigned __int8 *)(v32[14] + 1042) * v32[4];
      v45 = (unsigned __int16)KiMaximumGroups;
      v46 = KiMaximumGroupSize;
      v32[8] = v44;
      v47 = v45 * v46;
      if ( v44 > v47 )
      {
        v44 = v47;
        v32[8] = v47;
      }
      if ( v44 > v43 )
        v32[8] = v43;
    }
    else
    {
      v32[8] = v16;
    }
  }
  __dmb(0xBu);
  KiBarrierWait = 0;
  return v58();
}
