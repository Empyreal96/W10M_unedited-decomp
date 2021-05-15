// PopSaveHiberContext 
 
int __fastcall PopSaveHiberContext(unsigned int a1)
{
  unsigned int v2; // r4
  int v3; // r4
  int v4; // r3
  int v5; // r5
  unsigned int *v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r3
  _DWORD *v9; // r7
  unsigned int v10; // r0
  _DWORD *v11; // r1
  int *v12; // r4
  int v13; // t1
  int v14; // r0
  _DWORD *v15; // r0
  __int64 v16; // r4
  int v17; // r1
  int v18; // r8
  __int64 v19; // r0
  int v20; // r1
  unsigned int v21; // r2
  int v22; // r4
  int v23; // r0
  int v24; // r0
  _DWORD *v25; // r4
  unsigned int v26; // r5
  unsigned int v27; // r10
  int v28; // r6
  _DWORD *v29; // r2
  int v30; // r3
  int v31; // r0
  int v32; // r3
  unsigned int v33; // r0
  int v34; // r6
  __int64 v35; // r4
  unsigned __int64 v36; // kr28_8
  unsigned int v37; // r3
  unsigned int *v38; // r5
  unsigned int v39; // r2
  unsigned int v40; // r2
  int v41; // r3
  unsigned int v42; // r0
  int v43; // r5
  int v44; // r3
  int v45; // r0
  int v46; // r6
  int v47; // r7
  __int64 v48; // r4
  int v50; // [sp+Ch] [bp-E4h]
  _DWORD *v51; // [sp+10h] [bp-E0h]
  int v52; // [sp+14h] [bp-DCh]
  char v53[4]; // [sp+1Ch] [bp-D4h] BYREF
  char v54; // [sp+20h] [bp-D0h] BYREF
  char v55[12]; // [sp+30h] [bp-C0h] BYREF
  int v56; // [sp+3Ch] [bp-B4h]
  unsigned int v57; // [sp+44h] [bp-ACh]

  v2 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  if ( v2 >= *(_DWORD *)(a1 + 160) )
    return 0;
  if ( v2 )
  {
    while ( 1 )
    {
      v4 = *(char *)(a1 + 5);
      __dmb(0xBu);
      if ( v4 )
        break;
      KePollFreezeExecution();
    }
    v5 = 7 * v2;
    PopCompressHiberBlocks(a1, *(_DWORD *)(a1 + 164) + 112 * v2, 1);
    __dmb(0xBu);
    v6 = (unsigned int *)(a1 + 12);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
    __dmb(0xBu);
    while ( 1 )
    {
      v8 = *v6;
      __dmb(0xBu);
      if ( !v8 )
        break;
      KePollFreezeExecution();
    }
    return PopCompressHiberBlocks(a1, *(_DWORD *)(a1 + 164) + 16 * v5, 0);
  }
  PopWatchdogTimerCount = 0;
  if ( (__get_CPSR() & 0x80) == 0 )
  {
    __disable_irq();
    PopInternalError(661561);
  }
  v52 = IoDumpStackResumeCapable((int)v53);
  if ( !v52 )
  {
    byte_61EED1 = 1;
    dword_61EF18 |= 4u;
  }
  if ( PshedArePluginsPresent() )
  {
    byte_61EED1 = 1;
    dword_61EF18 |= 8u;
  }
  if ( !off_617AD0() )
    dword_61EF18 |= 1u;
  byte_61EED1 = 1;
  *(_DWORD *)(a1 + 104) = &v54;
  v9 = *(_DWORD **)(a1 + 128);
  *(_BYTE *)(a1 + 2) = 1;
  *(_DWORD *)(a1 + 112) = PoWakeState;
  v10 = 0;
  v51 = v9;
  ++*v9;
  v11 = *(_DWORD **)(a1 + 36);
  v12 = *(int **)(a1 + 28);
  if ( (*(_DWORD *)(a1 + 32) & 0xFFFFFFE0) != 0 )
  {
    do
    {
      v13 = *v12++;
      ++v10;
      *v11++ |= v13;
    }
    while ( v10 < *(_DWORD *)(a1 + 32) >> 5 );
  }
  if ( (PoDebug & 0x81) != 0 )
  {
    v14 = RtlNumberOfSetBits((unsigned int *)(a1 + 24));
    DbgPrint("Inventoried: %d pages not required to hibernate\n", v14);
  }
  if ( byte_61EED1 )
  {
    v15 = (_DWORD *)(a1 + 24);
  }
  else
  {
    RtlCopyBitMap((unsigned int *)(a1 + 32), (_DWORD *)(a1 + 24), 0);
    v15 = (_DWORD *)(a1 + 32);
  }
  RtlSetAllBits(v15);
  *(_DWORD *)(a1 + 116) = 8;
  if ( !byte_61EED1 )
    IoNotifyDump(1);
  LODWORD(v16) = ReadTimeStampCounter();
  HIDWORD(v16) = v17;
  v18 = IoInitializeDumpStack(*(_DWORD *)(a1 + 108));
  LODWORD(v19) = ReadTimeStampCounter();
  qword_61EFB0 += v19 - v16;
  if ( v18 < 0 || PopSimulateHiberBugcheck == 1 )
  {
    if ( (PoDebug & 0x80) != 0 )
      DbgPrint("PopSave: dump driver initialization failed %08x\n", v18);
    PopInternalAddToDumpFile(*(_DWORD *)(a1 + 108), 256, 0);
    KeBugCheckEx(160, 12, v18, *(_DWORD *)(a1 + 108), 0);
  }
  PopMarkComponentsBootPhase((char *)a1);
  if ( (PoDebug & 0x81) != 0 )
  {
    v22 = RtlNumberOfClearBits((_DWORD *)(a1 + 32));
    v23 = RtlNumberOfClearBits((_DWORD *)(a1 + 24));
    DbgPrint("             %d pages to hibernate\n", v23 + v22);
  }
  if ( (PoDebug & 0x81) != 0 )
  {
    v24 = PopGetRangeCount((unsigned int *)dword_61EC98, v20, v21, PoDebug);
    DbgPrint("             %d ranges of consecutive physical pages\n", v24);
  }
  v25 = *(_DWORD **)(a1 + 40);
  PoHiberInProgress = 1;
  while ( v25 != (_DWORD *)(a1 + 40) )
  {
    v27 = v25[4];
    v26 = v25[3];
    v28 = v25[5];
    v25 = (_DWORD *)*v25;
    *(_QWORD *)(a1 + 56) += v27 - v26;
    while ( v26 < v27 )
    {
      PopCreateDumpMdl(a1, (int)v55, v26, v27);
      memmove(v28, v56, v57);
      v28 += v57;
      v26 += v57 >> 12;
    }
  }
  PopResetRangeEnum((_DWORD *)a1);
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopSave: NoFree pages %08x\n", v9[14]);
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopSave: HiberPte %08p for %08x Ptes\n", (const void *)dword_61EEBC, v9[12]);
  v29 = *(_DWORD **)(a1 + 104);
  v30 = dword_61EEB0;
  *v29 = dword_61EEB0;
  v29[1] = v30;
  v29[2] = 0;
  v29[3] = 0;
  ReadTimeStampCounter();
  v31 = PopWriteHeaderPages(a1, v9);
  v3 = v31;
  if ( v31 < 0 )
    goto LABEL_63;
  v32 = v9[16];
  *(_DWORD *)(a1 + 64) = a1 + 32;
  v50 = v32;
  *(_DWORD *)(a1 + 116) = 4;
  v33 = RtlNumberOfClearBits((_DWORD *)(a1 + 32));
  v34 = dword_61EF00;
  v35 = *(_QWORD *)(a1 + 168);
  v36 = __PAIR64__(v33 >> 20, v33 << 12) + (*(_QWORD *)(a1 + 56) << 12);
  memset((_BYTE *)dword_61EF00, 0, 56);
  *(_DWORD *)(v34 + 12) = HIDWORD(v36);
  *(_DWORD *)(v34 + 16) = 0;
  *(_QWORD *)v34 = v35;
  *(_DWORD *)(v34 + 8) = v36;
  qword_61F128 = 0i64;
  qword_61F130 = 0;
  MEMORY[0x61F134] = 0;
  *(_DWORD *)(a1 + 204) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 220) = 0;
  if ( v52 && *(_DWORD *)(*(_DWORD *)(a1 + 108) + 84) )
    *(_BYTE *)(a1 + 260) = 1;
  v37 = *(_DWORD *)(a1 + 156) + ((unsigned int)(4 * PopHiberScratchPages + 4095) >> 12) + 2;
  v9[20] = v37;
  *(_DWORD *)(a1 + 248) = v37 << 12;
  *(_DWORD *)(a1 + 252) = 0;
  __dmb(0xBu);
  *(_BYTE *)(a1 + 5) = 1;
  PopWriteHiberImage(a1, 1);
  __dmb(0xBu);
  v38 = (unsigned int *)(a1 + 12);
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 + 1, v38) );
  __dmb(0xBu);
  while ( 1 )
  {
    v40 = *v38;
    __dmb(0xBu);
    v41 = *(_DWORD *)(a1 + 160);
    if ( v40 == v41 )
      break;
    KePollFreezeExecution();
  }
  v42 = 0;
  if ( v41 )
  {
    v43 = 0;
    do
    {
      qword_61F128 += *(_QWORD *)(*(_DWORD *)(a1 + 164) + v43 + 40);
      ++v42;
      v44 = *(_DWORD *)(a1 + 164) + v43;
      *(_DWORD *)(v44 + 40) = 0;
      *(_DWORD *)(v44 + 44) = 0;
      v43 += 112;
    }
    while ( v42 < *(_DWORD *)(a1 + 160) );
  }
  qword_61F138 = qword_61F158;
  dword_61F148 = dword_61F160;
  dword_61F14C = 0;
  qword_61F158 = 0i64;
  dword_61F160 = 0;
  *(_DWORD *)(a1 + 116) = 5;
  *(_DWORD *)(a1 + 64) = a1 + 24;
  *(_DWORD *)(a1 + 72) = 0;
  v45 = RtlNumberOfClearBits((_DWORD *)(a1 + 24));
  v46 = dword_61EF00;
  v47 = v45;
  v48 = *(_QWORD *)(a1 + 168);
  memset((_BYTE *)dword_61EF00, 0, 56);
  *(_DWORD *)(v46 + 16) = 0;
  *(_QWORD *)v46 = v48;
  *(_QWORD *)(v46 + 8) = (unsigned __int64)(unsigned int)v47 << 12;
  v51[21] = (unsigned int)(*(_DWORD *)(a1 + 248) + 4095) >> 12;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 220) = 0;
  PopWriteHiberImage(a1, 0);
  *(_DWORD *)(a1 + 116) = 7;
  PopWriteChecksumPages(a1);
  *(_DWORD *)(a1 + 116) = 6;
  v31 = PopWriteImageHeader(a1, v51, v50);
  v3 = *(_DWORD *)(a1 + 120);
  if ( v3 < 0 )
  {
LABEL_63:
    if ( v3 == 1073742484 )
      goto LABEL_65;
    goto LABEL_64;
  }
  if ( (PopSimulate & 0x8000) == 0 && dword_61EC80 == dword_61EC88 )
    DbgUnLoadImageSymbols();
  if ( (PopSimulate & 0x1000) == 0 )
  {
    v3 = 0;
    goto LABEL_63;
  }
  v3 = -1073741632;
LABEL_64:
  v31 = KdPowerTransition(4);
LABEL_65:
  if ( v3 >= 0 && v3 != 1073742484 && dword_61EC80 == 5 )
    v31 = PopNotifyShutdownListener(v31);
  off_617B0C(v31);
  return v3;
}
