// RtlpExceptionHandler 
 
int __fastcall RtlpExceptionHandler(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int result; // r0

  v4 = *(_DWORD *)(a1 + 4);
  result = 1;
  if ( (v4 & 0x66) == 0 )
  {
    *(_DWORD *)(a4 + 12) = *(_DWORD *)(*(_DWORD *)(a2 - 8) + 12);
    result = 2;
  }
  return result;
}
