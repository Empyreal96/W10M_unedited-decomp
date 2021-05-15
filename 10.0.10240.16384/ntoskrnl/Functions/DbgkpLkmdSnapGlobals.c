// DbgkpLkmdSnapGlobals 
 
int __fastcall DbgkpLkmdSnapGlobals(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r10
  int result; // r0
  unsigned int v7; // r6
  _DWORD *v8; // r5
  int v9; // r1

  v5 = KeNumberProcessors_0;
  result = (*(int (__fastcall **)(int, void **, int))(a1 + 168))(a1 + 128, &KiProcessorBlock, 4 * KeNumberProcessors_0);
  v7 = 0;
  if ( v5 )
  {
    v8 = (_DWORD *)a1;
    do
    {
      if ( v7 >= KeNumberProcessors_0 )
        v9 = 0;
      else
        v9 = *(_DWORD *)((char *)v8 + (_DWORD)&KiProcessorBlock - a1);
      if ( (*(int (__fastcall **)(int, int, int, int))(a1 + 168))(a1 + 128, v9, 18560, 2) >= 0 )
      {
        *(_DWORD *)(a4 + 4) = 0;
        *v8 = a4;
      }
      result = KeEnumerateProcessorDpcs(v7++);
      ++v8;
    }
    while ( v7 < v5 );
  }
  return result;
}
