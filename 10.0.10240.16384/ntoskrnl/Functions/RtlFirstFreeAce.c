// RtlFirstFreeAce 
 
int __fastcall RtlFirstFreeAce(int a1, _DWORD *a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r2
  int result; // r0

  *a2 = 0;
  v2 = 0;
  v3 = a1 + 8;
  if ( *(_WORD *)(a1 + 4) )
  {
    while ( v3 < (unsigned int)*(unsigned __int16 *)(a1 + 2) + a1 )
    {
      ++v2;
      v3 += *(unsigned __int16 *)(v3 + 2);
      if ( v2 >= *(unsigned __int16 *)(a1 + 4) )
        goto LABEL_2;
    }
    result = 0;
  }
  else
  {
LABEL_2:
    if ( v3 <= (unsigned int)*(unsigned __int16 *)(a1 + 2) + a1 )
      *a2 = v3;
    result = 1;
  }
  return result;
}
