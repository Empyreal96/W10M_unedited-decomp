// _wcsnicmp 
 
int __fastcall wcsnicmp(int a1, unsigned __int16 *a2, int a3)
{
  int v3; // r4
  int result; // r0
  int v6; // r0
  unsigned int v7; // r3
  int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // t1

  v3 = a3;
  result = 0;
  if ( a3 )
  {
    v6 = a1 - (_DWORD)a2;
    do
    {
      v7 = *(unsigned __int16 *)((char *)a2 + v6);
      if ( v7 >= 0x41 && v7 <= 0x5A )
        LOWORD(v7) = v7 + 32;
      v8 = (unsigned __int16)v7;
      v10 = *a2++;
      v9 = v10;
      if ( v10 >= 0x41 && v9 <= 0x5A )
        LOWORD(v9) = v9 + 32;
      --v3;
    }
    while ( v3 && v8 && v8 == (unsigned __int16)v9 );
    result = v8 - (unsigned __int16)v9;
  }
  return result;
}
