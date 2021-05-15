// __GSHandlerCheckCommon 
 
int __fastcall _GSHandlerCheckCommon(int a1, int a2, int *a3)
{
  int v3; // r3
  unsigned int v5; // r2
  int result; // r0

  v3 = *a3;
  v5 = *a3 & 0xFFFFFFFC;
  result = *(_DWORD *)(v5 + a1);
  if ( (v3 & 1) != 0 )
    result = v5 - result + a1;
  return result;
}
