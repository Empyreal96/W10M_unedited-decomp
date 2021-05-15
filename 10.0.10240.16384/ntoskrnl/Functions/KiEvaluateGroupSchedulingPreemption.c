// KiEvaluateGroupSchedulingPreemption 
 
int __fastcall KiEvaluateGroupSchedulingPreemption(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v6; // r5
  BOOL v8; // r2
  int v9; // r4
  int v10; // lr
  unsigned int v11; // r0
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r2
  unsigned int v16; // r5
  int i; // r1
  int v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r1
  unsigned __int8 *v22; // r3
  unsigned int v23; // r2

  v6 = 0;
  v8 = *(_DWORD *)(a1 + 4) != a2 || a1 == ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v9 = *(_DWORD *)(a2 + 68);
  if ( v9 )
  {
    v9 += *(_DWORD *)(a1 + 2352);
    if ( v9 )
    {
      v13 = v9;
      if ( *(char *)(a2 + 123) >= 16
        || (*(_DWORD *)(a2 + 80) & 0x100) != 0
        || v8 && (*(_DWORD *)(a2 + 308) || *(_BYTE *)(a2 + 134) == 1) )
      {
        v6 = 0;
      }
      else
      {
        v14 = v9;
        do
        {
          if ( (*(_BYTE *)(v14 + 92) & 2) != 0 )
            return sub_52E70C(v9);
          v14 = *(_DWORD *)(v14 + 236);
        }
        while ( v14 );
        do
        {
          v6 = *(_DWORD *)(v13 + 96);
          if ( v6 )
            break;
          v13 = *(_DWORD *)(v13 + 236);
        }
        while ( v13 );
      }
    }
  }
  *a4 = 0;
  v10 = *(_DWORD *)(a3 + 68);
  v11 = 0;
  if ( v10 )
  {
    v10 += *(_DWORD *)(a1 + 2352);
    if ( v10 )
    {
      v20 = v10;
      if ( *(char *)(a3 + 123) >= 16
        || (*(_DWORD *)(a3 + 80) & 0x100) != 0
        || *(_DWORD *)(a3 + 308)
        || *(_BYTE *)(a3 + 134) == 1 )
      {
        v11 = 0;
LABEL_44:
        if ( (*(_DWORD *)(a3 + 80) & 0x600) == 0 && (*(_DWORD *)(a3 + 308) || *(_BYTE *)(a3 + 134) == 1) )
        {
          __dmb(0xBu);
          v22 = (unsigned __int8 *)(a3 + 81);
          do
            v23 = __ldrex(v22);
          while ( __strex(v23 | 4, v22) );
          __dmb(0xBu);
        }
      }
      else
      {
        v21 = v10;
        do
        {
          if ( (*(_BYTE *)(v21 + 92) & 2) != 0 )
          {
            v11 = -1;
            goto LABEL_54;
          }
          v21 = *(_DWORD *)(v21 + 236);
        }
        while ( v21 );
        while ( 1 )
        {
          v11 = *(_DWORD *)(v20 + 96);
          if ( v11 )
            break;
          v20 = *(_DWORD *)(v20 + 236);
          if ( !v20 )
            goto LABEL_44;
        }
LABEL_54:
        *a4 = v10;
      }
    }
  }
  if ( !v9 || !v10 || !v6 || !v11 )
    goto LABEL_7;
  if ( v9 != v10 )
  {
    v15 = *(unsigned __int8 *)(v9 + 93);
    v16 = *(unsigned __int8 *)(v10 + 93);
    i = 0;
    v11 = 0;
    if ( v15 < v16 )
    {
      i = -1;
      do
      {
        if ( *(_DWORD *)(v10 + 96) > v11 )
          v11 = *(_DWORD *)(v10 + 96);
        v10 = *(_DWORD *)(v10 + 236);
      }
      while ( v15 < *(unsigned __int8 *)(v10 + 93) );
    }
    else if ( v15 > v16 )
    {
      i = 1;
      do
      {
        if ( *(_DWORD *)(v9 + 96) > v11 )
          v11 = *(_DWORD *)(v9 + 96);
        v9 = *(_DWORD *)(v9 + 236);
      }
      while ( *(unsigned __int8 *)(v9 + 93) > v16 );
    }
    if ( v9 != v10 )
    {
      v18 = *(_DWORD *)(v9 + 236);
      v19 = *(_DWORD *)(v10 + 236);
      for ( i = 0; v18 != v19; v19 = *(_DWORD *)(v19 + 236) )
      {
        v9 = v18;
        v18 = *(_DWORD *)(v18 + 236);
        v10 = v19;
      }
    }
    if ( i )
    {
      if ( i <= 0 )
      {
        v6 = 0;
        goto LABEL_8;
      }
      v6 = v11;
      v11 = 0;
    }
    else
    {
      v6 = *(_DWORD *)(v9 + 96);
      v11 = *(_DWORD *)(v10 + 96);
    }
LABEL_7:
    if ( v11 < v6 )
      return 1;
LABEL_8:
    if ( v11 != v6 )
      return 0;
  }
  return *(char *)(a3 + 123) > *(char *)(a2 + 123);
}
