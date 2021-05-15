// KiAdjustProcessorAffinity 
 
void KiAdjustProcessorAffinity()
{
  _DWORD *v0; // r2
  unsigned int i; // r7
  unsigned int v2; // r2
  unsigned int v3; // lr
  void **v4; // r3
  _DWORD *v5; // r6
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r0
  void **v9; // r4
  _DWORD *v10; // r1
  int v11; // lr
  char *v12; // r4
  unsigned int v13; // r5
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // [sp+0h] [bp-48h]
  int v17; // [sp+4h] [bp-44h]
  void **v18; // [sp+10h] [bp-38h]
  int v19; // [sp+14h] [bp-34h]
  int v20; // [sp+18h] [bp-30h]
  int v21; // [sp+1Ch] [bp-2Ch]
  int v22; // [sp+24h] [bp-24h]
  void **v23; // [sp+28h] [bp-20h]

  v0 = KiProcessorBlock;
  if ( (*((_DWORD *)KiProcessorBlock + 452) & 0x1000000) != 0 )
  {
    sub_554590();
  }
  else
  {
    for ( i = 0; i < *((unsigned __int8 *)KiProcessorBlock + 3576); v0 += 3 )
    {
      if ( !v0[878] )
        break;
      ++i;
    }
    v2 = KeNumberProcessors_0;
    v3 = 0;
    v16 = 0;
    if ( KeNumberProcessors_0 )
    {
      v4 = &KiProcessorBlock;
      do
      {
        v5 = *v4;
        v23 = v4 + 1;
        v6 = *((_DWORD *)*v4 + 452);
        v7 = 1 << *((_DWORD *)*v4 + 5);
        v8 = 0;
        v17 = v7;
        if ( v2 )
        {
          v19 = v6 & 0xFFFFFF;
          v20 = v6 & 0xFFFF00;
          v9 = &KiProcessorBlock;
          v22 = v6 & 0xFF0000;
          v18 = &KiProcessorBlock;
          do
          {
            if ( v8 != v3 )
            {
              v10 = *v9;
              v11 = *((_DWORD *)*v9 + 452);
              if ( v19 == (v11 & 0xFFFFFF) )
                v17 |= 1 << v10[5];
              if ( v20 == (v11 & 0xFFFF00) )
              {
                v21 = v10[5];
                if ( i < *((unsigned __int8 *)v5 + 3576) )
                {
                  v12 = (char *)&v5[i];
                  v13 = i;
                  do
                  {
                    ++v13;
                    *((_DWORD *)v12 + 870) |= (1 << v5[5]) | (1 << v21);
                    v12 += 4;
                  }
                  while ( v13 < *((unsigned __int8 *)v5 + 3576) );
                  v9 = v18;
                  v2 = KeNumberProcessors_0;
                }
              }
              v14 = v11 & 0xFF0000;
              v3 = v16;
              if ( v22 == v14 )
              {
                v5[846] |= 1 << v10[5];
                v2 = KeNumberProcessors_0;
              }
            }
            ++v8;
            v18 = ++v9;
          }
          while ( v8 < v2 );
          v7 = v17;
        }
        v5[867] = v7;
        v15 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v7 >> 16))
                              + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v7 >> 24))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v7 >> 8))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v7));
        *((_BYTE *)v5 + 1043) = v15;
        if ( !v15 )
          __brkdiv0();
        *((_BYTE *)v5 + 1042) = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal
                                                  + (unsigned __int8)((unsigned int)~v5[846] >> 16))
                                                + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v5[846] >> 24))
                                                + *((_BYTE *)RtlpBitsClearTotal
                                                  + (unsigned __int8)((unsigned __int16)~*((_WORD *)v5 + 1692) >> 8))
                                                + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*((_BYTE *)v5 + 3384)))
                              / v15;
        v2 = KeNumberProcessors_0;
        v3 = v16 + 1;
        v4 = v23;
        v16 = v3;
      }
      while ( v3 < KeNumberProcessors_0 );
    }
  }
}
