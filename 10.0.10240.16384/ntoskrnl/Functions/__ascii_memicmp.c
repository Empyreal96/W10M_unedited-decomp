// __ascii_memicmp 
 
int __fastcall _ascii_memicmp(int a1, unsigned __int8 *a2, int a3)
{
  int v3; // r5
  int v4; // r4
  int v5; // r6
  unsigned int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // t1

  v3 = 0;
  v4 = 0;
  if ( a3 )
  {
    v5 = a1 - (_DWORD)a2;
    do
    {
      v6 = a2[v5];
      v8 = *a2++;
      v7 = v8;
      --a3;
      if ( v6 != v8 )
      {
        v3 = v6 < 0x41 || v6 > 0x5A ? v6 : v6 + 32;
        v4 = v7 < 0x41 || v7 > 0x5A ? v7 : v7 + 32;
        if ( v3 != v4 )
          break;
      }
    }
    while ( a3 );
  }
  return v3 - v4;
}
