// IoCheckEaBufferValidity 
 
int __fastcall IoCheckEaBufferValidity(int a1, unsigned int a2)
{
  unsigned int v2; // r5
  int v5; // r1
  unsigned int v6; // r6
  int v7; // r1

  v2 = a2;
  if ( a2 > 0x7FFFFFFF )
    return sub_806CC0();
  while ( 1 )
  {
    if ( v2 < 8
      || (v5 = *(unsigned __int8 *)(a1 + 5), v6 = *(unsigned __int16 *)(a1 + 6) + v5 + 9, v2 < v6)
      || *(_BYTE *)(v5 + a1 + 8) )
    {
LABEL_12:
      JUMPOUT(0x806CC2);
    }
    v7 = *(_DWORD *)a1;
    if ( !*(_DWORD *)a1 )
      return 0;
    if ( ((v6 + 3) & 0xFFFFFFFC) != v7 || v7 < 0 || v2 < v7 )
      goto LABEL_12;
    v2 -= v7;
    a1 += v7;
  }
}
