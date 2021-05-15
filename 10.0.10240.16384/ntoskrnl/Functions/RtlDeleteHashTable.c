// RtlDeleteHashTable 
 
int __fastcall RtlDeleteHashTable(int result, int a2)
{
  _DWORD *v2; // r4
  int v3; // r5
  int v4; // r7
  int *v5; // r6
  int v6; // r0
  int v7; // t1

  v2 = (_DWORD *)result;
  if ( *(_DWORD *)(result + 8) > 0x80u )
  {
    v3 = *(_DWORD *)(result + 32);
    if ( v3 )
    {
      v4 = 0;
      v5 = *(int **)(result + 32);
      do
      {
        v7 = *v5++;
        v6 = v7;
        if ( !v7 )
          break;
        RtlpSecondLevelDirFreeUsingFreeList(v6, a2);
        ++v4;
      }
      while ( v4 < 512 );
      result = ExFreePoolWithTag(v3);
    }
  }
  else
  {
    result = *(_DWORD *)(result + 32);
    if ( result )
      result = RtlpSecondLevelDirFreeUsingFreeList(result, a2);
  }
  if ( (*v2 & 1) != 0 )
    result = ExFreePoolWithTag(v2);
  return result;
}
