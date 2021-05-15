// _wcsicmp 
 
int __fastcall wcsicmp(int a1, unsigned __int16 *a2)
{
  int v2; // r0
  unsigned int v3; // r3
  int v4; // r2
  unsigned int v5; // r3
  unsigned int v6; // t1

  v2 = a1 - (_DWORD)a2;
  do
  {
    v3 = *(unsigned __int16 *)((char *)a2 + v2);
    if ( v3 >= 0x41 && v3 <= 0x5A )
      LOWORD(v3) = v3 + 32;
    v4 = (unsigned __int16)v3;
    v6 = *a2++;
    v5 = v6;
    if ( v6 >= 0x41 && v5 <= 0x5A )
      LOWORD(v5) = v5 + 32;
  }
  while ( v4 && v4 == (unsigned __int16)v5 );
  return v4 - (unsigned __int16)v5;
}
