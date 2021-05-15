// MiCreatePteCopyList 
 
int __fastcall MiCreatePteCopyList(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v4; // r3
  int result; // r0

  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 12) = 0;
  *(_BYTE *)(a3 + 9) = 0;
  *(_BYTE *)(a3 + 8) = 17;
  if ( a1 <= a2 >> 1 )
    v4 = 2 * a1;
  else
    v4 = a2 & 0xFFFFFFFE;
  *(_DWORD *)(a3 + 4) = v4;
  result = MiReservePtes(&dword_634D58);
  *(_DWORD *)(a3 + 12) = result;
  if ( !result )
    result = sub_53A38C();
  return result;
}
