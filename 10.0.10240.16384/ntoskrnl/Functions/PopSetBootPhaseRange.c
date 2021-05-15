// PopSetBootPhaseRange 
 
_BYTE *PopSetBootPhaseRange(int a1, char *a2, unsigned int a3, ...)
{
  unsigned int v6; // r6
  va_list varg_r3; // [sp+2Ch] [bp+14h] BYREF

  va_start(varg_r3, a3);
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopSetBootPhaseRange - setting pages %p - %p, Tag %.4s\n", a2, &a2[a3], (const char *)varg_r3);
  v6 = (unsigned int)a2;
  if ( a2 < &a2[a3] )
  {
    do
    {
      if ( ((*(int *)(*(_DWORD *)(a1 + 28) + 4 * (v6 >> 5)) >> (v6 & 0x1F)) & 1) == 0 )
        *(_BYTE *)((v6 >> 3) + *(_DWORD *)(a1 + 36)) &= ~(1 << (v6 & 7));
      ++v6;
    }
    while ( v6 < (unsigned int)&a2[a3] );
  }
  return RtlSetBits((_BYTE *)(a1 + 24), (unsigned int)a2, a3);
}
