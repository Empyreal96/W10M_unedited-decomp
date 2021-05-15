// RtlpUpcaseUnicodeStringPrivate 
 
int __fastcall RtlpUpcaseUnicodeStringPrivate(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned __int16 *v4; // r4
  unsigned __int16 *v5; // r5
  int v6; // r1
  int v7; // r0
  unsigned int v9; // r6
  unsigned int v10; // r1
  int v11; // lr
  unsigned int v12; // r0

  v4 = a2;
  v5 = a1;
  v6 = *a2;
  a1[1] = v6;
  v7 = ExAllocatePoolWithTag(512, v6, 1735554131);
  *((_DWORD *)v5 + 1) = v7;
  if ( !v7 )
    return -1073741801;
  v9 = *v4;
  v10 = 0;
  v11 = Nls844UnicodeUpcaseTable;
  while ( v10 < v9 >> 1 )
  {
    v12 = *(unsigned __int16 *)(*((_DWORD *)v4 + 1) + 2 * v10);
    if ( v12 >= 0x61 )
    {
      if ( v12 > 0x7A )
        LOWORD(v12) = *(_WORD *)(v11
                               + 2
                               * ((v12 & 0xF)
                                + *(unsigned __int16 *)(v11
                                                      + 2
                                                      * (((unsigned __int8)v12 >> 4)
                                                       + *(unsigned __int16 *)(v11 + 2 * (v12 >> 8))))))
                    + v12;
      else
        LOWORD(v12) = v12 - 32;
    }
    *(_WORD *)(*((_DWORD *)v5 + 1) + 2 * v10++) = v12;
  }
  *a1 = *a2;
  return 0;
}
