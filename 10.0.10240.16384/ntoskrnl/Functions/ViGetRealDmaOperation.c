// ViGetRealDmaOperation 
 
int __fastcall ViGetRealDmaOperation(int a1, int a2)
{
  int *v4; // r0
  int v5; // r3

  if ( ViVerifyDma && !a1 )
  {
    ViHalPreprocessOptions(&dword_6187C4, "DMA adapters aren't supposed to be NULL anymore", 25, 0, 0, 0);
    VfReportIssueWithOptions(230, 25, 0, 0, 0, &dword_6187C4);
  }
  v4 = ViGetAdapterInformationInternal(a1, 1);
  if ( v4 )
    v5 = v4[7];
  else
    v5 = *(_DWORD *)(a1 + 4);
  return *(_DWORD *)(v5 + a2);
}
