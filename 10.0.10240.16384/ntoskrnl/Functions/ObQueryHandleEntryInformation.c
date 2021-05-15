// ObQueryHandleEntryInformation 
 
_DWORD *__fastcall ObQueryHandleEntryInformation(_DWORD *result, _DWORD *a2)
{
  unsigned int v2; // r5
  int v3; // r3

  v2 = *result & 0xFFFFFFF8;
  v3 = *result & 6;
  if ( (result[1] & 0x4000000) != 0 )
    LOBYTE(v3) = v3 | 8;
  if ( (result[1] & 0x2000000) != 0 )
    LOBYTE(v3) = v3 | 1;
  a2[4] = v3 & 7;
  a2[3] = *(unsigned __int8 *)(ObTypeIndexTable[*(unsigned __int8 *)(v2 + 12) ^ BYTE1(v2) ^ (unsigned __int8)ObHeaderCookie]
                             + 20);
  a2[1] = *(_DWORD *)v2;
  *a2 = *(_DWORD *)(v2 + 4);
  a2[2] = result[1] & 0x1FFFFFF;
  return result;
}
