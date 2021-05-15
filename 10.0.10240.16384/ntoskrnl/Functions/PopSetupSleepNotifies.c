// PopSetupSleepNotifies 
 
_DWORD *__fastcall PopSetupSleepNotifies(int a1)
{
  int v1; // r5
  _DWORD *v2; // r4
  _DWORD *v3; // r6
  _DWORD *result; // r0
  _DWORD *v5; // r1
  _DWORD *v6; // r2
  int v7; // r3
  int v8; // r3
  __int64 v9; // kr00_8

  v1 = 4;
  v2 = (_DWORD *)(a1 + 188);
  do
  {
    v3 = v2 + 6;
    PopMoveList((int)(v2 + 4), v2 + 6);
    PopMoveList((int)(v2 + 4), v2 + 10);
    result = (_DWORD *)PopMoveList((int)(v2 + 4), v2 + 8);
    v5 = (_DWORD *)v2[4];
    while ( v5 != v2 + 4 )
    {
      v6 = v5;
      v7 = v5[13];
      v5 = (_DWORD *)*v5;
      v6[14] = v7;
      v8 = v6[11];
      v6[12] = v8;
      if ( !v8 )
      {
        v9 = *(_QWORD *)v6;
        if ( *(_DWORD **)(*v6 + 4) != v6 || *(_DWORD **)HIDWORD(v9) != v6 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v9) = v9;
        *(_DWORD *)(v9 + 4) = HIDWORD(v9);
        result = (_DWORD *)v2[7];
        *v6 = v3;
        v6[1] = result;
        if ( (_DWORD *)*result != v3 )
          __fastfail(3u);
        *result = v6;
        v2[7] = v6;
      }
    }
    --v1;
    v2[3] = v2[2];
    v2 -= 10;
  }
  while ( v1 >= 0 );
  return result;
}
