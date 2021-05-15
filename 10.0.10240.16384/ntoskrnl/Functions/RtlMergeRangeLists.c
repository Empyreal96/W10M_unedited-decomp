// RtlMergeRangeLists 
 
int __fastcall RtlMergeRangeLists(_DWORD *a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v7; // r4
  int v8; // r5
  int v9; // r3
  int v10; // r0
  int v11; // r2
  __int64 v12; // r0
  int v13; // r0
  int v14; // r9
  int v15; // r2
  int v16; // r0
  int v17; // r2
  __int64 v18; // r0

  v7 = RtlCopyRangeList(a1, a2);
  if ( v7 < 0 )
  {
LABEL_16:
    RtlFreeRangeList(a1);
  }
  else
  {
    v8 = *a3 - 28;
    if ( a3 != (_DWORD *)*a3 )
    {
      do
      {
        if ( (*(_WORD *)(v8 + 26) & 1) != 0 )
        {
          v9 = *(_DWORD *)(v8 + 16);
          while ( 1 )
          {
            v14 = v9 - 28;
            if ( v8 + 16 == v9 )
              break;
            v10 = RtlpCopyRangeListEntry(v9 - 28);
            if ( !v10 )
              goto LABEL_18;
            v11 = a4 | 1;
            HIDWORD(v12) = v10;
            if ( (*(_BYTE *)(v14 + 25) & 2) == 0 )
              v11 = a4;
            LODWORD(v12) = a1;
            v13 = RtlpAddRange(v12, v11);
            v9 = *(_DWORD *)(v14 + 28);
            v7 = v13;
          }
        }
        else
        {
          v16 = RtlpCopyRangeListEntry(v8);
          if ( !v16 )
          {
LABEL_18:
            v7 = -1073741670;
            goto LABEL_16;
          }
          v17 = a4 | 1;
          HIDWORD(v18) = v16;
          if ( (*(_BYTE *)(v8 + 25) & 2) == 0 )
            v17 = a4;
          LODWORD(v18) = a1;
          v7 = RtlpAddRange(v18, v17);
          if ( v7 < 0 )
            goto LABEL_16;
        }
        v8 = *(_DWORD *)(v8 + 28) - 28;
      }
      while ( a3 != (_DWORD *)(v8 + 28) );
    }
    v15 = a1[4];
    a1[3] += a3[3];
    a1[4] = a3[3] + v15;
  }
  return v7;
}
