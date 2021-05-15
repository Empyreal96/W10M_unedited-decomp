// MiReleaseOutSwapReservations 
 
int __fastcall MiReleaseOutSwapReservations(int result, unsigned int a2)
{
  unsigned int *v3; // r5
  unsigned int v4; // r4
  unsigned int v5; // r6
  int v6[2]; // [sp+0h] [bp-50h] BYREF
  char v7; // [sp+8h] [bp-48h]
  char v8[3]; // [sp+9h] [bp-47h] BYREF
  int *v9; // [sp+Ch] [bp-44h]
  int v10; // [sp+10h] [bp-40h]
  int v11; // [sp+14h] [bp-3Ch]
  int v12; // [sp+18h] [bp-38h]

  v7 = 3;
  v8[0] = 0;
  v9 = v6;
  v10 = 1;
  v11 = 0;
  v12 = 0;
  v3 = (unsigned int *)result;
  v6[1] = 4096;
  while ( (unsigned int)v3 <= a2 )
  {
    v4 = *v3;
    v5 = *v3 + v3[1];
    while ( v4 < v5 )
    {
      v6[0] = v4;
      result = MmAccessFault(0, v4, 0, (int)v8);
      v4 += 4096;
    }
    v3 += 2;
  }
  return result;
}
