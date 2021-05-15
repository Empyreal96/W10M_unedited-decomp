// MiObtainSessionVaCharges 
 
unsigned int MiObtainSessionVaCharges()
{
  int v0; // r4
  unsigned int *v1; // r2
  unsigned int v2; // r0
  unsigned int *v3; // r2
  unsigned int result; // r0

  v0 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v1 = (unsigned int *)(v0 + 32);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  v3 = (unsigned int *)(v0 + 28);
  do
    result = __ldrex(v3);
  while ( __strex(result + 1, v3) );
  return result;
}
