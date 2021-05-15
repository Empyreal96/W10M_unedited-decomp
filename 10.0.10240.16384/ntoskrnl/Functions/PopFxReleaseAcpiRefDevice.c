// PopFxReleaseAcpiRefDevice 
 
int __fastcall PopFxReleaseAcpiRefDevice(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 136);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  if ( !v3 )
    result = KeSetEvent(result + 140, 0, 0);
  return result;
}
