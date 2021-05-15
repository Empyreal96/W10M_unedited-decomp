// SmKmEtwLogStoreStats 
 
int __fastcall SmKmEtwLogStoreStats(int *a1, _DWORD *a2)
{
  int result; // r0
  int v5[6]; // [sp+20h] [bp-5A8h] BYREF
  char v6[1360]; // [sp+38h] [bp-590h] BYREF
  _DWORD v7[4]; // [sp+588h] [bp-40h] BYREF
  char v8[32]; // [sp+598h] [bp-30h] BYREF

  v7[0] = 0;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = 0;
  memset(v8, 0, sizeof(v8));
  memset(v6, 0, 1356);
  memset(v5, 0, sizeof(v5));
  v5[0] = (int)v7;
  v5[3] = 3;
  v5[1] = (int)v6;
  v5[5] = 1356;
  result = SMKM_STORE<SM_TRAITS>::SmStEtwFillStoreStatsEvent(a2, v5);
  if ( result )
    result = EtwWriteEx(*a1, a1[1], (int)SmEventStoreIoStats, 0, 0, 0, 0, 0, 0, v5[2], v5[0]);
  return result;
}
