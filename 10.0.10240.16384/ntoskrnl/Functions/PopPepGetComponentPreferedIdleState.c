// PopPepGetComponentPreferedIdleState 
 
unsigned int __fastcall PopPepGetComponentPreferedIdleState(_DWORD *a1)
{
  int v2; // r5
  unsigned int result; // r0
  unsigned int v4; // r4
  _DWORD *v5; // r3
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r1

  v2 = 0;
  result = a1[39] - 1;
  if ( result >= a1[33] )
    result = a1[33];
  v4 = result;
  if ( result )
  {
    v5 = a1;
    v6 = 6;
    do
    {
      v7 = v5[30];
      if ( v7 < v4 )
        v4 = v5[30];
      if ( v7 == result )
        ++v2;
      ++v5;
      --v6;
    }
    while ( v6 );
    v8 = 0;
    if ( v2 == 5 && a1[32] < result )
      v8 = 1;
    PopPepUpdateComponentResidentStatus(a1, v8);
    result = v4;
  }
  return result;
}
