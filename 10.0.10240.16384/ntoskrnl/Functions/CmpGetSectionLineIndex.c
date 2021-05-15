// CmpGetSectionLineIndex 
 
int __fastcall CmpGetSectionLineIndex(int a1, int a2, int a3, unsigned int a4)
{
  int v7; // r0
  int v8; // r0
  _DWORD *v9; // r2
  unsigned int v10; // r1

  v7 = CmpSearchSectionByName(a1, a2);
  if ( v7 )
  {
    v8 = CmpSearchLineInSectionByIndex(v7, a3);
    if ( v8 )
    {
      v9 = *(_DWORD **)(v8 + 8);
      v10 = 0;
      if ( a4 )
      {
        while ( v9 )
        {
          ++v10;
          v9 = (_DWORD *)*v9;
          if ( v10 >= a4 )
            goto LABEL_4;
        }
      }
      else
      {
LABEL_4:
        if ( v9 )
          return CmpProcessForSimpleStringSub(a1, v9[1]);
      }
    }
  }
  return 0;
}
