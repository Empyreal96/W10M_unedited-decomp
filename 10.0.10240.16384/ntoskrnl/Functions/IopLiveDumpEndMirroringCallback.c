// IopLiveDumpEndMirroringCallback 
 
int __fastcall IopLiveDumpEndMirroringCallback(int a1)
{
  _DWORD *v1; // r5
  int v2; // r4
  int v3; // r1
  int v4; // r2
  int v5; // r3
  unsigned int v6; // r4
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r6
  unsigned int v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r6

  v1 = (_DWORD *)IopLiveDumpContext;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      IopLiveDumpTraceMirroringPhase1End();
      v5 = v1[12];
      if ( (v5 & 1) != 0 )
      {
        v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        RtlCaptureContext(*(_DWORD **)(v6 + 2712), v3, v4, v5);
        KiSaveProcessorControlState((_DWORD *)(v6 + 1440), v7, v8, v9);
      }
      else
      {
        v10 = v1[57];
        v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        RtlCaptureContext(*(_DWORD **)(v11 + 2712), v3, v4, v5);
        KiSaveProcessorControlState((_DWORD *)(v11 + 1440), v12, v13, v14);
        if ( v10 != -800 )
        {
          memset((_BYTE *)(v10 + 800), 0, 1200);
          memmove(v10 + 800, *(_DWORD *)(v11 + 2712), 0x1A0u);
        }
      }
      if ( (v1[12] & 1) != 0 )
        v15 = 0;
      else
        v15 = v1 + 69;
      v2 = IopLiveDumpMarkRequiredDumpData(v1, v15);
      if ( v2 >= 0 )
      {
        if ( (v1[12] & 1) != 0 )
          v1[15] = RtlNumberOfSetBits(v1 + 55);
        v2 = IopLiveDumpMarkImportantDumpData(v1 + 55, v15);
        if ( v2 >= 0 )
        {
          if ( (v1[12] & 1) != 0 )
          {
            IopLiveDumpPopulateBitmapForDump(v1);
          }
          else
          {
            IoFillDumpHeader(v1[57], 6, *v1, v1[1], v1[2], v1[3], v1[4], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
            v1[27] = 0;
            IopLiveDumpPopulateBitmapForDump(v1);
            IopLiveDumpStartDumpDataBuffering(v1 + 35);
          }
          v2 = 0;
        }
      }
      IopLiveDumpUncorralProcessors(v1 + 35, 0);
    }
    else
    {
      v2 = -1073741595;
    }
  }
  else
  {
    IopLiveDumpTraceMirroringPhase0End();
    IopLiveDumpCorralProcessors((int)(v1 + 35));
    v2 = 0;
  }
  return v2;
}
