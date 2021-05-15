// EnlistKeyBodyWithKCB 
 
int __fastcall EnlistKeyBodyWithKCB(_DWORD *a1, char a2)
{
  unsigned int v3; // r7
  int result; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r4

  v3 = 0;
  a1[4] = a1 + 4;
  a1[5] = a1 + 4;
  result = 72;
  while ( 1 )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)(a1[1] + result);
    do
      v7 = __ldrex(v6);
    while ( !v7 && __strex((unsigned int)a1, v6) );
    __dmb(0xBu);
    if ( !v7 )
      break;
    ++v3;
    result += 4;
    if ( v3 >= 4 )
    {
      if ( (a2 & 1) != 0 )
        result = CmpUnlockKcb(a1[1]);
      if ( (a2 & 2) == 0 )
        result = CmpLockKcbExclusive(a1[1]);
      return sub_7FD264(result);
    }
  }
  return result;
}
