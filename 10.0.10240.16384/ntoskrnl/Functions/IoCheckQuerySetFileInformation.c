// IoCheckQuerySetFileInformation 
 
int __fastcall IoCheckQuerySetFileInformation(unsigned int a1, unsigned int a2, int a3)
{
  int *v4; // r3
  unsigned int v5; // r3

  if ( a1 >= 0x40 )
    return -1073741821;
  v4 = &IopQueryOperationLength;
  if ( a3 )
    v4 = &IopSetOperationLength;
  v5 = *((char *)v4 + a1);
  if ( !v5 )
    return -1073741821;
  if ( a2 >= v5 )
    return 0;
  return -1073741820;
}
