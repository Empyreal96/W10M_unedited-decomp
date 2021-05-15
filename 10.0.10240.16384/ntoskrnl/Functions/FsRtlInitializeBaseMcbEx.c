// FsRtlInitializeBaseMcbEx 
 
int __fastcall FsRtlInitializeBaseMcbEx(int a1, int a2, __int16 a3)
{
  int v4; // r0

  *(_WORD *)(a1 + 8) = a2;
  *(_DWORD *)(a1 + 4) = 0;
  *(_WORD *)(a1 + 10) = a3;
  if ( a2 == 1 )
    v4 = ExAllocateFromPagedLookasideList(&FsRtlFirstMappingLookasideList);
  else
    v4 = ExAllocatePoolWithTag((unsigned __int16)a2, 120, 1953649478);
  *(_DWORD *)(a1 + 12) = v4;
  if ( !v4 )
    return sub_52A71C();
  *(_DWORD *)a1 = 15;
  return 1;
}
