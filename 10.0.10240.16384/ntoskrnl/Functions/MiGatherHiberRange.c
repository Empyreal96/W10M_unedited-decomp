// MiGatherHiberRange 
 
int __fastcall MiGatherHiberRange(int a1, const void *a2, int a3, int a4)
{
  int v4; // r3
  const void *v5; // r2
  int v6; // r1

  if ( a4 == 2 )
  {
    v5 = a2;
    v6 = 81920;
    v4 = 1;
  }
  else
  {
    v4 = a3 << 12;
    v5 = a2;
    v6 = 0x10000;
  }
  PoSetHiberRange(0, v6, v5, (const void *)v4, 1953525069);
  return 0;
}
