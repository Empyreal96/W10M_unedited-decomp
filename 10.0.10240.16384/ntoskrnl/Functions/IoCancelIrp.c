// IoCancelIrp 
 
int __fastcall IoCancelIrp(int a1)
{
  int result; // r0
  int v3; // r0
  int v4; // r6
  unsigned int *v5; // r1
  int (__fastcall *v6)(int, int, _DWORD); // r5
  int v7; // r0
  int v8; // r0

  if ( ViVerifierDriverAddedThunkListHead )
    return sub_529C18();
  v3 = KeAcquireQueuedSpinLock(7);
  *(_BYTE *)(a1 + 36) = 1;
  v4 = v3;
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 56);
  do
    v6 = (int (__fastcall *)(int, int, _DWORD))__ldrex(v5);
  while ( __strex(0, v5) );
  __dmb(0xBu);
  if ( v6 )
  {
    if ( *(char *)(a1 + 35) > (char)(*(_BYTE *)(a1 + 34) + 1) )
      KeBugCheckEx(72, a1, v6);
    *(_BYTE *)(a1 + 37) = v3;
    v7 = *(_DWORD *)(*(_DWORD *)(a1 + 96) + 24);
    if ( ViVerifierDriverAddedThunkListHead )
      v8 = IovpCancelRoutine(v7, a1, v6);
    else
      v8 = v6(v7, a1, 0);
    if ( KeGetCurrentIrql(v8) == 2 && v4 != 2 )
      KeBugCheckEx(283, a1, v6);
    result = 1;
  }
  else
  {
    KeReleaseQueuedSpinLock(7, v3);
    result = 0;
  }
  return result;
}
