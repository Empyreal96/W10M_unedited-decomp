// RunLengthEncode 
 
int __fastcall RunLengthEncode(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // r4
  int v3; // r2
  int *v4; // r1
  int v5; // t1

  if ( a2 && (a2 & 3) == 0 && ((unsigned __int8)a1 & 3) == 0 )
  {
    v2 = a2 >> 2;
    v3 = 1;
    if ( a2 >> 2 <= 1 )
      return 1;
    v4 = a1 + 1;
    while ( 1 )
    {
      v5 = *v4++;
      if ( v5 != *a1 )
        break;
      if ( ++v3 >= v2 )
        return 1;
    }
  }
  return 0;
}
