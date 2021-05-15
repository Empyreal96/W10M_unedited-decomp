// PiDrvDbUnloadNodeDpcRoutine 
 
int __fastcall PiDrvDbUnloadNodeDpcRoutine(int a1, int a2)
{
  unsigned int *v3; // r4
  int result; // r0
  unsigned int v5; // r2

  v3 = (unsigned int *)(a2 + 240);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_55565C();
  do
    v5 = __ldrex(v3);
  while ( __strex(1u, v3) );
  __dmb(0xBu);
  if ( v5 )
    result = KxWaitForSpinLockAndAcquire(v3);
  if ( !*(_BYTE *)(a2 + 244) )
  {
    *(_DWORD *)(a2 + 232) = PiDrvDbUnloadNodeWorkerCallback;
    *(_DWORD *)(a2 + 236) = a2;
    *(_DWORD *)(a2 + 224) = 0;
    result = ExQueueWorkItem((_DWORD *)(a2 + 224), 1);
    *(_BYTE *)(a2 + 244) = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(v3);
  __dmb(0xBu);
  *v3 = 0;
  return result;
}
