// IoCheckQuerySetVolumeInformation 
 
int __fastcall IoCheckQuerySetVolumeInformation(unsigned int a1, unsigned int a2, int a3)
{
  int *v3; // r3
  unsigned int v4; // r3

  v3 = IopQueryFsOperationLength;
  if ( a3 )
    v3 = IopSetFsOperationLength;
  if ( a1 >= 0xE )
    return -1073741821;
  v4 = *((char *)v3 + a1);
  if ( !v4 )
    return -1073741821;
  if ( a2 >= v4 )
    return 0;
  return -1073741820;
}
