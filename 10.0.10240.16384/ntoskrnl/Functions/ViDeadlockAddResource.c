// ViDeadlockAddResource 
 
int __fastcall ViDeadlockAddResource(unsigned int a1, unsigned int a2, int a3, int *a4, int *a5, int a6)
{
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r10
  int v18; // r1
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r6
  int v22; // r2
  int v23; // r4
  __int64 v24; // r0

  if ( a2 > 8 )
    return 0;
  v10 = ViDeadlockSearchResource(a1, a6);
  if ( v10 )
  {
    if ( (ViDeadlockResourceTypeInfo[a2] & 8) == 0 )
    {
      ViDeadlockPreprocessOptions(&dword_6187F0, "Re-initializing active lock 0x%p.", (const void *)0x1005);
      VfReportIssueWithOptions(196, 4101, a1, v10, 0, &dword_6187F0);
    }
    if ( *(_DWORD *)(v10 + 12) )
    {
      ViDeadlockPreprocessOptions(&dword_6187E8, "Re-initializing active lock 0x%p.", (const void *)0x1005);
      VfReportIssueWithOptions(196, 4101, a1, v10, 1, &dword_6187E8);
    }
    ViDeadlockRemoveResource(v10, 0, a6);
    *a5 = v10;
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 < *(_DWORD *)(v11 + 0x20) )
  {
    v12 = *(_DWORD *)(v11 + 36);
    __dmb(0xBu);
    if ( a1 > v12 )
      return 0;
  }
  if ( !a3 )
    return 0;
  *(_WORD *)(a3 + 4) = 0;
  *(_WORD *)(a3 + 6) = 0;
  *(_DWORD *)(a3 + 12) = 0;
  *(_DWORD *)(a3 + 64) = 0;
  *(_DWORD *)(a3 + 96) = 0;
  *(_DWORD *)a3 = a2;
  *(_DWORD *)(a3 + 8) = a1;
  *(_DWORD *)(a3 + 16) = a3 + 16;
  *(_DWORD *)(a3 + 20) = a3 + 16;
  v13 = *a4;
  v14 = a4[1];
  v15 = a4[2];
  v16 = a4[3];
  v17 = a4 + 4;
  *(_DWORD *)(a3 + 32) = v13;
  *(_DWORD *)(a3 + 36) = v14;
  *(_DWORD *)(a3 + 40) = v15;
  *(_DWORD *)(a3 + 44) = v16;
  v18 = v17[1];
  v19 = v17[2];
  v20 = v17[3];
  *(_DWORD *)(a3 + 48) = *v17;
  *(_DWORD *)(a3 + 52) = v18;
  *(_DWORD *)(a3 + 56) = v19;
  *(_DWORD *)(a3 + 60) = v20;
  v21 = (a1 >> 12)
      - 1023
      * ((unsigned int)((((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                      + ((unsigned int)((a1 >> 12) - (((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  v22 = a3 + 24;
  v23 = ViDeadlockGlobals;
  HIDWORD(v24) = *(_DWORD *)(ViDeadlockGlobals + 16) + 8 * v21;
  LODWORD(v24) = *(_DWORD *)HIDWORD(v24);
  *(_QWORD *)(a3 + 24) = v24;
  if ( *(_DWORD *)(v24 + 4) != HIDWORD(v24) )
    __fastfail(3u);
  *(_DWORD *)(v24 + 4) = v22;
  *(_DWORD *)HIDWORD(v24) = v22;
  VfUtilAddressRangeAdd((unsigned int *)(v23 + 8 * (v21 + 3)), a1, ViDeadlockResourceTypeSizeInfo[a2]);
  ++*(_DWORD *)(v23 + 20);
  return 1;
}
