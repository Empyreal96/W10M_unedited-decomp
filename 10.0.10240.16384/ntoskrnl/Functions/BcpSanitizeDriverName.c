// BcpSanitizeDriverName 
 
unsigned int __fastcall BcpSanitizeDriverName(unsigned __int16 *a1, int a2)
{
  unsigned int v3; // r2
  int v4; // r4
  unsigned int v5; // r3
  unsigned int v6; // r2
  int v7; // r5
  unsigned int result; // r0
  _WORD *v9; // r1
  int v10; // r4
  unsigned int v11; // r3

  v3 = *a1;
  v4 = *((_DWORD *)a1 + 1);
  v5 = *(unsigned __int16 *)(a2 + 2) - 2;
  if ( v3 >= v5 )
    v6 = v5 >> 1;
  else
    v6 = v3 >> 1;
  v7 = *(_DWORD *)(a2 + 4);
  result = 0;
  if ( v6 )
  {
    v9 = *(_WORD **)(a2 + 4);
    v10 = v4 - v7;
    result = v6;
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + v10);
      if ( v11 != 46
        && v11 != 95
        && v11 != 32
        && (v11 < 0x61 || v11 > 0x7A)
        && (v11 < 0x41 || v11 > 0x5A)
        && (v11 < 0x30 || v11 > 0x39) )
      {
        LOWORD(v11) = 32;
      }
      *v9++ = v11;
      --v6;
    }
    while ( v6 );
  }
  *(_WORD *)(2 * result + v7) = 0;
  *(_WORD *)a2 = 2 * result;
  return result;
}
