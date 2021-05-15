// PopCopyFirmwareRuntimeInformationPfnList 
 
char *__fastcall PopCopyFirmwareRuntimeInformationPfnList(char *result, int a2)
{
  int v2; // r2
  int v4; // r6
  unsigned int v5; // r4
  const void **v6; // r7
  const void *v7; // t1

  v2 = *((_DWORD *)result + 36);
  v4 = (int)result;
  if ( v2 )
  {
    v5 = ((*(_DWORD *)(v2 + 20) & 0xFFF) != 0) + (*(_DWORD *)(v2 + 20) >> 12);
    if ( v5 > 1 )
      v5 = 1;
    v6 = (const void **)(v2 + 28);
    result = (char *)memmove(a2 + 588, v2 + 28, 4 * v5);
    for ( *(_DWORD *)(a2 + 584) = v5; v5; --v5 )
    {
      v7 = *v6++;
      result = PoSetHiberRange(v4, 49152, v7, (const void *)1, 1682794822);
    }
  }
  else
  {
    *(_DWORD *)(a2 + 584) = 0;
  }
  return result;
}
