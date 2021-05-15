// MmInitializeProcessor 
 
int __fastcall MmInitializeProcessor(_DWORD *a1)
{
  int v2; // r0
  int result; // r0
  int v4; // r2

  if ( a1[5] )
    a1[1022] = -1;
  v2 = MiReservePtes(&dword_634D58, 0x10u);
  if ( !v2 )
    return 0;
  a1[897] = v2 << 10;
  result = 1;
  a1[684] = dword_633814;
  v4 = dword_63F718 + 104 * *(unsigned __int16 *)(a1[590] + 266);
  a1[682] = *(unsigned __int8 *)(v4 + 76);
  a1[683] = *(_DWORD *)(v4 + 72);
  return result;
}
