// CcMapAndRead 
 
int __fastcall CcMapAndRead(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r6
  int v8; // lr
  int v9; // r2
  unsigned int v10; // r4
  unsigned int v11; // r9
  unsigned int v12; // r10
  unsigned int v13; // r5
  int v14; // r0
  char v16[4]; // [sp+0h] [bp-30h] BYREF
  int v17; // [sp+4h] [bp-2Ch]
  int v18; // [sp+8h] [bp-28h]
  int v19; // [sp+Ch] [bp-24h]

  v18 = a2;
  v19 = a3;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = 0;
  v17 = 0;
  v6 = 0;
  v16[0] = 1;
  v7 = v4 & 0xFFFFFFC0;
  v8 = 1;
  if ( !a3 )
    v17 = 2;
  v9 = *(_DWORD *)((v4 & 0xFFFFFFC0) + 0x3B4);
  v10 = (a1 + (a4 & 0xFFFu) + 4095) >> 12;
  v11 = a4 & 0xFFFFF000;
  v12 = *(unsigned __int8 *)(v7 + 972) + 4 * v9;
  if ( v10 )
  {
    while ( 1 )
    {
      *(_BYTE *)(v7 + 972) = 1;
      v13 = v10 - 1;
      if ( v10 - 1 > *(_DWORD *)(v7 + 948) )
      {
        if ( v13 > 0xF )
          *(_DWORD *)(v7 + 948) = 15;
        else
          *(_DWORD *)(v7 + 948) = v13;
      }
      if ( a2 )
      {
        if ( v8 != 2 )
          v13 = 1;
      }
      else
      {
        v13 = v10;
      }
      v14 = MmCheckCachedPageStates(v11, v13 << 12, ((v8 & a2) != 0) | v17, v16);
      v5 = v14;
      if ( !v16[0] && !v19 )
        break;
      if ( v14 < 0 )
        break;
      v10 -= v13;
      a2 = v18;
      v11 += v13 << 12;
      if ( v10 == 1 )
      {
        v8 = 4;
      }
      else
      {
        v8 = 2;
        if ( !v10 )
          goto LABEL_11;
      }
    }
  }
  else
  {
LABEL_11:
    v6 = 1;
  }
  *(_BYTE *)(v7 + 972) = v12 & 3;
  *(_DWORD *)(v7 + 948) = v12 >> 2;
  if ( v5 < 0 && v19 )
    sub_52CA94();
  return v6;
}
