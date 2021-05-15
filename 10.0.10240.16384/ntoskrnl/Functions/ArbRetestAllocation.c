// ArbRetestAllocation 
 
int __fastcall ArbRetestAllocation(int a1, _DWORD **a2)
{
  _DWORD *v4; // r2
  int v5; // r4
  _DWORD **v6; // r3
  _DWORD *v7; // r6
  _DWORD *i; // r6
  __int64 v10; // [sp+0h] [bp-90h] BYREF
  __int64 v11[7]; // [sp+8h] [bp-88h] BYREF
  char v12[80]; // [sp+40h] [bp-50h] BYREF

  memset(v11, 0, sizeof(v11));
  memset(v12, 0, 56);
  LODWORD(v11[5]) = 1;
  HIDWORD(v11[5]) = v12;
  v4 = a2[2];
  HIDWORD(v11[4]) = v12;
  LOWORD(v11[6]) = 1;
  if ( !v4 )
  {
    v5 = RtlCopyRangeList(*(_DWORD **)(a1 + 24), *(_DWORD **)(a1 + 20));
    if ( v5 >= 0 )
    {
      v6 = (_DWORD **)*a2;
      v7 = (_DWORD *)**a2;
      while ( v6 != v7 )
      {
        v5 = RtlDeleteOwnersRanges(*(int ***)(a1 + 24), v7[4]);
        if ( v5 < 0 )
          goto LABEL_18;
        v7 = (_DWORD *)*v7;
        v6 = (_DWORD **)*a2;
      }
      goto LABEL_9;
    }
LABEL_18:
    RtlFreeRangeList(*(_DWORD **)(a1 + 24));
    return v5;
  }
  v5 = (*(int (__fastcall **)(int, _DWORD *, _DWORD *, _DWORD))(a1 + 140))(a1, a2[1], v4, *(_DWORD *)(a1 + 24));
  if ( v5 < 0 )
    goto LABEL_18;
LABEL_9:
  for ( i = (_DWORD *)**a2; *a2 != i; i = (_DWORD *)*i )
  {
    HIDWORD(v11[6]) = 0;
    LODWORD(v11[4]) = i;
    v5 = ArbpBuildAlternative(a1, i[12], (int)v12);
    if ( i[13] != 2 )
    {
      (*(void (__fastcall **)(_DWORD, __int64 *, __int64 *))(a1 + 68))(i[11], v11, &v10);
      v11[1] = v10 + v11[0] - 1;
      v5 = (*(int (__fastcall **)(int, __int64 *))(a1 + 112))(a1, v11);
      if ( v5 < 0 )
        goto LABEL_18;
      if ( v10 )
        (*(void (__fastcall **)(int, __int64 *))(a1 + 128))(a1, v11);
      if ( (v11[6] & 0x10) != 0 )
      {
        ExFreePoolWithTag(HIDWORD(v11[6]));
        LOWORD(v11[6]) &= 0xFFEFu;
      }
    }
  }
  return v5;
}
