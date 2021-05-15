// EtwpEnumerateWorkingSet 
 
int __fastcall EtwpEnumerateWorkingSet(int a1, int a2)
{
  int v4; // r5
  int v5; // r1
  int result; // r0
  int v7; // r2

  v4 = 4096;
  while ( 1 )
  {
    if ( !*(_DWORD *)(a2 + 28) )
    {
      v5 = 24 * v4 + 8;
      *(_DWORD *)(a2 + 32) = v5;
      result = ExAllocatePoolWithTag(512, v5, 1953985605);
      *(_DWORD *)(a2 + 28) = result;
      if ( !result )
        break;
    }
    memset(*(_BYTE **)(a2 + 28), 0, *(_DWORD *)(a2 + 32));
    v7 = MiGetWorkingSetInfoEx(a1 + 492, *(unsigned int **)(a2 + 28), *(_DWORD *)(a2 + 32), 0);
    result = *(_DWORD *)(a2 + 28);
    if ( v7 != -1073741820 )
    {
      if ( v7 >= 0 )
      {
        if ( *(_DWORD *)(result + 4) )
          result = EtwLogPfnInfoRundown(a1, *(_DWORD *)(a2 + 16), *(int **)(a2 + 28));
      }
      return result;
    }
    v4 = *(_DWORD *)(result + 4) + 64;
    ExFreePoolWithTag(result);
    *(_DWORD *)(a2 + 28) = 0;
  }
  return result;
}
