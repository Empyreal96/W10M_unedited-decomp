// MiValidateUserCallTarget 
 
int __fastcall MiValidateUserCallTarget(unsigned int a1, _DWORD *a2)
{
  char v2; // r4
  unsigned int v3; // r5
  int result; // r0

  v2 = a1;
  v3 = 2 * (a1 >> 4);
  result = (*(char *)((v3 >> 3) + *a2) >> (v3 & 7)) & 1;
  if ( result )
  {
    if ( (v2 & 0xFu) > 1 )
      result = (*(char *)(((v3 + 1) >> 3) + *a2) >> ((v3 + 1) & 7)) & 1;
  }
  return result;
}
