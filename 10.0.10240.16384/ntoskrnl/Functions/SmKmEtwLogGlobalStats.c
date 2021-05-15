// SmKmEtwLogGlobalStats 
 
int __fastcall SmKmEtwLogGlobalStats(__int64 *a1, int a2)
{
  __int64 v2; // r0
  int v4; // [sp+20h] [bp-30h] BYREF
  int v5[10]; // [sp+28h] [bp-28h] BYREF

  v5[0] = (int)&v4;
  v5[1] = 0;
  v5[2] = 4;
  v5[3] = 0;
  v5[4] = a2;
  v5[5] = 0;
  v5[7] = 0;
  v2 = *a1;
  v4 = 896;
  v5[6] = 896;
  return EtwWriteEx(v2, SHIDWORD(v2), (int)SmEventGlobalStats, 0, 0, 0, 0, 0, 0, 2, (int)v5);
}
