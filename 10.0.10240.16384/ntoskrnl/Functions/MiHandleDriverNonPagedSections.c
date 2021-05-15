// MiHandleDriverNonPagedSections 
 
int __fastcall MiHandleDriverNonPagedSections(int a1, char a2, int a3)
{
  int v3; // r5
  int v5; // r4
  char v6; // r7
  unsigned int v7; // r6
  char v8; // r8
  unsigned int v9; // r5
  int v10; // r7
  int v11; // r0
  unsigned int v12; // r6
  int v14; // r4
  unsigned int v15; // [sp+8h] [bp-28h] BYREF
  unsigned int v16; // [sp+Ch] [bp-24h] BYREF
  int v17[8]; // [sp+10h] [bp-20h] BYREF

  v3 = a3;
  if ( (*(_DWORD *)(((*(_DWORD *)(a1 + 24) >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
  {
    v5 = 0;
    v6 = 1;
    if ( a3 == 1 )
    {
      if ( (dword_681250 & 1) != 0 || (a2 & 2) != 0 )
      {
        v8 = 2;
        if ( (a2 & 1) != 0 )
          v8 = 1;
        v9 = 0;
LABEL_15:
        v10 = 0;
        while ( 1 )
        {
          v11 = MiSnapDriverRange(a1, v10, 8, 0, &v15, &v16);
          v12 = v15;
          v10 = v11;
          if ( v15 )
          {
            if ( v9 )
              return sub_7CDA94();
            v5 = MiLockCode(a1, v15, v16, v8);
            if ( v5 < 0 )
            {
              v9 = v12;
              goto LABEL_15;
            }
          }
          if ( !v10 )
            return v5;
        }
      }
      if ( (a2 & 1) == 0 )
      {
        MiDisablePagingOfDriver();
        v6 = 2;
      }
      goto LABEL_7;
    }
    if ( (dword_681250 & 1) == 0 )
    {
LABEL_7:
      v17[0] = 0;
      v15 = 0;
      v7 = 0;
      while ( MiFindDriverNonPagedSections(a1, v17, &v15, &v16) >= 0 )
      {
        if ( v3 == 1 )
        {
          v5 = MiLockCode(a1, v15, v16, v6);
          if ( v5 < 0 )
          {
            v3 = 0;
            v7 = v15;
            v17[0] = 0;
          }
        }
        else
        {
          if ( v15 == v7 )
            return v5;
          MiUnlockCodePage(v15, v16);
        }
      }
      return v5;
    }
    v14 = 0;
    do
    {
      v14 = MiSnapDriverRange(a1, v14, 8, 0, &v15, &v16);
      if ( v15 )
        MiUnlockCodePage(v15, v16);
    }
    while ( v14 );
  }
  return 0;
}
