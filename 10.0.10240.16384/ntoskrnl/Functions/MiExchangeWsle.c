// MiExchangeWsle 
 
int __fastcall MiExchangeWsle(int result, unsigned int a2, int a3, int a4)
{
  _DWORD *v4; // r7
  int varg_r0; // [sp+20h] [bp+8h]

  varg_r0 = result;
  v4 = (_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000);
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 92) + 36) * a3 + *(_DWORD *)(*(_DWORD *)(result + 92) + 252)) = a2;
  if ( (a2 & 8) == 0 )
    return MiReplaceWsleHash();
  if ( (*v4 & 2) == 0 )
    sub_51A1A0();
  *(_DWORD *)(MmPfnDatabase + 24 * (*v4 >> 12)) = a3;
  return result;
}
