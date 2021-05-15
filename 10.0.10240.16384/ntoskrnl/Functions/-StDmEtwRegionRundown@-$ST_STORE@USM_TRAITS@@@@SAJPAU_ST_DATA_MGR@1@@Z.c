// -StDmEtwRegionRundown@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmEtwRegionRundown(int a1)
{
  int v3; // r4
  __int64 v4; // kr00_8
  unsigned int v5; // r0
  unsigned int v6; // r1
  unsigned int v7; // r3
  _DWORD *v8; // r7
  int i; // r3
  int v10; // r1
  int v11; // r3
  int v12; // r3

  if ( (dword_636E9C & 0x80) == 0 )
    return -1073741637;
  v3 = -1;
  while ( 1 )
  {
    if ( *(_BYTE *)(a1 + 72) )
    {
      v4 = *(_QWORD *)(a1 + 120);
      v5 = v3 + 1 < (unsigned int)v4 ? v3 + 1 : 0;
      v6 = v4 - 1;
      while ( 1 )
      {
        if ( v6 - v5 == -1 )
          goto LABEL_11;
        v8 = (_DWORD *)(HIDWORD(v4) + 4 * (v5 >> 5));
        for ( i = ~*v8 | ((1 << (v5 & 0x1F)) - 1); i == -1; i = ~*v8 )
        {
          if ( (unsigned int)++v8 > HIDWORD(v4) + 4 * (v6 >> 5) )
            goto LABEL_11;
        }
        v7 = __clz(__rbit(~i)) + 32 * (((int)v8 - HIDWORD(v4)) >> 2);
        if ( v7 > v6 )
        {
LABEL_11:
          v7 = -1;
        }
        else if ( v7 != -1 )
        {
          break;
        }
        if ( !v5 )
          break;
        v10 = v3 + 2;
        if ( v3 + 2 > (unsigned int)v4 )
          v10 = *(_DWORD *)(a1 + 120);
        v6 = v10 - 1;
        v5 = 0;
      }
      if ( (int)v7 <= v3 )
        v7 = *(_DWORD *)(a1 + 84);
      v3 = v7;
    }
    else
    {
      ++v3;
    }
    if ( v3 == *(_DWORD *)(a1 + 84) )
      return 0;
    if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v3) & 0x1FFF) != 0 )
    {
      v11 = *(_DWORD *)(a1 + 312);
      if ( v11 )
        v12 = *(unsigned __int8 *)(v11 + v3);
      else
        v12 = 0;
      SmEtwLogRegionOp(&unk_636E90, 10, a1, v3, 0, *(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v3) & 0x1FFF, v12);
    }
  }
}
