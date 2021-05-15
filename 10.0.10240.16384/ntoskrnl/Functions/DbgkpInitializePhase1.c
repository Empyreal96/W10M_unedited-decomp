// DbgkpInitializePhase1 
 
int DbgkpInitializePhase1()
{
  int result; // r0
  __int16 v1[2]; // [sp+0h] [bp-8h] BYREF
  const __int16 *v2; // [sp+4h] [bp-4h]

  v1[0] = 70;
  v1[1] = 72;
  v2 = L"\\KernelObjects\\SystemErrorPortReady";
  result = DbgkpCreateNotificationEvent(v1);
  if ( result >= 0 )
    result = DbgkWerInitialize();
  return result;
}
