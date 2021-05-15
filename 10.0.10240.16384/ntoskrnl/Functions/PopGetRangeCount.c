// PopGetRangeCount 
 
int __fastcall PopGetRangeCount(unsigned int *a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r3
  unsigned int v6; // r1
  int v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r3
  unsigned int v15[4]; // [sp+0h] [bp-10h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = a1[6];
  v6 = 0;
  v7 = 0;
  v15[0] = 0;
  if ( v5 )
  {
    do
    {
      v8 = RtlFindNextForwardRunClearCapped(a1 + 6, v6, 0xFFFFFFFF, v15);
      ++v7;
      v6 = v8 + v15[0];
      v9 = a1[6];
      v15[0] = v6;
    }
    while ( v6 < v9 );
  }
  v10 = a1[8];
  v11 = 0;
  v15[0] = 0;
  if ( v10 )
  {
    do
    {
      v12 = RtlFindNextForwardRunClearCapped(a1 + 8, v11, 0xFFFFFFFF, v15);
      ++v7;
      v11 = v12 + v15[0];
      v13 = a1[8];
      v15[0] = v11;
    }
    while ( v11 < v13 );
  }
  return a1[12] + v7;
}
