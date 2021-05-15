// BgpClearScreen 
 
int __fastcall BgpClearScreen(int a1)
{
  __int64 v2; // kr00_8
  unsigned int v3; // r0
  unsigned int v4; // r1
  unsigned int v5; // r3
  unsigned int v6; // r2
  __int64 v7; // r6
  int v8; // r0
  int result; // r0
  unsigned int v10; // r3
  int v11; // r2
  int v12; // r0
  unsigned int v13; // [sp+0h] [bp-30h]
  unsigned int v14; // [sp+8h] [bp-28h] BYREF
  unsigned int v15; // [sp+Ch] [bp-24h]
  unsigned int v16; // [sp+10h] [bp-20h]

  if ( (dword_619018 & 1) == 0 )
    return -1073741823;
  v2 = *(_QWORD *)&dword_618FC4;
  v13 = dword_618FC8;
  v3 = (unsigned int)BgpGetBitsPerPixel(a1, dword_618FCC) >> 3;
  v5 = v2 * HIDWORD(v2) * v3;
  v6 = 8128;
  if ( v5 < 0x1FC0 )
    v6 = v2 * HIDWORD(v2) * v3;
  v14 = HIDWORD(v2);
  v15 = v2;
  v7 = v2;
  v16 = v4;
  if ( v5 > v6 )
  {
    do
    {
      LODWORD(v7) = (unsigned int)v7 >> 1;
      HIDWORD(v7) >>= 1;
      v4 >>= 1;
    }
    while ( HIDWORD(v7) * (_DWORD)v7 * v3 > v6 );
    v15 = v7;
    v16 = v4;
    v14 = HIDWORD(v7);
  }
  v8 = BgpGetBitsPerPixel(v3, v4);
  result = BgpGxInitializeRectangle(&v14, v8, dword_6475C8, 0x2000);
  if ( result >= 0 )
  {
    BgpGxFillRectangle(dword_6475C8, a1);
    v10 = 0;
    v15 = 0;
    if ( (_DWORD)v2 )
    {
      v11 = 0;
      do
      {
        v14 = 0;
        if ( v13 )
        {
          do
          {
            v12 = BgpGxDrawRectangle(dword_6475C8, &v14, v11);
            if ( (dword_6475D8 & 0x10) != 0 )
              return sub_54D654(v12);
            v14 += HIDWORD(v7);
          }
          while ( v14 < v13 );
          v10 = v15;
          v11 = 0;
        }
        v10 += v7;
        v15 = v10;
      }
      while ( v10 < (unsigned int)v2 );
    }
    result = 0;
    dword_619018 |= 0x2000u;
  }
  return result;
}
