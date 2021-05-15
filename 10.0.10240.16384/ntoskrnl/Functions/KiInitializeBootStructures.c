// KiInitializeBootStructures 
 
int __fastcall KiInitializeBootStructures(_DWORD *a1)
{
  unsigned int v2; // r2
  _DWORD *v3; // r5
  int v4; // r9
  __int64 v5; // kr00_8
  unsigned __int8 *v6; // r3
  unsigned int v7; // r2
  int v8; // r1
  _BYTE *v9; // r4
  __int64 v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r0
  int result; // r0
  unsigned __int8 *v16; // r3
  unsigned int v17; // r2
  _BYTE *v18; // r0
  int v19; // [sp+0h] [bp-20h]

  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v3 = (_DWORD *)(v2 + 1408);
  *(_WORD *)(v2 + 44) = 1;
  *(_WORD *)(v2 + 46) = 1;
  *(_WORD *)(v2 + 2446) = 1;
  *(_WORD *)(v2 + 2444) = 1;
  *(_BYTE *)(v2 + 2448) = 0;
  v4 = *(_DWORD *)(v2 + 1428);
  if ( !v4 )
  {
    a1[20] = &KiInitialProcess;
    a1[21] = &KiInitialThread;
    KeKernelStackSize = a1[22];
    *(_DWORD *)(v2 + 5492) = a1[18] + 28672;
  }
  *(_DWORD *)(v2 + 4868) = v2 + 19072;
  v5 = *((_QWORD *)a1 + 10);
  v19 = a1[20];
  *(_DWORD *)(v2 + 1412) = HIDWORD(v5);
  __mcr(15, 0, HIDWORD(v5), 13, 0, 3);
  *(_DWORD *)(v2 + 1416) = 0;
  *(_DWORD *)(v2 + 1420) = HIDWORD(v5);
  if ( v4 )
  {
    if ( !PoEnergyEstimationEnabled() )
      goto LABEL_8;
    __dmb(0xBu);
    v6 = (unsigned __int8 *)(HIDWORD(v5) + 2);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x20, v6) );
  }
  else
  {
    __dmb(0xBu);
    v16 = (unsigned __int8 *)(HIDWORD(v5) + 2);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x20, v16) );
  }
  __dmb(0xBu);
LABEL_8:
  *(_DWORD *)(HIDWORD(v5) + 116) = v5;
  *(_DWORD *)(HIDWORD(v5) + 100) = HIDWORD(v5) + 100;
  *(_DWORD *)(HIDWORD(v5) + 104) = HIDWORD(v5) + 100;
  *(&KiProcessorBlock + v4) = v3;
  v8 = a1[18] - 16;
  v9 = (_BYTE *)(a1[18] - 288);
  *(_DWORD *)(v8 + 12) = KiDispatchInterruptContinue;
  v3[432] = v8;
  memset(v9, 0, 272);
  *(_DWORD *)(HIDWORD(v5) + 320) = v9;
  if ( !v3[326] )
  {
    v3[326] = v3 + 136;
    v3[327] = 2097159;
  }
  if ( v4 )
  {
    KiInitializeExceptionVectorTable();
  }
  else
  {
    if ( (*(_DWORD *)(a1[33] + 68) & 8) == 0 )
      KiInitializeExceptionVectorTable();
    InbvDriverInitialize(-1, a1);
    v18 = (_BYTE *)a1[30];
    if ( v18 && strstr(v18, "GROUPSIZE") )
      JUMPOUT(0x69411A);
  }
  if ( !*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
    KiInitializeNxSupportDiscard();
  HalInitializeProcessor(v4, a1);
  KiSetFeatureBits(v3);
  v10 = KiTbInitialize(v4, v19);
  v13 = KiInitializeDebugRegisters(v10, SHIDWORD(v10), v11, v12);
  KiCacheInitialize(v13);
  v14 = KiInitPrcb(v3, v4);
  result = ExInitPoolLookasidePointers(v14);
  if ( !v4 )
  {
    KeActiveProcessors = 1;
    word_681D72 = 1;
    KeNumberProcessors_0 = 1;
    KeNumberProcessorsGroup0 = 1;
    dword_681D74 = 0;
    dword_681D78[0] = 1;
  }
  return result;
}
