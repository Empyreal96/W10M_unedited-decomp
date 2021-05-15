// ArbBootAllocation 
 
int __fastcall ArbBootAllocation(int a1, _DWORD *a2)
{
  _DWORD **v2; // r5
  __int64 v4; // kr00_8
  _DWORD **v5; // r3
  _DWORD *v6; // r6
  __int64 v7; // kr08_8
  __int64 v8; // r8
  unsigned int v9; // r10
  __int64 v10; // r2
  __int64 v11; // r2
  int v12; // r5
  int v13; // r0
  __int64 v15; // r2
  __int64 v17[7]; // [sp+10h] [bp-90h] BYREF
  __int64 v18[11]; // [sp+48h] [bp-58h] BYREF

  v2 = (_DWORD **)a2;
  memset(v17, 0, sizeof(v17));
  memset(v18, 0, 56);
  LODWORD(v17[5]) = 1;
  HIDWORD(v17[5]) = v18;
  HIDWORD(v17[4]) = v18;
  v4 = *(_QWORD *)(a1 + 20);
  LOWORD(v17[6]) = 2;
  BYTE2(v17[6]) = 1;
  RtlCopyRangeList(HIDWORD(v4), v4);
  v5 = (_DWORD **)*v2;
  v6 = (_DWORD *)**v2;
  while ( 1 )
  {
    if ( v5 == v6 )
    {
      RtlFreeRangeList(*(_DWORD *)(a1 + 20));
      v15 = *(_QWORD *)(a1 + 20);
      v12 = 0;
      *(_DWORD *)(a1 + 20) = HIDWORD(v15);
      *(_DWORD *)(a1 + 24) = v15;
      return v12;
    }
    LODWORD(v17[4]) = v6;
    ArbpBuildAlternative(a1, v6[3], v18);
    v7 = v18[0];
    v8 = v18[1];
    BYTE3(v17[6]) = 0;
    HIDWORD(v17[6]) = 0;
    v9 = HIDWORD(v18[2]);
    v17[0] = v18[0];
    v17[1] = v18[1];
    if ( v18[2] )
    {
      if ( v18[3] )
      {
        if ( v18[1] >= (unsigned __int64)v18[0] )
        {
          _rt_udiv64(v18[3], v18[0]);
          if ( !v10 )
          {
            LODWORD(v11) = (unsigned __int64)(v8 - v7 + 1) >> 32;
            HIDWORD(v11) = v8 - v7 + 1;
            if ( v11 == __PAIR64__(v18[2], v9) )
              break;
          }
        }
      }
    }
LABEL_11:
    v6 = (_DWORD *)*v6;
    v5 = (_DWORD **)*a2;
  }
  v12 = (*(int (__fastcall **)(int, __int64 *))(a1 + 112))(a1, v17);
  if ( v12 >= 0 )
  {
    (*(void (__fastcall **)(int, __int64 *))(a1 + 128))(a1, v17);
    v13 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 64))(
            *(_DWORD *)(HIDWORD(v17[4]) + 40),
            *(_DWORD *)(a1 + 64),
            v17[0],
            HIDWORD(v17[0]),
            v6[11]);
    if ( (v17[6] & 0x10) != 0 )
      return sub_80E468(v13);
    goto LABEL_11;
  }
  RtlFreeRangeList(*(_DWORD *)(a1 + 24));
  return v12;
}
