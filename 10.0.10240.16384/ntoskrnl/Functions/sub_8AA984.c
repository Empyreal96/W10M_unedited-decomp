// sub_8AA984 
 
int __fastcall sub_8AA984(int a1, unsigned int a2)
{
  int v3; // r4
  _WORD *v4; // r6
  unsigned int v5; // r0

  v3 = a2;
  if ( a2 < *(unsigned __int16 *)(a1 + 2) )
    return 0;
  if ( a2 >= 0xFF7F )
  {
    if ( a2 > 0xFFFF )
      return -1073741670;
  }
  else
  {
    v3 = (a2 + 127) >> 7 << 7;
  }
  v4 = (_WORD *)ExAllocatePoolWithTag(1, v3, 542329939);
  if ( v4 )
  {
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 )
    {
      *(_DWORD *)(a1 + 4) = 0;
      *(_WORD *)a1 = 0;
      ExFreePoolWithTag(v5);
    }
    *(_DWORD *)(a1 + 8) = v4;
    *v4 = 0;
    *(_WORD *)(a1 + 2) = v3;
    return 0;
  }
  return -1073741670;
}
