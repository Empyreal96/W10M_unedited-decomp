// PopGetHiberFlags 
 
int PopGetHiberFlags()
{
  int result; // r0

  result = 0;
  if ( dword_61EC6C < 0 && dword_61EC74 == 2 )
    result = 2;
  if ( PopFirmwareProtection )
    result |= 4u;
  return result;
}
