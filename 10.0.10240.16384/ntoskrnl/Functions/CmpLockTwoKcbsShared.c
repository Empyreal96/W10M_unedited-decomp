// CmpLockTwoKcbsShared 
 
unsigned int __fastcall CmpLockTwoKcbsShared(unsigned int result, _DWORD *a2)
{
  _DWORD *v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r3

  v2 = (_DWORD *)result;
  if ( result )
  {
    if ( a2 )
    {
      v3 = (*(_DWORD *)(result + 4) >> 21) & 0x3FF;
      v4 = (a2[1] >> 21) & 0x3FF;
      if ( v3 > v4 )
        goto LABEL_12;
      if ( v3 < v4 || result < (unsigned int)a2 )
        return sub_804B58();
      if ( result > (unsigned int)a2 )
LABEL_12:
        CmpLockKcbShared(a2);
    }
  }
  else
  {
    if ( !a2 )
      return result;
    v2 = a2;
  }
  return CmpLockKcbShared(v2);
}
