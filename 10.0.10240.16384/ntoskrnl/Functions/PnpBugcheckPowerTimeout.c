// PnpBugcheckPowerTimeout 
 
void __fastcall __noreturn PnpBugcheckPowerTimeout(int a1)
{
  int v1; // r3
  __int16 v2[2]; // [sp+8h] [bp-18h] BYREF
  int *v3; // [sp+Ch] [bp-14h]
  int v4; // [sp+10h] [bp-10h]

  v1 = PnpDeviceEventThread;
  __dmb(0xBu);
  if ( !v1 )
  {
    v1 = PnpDeviceActionThread;
    __dmb(0xBu);
  }
  v2[0] = -32767;
  v2[1] = 1;
  v3 = &PnpDeviceCompletionQueue;
  v4 = ExWorkerQueue;
  KeBugCheck2(159, 4, a1, v1, v2, 0);
}
