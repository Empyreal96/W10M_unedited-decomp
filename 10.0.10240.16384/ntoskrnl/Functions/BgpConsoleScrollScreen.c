// BgpConsoleScrollScreen 
 
int BgpConsoleScrollScreen()
{
  unsigned int v0; // r6
  int v1; // r1
  int *v2; // r7
  unsigned int v3; // r8
  int *v4; // r5
  int v5; // r9
  int v6; // r7
  __int64 v7; // kr00_8
  int *v8; // r5
  unsigned int i; // r6
  int result; // r0
  int v11; // [sp+10h] [bp-38h]
  int v12; // [sp+18h] [bp-30h]
  int v13; // [sp+1Ch] [bp-2Ch]
  char v14[4]; // [sp+20h] [bp-28h] BYREF
  char v15[36]; // [sp+24h] [bp-24h] BYREF

  v0 = 0;
  v1 = dword_61034C;
  v2 = dword_610348;
  do
  {
    v3 = 0;
    if ( v1 != 1 )
    {
      v4 = v2;
      do
      {
        v5 = *((unsigned __int16 *)v4 + 46);
        if ( *((unsigned __int16 *)v4 + 40) != v5 || v4[18] != v4[21] || v4[19] != v4[22] )
        {
          v12 = v4[22];
          v13 = v4[21];
          if ( BgpDisplayCharacterEx(
                 v5,
                 (int *)dword_61036C,
                 dword_61037C + dword_610370 * v0,
                 dword_610380 + dword_610374 * v3,
                 v12,
                 v13,
                 (int)v15,
                 (int)v14,
                 v11,
                 0) >= 0 )
          {
            *((_WORD *)v4 + 40) = v5;
            v4[19] = v12;
            v4[18] = v13;
          }
          v1 = dword_61034C;
        }
        ++v3;
        v4 += 3;
      }
      while ( v3 < v1 - 1 );
    }
    ++v0;
    v2 += 75;
  }
  while ( v0 < 0x50 );
  v6 = v1 - 1;
  v7 = *(_QWORD *)&dword_610354;
  v8 = &dword_610348[3 * v1 - 3];
  for ( i = 0; i < 0x50; ++i )
  {
    result = BgpDisplayCharacterEx(
               32,
               (int *)dword_61036C,
               dword_61037C + dword_610370 * i,
               dword_610380 + dword_610374 * v6,
               SHIDWORD(v7),
               v7,
               (int)v14,
               (int)v15,
               v11,
               0);
    if ( result >= 0 )
    {
      *((_WORD *)v8 + 40) = 32;
      *((_QWORD *)v8 + 9) = v7;
    }
    v8 += 75;
  }
  dword_610384 = 0;
  dword_610388 = dword_61034C - 1;
  return result;
}
