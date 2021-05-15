// PopIgnoreBatteryStatusChange 
 
int PopIgnoreBatteryStatusChange()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 0;
  do
    v1 = __ldrex(dword_61EDC0);
  while ( __strex(0, dword_61EDC0) );
  __dmb(0xBu);
  if ( v1 )
  {
    result = KeCancelTimer((int)&dword_61EDC0[2]);
    if ( !result )
      result = KeWaitForSingleObject((unsigned int)&byte_61EE18, 0, 0, 0, 0);
  }
  byte_61EE28 = 1;
  return result;
}
