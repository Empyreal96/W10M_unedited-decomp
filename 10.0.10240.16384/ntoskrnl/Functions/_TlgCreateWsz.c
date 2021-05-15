// _TlgCreateWsz 
 
unsigned int __fastcall TlgCreateWsz(int a1, unsigned __int16 *a2)
{
  __int16 *v3; // r5
  unsigned int result; // r0
  __int64 v5; // r2

  v3 = &word_5CB8A8;
  result = 0;
  if ( a2 )
  {
    v3 = (__int16 *)a2;
    result = wcslen(a2);
  }
  LODWORD(v5) = 0;
  HIDWORD(v5) = 2 * (result + 1);
  *(_QWORD *)(a1 + 4) = v5;
  *(_DWORD *)a1 = v3;
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
