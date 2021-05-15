// PiDmListUpdateAggregationCountWorker 
 
int __fastcall PiDmListUpdateAggregationCountWorker(int a1, int a2, int a3)
{
  int *v3; // r7
  int v6; // r9
  int result; // r0
  int v8; // r6
  unsigned int v9; // r4
  char v10[4]; // [sp+8h] [bp-38h] BYREF
  unsigned int v11; // [sp+Ch] [bp-34h] BYREF
  unsigned int *v12; // [sp+10h] [bp-30h] BYREF
  int v13[2]; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v14[9]; // [sp+1Ch] [bp-24h] BYREF

  v3 = PiDmAggregatedBooleanDefs;
  v13[1] = a3;
  v6 = 3;
  while ( 1 )
  {
    result = *v3;
    if ( *(_DWORD *)(a2 + 20) != *v3 )
      goto LABEL_3;
    if ( *(_DWORD *)(a1 + 20) != v3[3] )
      goto LABEL_3;
    v8 = v3[6];
    if ( *(_DWORD *)(a1 + v8) == 0x80000000 )
      goto LABEL_3;
    PiDmGetCacheKeys(result, &v12, (int *)&v11);
    v9 = v11;
    result = PiDmGetCachedKeyIndex(v12, v11, v3[1]);
    if ( result >= v9 )
      goto LABEL_3;
    result = a2 + 20 * result;
    if ( *(_DWORD *)(result + 64) )
      break;
LABEL_13:
    *(_DWORD *)(a1 + v8) = 0x80000000;
LABEL_3:
    v3 += 7;
    if ( !--v6 )
      return result;
  }
  result = PiDmCacheDataDecode((int *)(result + 64), v13, (int)v10, 1u, v14);
  if ( result < 0 )
  {
    if ( result == -1073741275 || result == -1073741789 )
      goto LABEL_3;
    goto LABEL_13;
  }
  if ( v13[0] != 17 || v10[0] != -1 )
    goto LABEL_3;
  return sub_7C8F2C();
}
