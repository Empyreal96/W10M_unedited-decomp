// AuthzBasepResetOperands 
 
int __fastcall AuthzBasepResetOperands(int result, int a2)
{
  unsigned int v2; // r5
  int v4; // r4

  v2 = 0;
  v4 = result;
  do
  {
    *(_WORD *)v4 = 0;
    *(_BYTE *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = 0;
    if ( *(_BYTE *)(v2 + a2) )
    {
      result = ExFreePoolWithTag(*(_DWORD *)(*(_DWORD *)(v4 + 16) + 8), 0);
      *(_DWORD *)(*(_DWORD *)(v4 + 16) + 8) = 0;
      *(_BYTE *)(v2 + a2) = 0;
    }
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 24) = 0;
    ++v2;
    v4 += 28;
  }
  while ( v2 < 2 );
  return result;
}
