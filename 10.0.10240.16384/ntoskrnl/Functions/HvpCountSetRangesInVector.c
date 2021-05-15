// HvpCountSetRangesInVector 
 
int __fastcall HvpCountSetRangesInVector(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v7; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  v5 = 0;
  v6 = 0;
  if ( *a1 )
  {
    while ( 1 )
    {
      v7 = RtlFindNextForwardRunClear((int)a1, v5, (int)v9);
      if ( !v7 )
        break;
      if ( v9[0] != v5 )
        ++v6;
      v5 = v9[0] + v7;
      if ( (unsigned int)(v9[0] + v7) >= *a1 )
        return v6;
    }
    ++v6;
  }
  return v6;
}
