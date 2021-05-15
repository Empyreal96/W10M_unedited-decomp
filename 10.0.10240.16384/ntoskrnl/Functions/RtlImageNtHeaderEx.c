// RtlImageNtHeaderEx 
 
int __fastcall RtlImageNtHeaderEx(int a1, unsigned int a2, unsigned __int64 a3, _DWORD *a4)
{
  BOOL v5; // r0
  unsigned int v6; // r3
  _DWORD *v7; // r0
  int v8; // r3

  if ( !a4 )
    return -1073741811;
  *a4 = 0;
  if ( (a1 & 0xFFFFFFFE) != 0 || a2 == -1 || !a2 )
    return -1073741811;
  v5 = (a1 & 1) == 0;
  if ( v5 && a3 < 0x40 )
    return -1073741701;
  if ( *(_WORD *)a2 != 23117 )
    return -1073741701;
  v6 = *(_DWORD *)(a2 + 60);
  if ( v5 )
  {
    if ( v6 >= a3 || v6 >= 0xFFFFFFE7 || v6 + 24 >= a3 )
      return -1073741701;
  }
  v7 = (_DWORD *)(v6 + a2);
  if ( v6 + a2 < a2
    || a2 < MmHighestUserAddress
    && ((unsigned int)v7 >= MmHighestUserAddress || (unsigned int)(v7 + 62) >= MmHighestUserAddress) )
  {
    return -1073741701;
  }
  if ( *v7 != 17744 )
    return -1073741701;
  v8 = 0;
  *a4 = v7;
  return v8;
}
