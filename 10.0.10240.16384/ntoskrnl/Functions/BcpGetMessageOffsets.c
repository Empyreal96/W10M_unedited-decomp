// BcpGetMessageOffsets 
 
int __fastcall BcpGetMessageOffsets(unsigned int *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // lr
  int *v5; // r10
  int v7; // r8
  unsigned int v8; // r4
  unsigned int v9; // r6
  unsigned int v10; // r3
  unsigned int v14; // [sp+8h] [bp-28h]
  unsigned int v15; // [sp+10h] [bp-20h]

  v4 = a3;
  v5 = &dword_616150[14 * a3];
  *a1 = BcpCursor;
  v7 = 0;
  a1[1] = dword_653570;
  a1[2] = dword_653574;
  v14 = *a1;
  v15 = a1[2];
  if ( a4 )
  {
    v8 = a1[1];
    v9 = 0;
    dword_619018 |= 0x1000000u;
    while ( 1 )
    {
      v7 = BcpDisplayProgress(v9, v4);
      if ( v7 < 0 )
        break;
      if ( __PAIR64__(v8, v14) < ProgressEnd )
      {
        v14 = ProgressEnd;
        v15 = *(_DWORD *)algn_618F38;
        v8 = HIDWORD(ProgressEnd);
      }
      BcpSetCursorPosition(*a1, a1[1], a1 + 2);
      ++v9;
      v4 = a3;
      if ( v9 > 0x64 )
      {
        dword_619018 &= 0xFEFFFFFF;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    *a2 = v5[3] + v5[7];
    v10 = v15 + v5[10];
    a2[1] = v10;
    a2[2] = v10;
  }
  return v7;
}
