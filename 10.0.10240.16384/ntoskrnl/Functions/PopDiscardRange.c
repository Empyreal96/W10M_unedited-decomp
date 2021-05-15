// PopDiscardRange 
 
_BYTE *PopDiscardRange(int a1, char *a2, unsigned int a3, ...)
{
  va_list varg_r3; // [sp+24h] [bp+14h] BYREF

  va_start(varg_r3, a3);
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopDiscardRange - removing pages %p - %p, Tag %.4s\n", a2, &a2[a3], (const char *)varg_r3);
  return RtlSetBits((_BYTE *)(a1 + 24), (unsigned int)a2, a3);
}
