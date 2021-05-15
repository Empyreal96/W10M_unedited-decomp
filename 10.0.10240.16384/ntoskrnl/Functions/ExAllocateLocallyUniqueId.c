// ExAllocateLocallyUniqueId 
 
int *__fastcall ExAllocateLocallyUniqueId(int *result)
{
  int v1; // r1
  int v2; // r5
  unsigned __int64 v3; // r2
  unsigned int v4; // r4
  int v5; // r6
  unsigned __int64 v6; // kr08_8
  unsigned __int64 v7; // r2
  unsigned __int64 v8; // kr10_8

  v1 = unk_616394;
  v2 = ExpLuid;
  v3 = ExpLuid + 1;
  __dmb(0xBu);
  do
  {
    v6 = __ldrexd(&ExpLuid);
    v4 = HIDWORD(v6);
    v5 = v6;
  }
  while ( v6 == __PAIR64__(v1, v2) && __strexd(v3, &ExpLuid) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( v2 == v5 && v1 == v4 )
      break;
    v2 = v5;
    v1 = v4;
    v7 = __PAIR64__(v4, v5) + 1;
    __dmb(0xBu);
    do
    {
      v8 = __ldrexd(&ExpLuid);
      v4 = HIDWORD(v8);
      v5 = v8;
    }
    while ( v8 == __PAIR64__(v1, v2) && __strexd(v7, &ExpLuid) );
  }
  *result = v2;
  result[1] = v1;
  return result;
}
