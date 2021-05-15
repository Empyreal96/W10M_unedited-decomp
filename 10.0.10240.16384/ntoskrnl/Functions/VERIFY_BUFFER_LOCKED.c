// VERIFY_BUFFER_LOCKED 
 
int __fastcall VERIFY_BUFFER_LOCKED(int a1)
{
  int result; // r0

  result = MmAreMdlPagesLocked(a1);
  if ( !result )
  {
    ViHalPreprocessOptions(&dword_618730, "DMA Pages Not Locked! MDL %p for DMA not locked", (const void *)0xE);
    result = VfReportIssueWithOptions(230, 14, a1, 0, 0, &dword_618730);
  }
  return result;
}
