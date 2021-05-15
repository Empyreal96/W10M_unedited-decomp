// PiClearDeviceObjectList 
 
_BYTE *__fastcall PiClearDeviceObjectList(unsigned int *a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r6
  _BYTE *result; // r0
  unsigned int *v4; // r5
  int v5; // t1

  v1 = a1;
  v2 = 0;
  if ( *a1 )
  {
    v4 = a1;
    do
    {
      v5 = v4[4];
      v4 += 4;
      ObfDereferenceObject(v5);
      ++v2;
    }
    while ( v2 < *v1 );
  }
  result = memset((_BYTE *)v1 + 16, 0, 16 * v1[1]);
  *v1 = 0;
  v1[2] = 0;
  return result;
}
