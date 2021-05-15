// FsRtlFindFirstOverlappingSharedNode 
 
int __fastcall FsRtlFindFirstOverlappingSharedNode(int a1, unsigned __int64 *a2, _DWORD *a3, _DWORD *a4, _BYTE *a5)
{
  unsigned __int64 *v6; // r3
  int v7; // r10
  unsigned __int64 v8; // r8
  int v9; // r4
  _QWORD *v10; // r1
  unsigned __int64 v11; // kr00_8
  int result; // r0

  v6 = a2;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v7 = 0;
  if ( a1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      v9 = a1 - 16;
      v10 = *(_QWORD **)(a1 - 16);
      if ( *(_QWORD *)(a1 - 8) >= *v6 && ((v11 = v10[1]) != 0 || v10[2]) )
      {
        if ( v11 <= *(_QWORD *)a3 )
        {
          if ( (*a3 & a3[1]) == -1 )
            return sub_51E2A4();
          if ( v11 <= v8 )
          {
LABEL_12:
            if ( a1 )
              goto LABEL_13;
            break;
          }
          v7 = a1 - 16;
        }
        if ( a4 )
          *a4 = a1;
        if ( a5 )
          *a5 = 1;
        a1 = *(_DWORD *)(a1 + 4);
      }
      else
      {
        if ( v10[5] == *(_QWORD *)a3 && v10[1] == v8 )
          goto LABEL_12;
        if ( a4 )
          *a4 = a1;
        if ( a5 )
          *a5 = 0;
        a1 = *(_DWORD *)(a1 + 8);
      }
      v6 = a2;
      if ( !a1 )
        goto LABEL_12;
    }
  }
  v9 = v7;
LABEL_13:
  if ( v9 )
    result = v9 + 16;
  else
    result = 0;
  return result;
}
