// BiAcquireBcdSyncMutant 
 
int __fastcall BiAcquireBcdSyncMutant(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[2]; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+8h] [bp-8h]
  int v7; // [sp+Ch] [bp-4h]

  v5[0] = a1;
  v5[1] = a2;
  v6 = a3;
  v7 = a4;
  if ( a1 )
    return 0;
  result = BiGetCurrentBcdMutantHandle(v5);
  if ( result < 0 )
    return result;
  if ( v5[0] == -1 )
    return 0;
  v6 = -600000000;
  v7 = -1;
  result = ZwWaitForSingleObject();
  if ( result == 258 )
    result = -1073741823;
  return result;
}
