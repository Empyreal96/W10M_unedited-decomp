// RtlInitAnsiStringEx 
 
int __fastcall RtlInitAnsiStringEx(int a1, unsigned int a2)
{
  char *v3; // r0

  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 2) = 0;
  *(_DWORD *)(a1 + 4) = a2;
  if ( !a2 )
    return 0;
  v3 = strlen(a2);
  if ( (unsigned int)v3 <= 0xFFFE )
  {
    *(_WORD *)(a1 + 2) = (_WORD)v3 + 1;
    *(_WORD *)a1 = (_WORD)v3;
    return 0;
  }
  return -1073741562;
}
