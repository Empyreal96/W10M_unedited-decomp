// MiPrefetchDriverPages 
 
unsigned int __fastcall MiPrefetchDriverPages(unsigned int result, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r2
  int v5; // r5
  int v6; // r4
  int v7; // r3
  int v8; // [sp+0h] [bp-18h] BYREF
  unsigned int v9; // [sp+4h] [bp-14h]
  int v10; // [sp+8h] [bp-10h]

  v10 = a4;
  v4 = 0;
  v5 = 0;
  v8 = 0;
  v9 = 0;
  if ( result <= a2 )
  {
    v6 = (result + 4) << 10;
    do
    {
      v7 = *(_DWORD *)result;
      if ( (*(_DWORD *)result & 2) == 0 && ((v7 & 0x400) != 0 || (v7 & 0x800) == 0 && v7 != 128) )
      {
        if ( !v4 )
          v5 = result << 10;
        v4 = v6 - v5;
      }
      result += 4;
      v6 += 4096;
    }
    while ( result <= a2 );
    v8 = v5;
    v9 = v4;
    if ( v4 > 0x1000 )
      result = MiPrefetchVirtualMemory(1, (int)&v8, 1, 45);
  }
  return result;
}
