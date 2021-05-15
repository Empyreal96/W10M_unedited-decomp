// KiTurnOnFrozenProcessors 
 
int KiTurnOnFrozenProcessors()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // [sp+0h] [bp-10h]

  result = KiSetSafeToPowerDownFrozenProcessors(0);
  v1 = 0;
  v2 = 0;
  if ( KeNumberProcessors_0 )
  {
    while ( 1 )
    {
      result = (int)*(&KiProcessorBlock + v1);
      if ( result != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 )
      {
        result = KiTurnOnFrozenProcessorInternal(result);
        if ( result )
          break;
      }
      v1 = v2 + 1;
      v2 = v1;
      if ( v1 >= KeNumberProcessors_0 )
        return result;
    }
    result = sub_51C11C();
  }
  return result;
}
