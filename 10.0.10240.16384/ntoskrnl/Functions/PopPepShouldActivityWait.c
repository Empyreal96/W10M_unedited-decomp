// PopPepShouldActivityWait 
 
int __fastcall PopPepShouldActivityWait(int a1, int a2, int a3, int a4, char a5)
{
  int *v7; // r3
  _DWORD **v8; // r1
  char *v9; // r4
  int v10; // r0

  if ( a5 )
    return sub_5401C8();
  v7 = &dword_403120[31 * a2 + 2];
  if ( a3 > a4 )
    return 0;
  v8 = (_DWORD **)(a1 + 4 * a3);
  v9 = (char *)v7 - a1;
  while ( 1 )
  {
    v10 = *(int *)((char *)v8 + (_DWORD)v9);
    if ( v10 )
    {
      if ( (**v8 & v10) != 0 )
        break;
    }
    ++a3;
    ++v8;
    if ( a3 > a4 )
      return 0;
  }
  return 1;
}
