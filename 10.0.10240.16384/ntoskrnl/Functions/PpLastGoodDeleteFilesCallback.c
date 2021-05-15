// PpLastGoodDeleteFilesCallback 
 
int PpLastGoodDeleteFilesCallback()
{
  int result; // r0

  IopFileUtilClearAttributes();
  result = ZwOpenFile();
  if ( result >= 0 )
  {
    ZwSetInformationFile();
    ZwClose();
    result = 0;
  }
  return result;
}
