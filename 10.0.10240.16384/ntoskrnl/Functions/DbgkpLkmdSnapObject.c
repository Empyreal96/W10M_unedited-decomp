// DbgkpLkmdSnapObject 
 
int __fastcall DbgkpLkmdSnapObject(int a1, _WORD *a2, int a3)
{
  _WORD *v4; // r7
  _WORD *v6; // r8
  int v7; // r2
  int result; // r0
  int v9; // r2
  int v10; // r1

  v4 = 0;
  v6 = 0;
  if ( a3 == 3 )
  {
    if ( *a2 != 3 )
      return -1073741819;
    v7 = (unsigned __int16)a2[1];
  }
  else
  {
    if ( a3 != 4 )
    {
      if ( a3 == 5 )
      {
        v6 = a2;
        if ( *a2 == 5 )
        {
          v7 = 128;
          goto LABEL_11;
        }
      }
      return -1073741819;
    }
    v4 = a2;
    if ( *a2 != 4 )
      return -1073741819;
    v7 = 168;
  }
LABEL_11:
  result = (*(int (__fastcall **)(int, _WORD *, int, _DWORD))(a1 + 168))(a1 + 128, a2, v7, 0);
  if ( result < 0 )
    return result;
  if ( a3 == 4 )
  {
    v9 = (unsigned __int16)v4[15];
    v10 = *((_DWORD *)v4 + 8);
  }
  else
  {
    if ( a3 != 5 )
      return result;
    v9 = (unsigned __int16)v6[25];
    v10 = *((_DWORD *)v6 + 13);
  }
  return (*(int (__fastcall **)(int, int, int, _DWORD))(a1 + 168))(a1 + 128, v10, v9, 0);
}
