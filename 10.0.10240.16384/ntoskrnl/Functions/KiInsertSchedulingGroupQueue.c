// KiInsertSchedulingGroupQueue 
 
int __fastcall KiInsertSchedulingGroupQueue(int a1, int a2, int a3)
{
  int v5; // r3
  int **v6; // r0
  int *v7; // r1
  __int64 v8; // r0
  int v9; // r3
  int *v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r3

  *(_BYTE *)(a2 + 92) |= 1u;
  v5 = *(_DWORD *)(a2 + 236);
  if ( v5 )
    v6 = (int **)(v5 + 228);
  else
    v6 = (int **)(a1 + 1976);
  v7 = *v6;
  if ( *v6 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(a2 + 96) - v7[4];
      if ( !v9 )
      {
        if ( !*(_WORD *)(a2 + 94) )
        {
          LODWORD(v8) = sub_52BF90();
          return v8;
        }
        v11 = 31 - __clz(*(unsigned __int16 *)(a2 + 94));
        v12 = 0;
        if ( *((_WORD *)v7 + 7) )
          v12 = 31 - __clz(*((unsigned __int16 *)v7 + 7));
        v9 = v12 - v11;
      }
      if ( v9 >= 0 )
      {
        v10 = (int *)v7[1];
        if ( !v10 )
          break;
      }
      else
      {
        v10 = (int *)*v7;
        if ( !*v7 )
          break;
      }
      v7 = v10;
    }
  }
  LODWORD(v8) = RtlRbInsertNodeEx();
  if ( a3 )
  {
    v8 = KeQueryInterruptTime(v8);
    *(_QWORD *)(a2 + 64) = v8;
  }
  return v8;
}
