// MiCanPageMove 
 
BOOL __fastcall MiCanPageMove(int a1)
{
  _DWORD *v1; // r2
  int v2; // r1
  BOOL result; // r0

  result = 1;
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 && (*(_DWORD *)(a1 + 8) & 0x400) != 0 )
  {
    v1 = (_DWORD *)(*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC)));
    v2 = *v1;
    if ( v1 != (_DWORD *)(*v1 + 80) && (*(_DWORD *)(v2 + 28) & 0x20) != 0 && (*(_DWORD *)(v2 + 52) & 0x10000000) != 0 )
      result = 0;
  }
  return result;
}
