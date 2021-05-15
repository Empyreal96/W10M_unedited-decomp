// ArbTestAllocation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ArbTestAllocation(int a1, int ***a2)
{
  int v5; // r4
  int v6; // r8
  int v7; // r9
  int *v8; // r6
  unsigned int v9; // r4 OVERLAPPED
  int v10; // r3
  unsigned int i; // r3
  int **v12; // r6
  __int64 v13; // r0
  int *v14; // r4 OVERLAPPED
  int v15; // r0
  int v16; // r3

  if ( a2[2] )
    return sub_80E348();
  v5 = RtlCopyRangeList(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 20));
  if ( v5 >= 0 )
  {
    v6 = 0;
    v7 = 0;
    v8 = **a2;
    if ( *a2 == (int **)v8 )
    {
LABEL_11:
      v12 = *a2;
      do
      {
        LODWORD(v13) = *v12;
        HIDWORD(v13) = 1;
        v14 = (int *)**v12;
        if ( *v12 == (int *)v12 )
          break;
        do
        {
          if ( v14 == (int *)v12 )
            break;
          if ( *(_DWORD *)(v13 + 28) > v14[7] )
          {
            HIDWORD(v13) = *(_DWORD *)(v13 + 4);
            v16 = *v14;
            *(_DWORD *)HIDWORD(v13) = v14;
            *(_DWORD *)(v16 + 4) = v13;
            *(_QWORD *)v13 = *(_QWORD *)(&v14 - 1);
            *(_QWORD *)v14 = v13;
            HIDWORD(v13) = 0;
          }
          LODWORD(v13) = *(_DWORD *)v13;
          v14 = *(int **)v13;
        }
        while ( (int **)v13 != v12 );
      }
      while ( !HIDWORD(v13) );
      v5 = ArbpBuildAllocationStack(a1, *a2, v6);
      if ( v5 >= 0 )
      {
        v5 = (*(int (__fastcall **)(int, _DWORD))(a1 + 116))(a1, *(_DWORD *)(a1 + 56));
        if ( v5 >= 0 )
          return v5;
      }
    }
    else
    {
      while ( 1 )
      {
        ++v6;
        if ( !a2[2] && v7 != v8[4] )
        {
          v7 = v8[4];
          v5 = RtlDeleteOwnersRanges(*(_DWORD *)(a1 + 24));
          if ( v5 < 0 )
            break;
        }
        v8[7] = 0;
        if ( *(_DWORD *)(a1 + 72) )
        {
          *(_QWORD *)(&v9 - 1) = *((_QWORD *)v8 + 1);
          for ( i = v9 + 32 * v10; v9 < i; i = v8[3] + 32 * v8[2] )
          {
            v15 = (*(int (__fastcall **)(unsigned int))(a1 + 72))(v9);
            if ( v15 < 0 )
            {
              v5 = -1073741438;
              goto LABEL_24;
            }
            v8[7] += v15;
            v9 += 32;
          }
        }
        v8 = (int *)*v8;
        if ( *a2 == (int **)v8 )
          goto LABEL_11;
      }
    }
  }
LABEL_24:
  RtlFreeRangeList(*(_DWORD *)(a1 + 24));
  return v5;
}
