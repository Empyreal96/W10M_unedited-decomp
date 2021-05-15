// VfMapTransferEx 
 
int __fastcall VfMapTransferEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int *a8)
{
  int v9; // r0
  int v10; // r5
  int v11; // r1
  int v12; // r0
  int v13; // r7
  int (__fastcall *v14)(int, int, int); // r0
  int v15; // r0
  int v16; // r4

  v9 = ViGetAdapterInformationInternal(a1, 1);
  v10 = v9;
  if ( v9 )
  {
    VF_ASSERT_MAX_IRQL(v9);
    VERIFY_BUFFER_LOCKED(a2);
    ViCheckAdapterBuffers(v10);
    v12 = ViCheckMdlLength(a2, v11, a5, a6, *a8);
    v13 = v12;
    if ( v12 )
    {
      ViHalPreprocessOptions(
        &dword_618728,
        "The provided MDL is not sufficient to satisfy the requested length",
        36,
        v12,
        0,
        0);
      VfReportIssueWithOptions(230, 36, v13, 0, 0, &dword_618728);
    }
  }
  v14 = (int (__fastcall *)(int, int, int))ViGetRealDmaOperation(a1, 92);
  v15 = v14(a1, a2, a3);
  v16 = v15;
  if ( v10 && v15 >= 0 )
    INCREASE_MAPPED_TRANSFER_BYTE_COUNT(v10, *a8, 1);
  return v16;
}
