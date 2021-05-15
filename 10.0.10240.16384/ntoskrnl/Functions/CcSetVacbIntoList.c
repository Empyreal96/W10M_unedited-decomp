// CcSetVacbIntoList 
 
int __fastcall CcSetVacbIntoList(__int64 a1)
{
  _QWORD *v1; // r2

  v1 = (_QWORD *)(a1 + 8);
  LODWORD(a1) = *(_DWORD *)HIDWORD(a1);
  *v1 = a1;
  if ( *(_DWORD *)(a1 + 4) != HIDWORD(a1) )
    sub_53DE30();
  *(_DWORD *)(a1 + 4) = v1;
  *(_DWORD *)HIDWORD(a1) = v1;
  return a1;
}
