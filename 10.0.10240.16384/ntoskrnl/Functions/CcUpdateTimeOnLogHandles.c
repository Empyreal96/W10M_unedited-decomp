// CcUpdateTimeOnLogHandles 
 
int __fastcall CcUpdateTimeOnLogHandles(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int *v5; // r2
  int v6; // r4
  int v7; // r3
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]

  v8 = a3;
  v9 = a4;
  result = KeQueryTickCount(&v8);
  v5 = (int *)CcVolumeCacheMapList;
  if ( (int *)CcVolumeCacheMapList != &CcVolumeCacheMapList )
  {
    v6 = v8;
    result = v9;
    do
    {
      v7 = v5[27];
      if ( (v7 & 1) != 0 )
      {
        v5[26] = result;
        v5[27] = v7 & 0xFFFFFFFE;
        v5[25] = v6;
      }
      v5 = (int *)*v5;
    }
    while ( v5 != &CcVolumeCacheMapList );
  }
  return result;
}
