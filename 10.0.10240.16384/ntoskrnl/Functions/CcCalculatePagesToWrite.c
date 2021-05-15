// CcCalculatePagesToWrite 
 
unsigned int __fastcall CcCalculatePagesToWrite(int a1, _DWORD *a2, int a3, char a4)
{
  unsigned int v4; // r6
  __int64 v5; // r4
  int v6; // r1
  unsigned int result; // r0
  int v8; // r2

  if ( a1 == 1 || a1 == 2 || a1 == 16 )
    return *a2;
  v4 = *(_DWORD *)(a3 + 12);
  v5 = *(_QWORD *)a2;
  v6 = a2[2];
  result = v5;
  if ( (unsigned int)v5 > CcMaxLazyWritePages || (a4 & 1) != 0 )
    result = (unsigned int)v5 >> 3;
  v8 = 0;
  if ( (unsigned int)(v6 + v5) > HIDWORD(v5) )
    v8 = v6 - HIDWORD(v5) + v5;
  if ( v8 - result + (unsigned int)v5 > v4 )
    return sub_54ABC4();
  if ( result > (unsigned int)v5 )
    result = v5;
  return result;
}
