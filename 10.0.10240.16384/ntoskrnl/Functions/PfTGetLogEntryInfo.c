// PfTGetLogEntryInfo 
 
int __fastcall PfTGetLogEntryInfo(int a1, unsigned __int16 *a2, int a3)
{
  unsigned __int16 *v3; // r4
  int v6; // r5
  int result; // r0

  v3 = a2;
  memset(a2, 0, 24);
  if ( (*(_DWORD *)a1 & 3) != 0 )
  {
    *v3 = -1;
    if ( (*(_DWORD *)a1 & 0x18) == 16 )
      v3[6] = *(_WORD *)(a1 + 6);
    else
      v3[6] = -1;
  }
  else
  {
    v3[6] = *(_WORD *)(a1 + 6);
    *v3 = *(_WORD *)(a1 + 4);
  }
  v6 = 2;
  do
  {
    result = *v3;
    if ( result != 0xFFFF )
    {
      result = PfTLocateEntryInfo(result, a3);
      *((_DWORD *)v3 + 1) = *(_DWORD *)(a3 + 8);
      *((_DWORD *)v3 + 2) = result;
    }
    v3 += 6;
    --v6;
  }
  while ( v6 );
  return result;
}
