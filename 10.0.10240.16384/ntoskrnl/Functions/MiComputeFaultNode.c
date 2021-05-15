// MiComputeFaultNode 
 
int __fastcall MiComputeFaultNode(int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v6; // r4
  int v7; // r2
  int v8; // r5
  _DWORD *v10; // r0
  unsigned int v11; // r3

  if ( (a4 & 1) != 0 )
    v6 = a4 & 0xFFFFFFFE;
  else
    v6 = 0;
  v7 = *(_DWORD *)(a1 + 92);
  *a5 = 0;
  v8 = 0;
  if ( v7 != -1069539328 )
  {
    if ( (a4 & 1) != 0 && *(_BYTE *)(a4 & 0xFFFFFFFE) == 4 )
      v8 = *(unsigned __int8 *)(v6 + 20);
    return v8;
  }
  if ( a2 >= 0xC0000000 && a2 <= 0xC03FFFFF
    || !v6 && MEMORY[0xC040213C] != 1
    || (v10 = MiLocateAddress(a2)) == 0
    || (v11 = v10[7], *a5 = v10, (v8 = (v11 >> 8) & 0x3F) == 0)
    && ((v11 & 0x8000) != 0 || (v8 = (*(_DWORD *)(*(_DWORD *)v10[11] + 28) >> 20) & 0x3F) == 0) )
  {
    if ( a3 )
      v8 = (*(_DWORD *)(a3 + 28) >> 20) & 0x3F;
  }
  if ( !v6 || v8 || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1 )
    return v8;
  return sub_544E88();
}
