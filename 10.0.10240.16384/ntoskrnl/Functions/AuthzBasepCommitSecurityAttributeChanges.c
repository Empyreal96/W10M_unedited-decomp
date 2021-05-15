// AuthzBasepCommitSecurityAttributeChanges 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AuthzBasepCommitSecurityAttributeChanges(_DWORD *a1, int a2)
{
  int v3; // r8
  __int64 v4; // kr00_8
  int v5; // r3
  _DWORD *v6; // r1
  int v7; // r6
  _DWORD *v8; // r0
  BOOL v9; // lr
  __int64 v10; // kr08_8
  int v11; // r3
  _DWORD *v12; // r2
  int v14; // r1 OVERLAPPED
  _DWORD *v15; // r2 OVERLAPPED

  v3 = 0;
  if ( (*(_DWORD *)(a2 + 32) & 2) != 0 )
  {
    v4 = *(_QWORD *)(a2 + 8);
    if ( *(_DWORD *)(v4 + 4) != a2 + 8 || *(_DWORD *)HIDWORD(v4) != a2 + 8 )
      sub_517EB0(a1, HIDWORD(v4));
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    *(_DWORD *)(a2 + 32) &= 0xFFFFFFFD;
    if ( a1 )
      --a1[3];
  }
  v5 = *(_DWORD *)(a2 + 32);
  if ( (v5 & 4) != 0 )
  {
    AuthzBasepRemoveSecurityAttributeFromLists();
    AuthzBasepFreeSecurityAttributeValues(a2, 0);
    v3 = 1;
  }
  else
  {
    if ( (v5 & 1) == 0 )
    {
      v6 = (_DWORD *)a1[2];
      *(_DWORD *)a2 = a1 + 1;
      *(_DWORD *)(a2 + 4) = v6;
      if ( (_DWORD *)*v6 != a1 + 1 )
        __fastfail(3u);
      *v6 = a2;
      a1[2] = a2;
      *(_DWORD *)(a2 + 32) |= 1u;
      ++*a1;
    }
    v7 = a2 + 44;
    while ( *(_DWORD *)(a2 + 56) != a2 + 56 )
    {
      v8 = (_DWORD *)(*(_DWORD *)(a2 + 56) - 8);
      v9 = (*(_DWORD *)(*(_DWORD *)(a2 + 56) + 8) & 4) != 0;
      if ( (*(_DWORD *)(*(_DWORD *)(a2 + 56) + 8) & 2) != 0 )
      {
        v10 = *(_QWORD *)*(_DWORD *)(a2 + 56);
        if ( *(_DWORD *)(v10 + 4) != *(_DWORD *)(a2 + 56) || *(_DWORD *)HIDWORD(v10) != *(_DWORD *)(a2 + 56) )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v10) = v10;
        *(_DWORD *)(v10 + 4) = HIDWORD(v10);
        v8[4] &= 0xFFFFFFFD;
        --*(_DWORD *)(a2 + 52);
      }
      v11 = v8[4];
      if ( v9 )
      {
        if ( (v11 & 1) != 0 )
        {
          *(_QWORD *)&v14 = *(_QWORD *)v8;
          if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v15 != v8 )
            __fastfail(3u);
          *v15 = v14;
          *(_DWORD *)(v14 + 4) = v15;
          v8[4] &= 0xFFFFFFFE;
          --*(_DWORD *)(a2 + 36);
          if ( (v8[4] & 4) != 0 )
            --*(_DWORD *)(a2 + 40);
        }
        ExFreePoolWithTag(v8, 0);
      }
      else if ( (v11 & 1) == 0 )
      {
        v12 = *(_DWORD **)(a2 + 48);
        *v8 = v7;
        v8[1] = v12;
        if ( *v12 != v7 )
          __fastfail(3u);
        *v12 = v8;
        *(_DWORD *)(a2 + 48) = v8;
        v8[4] |= 1u;
        ++*(_DWORD *)(a2 + 36);
      }
    }
  }
  return v3;
}
