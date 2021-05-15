// sub_7CDCF0 
 
void __fastcall sub_7CDCF0(int a1, int a2, int a3)
{
  int v3; // r5
  unsigned int *v4; // r6
  int v5; // r7
  int v6; // r4
  __int64 v7; // kr00_8
  _DWORD *v8; // r0
  unsigned int v9; // r2

  v6 = v5 + 40 * a2;
  v7 = *(_QWORD *)(v6 + 8);
  v8 = (_DWORD *)(v3 + HIDWORD(v7));
  if ( (int)v7 + v3 + HIDWORD(v7) <= (unsigned int)(*(_DWORD *)(a3 + 80) + v3) )
  {
    if ( *(_DWORD *)(v6 + 16) )
    {
      if ( (unsigned int)v7 >= 0x28 && *v8 == -557841984 )
      {
        v9 = v8[6];
        if ( v9 == (_DWORD)v7 && v9 > v8[7] + 40 && (v8[8] & 7) == 0 )
        {
          *v4 = v9;
          JUMPOUT(0x772BDA);
        }
      }
    }
  }
  DbgPrintEx(126, 0, (int)"COV: Malformed coverage section at ImageBase 0x%p\n", v3);
  JUMPOUT(0x772BD8);
}
