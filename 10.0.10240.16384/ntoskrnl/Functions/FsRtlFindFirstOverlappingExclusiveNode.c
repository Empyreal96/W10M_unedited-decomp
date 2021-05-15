// FsRtlFindFirstOverlappingExclusiveNode 
 
int __fastcall FsRtlFindFirstOverlappingExclusiveNode(int a1, unsigned __int64 *a2, _DWORD *a3, _DWORD *a4, _BYTE *a5)
{
  unsigned __int64 *v5; // r7
  int v6; // r10
  unsigned __int64 v7; // r6
  unsigned __int64 v8; // kr00_8
  unsigned __int64 v9; // kr08_8
  _DWORD *v12; // [sp+0h] [bp-28h]
  int v13; // [sp+8h] [bp-20h]

  v5 = a2;
  v12 = a3;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v6 = 0;
  if ( a1 )
  {
    while ( 1 )
    {
      v7 = *v5;
      v8 = *(_QWORD *)(a1 + 48);
      v13 = a1;
      if ( v8 >= v7 && ((v9 = *(_QWORD *)(a1 + 16)) != 0 || (a3 = v12, *(_QWORD *)(a1 + 24))) )
      {
        if ( v9 <= *(_QWORD *)a3 )
        {
          if ( (*a3 & a3[1]) == -1 )
            return sub_51E3A0();
          if ( v9 <= v7 )
          {
LABEL_15:
            if ( !a1 )
              return v6;
            return v13;
          }
          v6 = a1;
        }
        if ( a4 )
          *a4 = a1;
        if ( a5 )
          *a5 = 1;
      }
      else
      {
        if ( v8 != __PAIR64__(a3[1], *v12) || *(_QWORD *)(a1 + 16) != v7 )
        {
          if ( a4 )
            *a4 = a1;
          if ( a5 )
            *a5 = 0;
          a1 = *(_DWORD *)(a1 + 8);
          goto LABEL_14;
        }
        v6 = a1;
        if ( a4 )
          *a4 = a1;
        if ( a5 )
          *a5 = 0;
      }
      a1 = *(_DWORD *)(a1 + 4);
LABEL_14:
      a3 = v12;
      v5 = a2;
      if ( !a1 )
        goto LABEL_15;
    }
  }
  return v6;
}
