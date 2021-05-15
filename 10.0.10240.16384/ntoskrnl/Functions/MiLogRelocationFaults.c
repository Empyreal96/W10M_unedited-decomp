// MiLogRelocationFaults 
 
unsigned int __fastcall MiLogRelocationFaults(int a1, _DWORD *a2, int a3)
{
  int v6; // r7
  _DWORD *i; // r4

  v6 = MI_REFERENCE_CONTROL_AREA_FILE(a1);
  MiLogRelocationRva(*a2, a2[1], v6, a1);
  for ( i = *(_DWORD **)(a3 + 8); i; i = (_DWORD *)*i )
  {
    if ( (i[1] & 0xFFF) != 0 )
      MiLogRelocationRva(i[1], 0x2000, v6, a1);
  }
  return MI_DEREFERENCE_CONTROL_AREA_FILE(a1, v6);
}
