// BgpConsoleSetPointSize 
 
int __fastcall BgpConsoleSetPointSize(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5, int a6)
{
  int v6; // r7
  unsigned int v7; // r9
  unsigned int v8; // r10
  unsigned int v9; // r5
  int v10; // r8
  unsigned int v11; // r4
  int result; // r0
  unsigned int v16; // [sp+Ch] [bp-2Ch]
  unsigned int v17; // [sp+10h] [bp-28h] BYREF
  unsigned int v18; // [sp+14h] [bp-24h]

  v6 = 0;
  v7 = a3;
  v16 = a1;
  v8 = a1;
  v9 = 5;
  v10 = 32;
  while ( 1 )
  {
    v11 = (v10 + v9 + 1) >> 1;
    *(_DWORD *)(a5 + 12) = v11;
    result = BgpFoGetTextMetrics(a5, &v17);
    if ( result < 0 )
      return result;
    if ( !v18 )
      __brkdiv0();
    if ( v8 > v7 / v18 )
      goto LABEL_9;
    if ( !v17 )
      __brkdiv0();
    if ( a2 > a4 / v17 || v18 > 0x3B || v17 > 0x1A )
    {
LABEL_9:
      v10 = v11 - 1;
    }
    else
    {
      v6 = 1;
      v9 = (v10 + v9 + 1) >> 1;
    }
    v7 = a3;
    v8 = v16;
    if ( v9 == v10 )
    {
      if ( !v6 )
        return -1073741823;
      *(_DWORD *)(a5 + 12) = v9;
      return BgpFoGetTextMetrics(a5, a6);
    }
  }
}
