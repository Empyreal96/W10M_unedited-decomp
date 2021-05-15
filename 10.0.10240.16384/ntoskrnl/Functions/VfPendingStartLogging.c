// VfPendingStartLogging 
 
_DWORD *__fastcall VfPendingStartLogging(int a1)
{
  _DWORD *result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r3

  if ( !VfForcedPendingLog )
    return 0;
  __dmb(0xBu);
  do
  {
    v3 = __ldrex(&VfForcedPendingIrps);
    v4 = v3 + 1;
  }
  while ( __strex(v4, &VfForcedPendingIrps) );
  __dmb(0xBu);
  v5 = VfForcedPendingLogLength;
  __dmb(0xBu);
  result = (_DWORD *)(VfForcedPendingLog + (((v5 - 1) & v4) << 8));
  *result = a1;
  result[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result[2] = 0;
  return result;
}
