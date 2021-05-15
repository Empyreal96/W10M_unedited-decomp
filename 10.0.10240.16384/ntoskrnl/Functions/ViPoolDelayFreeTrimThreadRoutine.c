// ViPoolDelayFreeTrimThreadRoutine 
 
void __fastcall __noreturn ViPoolDelayFreeTrimThreadRoutine(int a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r4

  while ( 1 )
  {
    do
    {
      KeWaitForSingleObject(a1 + 8, 0, 0, 0, 0);
      ++*(_DWORD *)(a1 + 40);
      v2 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)a1);
    }
    while ( !v2 );
    do
    {
      v3 = (_DWORD *)*v2;
      ExFreePoolWithTag((unsigned int)v2);
      v2 = v3;
    }
    while ( v3 );
  }
}
