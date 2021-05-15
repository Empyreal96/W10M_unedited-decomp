// KeInitializeEntropySystem 
 
int __fastcall KeInitializeEntropySystem(int (__fastcall *a1)(_DWORD, _DWORD), void (__fastcall *a2)(int, int, int), int a3)
{
  int v6; // r5
  void **v7; // r7
  int v8; // t1

  if ( KiEntropyTimingRoutine )
    return -1073741811;
  v6 = KeNumberProcessors_0;
  if ( KeNumberProcessors_0 )
  {
    v7 = &KiProcessorBlock;
    do
    {
      v8 = (int)*v7++;
      a2(v8 + 2428, 256, a3);
      --v6;
    }
    while ( v6 );
  }
  KiEntropyTimingRoutine = a1;
  return 0;
}
