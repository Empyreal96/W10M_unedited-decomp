// PopCheckSkipTick 
 
int PopCheckSkipTick()
{
  int result; // r0

  if ( PopApicMode == 2 )
    result = 1;
  else
    result = sub_7F10F8();
  return result;
}
