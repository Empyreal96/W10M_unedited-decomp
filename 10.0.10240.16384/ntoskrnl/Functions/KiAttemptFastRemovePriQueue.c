// KiAttemptFastRemovePriQueue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiAttemptFastRemovePriQueue(_DWORD *a1, int *a2, int a3)
{
  unsigned int v3; // r6
  int v4; // lr
  int v6; // r4
  _DWORD *v7; // r5
  _DWORD *v8; // r7
  int v9; // t1
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED

  v3 = 0;
  v4 = 0;
  v6 = 32;
  v7 = a1 + 68;
  v8 = a1 + 100;
  do
  {
    v9 = *--v8;
    --v6;
    v7 -= 2;
    v3 += v9;
    if ( v6 == a3 )
      --v3;
    if ( v3 >= a1[100] )
      break;
    if ( (_DWORD *)*v7 != v7 )
    {
      v4 = a1[2 * v6 + 4];
      if ( !*(_DWORD *)v4 )
        sub_53F8D8();
      --a1[1];
      *(_QWORD *)&v10 = *(_QWORD *)v4;
      if ( *(_DWORD *)(*(_DWORD *)v4 + 4) != v4 || *v11 != v4 )
        __fastfail(3u);
      *v11 = v10;
      *(_DWORD *)(v10 + 4) = v11;
      *(_DWORD *)v4 = 0;
      *a2 = v6;
      return v4;
    }
  }
  while ( v6 > 0 );
  return v4;
}
