// CmpLockTwoKcbsExclusive 
 
int __fastcall CmpLockTwoKcbsExclusive(unsigned int a1, unsigned int a2)
{
  unsigned int v4; // r2
  unsigned int v5; // r3
  unsigned int v6; // r0

  if ( a1 )
  {
    if ( a2 )
    {
      v4 = (*(_DWORD *)(a1 + 4) >> 21) & 0x3FF;
      v5 = (*(_DWORD *)(a2 + 4) >> 21) & 0x3FF;
      if ( v4 < v5 )
      {
LABEL_4:
        CmpLockKcbExclusive(a1);
        v6 = a2;
        return CmpLockKcbExclusive(v6);
      }
      if ( v4 > v5 )
        goto LABEL_7;
      if ( a1 < a2 )
        goto LABEL_4;
      if ( a1 > a2 )
LABEL_7:
        CmpLockKcbExclusive(a2);
    }
    v6 = a1;
    return CmpLockKcbExclusive(v6);
  }
  return sub_7D25FC();
}
