// KiInitializeProcessorState 
 
int __fastcall KiInitializeProcessorState(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  _BYTE *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r9
  int v17; // r4
  __int64 v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3

  memset((_BYTE *)a3, 0, a5);
  v14 = memset((_BYTE *)a1, 0, 928);
  *(_DWORD *)(a3 + 1428) = a7;
  *(_DWORD *)(a3 + 2372) = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x944);
  v15 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  *(_DWORD *)(a3 + 2376) = *(_DWORD *)(v15 + 968);
  *(_DWORD *)(a3 + 2380) = *(_DWORD *)(v15 + 972);
  v16 = ((32 * a8 + 20063) & 0xFFFFFF80) + a3 + 12288;
  *(_DWORD *)(a3 + 5488) = v16;
  v17 = (int)*(&KeNodeBlock + a6);
  *(_DWORD *)(a3 + 5492) = a11;
  if ( (_UNKNOWN *)v17 == (_UNKNOWN *)((char *)&KiNodeInit + 384 * a6) )
    return sub_7D0A44(v14);
  if ( (*(_BYTE *)(v17 + 289) & 4) == 0 )
    KiCommitNodeAssignment(v17);
  *(_DWORD *)(a3 + 3768) = v17;
  HIDWORD(v19) = a3 + 1408;
  KiAddProcessorToGroupDatabase(a3 + 1408, a4);
  memset((_BYTE *)(a1 + 512), 0, 416);
  *(_DWORD *)(a1 + 512) = 2097154;
  *(_DWORD *)(a1 + 516) = a2;
  *(_DWORD *)(a1 + 568) = a9;
  *(_DWORD *)(a1 + 576) = KiSystemStartup;
  *(_DWORD *)(a1 + 580) = 435;
  KfRaiseIrql(2);
  KiSaveProcessorControlState((_DWORD *)a1, v20, v21, v22);
  KfLowerIrql(0);
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  LODWORD(v19) = a10;
  *(_DWORD *)(a1 + 36) = a3;
  *(_QWORD *)(a2 + 72) = v19;
  *(_DWORD *)(a2 + 80) = &KiInitialProcess;
  *(_DWORD *)(a2 + 84) = v16;
  return a3 + 1408;
}
