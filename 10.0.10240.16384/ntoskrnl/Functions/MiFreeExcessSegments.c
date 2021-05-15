// MiFreeExcessSegments 
 
int __fastcall MiFreeExcessSegments(int a1)
{
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r0
  int v5; // r6
  unsigned int v6; // r0
  int v8; // r4
  unsigned int v9; // r0

  if ( !dword_634D54 )
    return 0;
  v2 = dword_634D4C;
  v3 = 0;
  if ( !dword_634D4C )
    return 0;
  v4 = MiFreePoolPagesLeft(6) + v2;
  if ( v4 > dword_640714 )
    v4 = dword_640714;
  if ( !v4 )
    __brkdiv0();
  if ( 100 * v2 / v4 > dword_68126C )
    goto LABEL_23;
  v5 = dword_632A90;
  __dmb(0xBu);
  v6 = MiFreePoolPagesLeft(5) + v5;
  if ( v6 > dword_640714 )
    v6 = dword_640714;
  if ( !v6 )
    __brkdiv0();
  if ( 100 * v5 / v6 > dword_68126C )
    goto LABEL_23;
  if ( (unsigned int)dword_635310 < 0x6000000 )
    return sub_54694C();
  v8 = dword_632D0C;
  if ( dword_632D0C )
  {
    v9 = MiFreePoolPagesLeft(14) + v8;
    if ( !v9 )
      __brkdiv0();
    if ( 100 * v8 / v9 > dword_68126C )
LABEL_23:
      v3 = 1;
  }
  if ( (v3 & a1) != 0 )
    KeSetEvent((int)&unk_63F9F8, 0, 0);
  return v3;
}
