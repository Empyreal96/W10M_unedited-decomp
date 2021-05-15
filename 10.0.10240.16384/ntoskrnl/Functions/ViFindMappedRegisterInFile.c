// ViFindMappedRegisterInFile 
 
int *__fastcall ViFindMappedRegisterInFile(int a1, int a2, _DWORD *a3)
{
  int *v3; // r5
  unsigned int v4; // r0
  int v5; // r4
  int v6; // t1

  v3 = (int *)(a1 + 48);
  v4 = *(_DWORD *)(a1 + 16);
  v5 = 0;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v6 = *v3;
    v3 += 5;
    if ( a2 == v6 )
      break;
    if ( ++v5 >= v4 )
      return 0;
  }
  if ( a3 )
    *a3 = v5;
  return v3 - 5;
}
