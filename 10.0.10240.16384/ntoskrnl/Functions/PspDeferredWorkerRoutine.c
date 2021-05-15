// PspDeferredWorkerRoutine 
 
int __fastcall PspDeferredWorkerRoutine(int a1)
{
  *(_DWORD *)(a1 + 24) = (*(int (__fastcall **)(_DWORD))(a1 + 16))(*(_DWORD *)(a1 + 20));
  return KeSetEvent(a1, 1, 0);
}
