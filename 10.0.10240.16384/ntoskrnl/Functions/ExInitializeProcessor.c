// ExInitializeProcessor 
 
int __fastcall ExInitializeProcessor(int a1, int a2)
{
  int v4; // r0
  int v5; // r6
  int result; // r0

  v4 = ExAllocatePoolWithTag(512, 128, 1128888389);
  v5 = v4;
  if ( v4 )
  {
    ExInitializeSystemLookasideList(v4, 512, 576, 1128888389);
    *(_DWORD *)(a1 + 1472) = v5;
  }
  if ( a2 )
    result = sub_50B77C();
  else
    result = 0;
  return result;
}
