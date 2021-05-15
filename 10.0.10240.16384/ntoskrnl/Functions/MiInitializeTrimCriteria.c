// MiInitializeTrimCriteria 
 
__int64 __fastcall MiInitializeTrimCriteria(__int64 result, int a2, char a3)
{
  _DWORD *v3; // r3

  *(_BYTE *)result = 0;
  *(_DWORD *)(result + 48) = 0;
  *(_DWORD *)(result + 40) = a2;
  HIDWORD(result) = *(_DWORD *)(HIDWORD(result) + 3712);
  *(_BYTE *)(result + 2) = a3;
  v3 = (_DWORD *)(result + 8);
  *(_DWORD *)(result + 36) = a2 + HIDWORD(result);
  *(_DWORD *)(result + 52) = 0;
  HIDWORD(result) = 0;
  do
    *v3++ = 0;
  while ( v3 != (_DWORD *)(result + 36) );
  return result;
}
