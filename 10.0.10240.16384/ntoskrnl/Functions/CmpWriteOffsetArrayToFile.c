// CmpWriteOffsetArrayToFile 
 
int __fastcall CmpWriteOffsetArrayToFile(int a1, unsigned int a2, int a3, int a4, int a5)
{
  int result; // r0
  int v8; // r1
  int v9[4]; // [sp+10h] [bp-20h] BYREF

  v9[2] = a4;
  v9[0] = 0;
  v9[3] = 0;
  result = ZwSetInformationFile();
  if ( result >= 0 )
  {
    if ( CmpDoFileWrite(result, v8, a5, a3, a2, v9, 0) )
      result = ZwFlushBuffersFile();
    else
      result = -1073741491;
  }
  return result;
}
