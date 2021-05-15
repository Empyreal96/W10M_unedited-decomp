// ViGetMdlBufferSa 
 
char *__fastcall ViGetMdlBufferSa(int a1, char *a2)
{
  int v3; // r2
  int v5; // r1
  int v6; // r0
  int *v7; // r4
  int v8; // r3
  int v9; // r1
  int v10; // r2

  v3 = *(_DWORD *)(a1 + 24);
  v5 = *(_DWORD *)(a1 + 16);
  if ( (unsigned int)a2 < v5 + v3 || (unsigned int)a2 >= *(_DWORD *)(a1 + 20) + v5 + v3 )
  {
    v7 = (int *)&unk_618764;
    ViHalPreprocessOptions(&unk_618764, "Virtual address %p out of bounds of MDL %p", (const void *)0x1B, a2);
    v8 = a1;
    v10 = (int)a2;
    v9 = 27;
  }
  else
  {
    if ( (*(_WORD *)(a1 + 6) & 5) != 0 )
      v6 = *(_DWORD *)(a1 + 12);
    else
      v6 = MmMapLockedPagesSpecifyCache(a1, 0, 1, 0, 0, 1073741840);
    if ( v6 )
      return &a2[v6 - *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 16)];
    v7 = (int *)&unk_61875C;
    ViHalPreprocessOptions(&unk_61875C, "Dma MDL %p not mapped in system VA.", (const void *)0x22);
    v8 = 0;
    v9 = 34;
    v10 = a1;
  }
  VfReportIssueWithOptions(230, v9, v10, v8, 0, v7);
  return 0;
}
