// EtwpQueryRegistryCallback 
 
int __fastcall EtwpQueryRegistryCallback(int a1, int a2, int a3, unsigned int a4, int a5, unsigned int *a6)
{
  int v6; // r7
  unsigned int v8; // r3
  unsigned int v10; // r3

  v6 = 0;
  if ( !a6 )
    return v6;
  if ( !a3 || !a4 )
  {
    if ( a2 != 3 )
      return v6;
    goto LABEL_23;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 11 )
    {
      *a6 = *(_DWORD *)a3;
      v10 = *(_DWORD *)(a3 + 4);
      goto LABEL_12;
    }
    if ( a2 == 1 )
    {
      if ( a4 > 2 )
      {
        if ( !RtlCreateUnicodeString((int)a6, (unsigned __int16 *)a3) )
          v6 = -1073741801;
        return v6;
      }
      v10 = 0;
      *a6 = 0;
LABEL_12:
      a6[1] = v10;
      return v6;
    }
    if ( a2 != 3 || a4 < 4 )
      return v6;
    if ( a4 <= *a6 )
    {
      memmove(a6[1], a3, a4);
      *a6 = a4;
      return v6;
    }
    v6 = -1073741306;
LABEL_23:
    v8 = 0;
    goto LABEL_7;
  }
  if ( a4 >= 4 )
  {
    v8 = *(_DWORD *)a3;
LABEL_7:
    *a6 = v8;
  }
  return v6;
}
