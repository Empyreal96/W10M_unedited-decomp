// HvRefreshHive 
 
int __fastcall HvRefreshHive(int a1)
{
  int v2; // r0
  int v3; // r6
  int v4; // r7
  int v5; // r3
  unsigned int v6; // r5
  int v7; // r3
  int v8; // r5
  int v9; // r6
  __int16 v10; // r3
  unsigned int v11; // r6
  _DWORD *v12; // r2
  __int64 v13; // r0
  int v14; // r7
  _DWORD *v15; // r7
  int v16; // r2
  __int64 v17; // r0
  int v18; // r4
  _DWORD *v19; // r4
  int v21[2]; // [sp+20h] [bp-158h] BYREF
  int v22; // [sp+28h] [bp-150h] BYREF
  int v23; // [sp+2Ch] [bp-14Ch]
  int v24; // [sp+30h] [bp-148h]
  int v25; // [sp+34h] [bp-144h]
  int v26; // [sp+38h] [bp-140h] BYREF
  int v27; // [sp+40h] [bp-138h] BYREF
  char v28[284]; // [sp+44h] [bp-134h] BYREF

  v21[0] = -1;
  v27 = 0;
  memset(v28, 0, sizeof(v28));
  if ( *(_DWORD *)(a1 + 2520) || *(_DWORD *)(a1 + 1932) )
    return -1073741823;
  v2 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36), v21);
  if ( v2 )
  {
    v4 = *(_DWORD *)(v2 + 16);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v21);
    v22 = *(_DWORD *)(a1 + 1776);
    v25 = 0;
    v5 = *(_DWORD *)(a1 + 96);
    if ( v5 )
    {
      if ( v5 != 1 )
      {
        v6 = 2;
        v23 = *(_DWORD *)(a1 + 1792);
        v24 = *(_DWORD *)(a1 + 1796);
LABEL_11:
        v3 = CmpInitializeHive(
               (int)&v26,
               2u,
               *(_DWORD *)(a1 + 92) & 0xFFFEFFFF,
               v6,
               0,
               &v22,
               0,
               16777218,
               0,
               0,
               0,
               &v27);
        if ( v3 < 0 )
          return v3;
        v8 = v26;
        if ( *(_DWORD *)(*(_DWORD *)(v26 + 32) + 36) == *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36) )
        {
          v9 = (*(int (__fastcall **)(int))(v26 + 4))(v26);
          if ( v9 )
          {
            if ( HvpMarkCellDirty(v8, *(_DWORD *)(*(_DWORD *)(v8 + 32) + 36), 0, 0) )
            {
              v10 = *(_WORD *)(v9 + 2);
              *(_DWORD *)(v9 + 16) = v4;
              *(_WORD *)(v9 + 2) = v10 | 0xC;
              (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, v21);
              if ( HvSyncHive(v8) )
              {
                CmpDestroySecurityCache((_DWORD *)a1);
                HvFreeHive(a1, 1);
                memmove(a1, v8, 0x6F0u);
                if ( *(_DWORD *)(v8 + 956) == v8 + 960 )
                  *(_DWORD *)(a1 + 956) = a1 + 960;
                v11 = 0;
                v12 = (_DWORD *)(a1 + 2008);
                *(_DWORD *)(a1 + 1992) = *(_DWORD *)(v8 + 1992);
                *(_DWORD *)(a1 + 1996) = *(_DWORD *)(v8 + 1996);
                *(_DWORD *)(a1 + 2000) = *(_DWORD *)(v8 + 2000);
                *(_DWORD *)(a1 + 2004) = *(_DWORD *)(v8 + 2004);
                do
                {
                  *v12 = v12;
                  v12[1] = v12;
                  LODWORD(v13) = (char *)v12 + v8 - a1;
                  while ( *(_DWORD *)v13 != (_DWORD)v13 )
                  {
                    HIDWORD(v13) = *(_DWORD *)v13;
                    v14 = **(_DWORD **)v13;
                    if ( __PAIR64__(*(_DWORD *)(v14 + 4), *(_DWORD *)(*(_DWORD *)v13 + 4)) != v13 )
                      __fastfail(3u);
                    *(_DWORD *)v13 = v14;
                    *(_DWORD *)(v14 + 4) = v13;
                    v15 = (_DWORD *)v12[1];
                    *(_DWORD *)HIDWORD(v13) = v12;
                    *(_DWORD *)(HIDWORD(v13) + 4) = v15;
                    if ( (_DWORD *)*v15 != v12 )
                      __fastfail(3u);
                    *v15 = HIDWORD(v13);
                    v12[1] = HIDWORD(v13);
                  }
                  ++v11;
                  v12 += 2;
                }
                while ( v11 < 0x40 );
                v16 = a1 + 1352;
                *(_DWORD *)(a1 + 1352) = a1 + 1352;
                *(_DWORD *)(a1 + 1356) = a1 + 1352;
                *(_DWORD *)(a1 + 1764) = a1 + 1764;
                *(_DWORD *)(a1 + 1768) = a1 + 1764;
                LODWORD(v17) = v8 + 1352;
                while ( *(_DWORD *)v17 != (_DWORD)v17 )
                {
                  HIDWORD(v17) = *(_DWORD *)v17;
                  v18 = **(_DWORD **)v17;
                  if ( __PAIR64__(*(_DWORD *)(v18 + 4), *(_DWORD *)(*(_DWORD *)v17 + 4)) != v17 )
                    __fastfail(3u);
                  *(_DWORD *)v17 = v18;
                  *(_DWORD *)(v18 + 4) = v17;
                  v19 = *(_DWORD **)(v16 + 4);
                  *(_DWORD *)HIDWORD(v17) = v16;
                  *(_DWORD *)(HIDWORD(v17) + 4) = v19;
                  if ( *v19 != v16 )
                    __fastfail(3u);
                  *v19 = HIDWORD(v17);
                  *(_DWORD *)(v16 + 4) = HIDWORD(v17);
                }
                v3 = 0;
                goto LABEL_41;
              }
            }
            else
            {
              (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, v21);
            }
            v3 = -1073741443;
          }
          else
          {
            v3 = -1073741670;
          }
        }
        else
        {
          v3 = -1073741811;
        }
        CmpDestroySecurityCache((_DWORD *)v8);
        HvFreeHive(v8, 0);
LABEL_41:
        CmpDereferenceHive((_DWORD *)v8);
        return v3;
      }
      v7 = *(_DWORD *)(a1 + 1780);
      v6 = 1;
    }
    else
    {
      v6 = 0;
      v7 = 0;
    }
    v23 = v7;
    v24 = 0;
    goto LABEL_11;
  }
  return -1073741670;
}
