// MiLogMemResetInfo 
 
int *__fastcall MiLogMemResetInfo(int a1, int a2, int a3)
{
  int v3; // r3
  char v4; // r2
  int v6[2]; // [sp+8h] [bp-18h] BYREF
  int v7; // [sp+10h] [bp-10h]

  v6[1] = a2;
  v7 = 0;
  v6[0] = a1;
  if ( (a3 & 0x80000) != 0 )
  {
    v3 = 0;
  }
  else
  {
    if ( (a3 & 0x1000000) != 0 )
      v4 = 1;
    else
      v4 = 2;
    v3 = v4 & 3;
  }
  v7 = v3;
  return MiLogPerfMemoryEvent(646, 0x20008000u, (int)v6, 12, 4200706);
}
