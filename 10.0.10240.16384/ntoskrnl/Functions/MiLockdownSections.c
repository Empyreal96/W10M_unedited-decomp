// MiLockdownSections 
 
_BYTE *__fastcall MiLockdownSections(_BYTE *result)
{
  _BYTE *v1; // r6
  unsigned int v2; // r7
  int v3; // r5
  int v4; // r1
  int v5; // r1
  _BYTE *v6; // r9
  int v7; // r6
  int v8; // r4
  int v9; // r1
  unsigned int v10; // r0

  v1 = result;
  v2 = *((_DWORD *)result + 6);
  v3 = 0;
  if ( (MiFlags & 0x30000) != 0 )
    return (_BYTE *)sub_7CDD4C();
  if ( v2 < dword_63389C
    || (result = (_BYTE *)MiGetSystemRegionIndex(*((_DWORD *)result + 6)), result[v4 + 9692] != 1)
    && (result = (_BYTE *)MiGetSystemRegionIndex(v2), result[v5 + 9692] != 11) )
  {
    v3 = 1;
  }
  if ( v3 )
  {
    result = (_BYTE *)RtlImageNtHeader(v2);
    v6 = (_BYTE *)*((_DWORD *)v1 + 34);
    v7 = *((unsigned __int16 *)result + 3);
    v8 = (int)&result[*((unsigned __int16 *)result + 10) + 24];
    if ( *((_WORD *)result + 3) )
    {
      do
      {
        v9 = 0;
        if ( *(_DWORD *)v8 == 1987011374 && *(_WORD *)(v8 + 4) == 29285 )
          v9 = 1;
        if ( (*(_DWORD *)(v8 + 36) & 0x20000000) != 0 )
          v9 |= 2u;
        if ( (v9 & v3) != 0 )
        {
          v10 = *(_DWORD *)(v8 + 16);
          if ( v10 < *(_DWORD *)(v8 + 8) )
            v10 = *(_DWORD *)(v8 + 8);
          result = RtlSetBits(
                     v6,
                     *(_DWORD *)(v8 + 12) >> 12,
                     (((*(_DWORD *)(v8 + 12) + v2 + v10 + 4095) & 0xFFFFF000) - (*(_DWORD *)(v8 + 12) + v2)) >> 12);
        }
        --v7;
        v8 += 40;
      }
      while ( v7 > 0 );
    }
  }
  return result;
}
