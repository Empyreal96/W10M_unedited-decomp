// SepDuplicateTokenClaims 
 
int __fastcall SepDuplicateTokenClaims(int a1, int a2)
{
  int result; // r0
  int v4; // r3
  unsigned int *v5; // [sp+0h] [bp-8h] BYREF

  v5 = 0;
  if ( (*(_DWORD *)(a1 + 176) & 0x8000) != 0 && *(_DWORD *)(a1 + 636) )
  {
    result = SepDuplicateClaimAttributes(*(unsigned int **)(a1 + 636), &v5);
    if ( result >= 0 )
    {
      *(_DWORD *)(a2 + 636) = v5;
      *(_DWORD *)(a2 + 176) |= 0x8000u;
    }
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 636);
    result = 0;
    *(_DWORD *)(a2 + 636) = v4;
  }
  return result;
}
