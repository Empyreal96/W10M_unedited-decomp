// SepConcatenatePrivileges 
 
int __fastcall SepConcatenatePrivileges(_DWORD *a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int result; // r0

  if ( a1 )
  {
    if ( *a1 )
      v5 = 12 * (*a1 - 1) + 20;
    else
      v5 = 8;
  }
  else
  {
    v5 = 0;
  }
  result = memmove((int)a1 + v5, (int)(a3 + 2), 12 * *a3);
  *a1 += *a3;
  return result;
}
