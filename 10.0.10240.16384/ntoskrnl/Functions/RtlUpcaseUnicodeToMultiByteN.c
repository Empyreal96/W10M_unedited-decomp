// RtlUpcaseUnicodeToMultiByteN 
 
int __fastcall RtlUpcaseUnicodeToMultiByteN(_BYTE *a1, unsigned int a2, unsigned int *a3, unsigned __int16 *a4, unsigned int a5)
{
  unsigned int *v5; // r6
  unsigned __int16 *v6; // lr
  unsigned int v7; // r5
  int v8; // r4
  unsigned __int16 *v9; // r8
  __int64 v10; // kr00_8
  int v11; // r10
  _BYTE *v12; // lr
  int result; // r0
  unsigned int v14; // r6
  _BYTE *v15; // r7
  __int64 v16; // kr08_8
  int v17; // r10
  int v18; // r6
  int v19; // t1
  unsigned int v20; // r2
  unsigned int v21; // r4
  unsigned int v22; // r2
  _BYTE *v25; // [sp+8h] [bp-20h]

  v5 = a3;
  v6 = a4;
  v7 = a5 >> 1;
  if ( NlsMbCodePageTag )
  {
    v15 = a1;
    v25 = a1;
    if ( v7 )
    {
      v16 = *(_QWORD *)&NlsAnsiToUnicodeData;
      v17 = NlsMbAnsiCodePageTables;
      v18 = Nls844UnicodeUpcaseTable;
      do
      {
        if ( !a2 )
          break;
        v19 = *v6++;
        v20 = *(unsigned __int16 *)(HIDWORD(v16) + 2 * v19);
        if ( NlsLeadByteInfoTable[v20 >> 8] )
          v21 = *(unsigned __int16 *)(v17 + 2
                                          * ((unsigned __int16)NlsLeadByteInfoTable[v20 >> 8] + (unsigned __int8)v20));
        else
          v21 = *(unsigned __int16 *)(v16 + 2 * (unsigned __int8)v20);
        if ( v21 >= 0x61 )
        {
          if ( v21 > 0x7A )
            LOWORD(v21) = *(_WORD *)(v18
                                   + 2
                                   * ((v21 & 0xF)
                                    + *(unsigned __int16 *)(v18
                                                          + 2
                                                          * (((unsigned __int8)v21 >> 4)
                                                           + *(unsigned __int16 *)(v18 + 2 * (v21 >> 8))))))
                        + v21;
          else
            LOWORD(v21) = v21 - 32;
        }
        v22 = *(unsigned __int16 *)(HIDWORD(v16) + 2 * (unsigned __int16)v21);
        if ( v22 >> 8 )
        {
          if ( a2-- < 2 )
            break;
          *a1++ = BYTE1(v22);
        }
        --a2;
        --v7;
        *a1++ = v22;
      }
      while ( v7 );
      v5 = a3;
      v15 = v25;
    }
    if ( v5 )
      *v5 = a1 - v15;
    result = 0;
  }
  else
  {
    if ( v7 >= a2 )
      v7 = a2;
    if ( a3 )
      *a3 = v7;
    v8 = v7 & 0xF;
    v9 = &a4[v8];
    v10 = *(_QWORD *)&NlsUnicodeToAnsiData;
    v11 = Nls844UnicodeUpcaseTable;
    v12 = &a1[v8];
    do
    {
      if ( v8 != 1 )
        return sub_7DE06C();
      v14 = *(unsigned __int16 *)(HIDWORD(v10) + 2 * *(unsigned __int8 *)(*(v9 - 1) + (_DWORD)v10));
      if ( v14 >= 0x61 )
      {
        if ( v14 > 0x7A )
          LOWORD(v14) = *(_WORD *)(v11
                                 + 2
                                 * (*(unsigned __int16 *)(v11
                                                        + 2
                                                        * (*(unsigned __int16 *)(v11 + 2 * (v14 >> 8))
                                                         + ((unsigned __int8)v14 >> 4)))
                                  + (v14 & 0xF)))
                      + v14;
        else
          LOWORD(v14) = v14 - 32;
      }
      *(v12 - 1) = *(_BYTE *)((unsigned __int16)v14 + (_DWORD)v10);
      --v7;
      v8 = 16;
    }
    while ( v7 );
    result = 0;
  }
  return result;
}
