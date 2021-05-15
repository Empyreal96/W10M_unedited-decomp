// CmpGetSectionLineIndexValueCount 
 
int __fastcall CmpGetSectionLineIndexValueCount(int a1, int a2, int a3)
{
  int v4; // r4
  int v5; // r0
  int v6; // r0
  _DWORD *v7; // r3

  v4 = 0;
  v5 = CmpSearchSectionByName();
  if ( v5 )
  {
    v6 = CmpSearchLineInSectionByIndex(v5, a3);
    if ( v6 )
    {
      v7 = *(_DWORD **)(v6 + 8);
      while ( v7 )
      {
        v7 = (_DWORD *)*v7;
        ++v4;
      }
    }
  }
  return v4;
}
