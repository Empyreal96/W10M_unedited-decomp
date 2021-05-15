// PipSmBiosGetString 
 
int __fastcall PipSmBiosGetString(int a1, unsigned int a2, int a3, int a4, unsigned __int16 *a5)
{
  int v7; // r1
  char *v8; // r2
  unsigned int v9; // r0
  unsigned int v11; // r4
  char *v12; // r5
  unsigned int v13; // [sp+0h] [bp-18h] BYREF
  char *v14; // [sp+4h] [bp-14h]
  int v15; // [sp+8h] [bp-10h]

  v13 = a2;
  v14 = (char *)a3;
  v15 = a4;
  if ( !a2 )
    return -1073741275;
  v7 = 1;
  v8 = (char *)(*(unsigned __int8 *)(a1 + 1) + a1);
  v9 = a3 + a4 - 1;
  if ( a2 > 1 )
  {
    do
    {
      while ( *v8 )
      {
        if ( (unsigned int)++v8 >= v9 )
          return -1073741275;
      }
      if ( !++v8 )
        return -1073741275;
      if ( !*v8 )
      {
        v8 = 0;
        break;
      }
    }
    while ( ++v7 < a2 );
  }
  if ( !v8 )
    return -1073741275;
  v11 = 0;
  LOWORD(v13) = 0;
  v12 = v8;
  v14 = v8;
  while ( *v8 )
  {
    v11 = (unsigned __int16)(v11 + 1);
    ++v8;
    LOWORD(v13) = v11;
    if ( (unsigned int)v8 >= v9 || v11 > 0x40 )
      return -1073741275;
  }
  if ( v8 == (char *)-1 )
    return -1073741275;
  if ( *v12 )
  {
    if ( strchr(&dword_405800, *v12) )
      return sub_9688D0();
    v14 = v12;
  }
  while ( v11 && strchr(&dword_405800, v12[v11 - 1]) )
  {
    v11 = (unsigned __int16)(v11 - 1);
    LOWORD(v13) = v11;
  }
  HIWORD(v13) = v11 + 1;
  return RtlAnsiStringToUnicodeString(a5, (unsigned __int16 *)&v13, 1, v11 + 1);
}
