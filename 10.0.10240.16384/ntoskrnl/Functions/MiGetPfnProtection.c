// MiGetPfnProtection 
 
int __fastcall MiGetPfnProtection(int a1, _DWORD *a2)
{
  int v2; // r4
  unsigned int v3; // r2

  v2 = (*a2 >> 4) & 0x1F;
  if ( !v2 )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( (v3 & 0x400) != 0 )
      v2 = (*(unsigned __int16 *)((*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
    else
      v2 = (v3 >> 5) & 0x1F;
    if ( *(int *)(a1 + 4) >= 0 )
    {
      v2 = MmMakeProtectNotWriteCopy[v2];
    }
    else if ( *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 272) )
    {
      return sub_51CC9C();
    }
  }
  return v2;
}
