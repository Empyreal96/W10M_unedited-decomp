// CmpSortByTag 
 
int __fastcall CmpSortByTag(_DWORD **a1)
{
  __int64 v1; // r4
  _DWORD *v2; // r1

  v1 = *(_QWORD *)a1;
  v2 = (_DWORD *)**a1;
  while ( (_DWORD)v1 != HIDWORD(v1) )
  {
    if ( *(_DWORD *)(v1 + 60) > v2[15] )
      return sub_9684D8();
    LODWORD(v1) = v2;
    v2 = (_DWORD *)*v2;
  }
  return 1;
}
