// MiVadPureReserve 
 
int __fastcall MiVadPureReserve(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 28);
  if ( (v1 & 0x8000) != 0 )
  {
    if ( *(int *)(a1 + 32) >= 0 && (v1 & 7) == 0 )
      return 1;
  }
  else if ( (*(_DWORD *)(a1 + 28) & 0xF8) == 192 )
  {
    return sub_530E30();
  }
  return 0;
}
