// VfBuildScatterGatherListEx 
 
int __fastcall VfBuildScatterGatherListEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, unsigned __int8 a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r4
  int v18; // r5
  int v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int v24; // r1
  int v25; // r0
  int v26; // r7
  int v27; // r0
  int (__fastcall *v32)(int, int, int, int, int, int, int, int, int, int, _DWORD, int, int, int, int, int); // [sp+3Ch] [bp-24h]

  v16 = a1;
  v32 = (int (__fastcall *)(int, int, int, int, int, int, int, int, int, int, _DWORD, int, int, int, int, int))ViGetRealDmaOperation(a1, 100);
  v18 = ViGetAdapterInformationInternal(v16, 1);
  if ( v18 )
  {
    VF_ASSERT_IRQL(2);
    if ( !a4 )
      return -1073741811;
    __dmb(0xBu);
    v20 = (unsigned int *)(v18 + 92);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 + 1, v20) );
    __dmb(0xBu);
    v22 = (unsigned int *)(v18 + 96);
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 + 1, v22) );
    __dmb(0xBu);
    VERIFY_BUFFER_LOCKED(a4);
    v25 = ViCheckMdlLength(a4, v24, a5, a6, a7);
    v26 = v25;
    if ( v25 )
    {
      ViHalPreprocessOptions(
        &dword_618724,
        "The provided MDL is not sufficient to satisfy the requested length",
        36,
        v25,
        0,
        0);
      VfReportIssueWithOptions(230, 36, v26, 0, 0, &dword_618724);
      v16 = a1;
    }
  }
  v27 = v32(v16, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
  v19 = v27;
  if ( v18 && v27 < 0 )
    DECREMENT_SCATTER_GATHER_LISTS(v18);
  return v19;
}
