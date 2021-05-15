// VfGetScatterGatherListEx 
 
int __fastcall VfGetScatterGatherListEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, unsigned __int8 a11, int a12, int a13, int a14)
{
  int v14; // r6
  int v16; // r0
  int v17; // r6
  unsigned int *v18; // r4
  unsigned int v19; // r5
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  int v23; // r0
  int v24; // r5
  int v25; // r0
  int v26; // r4
  int (__fastcall *v31)(int, int, int, int, int, int, int, int, int, int, _DWORD, int, int, int); // [sp+34h] [bp-24h]

  v14 = a1;
  v31 = (int (__fastcall *)(int, int, int, int, int, int, int, int, int, int, _DWORD, int, int, int))ViGetRealDmaOperation(a1, 96);
  v16 = ViGetAdapterInformationInternal(v14, 1);
  v17 = v16;
  if ( v16 )
  {
    VF_ASSERT_MAX_IRQL(v16);
    __dmb(0xBu);
    v18 = (unsigned int *)(v17 + 92);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 + 1, v18) );
    __dmb(0xBu);
    v20 = (unsigned int *)(v17 + 96);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 + 1, v20) );
    __dmb(0xBu);
    VERIFY_BUFFER_LOCKED(a4);
    v23 = ViCheckMdlLength(a4, v22, a5, a6, a7);
    v24 = v23;
    if ( v23 )
    {
      ViHalPreprocessOptions(
        &dword_61872C,
        "The provided MDL is not sufficient to satisfy the requested length",
        36,
        v23,
        0,
        0);
      VfReportIssueWithOptions(230, 36, v24, 0, 0, &dword_61872C);
    }
  }
  v25 = v31(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
  v26 = v25;
  if ( v17 && v25 < 0 )
    DECREMENT_SCATTER_GATHER_LISTS(v17);
  return v26;
}
