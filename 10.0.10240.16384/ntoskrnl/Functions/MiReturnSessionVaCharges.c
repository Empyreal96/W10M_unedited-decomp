// MiReturnSessionVaCharges 
 
unsigned int __fastcall MiReturnSessionVaCharges(int a1)
{
  int v1; // r5
  int v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r0
  unsigned int *v5; // r2
  unsigned int result; // r0

  v1 = -a1;
  v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v3 = (unsigned int *)(v2 + 28);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 + v1, v3) );
  v5 = (unsigned int *)(v2 + 32);
  do
    result = __ldrex(v5);
  while ( __strex(result + v1, v5) );
  return result;
}
