// KeGetBugMessageText 
 
int __fastcall KeGetBugMessageText(unsigned int a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r2
  int i; // r4
  unsigned __int16 *v7; // r1
  unsigned int j; // r2
  unsigned __int16 *v9; // r4
  unsigned __int16 v10; // r0

  result = 0;
  if ( KiBugCodeMessages )
  {
    v5 = (char *)KiBugCodeMessages + 4;
    for ( i = *(_DWORD *)KiBugCodeMessages; i; --i )
    {
      if ( a1 >= *v5 && a1 <= v5[1] )
      {
        v7 = (unsigned __int16 *)((char *)KiBugCodeMessages + v5[2]);
        for ( j = a1 - *v5; j; --j )
          v7 = (unsigned __int16 *)((char *)v7 + *v7);
        v9 = v7 + 2;
        v10 = (unsigned __int16)strlen((unsigned int)(v7 + 2));
        *(_DWORD *)(a2 + 4) = v9;
        *(_WORD *)a2 = v10;
        *(_WORD *)(a2 + 2) = v10;
        return 1;
      }
      v5 += 3;
    }
  }
  return result;
}
