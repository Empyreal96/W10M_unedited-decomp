// KiGetDebugExceptionType 
 
int KiGetDebugExceptionType()
{
  unsigned int v0; // r3

  v0 = ((unsigned int)__mrc(14, 0, 0, 2, 2) >> 2) & 0xF;
  switch ( v0 )
  {
    case 1u:
      return 8;
    case 2u:
      return 7;
    case 0xAu:
      return 6;
  }
  return 0;
}
