// CmpUnlockAndLockKcbs 
 
int __fastcall CmpUnlockAndLockKcbs(int result, _DWORD *a2, _DWORD *a3, int a4)
{
  _DWORD *v7; // r5

  v7 = (_DWORD *)result;
  if ( a2 )
  {
    result = CmpUnlockKcb(a2);
    if ( (_DWORD *)*v7 != a2 )
      return sub_805174(result);
    *v7 = 0;
  }
  if ( a3 )
  {
    if ( *v7 )
      v7[1] = a3;
    else
      *v7 = a3;
    if ( a4 == 1 )
    {
      result = CmpLockKcbExclusive(a3);
    }
    else if ( a4 == 2 )
    {
      result = CmpLockKcbShared(a3);
    }
  }
  return result;
}
