// RtlpCreateHeapEncoding 
 
int __fastcall RtlpCreateHeapEncoding(int result)
{
  int v1; // r4

  v1 = result;
  if ( (*(_DWORD *)(result + 72) & 2) == 0 && (*(_DWORD *)(result + 64) & 0x4000000) == 0 )
  {
    *(_DWORD *)(result + 80) = 0;
    *(_BYTE *)(result + 82) |= 0x10u;
    *(_DWORD *)(result + 76) = *(_DWORD *)(result + 80);
    *(_DWORD *)(result + 80) |= ExGenRandom(1);
    result = ExGenRandom(1);
    *(_WORD *)(v1 + 84) = result;
    *(_BYTE *)(v1 + 86) = 0;
    *(_BYTE *)(v1 + 87) = 0;
  }
  return result;
}
