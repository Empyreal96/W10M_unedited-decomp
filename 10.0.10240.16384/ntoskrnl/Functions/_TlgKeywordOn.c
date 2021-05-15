// _TlgKeywordOn 
 
BOOL __fastcall TlgKeywordOn(int a1, __int64 a2)
{
  return !a2 || (*(_QWORD *)(a1 + 8) & a2) != 0 && (a2 & *(_QWORD *)(a1 + 16)) == *(_QWORD *)(a1 + 16);
}
