// CmpLockIXLockExclusive 
 
int __fastcall CmpLockIXLockExclusive(int *a1, _DWORD *a2, int a3)
{
  int v4; // r3

  v4 = *a1;
  if ( !*a1 )
  {
    *a1 = -2147483647;
    a1[1] = (int)a2;
    if ( a3 )
    {
      if ( a3 == 1 )
        a2[3] = a1;
    }
    else
    {
      a2[2] = a1;
    }
    return 1;
  }
  if ( v4 >= 0 )
  {
    if ( v4 != 1 || !CmEqualTrans(*(_DWORD *)(a1[1] + 28), a2[7]) )
      return 0;
    *a1 = -2147483647;
  }
  else if ( !CmEqualTrans(*(_DWORD *)(a1[1] + 28), a2[7]) )
  {
    return 0;
  }
  return 1;
}
