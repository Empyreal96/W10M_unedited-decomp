// PspInitializeCallbacks 
 
_DWORD *PspInitializeCallbacks()
{
  _DWORD *v0; // r0
  int v1; // r2
  _DWORD *v2; // r0
  int v3; // r2
  _DWORD *result; // r0
  int v5; // r2

  v0 = PspCreateThreadNotifyRoutine;
  do
    v0 = SmRegistrationCtxInitialize(v0) + 1;
  while ( v1 != 1 );
  v2 = PspCreateProcessNotifyRoutine;
  do
    v2 = SmRegistrationCtxInitialize(v2) + 1;
  while ( v3 != 1 );
  result = PspLoadImageNotifyRoutine;
  do
    result = SmRegistrationCtxInitialize(result) + 1;
  while ( v5 != 1 );
  return result;
}
