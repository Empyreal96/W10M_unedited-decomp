// PpmReleaseLock 
 
int __fastcall PpmReleaseLock(int *a1)
{
  int v1; // r4
  int result; // r0
  unsigned int v3; // r1
  int v4; // r3

  v1 = *a1;
  *a1 = 0;
  result = KeSetEvent(a1 + 1, 0, 0);
  if ( v1 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = (__int16)(*(_WORD *)(v3 + 0x136) + 1);
    *(_WORD *)(v3 + 310) = v4;
    if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
