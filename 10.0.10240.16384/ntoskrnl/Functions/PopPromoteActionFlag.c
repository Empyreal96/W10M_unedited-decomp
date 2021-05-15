// PopPromoteActionFlag 
 
_BYTE *__fastcall PopPromoteActionFlag(_BYTE *result, char a2, int a3, int a4, int a5)
{
  int v5; // r3

  if ( a4 )
  {
    if ( (a3 & a5) != 0 && (dword_61EC6C & a5) == 0 )
    {
      v5 = a5 | dword_61EC6C;
LABEL_8:
      dword_61EC6C = v5;
      *result |= a2;
      return result;
    }
  }
  else if ( (a3 & a5) == 0 && (dword_61EC6C & a5) != 0 )
  {
    v5 = dword_61EC6C & ~a5;
    goto LABEL_8;
  }
  return result;
}
