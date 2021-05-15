// -StRegionLATRebase@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StRegionLATRebase(int result, unsigned int a2)
{
  int v3; // r4
  __int64 v4; // kr00_8
  unsigned int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r3
  _DWORD *v8; // r7
  int i; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = -1;
  *(_DWORD *)(result + 316) -= a2;
  while ( 1 )
  {
    if ( *(_BYTE *)(result + 72) )
    {
      v4 = *(_QWORD *)(result + 120);
      v5 = v3 + 1 < (unsigned int)v4 ? v3 + 1 : 0;
      v6 = v4 - 1;
      while ( 1 )
      {
        if ( v6 - v5 == -1 )
          goto LABEL_9;
        v8 = (_DWORD *)(HIDWORD(v4) + 4 * (v5 >> 5));
        for ( i = ~*v8 | ((1 << (v5 & 0x1F)) - 1); i == -1; i = ~*v8 )
        {
          if ( (unsigned int)++v8 > HIDWORD(v4) + 4 * (v6 >> 5) )
            goto LABEL_9;
        }
        v7 = __clz(__rbit(~i)) + 32 * (((int)v8 - HIDWORD(v4)) >> 2);
        if ( v7 > v6 )
        {
LABEL_9:
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
          v10 = *(_DWORD *)(result + 120);
        v6 = v10 - 1;
        v5 = 0;
      }
      if ( (int)v7 <= v3 )
        v7 = *(_DWORD *)(result + 84);
      v3 = v7;
    }
    else
    {
      ++v3;
    }
    if ( v3 == *(_DWORD *)(result + 84) )
      return result;
    v11 = *(_DWORD *)(result + 312);
    if ( *(unsigned __int8 *)(v11 + v3) > HIWORD(a2) )
      v12 = *(unsigned __int8 *)(v11 + v3) - HIWORD(a2);
    else
      LOBYTE(v12) = 0;
    *(_BYTE *)(v11 + v3) = v12;
  }
}
