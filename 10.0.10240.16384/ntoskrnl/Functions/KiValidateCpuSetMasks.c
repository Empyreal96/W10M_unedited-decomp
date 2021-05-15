// KiValidateCpuSetMasks 
 
int __fastcall KiValidateCpuSetMasks(int a1, unsigned int a2)
{
  if ( a2 > KeQueryMaximumGroupCount(a1) )
    return -1073741393;
  if ( a2 )
    return sub_51C28C();
  return 0;
}
