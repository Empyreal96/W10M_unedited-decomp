// sub_550BA4 
 
void sub_550BA4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, ...)
{
  unsigned int v7; // r6
  unsigned int v8; // r8
  va_list va; // [sp+Ch] [bp+Ch] BYREF

  va_start(va, a7);
  if ( !ExpResizeBigPageTable(0, 1, (int *)va) )
  {
    MiFreePoolPages(v7, v8);
    JUMPOUT(0x4ED860);
  }
  JUMPOUT(0x4ED86E);
}
