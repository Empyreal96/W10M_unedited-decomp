// FsRtlSplitLocks 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall FsRtlSplitLocks(int *a1, _DWORD *a2, unsigned int *a3, _QWORD *a4)
{
  _DWORD *v4; // r5
  _DWORD *result; // r0
  unsigned int v7; // r7 OVERLAPPED
  unsigned int v8; // r8 OVERLAPPED
  int v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r6
  unsigned int v12; // lr
  BOOL v13; // r10
  _DWORD *i; // r4
  unsigned __int64 v15; // kr08_8
  unsigned __int64 v16; // kr10_8
  _DWORD *v17; // r6
  _DWORD *v18; // r4
  int v19; // r3
  unsigned int v20; // [sp+0h] [bp-48h]
  unsigned int v21; // [sp+8h] [bp-40h]
  int v22; // [sp+10h] [bp-38h]
  unsigned int v23; // [sp+14h] [bp-34h]
  unsigned int v24; // [sp+18h] [bp-30h]

  v4 = a1;
  v22 = 0;
  if ( *((_BYTE *)a1 + 4) )
    return (_DWORD *)sub_51E558();
  *(_QWORD *)&v7 = *a4;
  v9 = *a1;
  v11 = a3[1];
  v10 = *a3;
  result = 0;
  v23 = v11;
  v24 = *a3;
  v21 = 0;
  v12 = 0;
  v20 = 0;
  if ( v9 && __PAIR64__(v11, v10) > __PAIR64__(v8, v7) )
  {
    v13 = *((_QWORD *)v4 + 1) > __PAIR64__(v11, v10);
    for ( i = (_DWORD *)*a2; ; i = (_DWORD *)*i )
    {
      if ( !i )
      {
        *((_QWORD *)v4 + 1) = *(_QWORD *)&v7;
        return result;
      }
      if ( *v4 != *a2 )
        break;
      v12 = i[3];
      *(_QWORD *)&v7 = *((_QWORD *)i + 5);
      v21 = i[2];
      v20 = v12;
      if ( !v13 )
        *((_QWORD *)v4 + 1) = *(_QWORD *)&v7;
LABEL_12:
      v11 = v23;
      a2 = i;
    }
    v15 = *((_QWORD *)i + 1);
    result = (_DWORD *)HIDWORD(v15);
    if ( v15 > __PAIR64__(v8, v7) && (*((_QWORD *)i + 2) || v15 != __PAIR64__(v12, v21)) )
    {
      result = (_DWORD *)ExAllocateFromNPagedLookasideList(&FsRtlLockTreeNodeLookasideList);
      v17 = result;
      if ( result )
      {
        v18 = result + 4;
        result[4] = result + 4;
        result[5] = 0;
        result[6] = 0;
        *((_BYTE *)result + 4) = 0;
        if ( v4[6] )
        {
          result = RtlRealSuccessor(v4 + 4);
          result[1] = v18;
          *v18 = result;
        }
        else
        {
          v4[6] = v18;
          *v18 = v4 + 4;
        }
        i = v17;
        *v17 = *a2;
        *a2 = 0;
        v17[7] = v4[7];
        v19 = v4[2];
        v4[7] = a2;
        v17[2] = v19;
        v17[3] = v4[3];
        *((_QWORD *)v4 + 1) = *(_QWORD *)&v7;
        if ( v22 )
          v22 = 0;
        else
          *((_BYTE *)v4 + 4) = 0;
        v4 = v17;
LABEL_11:
        v12 = v20;
        goto LABEL_12;
      }
      if ( *((_BYTE *)v4 + 4) )
        v22 = 1;
      v11 = v23;
      *((_BYTE *)v4 + 4) = 1;
    }
    if ( v13 && *((_QWORD *)i + 1) > __PAIR64__(v11, v24) )
      return result;
    v16 = *((_QWORD *)i + 5);
    if ( __PAIR64__(v8, v7) < v16 )
    {
      v8 = HIDWORD(v16);
      v7 = v16;
      if ( !v13 )
        *((_QWORD *)v4 + 1) = v16;
    }
    goto LABEL_11;
  }
  return result;
}
