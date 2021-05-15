// RtlpTraceDatabaseInternalFind 
 
int __fastcall RtlpTraceDatabaseInternalFind(int a1, unsigned int a2, int *a3, _DWORD *a4)
{
  unsigned int v8; // r1
  unsigned int v9; // r0
  _DWORD *i; // r0
  unsigned int v11; // r1
  int *v12; // r4
  int v13; // r2
  int v14; // t1

  v8 = (*(int (__fastcall **)(unsigned int, int *))(a1 + 72))(a2, a3);
  ++*(_DWORD *)(a1 + 4 * (v8 & 0xF) + 84);
  v9 = *(_DWORD *)(a1 + 64);
  if ( !v9 )
    __brkdiv0();
  for ( i = *(_DWORD **)(*(_DWORD *)(a1 + 68) + 4 * (v8 % v9)); ; i = (_DWORD *)i[6] )
  {
    if ( !i )
    {
      if ( a4 )
        *a4 = 0;
      return 0;
    }
    if ( a2 == i[2] )
    {
      v11 = 0;
      if ( a2 )
      {
        v12 = a3;
        do
        {
          v13 = *(int *)((char *)v12 + i[7] - (_DWORD)a3);
          v14 = *v12++;
          if ( v13 != v14 )
            break;
          ++v11;
        }
        while ( v11 < a2 );
      }
      if ( v11 == a2 )
        break;
    }
  }
  if ( a4 )
    *a4 = i;
  return 1;
}
