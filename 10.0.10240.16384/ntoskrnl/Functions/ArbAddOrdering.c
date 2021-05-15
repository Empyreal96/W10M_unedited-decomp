// ArbAddOrdering 
 
int __fastcall ArbAddOrdering(unsigned __int16 *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  int v4; // r8

  v4 = HIDWORD(a2);
  if ( a3 < a2 )
    return -1073741811;
  if ( *a1 == a1[1] )
    return sub_80D8B8();
  HIDWORD(a2) = *((_DWORD *)a1 + 1) + 16 * *a1;
  *(_DWORD *)HIDWORD(a2) = a2;
  *(_DWORD *)(HIDWORD(a2) + 4) = v4;
  *(_QWORD *)(*((_DWORD *)a1 + 1) + 16 * (*a1)++ + 8) = a3;
  return 0;
}
