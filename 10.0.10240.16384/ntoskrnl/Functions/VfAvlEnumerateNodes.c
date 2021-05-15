// VfAvlEnumerateNodes 
 
unsigned int *__fastcall VfAvlEnumerateNodes(int a1, int a2, int (__fastcall *a3)(int, int), int a4)
{
  unsigned int *result; // r0
  unsigned int v8; // r7
  unsigned int v9; // r8
  int v10; // r4
  int v11; // r0
  int i; // r1
  int v13; // r0

  result = (unsigned int *)*(unsigned __int8 *)(a2 + 5);
  if ( ((unsigned __int8)result & 1) == 0 )
  {
    *(_BYTE *)(a2 + 4) = KfRaiseIrql(2);
    result = (unsigned int *)(*(unsigned __int8 *)(a2 + 5) | 1);
    *(_BYTE *)(a2 + 5) = (_BYTE)result;
  }
  v8 = 0;
  v9 = dword_61D2AC;
  if ( dword_61D2AC )
  {
    v10 = 0;
    do
    {
      ViAvlAcquireTableLockAtDpcLevelSafe(v10 + dword_61D2A8, a2);
      v11 = v10 + dword_61D2A8;
      for ( i = 1; ; i = 0 )
      {
        v13 = RtlEnumerateGenericTableAvl(v11, i);
        if ( !v13 )
          break;
        result = (unsigned int *)a3(v13, a4);
        if ( !result )
          return result;
        v11 = v10 + dword_61D2A8;
      }
      result = ViAvlReleaseTableLockFromDpcLevel((unsigned int *)(v10 + dword_61D2A8), a2);
      ++v8;
      v10 += 256;
    }
    while ( v8 < v9 );
  }
  return result;
}
