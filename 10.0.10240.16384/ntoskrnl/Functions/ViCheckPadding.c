// ViCheckPadding 
 
int __fastcall ViCheckPadding(int result, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r9
  int *v6; // r4
  int v7; // r6
  int v8; // r2
  int v9; // r7
  int v10; // r8
  unsigned int v11; // r6
  int v12; // r2
  int v13; // r9

  v4 = a3;
  v5 = result;
  if ( a4 != a2 )
  {
    if ( !a4 )
    {
      result = ViHasBufferBeenTouched(result, a2);
      v4 = result;
      if ( !result )
        return result;
      v6 = (int *)&unk_618774;
      v7 = 0;
      ViHalPreprocessOptions(
        &unk_618774,
        "Verified driver or hardware has corrupted memory at %p.",
        (const void *)0x1000000F);
      v8 = 3;
      return VfReportIssueWithOptions(230, 15, v8, v4, v7, v6);
    }
    v9 = a3 + a4;
    v10 = a3 - result;
    v11 = result - (a3 + a4) + a2;
    v12 = 0;
    if ( (unsigned int)(v4 - result) >= 8 )
    {
      v10 -= 8;
      v12 = 1;
    }
    if ( v11 >= 8 )
    {
      v11 -= 8;
      v9 += 8;
      v12 |= 2u;
    }
    ViCheckTag(v4, a4, 0, v12);
    v13 = ViHasBufferBeenTouched(v5, v10);
    if ( v13 )
    {
      ViHalPreprocessOptions(
        &dword_618768,
        "Padding before allocation at %p has been illegally modified at %p.",
        (const void *)0x1000000F,
        (const void *)4);
      VfReportIssueWithOptions(230, 15, 4, v4, v13, &dword_618768);
    }
    result = ViHasBufferBeenTouched(v9, v11);
    v7 = result;
    if ( result )
    {
      v6 = (int *)&unk_61876C;
      ViHalPreprocessOptions(
        &unk_61876C,
        "Padding after allocation at %p has been illegally modified at %p.",
        (const void *)0x1000000F,
        (const void *)5);
      v8 = 5;
      return VfReportIssueWithOptions(230, 15, v8, v4, v7, v6);
    }
  }
  return result;
}
