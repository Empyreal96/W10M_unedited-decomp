// CmpIsHiveAlreadyLoaded 
 
int __fastcall CmpIsHiveAlreadyLoaded(int a1, int a2, char a3, int a4, int *a5)
{
  int v5; // r6
  int v9; // r4
  int v10; // r0
  int v11; // r2
  int v12; // r0
  int v13; // r2
  int *v14; // r4
  int v15; // r3
  int v16; // r0
  int v17; // r0
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1

  v5 = 0;
  if ( (a3 & 0x20) == 0 )
  {
    if ( a1 )
    {
      v9 = *(_DWORD *)(a1 + 4);
      if ( (*(_DWORD *)(v9 + 4) & 0x20000) == 0 )
      {
        v10 = *(_DWORD *)(v9 + 20);
        v11 = *(unsigned __int16 *)(v9 + 106);
        *(_DWORD *)a4 = v10;
        if ( (v11 & 4) != 0 )
        {
          if ( CmpIsThisSameFile(a2, *(_DWORD *)(v10 + 1776), v11, a4) )
          {
            v12 = *(_DWORD *)a4;
            if ( (*(_DWORD *)(*(_DWORD *)a4 + 3228) & 0x40) == 0
              && (*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) & 0x40000) == 0 )
            {
              v5 = 1;
              if ( *(_BYTE *)(v12 + 2532) == 1 )
              {
                CmpUnfreezeHive(v12);
                *(_BYTE *)(*(_DWORD *)a4 + 2532) = 0;
              }
            }
          }
        }
      }
    }
    else if ( (a3 & 0x10) != 0 )
    {
      v14 = (int *)CmpGetNextActiveHive(0);
      if ( v14 )
      {
        while ( 1 )
        {
          v15 = v14[807];
          if ( (v15 & 0x20) != 0 && CmpIsThisSameFile(a2, v14[444], v13, v15) && (v14[807] & 0x40) == 0 )
            break;
          v14 = (int *)CmpGetNextActiveHive((int)v14);
          if ( !v14 )
            return v5;
        }
        v16 = v14[632];
        *(_DWORD *)a4 = v14;
        v17 = CmpConstructName(v16);
        *a5 = v17;
        if ( v17 )
          v5 = 1;
        v18 = (unsigned int *)(v14 + 458);
        __pld(v14 + 458);
        v19 = v14[458] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v20 = __ldrex(v18);
        while ( v20 == v19 && __strex(v19 - 2, v18) );
        if ( v20 != v19 )
          ExfReleaseRundownProtection((unsigned __int8 *)v18);
      }
    }
  }
  return v5;
}
