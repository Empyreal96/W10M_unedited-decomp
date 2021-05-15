// ViCheckTag 
 
_BYTE *__fastcall ViCheckTag(_BYTE *result, int a2, int a3, char a4)
{
  int v6; // r7
  int v7; // r6
  _BYTE *v8; // r8
  int v9; // r5

  v6 = a2;
  v7 = (int)result;
  v8 = result;
  v9 = a2;
  if ( (a4 & 1) != 0 )
  {
    result = (_BYTE *)RtlCompareMemory(result - 8, (int)ViDmaVerifierTag, 8);
    if ( result != (_BYTE *)8 )
    {
      ViHalPreprocessOptions(
        &dword_618778,
        "Area before %x byte allocation at %p has been modified.",
        268435471,
        (const void *)1);
      result = (_BYTE *)VfReportIssueWithOptions(230, 15, 1, v9, v7, &dword_618778);
    }
    v8 = (_BYTE *)(v7 - 8);
    v9 = v6 + 8;
  }
  if ( (a4 & 2) != 0 )
  {
    result = (_BYTE *)RtlCompareMemory((unsigned __int8 *)(v7 + v6), (int)ViDmaVerifierTag, 8);
    if ( result != (_BYTE *)8 )
    {
      ViHalPreprocessOptions(
        &dword_618770,
        "Area after %x byte allocation at %p has been modified.",
        268435471,
        (const void *)2);
      result = (_BYTE *)VfReportIssueWithOptions(230, 15, 2, v6, v7, &dword_618770);
    }
    v9 += 8;
  }
  if ( a3 )
    result = memset(v8, 15, v9);
  return result;
}
