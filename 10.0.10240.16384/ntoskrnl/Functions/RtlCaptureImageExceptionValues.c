// RtlCaptureImageExceptionValues 
 
int __fastcall RtlCaptureImageExceptionValues(int a1, int *a2, int a3)
{
  int result; // r0

  result = RtlImageDirectoryEntryToData(a1, 1, 3, a3);
  *a2 = result;
  return result;
}
