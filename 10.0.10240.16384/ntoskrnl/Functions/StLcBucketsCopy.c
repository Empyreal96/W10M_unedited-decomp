// StLcBucketsCopy 
 
void __fastcall __spoils<R2,R3,R12> StLcBucketsCopy(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  int v4; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r3
  __int64 v9; // [sp+0h] [bp-20h] BYREF
  _DWORD v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = 8;
  if ( a4 <= 8 )
    v4 = a4;
  v6 = a3;
  KeQueryPerformanceCounter(v10, &v9);
  for ( ; v4; --v4 )
  {
    if ( !v9 )
      __brkdiv0();
    v7 = _rt_sdiv64(v9, 1000000i64 * *(_QWORD *)v6);
    *a1 = 10 * ((v7 + 9) / 0xAu);
    if ( !(10 * ((v7 + 9) / 0xAu)) )
      *a1 = -1;
    v8 = *(_DWORD *)(v6 + 8);
    v6 += 16;
    a1[1] = v8;
    a1 += 2;
  }
}
