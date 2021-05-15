// HvpCopyModifiedData 
 
unsigned __int8 *__fastcall HvpCopyModifiedData(unsigned __int8 *result, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r5
  unsigned int v6; // r4
  int v7; // r9
  int v8; // r10
  int *v9; // r0
  int v10; // r7
  int v11; // r0
  char v12[4]; // [sp+8h] [bp-28h] BYREF
  int v13[9]; // [sp+Ch] [bp-24h] BYREF

  v4 = 0;
  v6 = a2;
  v7 = (int)result;
  if ( a4 )
  {
    v8 = a3 - a2;
    do
    {
      v9 = (int *)HvpGetCellMap(v7, v6);
      v10 = (int)v9;
      if ( !v9 )
        KeBugCheckEx(81, 1, v7, v6, 1648);
      v11 = HvpMapEntryGetBlockAddress((int)v9, v9, v12, v13);
      result = (unsigned __int8 *)memmove(v11, v8 + v6, 0x1000u);
      if ( v12[0] )
        result = HvpMapEntryReleaseBlockAddress((int)result, v10);
      v4 += 4096;
      v6 += 4096;
    }
    while ( v4 < a4 );
  }
  return result;
}
