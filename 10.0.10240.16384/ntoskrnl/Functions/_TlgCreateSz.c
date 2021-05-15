// _TlgCreateSz 
 
char *__fastcall TlgCreateSz(int a1, unsigned int a2)
{
  char *v3; // r5
  char *result; // r0
  __int64 v5; // r2

  v3 = &byte_5CB13F;
  result = 0;
  if ( a2 )
  {
    v3 = (char *)a2;
    result = strlen(a2);
  }
  LODWORD(v5) = 0;
  HIDWORD(v5) = result + 1;
  *(_QWORD *)(a1 + 4) = v5;
  *(_DWORD *)a1 = v3;
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
