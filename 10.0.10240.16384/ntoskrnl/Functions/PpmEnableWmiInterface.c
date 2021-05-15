// PpmEnableWmiInterface 
 
int PpmEnableWmiInterface()
{
  int v0; // r4
  void **i; // r5
  int result; // r0

  v0 = 0;
  for ( i = &KiProcessorBlock; ; ++i )
  {
    result = KeQueryGroupAffinity(0);
    if ( ((1 << v0) & result) != 0 )
      break;
    if ( (unsigned int)++v0 >= 0x20 )
      return result;
  }
  return sub_7F15C4();
}
