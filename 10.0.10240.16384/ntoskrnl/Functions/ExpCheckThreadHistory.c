// ExpCheckThreadHistory 
 
int __fastcall ExpCheckThreadHistory(int a1)
{
  int v2; // r4
  int v3; // r1
  unsigned int v4; // r7
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r6
  int v10; // r2
  int v11; // r0
  int v12; // r5
  int v13; // r6
  _DWORD v14[12]; // [sp-4h] [bp-30h]

  if ( (*(_DWORD *)(a1 + 88) & 7) == 4 )
    return 0;
  v2 = 0;
  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  do
  {
    v5 = *(_DWORD *)(a1 + 4 * v3 + 32);
    if ( v5 )
    {
      if ( v5 != v4 )
      {
        v6 = *(unsigned __int8 *)(v5 + 132);
        __dmb(0xBu);
        if ( v6 == 5 )
        {
          v7 = *(_BYTE *)(v5 + 72) & 7;
          if ( (v7 == 1 || v7 == 4) && *(_BYTE *)(v5 + 363) == 1 )
          {
            v8 = *(_DWORD *)(v5 + 232);
            if ( v8 != *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) )
            {
              if ( v7 == 4 || v8 == v5 + 452 )
                return 1;
              v14[v2] = v8;
              v2 = (char)(v2 + 1);
            }
          }
        }
      }
    }
    v3 = (char)(v3 + 1);
  }
  while ( v3 < 4 );
  if ( v2 - 3 < 0 )
    return 0;
  v10 = 0;
  while ( 1 )
  {
    v11 = (char)(v10 + 1);
    v12 = 1;
    v13 = v11;
    if ( v2 - v11 >= 2 )
      break;
LABEL_20:
    v10 = (char)(v10 + 1);
    if ( v11 > v2 - 3 )
      return 0;
  }
  while ( 1 )
  {
    if ( v14[v10] == v14[v13] )
    {
      v12 = (char)(v12 + 1);
      if ( v12 >= 3 )
        return 1;
    }
    v13 = (char)(v13 + 1);
    if ( 3 - v12 > v2 - v13 )
      goto LABEL_20;
  }
}
