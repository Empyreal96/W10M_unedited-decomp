// CcCanReuseVacb 
 
BOOL __fastcall CcCanReuseVacb(int a1, unsigned int a2)
{
  int v3; // r3
  BOOL result; // r0

  v3 = *(_DWORD *)(a1 + 4);
  result = 0;
  if ( v3 && v3 != -1 && !*(_WORD *)(a1 + 8) && *(_DWORD *)a1 )
  {
    if ( a2 )
      result = ((a2 >> 20) & 0xFFC) - 1070596096 == ((*(_DWORD *)a1 >> 20) & 0xFFC) - 1070596096;
    else
      result = 1;
  }
  return result;
}
