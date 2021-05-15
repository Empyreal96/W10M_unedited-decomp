// sub_5519DC 
 
void __fastcall sub_5519DC(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  unsigned int *v4; // r5
  unsigned int *v5; // r7
  int v6; // r10
  int v7; // lr
  int v8; // r8
  int v9; // r0
  unsigned int v10; // r3
  unsigned int v11; // [sp+0h] [bp-C8h]
  int v12; // [sp+14h] [bp-B4h]

  if ( a3 != a2 && a3 != 1701147206 )
  {
    v8 = 0;
    while ( (unsigned int)v4 > v3 || ((unsigned int)v4 & v7) != 0 || v4[1] != a1 || !MiIsPoolHeader(v4) )
    {
      v9 = MiLockLeafPage(v4, v6);
      v7 = 7;
      if ( v9 )
      {
        ++v6;
        *(_BYTE *)(((unsigned int)(v8 >> 2) >> 3) + v12) |= 1 << ((v8 >> 2) & 7);
        if ( (*(_BYTE *)(v9 + 18) & 8) != 0 || (*v4 & 2) == 0 && (*(_BYTE *)(v9 + 18) & 0x20) != 0 )
          JUMPOUT(0x4EFAD0);
        v3 = v11;
      }
      v10 = *v4++;
      v8 += 4;
      *v5++ = v10;
      if ( ((unsigned __int16)v4 & 0xFFF) == 0 )
        break;
      a1 = 1734439494;
    }
    JUMPOUT(0x4EF982);
  }
  JUMPOUT(0x4EF976);
}
