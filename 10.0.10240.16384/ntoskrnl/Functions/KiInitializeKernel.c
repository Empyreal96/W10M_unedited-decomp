// KiInitializeKernel 
 
int __fastcall KiInitializeKernel(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r10
  unsigned int v14; // r2
  int *v15; // r0
  _WORD *v16; // r1
  int v17; // t1
  int v18; // r2
  __int64 v19; // r0
  int v20; // r10
  int result; // r0
  int v22; // [sp+8h] [bp-38h] BYREF
  int v23; // [sp+Ch] [bp-34h]
  int v24; // [sp+10h] [bp-30h]
  int v25; // [sp+14h] [bp-2Ch]
  _DWORD _18[16]; // [sp+18h] [bp-28h] BYREF

  _18[12] = a1;
  _18[14] = a3;
  _18[15] = a4;
  v25 = a3;
  v24 = a2;
  _18[13] = a2;
  v23 = a1;
  v7 = *(_DWORD *)(a4 + 1292);
  if ( (v7 & 0x80) == 0 )
  {
    __asm
    {
      VMRS            R3, MVFR1
      VMRS            R2, MVFR0
    }
    KeBugCheckEx(93, 9, _R2, _R3, 0);
  }
  if ( !a5 )
  {
    __dsb(0xFu);
    __mcr(15, 0, 0, 8, 7, 0);
    __dsb(0xFu);
    __isb(0xFu);
    v7 |= 0x80000000;
    byte_6836A0 = KiMaximumGroupSize;
    byte_6836A1 |= 2u;
    byte_68368E = 1;
    KeNodeBlock = &ExNode0;
    KiCommitNodeAssignment((int)&ExNode0);
    *(_DWORD *)(a4 + 2360) = KeNodeBlock;
    dword_683608 |= 1u;
    *(_BYTE *)(a4 + 19) = 1;
    KiAddProcessorToGroupDatabase(a4, 0);
    v14 = 1;
    v15 = &dword_683184;
    v16 = &unk_920C80;
    do
    {
      *v15 = (int)v16;
      v16[133] = v14;
      v17 = *v15++;
      *(_BYTE *)(v17 + 270) = 1;
      ++v14;
      v16 += 192;
    }
    while ( v14 < 0x10 );
    KiConfigureProcessorBlock((_DWORD *)a4);
    a1 = KeCompactServiceTable((int *)&KiServiceTable, (unsigned __int8 *)KiArgumentTable, 0x1B9u, 0);
  }
  *(_WORD *)(a4 + 3376) = 1;
  *(_WORD *)(a4 + 3378) = 1;
  *(_DWORD *)(a4 + 3380) = 0;
  *(_DWORD *)(a4 + 3384) = 0;
  *(_DWORD *)(a4 + 3384) = 1 << a5;
  *(_DWORD *)(a4 + 3468) = *(_DWORD *)(a4 + 1048);
  KiSetCacheInformation(a1);
  PoInitializePrcb(a4);
  if ( a5 )
  {
    if ( v7 != (KeFeatureBits & 0x3FFFFFFF) )
      KeBugCheckEx(62, v7, KeFeatureBits, 0, 0);
    if ( *(_DWORD *)(a4 + 1296) != *((_DWORD *)KiProcessorBlock + 324)
      || *(_DWORD *)(a4 + 1300) != *((_DWORD *)KiProcessorBlock + 325) )
    {
      KeBugCheckEx(62, a5, 0, 0, 0);
    }
    KfLowerIrql(2);
    v20 = v23;
  }
  else
  {
    KeProcessorArchitecture = 5;
    KeProcessorLevel = *(_WORD *)(a4 + 960);
    KeProcessorRevision = *(_WORD *)(a4 + 962);
    KeFeatureBits = v7;
    MEMORY[0xFFFF9286] = 1;
    MEMORY[0xFFFF9287] = 1;
    v18 = __mrc(15, 0, 0, 0, 0);
    if ( (v18 & 0xFF000000) != 1358954496 || (v18 & 0xFFF0) != 720 )
      KiCP14DebugEnabled = 1;
    v19 = KfLowerIrql(1);
    KiFreezeExecutionLock = 0;
    KiInitSystem(v19, HIDWORD(v19));
    dword_624D7C = (int)&KiProcessListHead;
    KiProcessListHead = (int)&KiProcessListHead;
    _18[1] = 0;
    _18[2] = 0;
    _18[0] = 1;
    v20 = v23;
    KeInitializeProcess(v23, 0, _18, 0, 0, 1);
    *(_BYTE *)(v20 + 105) = 127;
    __isb(0xFu);
    v22 = (int)&KiWaitAlways + (__mrc(15, 0, 9, 13, 0) ^ __ROR4__(&v22, 19));
    KiWaitNever = v22;
    dword_681F6C = 0;
    __isb(0xFu);
    v22 = (__mrc(15, 0, 9, 13, 0) ^ __ROR4__(&KiWaitAlways, 17)) - (_DWORD)&v22;
    KiWaitAlways = v22;
    dword_681F7C = 0;
  }
  MEMORY[0xFFFF9276] = 1;
  KiInitializeIdleThread(v24, v25, v20, a4);
  ExpInitializeExecutive(a5, a6);
  result = KiCompleteKernelInit(a4, v24, a5);
  *(_DWORD *)(a6 + 76) = 0;
  return result;
}
