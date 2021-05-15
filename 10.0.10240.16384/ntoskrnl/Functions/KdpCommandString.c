// KdpCommandString 
 
int __fastcall KdpCommandString(int result, int a2, __int64 a3, int a4, int a5)
{
  _BYTE *v5; // r8
  int v7; // r10
  int v8; // r7
  unsigned int v9; // r6
  int v10; // r1
  int v11; // r2
  int v12; // r3
  _DWORD *v13; // r4
  int v14; // r5
  _BYTE *v15; // r1
  int v16; // r4
  int v17; // r1
  int v18; // r2
  int v19; // r3

  v5 = (_BYTE *)HIDWORD(a3);
  v7 = result;
  if ( !(_BYTE)a3 )
  {
    LODWORD(a3) = (unsigned __int8)KdDebuggerNotPresent;
    if ( !KdDebuggerNotPresent )
    {
      v8 = KdEnterDebugger(a4, a5, a3);
      v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      KiSaveProcessorControlState((_DWORD *)(v9 + 1440), v10, v11, v12);
      v13 = *(_DWORD **)(v9 + 2712);
      v14 = *(_DWORD *)v5;
      KdpQuickMoveMemory((int)v13, v5, 416);
      *v13 = v14;
      KdpReportCommandStringStateChange(v7, a2, *(_DWORD *)(v9 + 2712));
      v15 = *(_BYTE **)(v9 + 2712);
      v16 = *(_DWORD *)v15;
      KdpQuickMoveMemory((int)v5, v15, 416);
      *(_DWORD *)v5 = v16;
      KiRestoreProcessorControlState((unsigned int *)(v9 + 1440));
      result = KdExitDebugger(v8, v17, v18, v19);
    }
  }
  return result;
}
