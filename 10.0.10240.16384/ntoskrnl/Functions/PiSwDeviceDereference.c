// PiSwDeviceDereference 
 
unsigned int *__fastcall PiSwDeviceDereference(unsigned int *result)
{
  unsigned int v1; // r2
  unsigned int v2; // r2

  __dmb(0xBu);
  do
  {
    v1 = __ldrex(result);
    v2 = v1 - 1;
  }
  while ( __strex(v2, result) );
  __dmb(0xBu);
  if ( !v2 )
    result = (unsigned int *)sub_81BF30();
  return result;
}
