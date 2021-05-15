// EtwpQueryPsmKey 
 
int __fastcall EtwpQueryPsmKey(int a1, _WORD *a2, unsigned int *a3)
{
  int result; // r0
  unsigned int v6; // r1
  __int64 v7; // kr00_8
  int v8; // [sp+8h] [bp-290h]
  int v9[2]; // [sp+20h] [bp-278h] BYREF
  char v10[8]; // [sp+28h] [bp-270h] BYREF
  int v11; // [sp+30h] [bp-268h]

  result = RtlpQueryPackageIdentityAttributes(a1, (int)a2, (int)v10, 0);
  if ( result >= 0 )
  {
    v6 = *a3;
    v7 = *(_QWORD *)(v11 + 16);
    v8 = *(_DWORD *)(v11 + 20);
    if ( (unsigned int)v7 <= 2 )
      result = RtlStringCbPrintfExW(a2, v6, v9, 0, 2048, L"%wZ%wc%wZ", v8, 43, HIDWORD(v7) + 8);
    else
      result = RtlStringCbPrintfExW(
                 a2,
                 v6,
                 v9,
                 0,
                 2048,
                 L"%wZ%wc%wZ%wc%wZ",
                 v8,
                 43,
                 HIDWORD(v7) + 8,
                 35,
                 HIDWORD(v7) + 16);
    if ( result >= 0 )
      *a3 = v9[0] - (_DWORD)a2 + 2;
  }
  return result;
}
