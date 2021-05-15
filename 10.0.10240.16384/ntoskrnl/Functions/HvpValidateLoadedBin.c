// HvpValidateLoadedBin 
 
BOOL __fastcall HvpValidateLoadedBin(int a1, int a2, unsigned int a3)
{
  __int64 v3; // kr00_8

  v3 = *(_QWORD *)(a1 + 4);
  return (int)v3 + HIDWORD(v3) <= a3
      && (unsigned int)(v3 + HIDWORD(v3)) >= HIDWORD(v3)
      && HIDWORD(v3) >= 0x1000
      && (v3 & 0xFFF00000000i64) == 0
      && *(_DWORD *)a1 == 1852400232
      && (_DWORD)v3 == a2;
}
