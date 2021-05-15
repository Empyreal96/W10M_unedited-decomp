// ViFlushDoubleBuffer 
 
int __fastcall ViFlushDoubleBuffer(_DWORD *a1, _DWORD *a2, int a3, unsigned int a4, char a5)
{
  int v6; // r4
  int v8; // r0
  int v9; // r6
  int v11; // r0
  int v12; // r10
  unsigned __int8 *v13; // r9
  int v14; // r0
  unsigned int v15; // r8
  int v16; // r3
  int v17; // [sp+8h] [bp-28h] BYREF
  int v18; // [sp+Ch] [bp-24h]
  _DWORD *v19; // [sp+10h] [bp-20h]

  v6 = a3;
  v18 = a3;
  v19 = a2;
  v8 = ViGetMdlBufferSa(a2, a3);
  v9 = v8;
  if ( !v8 )
    return 0;
  if ( !ViFindMappedRegisterInFile((int)a1, v8, &v17) )
  {
    ViHalPreprocessOptions(&dword_618788, "Cannot flush buffers that aren't mapped (Addr %p).", (const void *)0x16);
    VfReportIssueWithOptions(230, 22, v9, (int)a1, 0, &dword_618788);
    return 0;
  }
  v11 = a1[8];
  v12 = (v9 & 0xFFF) + (v17 << 12);
  v13 = (unsigned __int8 *)(a1[9] + v12);
  if ( (*(_WORD *)(v11 + 6) & 5) != 0 )
    v14 = *(_DWORD *)(v11 + 12);
  else
    v14 = MmMapLockedPages(v11, 0);
  v15 = v14 - (_DWORD)v13 + *(_DWORD *)(a1[8] + 20);
  if ( a4 > v15 )
  {
    ViHalPreprocessOptions(
      &dword_618784,
      "FLUSH: Can only flush %x bytes to end of map register file (%x attempted)",
      0x10000000,
      1);
    VfReportIssueWithOptions(230, 0, 1, v15, a4, &dword_618784);
    v6 = v18;
    a4 = v15;
  }
  if ( !a5 )
  {
    v16 = a1[10];
    if ( v16 )
      ViCopyBackModifiedBuffer(v19, v6, v13, v16 + v12, a4);
  }
  if ( !ViFreeMapRegistersToFile(a1, v9, a4) )
    VfUtilDbgPrint((int)"Flushing too many map registers\n");
  return 1;
}
