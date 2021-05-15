// IoGetAffinityInterrupt 
 
int __fastcall IoGetAffinityInterrupt(int a1, _DWORD *a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r3
  unsigned int v4; // r3
  int v5; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 52);
  if ( !v2 )
  {
    LOWORD(v3) = 0;
LABEL_6:
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
    *((_WORD *)a2 + 2) = v3;
    v5 = *(_DWORD *)(a1 - 84);
    result = 0;
    *a2 = v5;
    return result;
  }
  if ( v2 < 0x20 )
  {
    v4 = KiProcessorIndexToNumberMappingTable[v2];
    if ( v4 )
    {
      v3 = v4 >> 6;
      goto LABEL_6;
    }
  }
  return -1073741811;
}
