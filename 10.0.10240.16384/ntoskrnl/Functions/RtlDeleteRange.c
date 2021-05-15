// RtlDeleteRange 
 
int __fastcall RtlDeleteRange(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, unsigned __int64 a5, int a6)
{
  int v8; // r6
  int v9; // r0
  unsigned __int64 v11; // kr00_8
  int v13; // r2
  _DWORD *v14; // r3
  _DWORD *v15; // r7
  int i; // [sp+0h] [bp-20h]

  v8 = -1073741172;
  v9 = *a1 - 28;
  for ( i = *(_DWORD *)(v9 + 28) - 28; a1 != (_DWORD *)(v9 + 28); i = *(_DWORD *)(i + 28) - 28 )
  {
    v11 = *(_QWORD *)v9;
    if ( a5 < *(_QWORD *)v9 )
      break;
    if ( (*(_WORD *)(v9 + 26) & 1) != 0 )
    {
      if ( __PAIR64__(a4, a3) >= v11 && a5 <= *(_QWORD *)(v9 + 8) )
      {
        v13 = *(_DWORD *)(v9 + 16) - 28;
        v14 = **(_DWORD ***)(v9 + 16);
        while ( 1 )
        {
          v15 = v14 - 7;
          if ( v9 + 16 == v13 + 28 )
            break;
          if ( *(_QWORD *)v13 == __PAIR64__(a4, a3) && *(_QWORD *)(v13 + 8) == a5 && *(_DWORD *)(v13 + 20) == a6 )
          {
            v8 = RtlpDeleteFromMergedRange(v13);
            if ( v8 >= 0 )
            {
              --a1[3];
              ++a1[4];
            }
            return v8;
          }
          v14 = (_DWORD *)*v14;
          v13 = (int)v15;
        }
      }
    }
    else if ( v11 == __PAIR64__(a4, a3) )
    {
      return sub_80E72C();
    }
    v9 = i;
  }
  return v8;
}
