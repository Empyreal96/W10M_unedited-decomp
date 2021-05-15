// WheapWorkQueueWorkerRoutine 
 
int __fastcall WheapWorkQueueWorkerRoutine(int a1)
{
  unsigned int *v2; // r5
  _DWORD *v3; // r0
  int result; // r0
  unsigned int v5; // r2
  unsigned int v6; // r2

  v2 = (unsigned int *)(a1 + 12);
  do
  {
    v3 = ExInterlockedRemoveHeadList((_DWORD *)a1, (unsigned int *)(a1 + 8));
    result = (*(int (__fastcall **)(int, _DWORD *))(a1 + 64))(a1, v3);
    __dmb(0xBu);
    do
    {
      v5 = __ldrex(v2);
      v6 = v5 - 1;
    }
    while ( __strex(v6, v2) );
    __dmb(0xBu);
  }
  while ( v6 );
  return result;
}
