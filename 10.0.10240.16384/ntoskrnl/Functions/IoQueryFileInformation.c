// IoQueryFileInformation 
 
int __fastcall IoQueryFileInformation(int a1, int a2, int a3, int a4, int a5)
{
  return IopQueryXxxInformation(a1, a2, a3, 0, a4, a5, 1);
}
