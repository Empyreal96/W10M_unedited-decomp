// DbgkpLkmdSnapThread 
 
int __fastcall DbgkpLkmdSnapThread(int a1, int a2, int a3, int a4)
{
  KeEnumerateQueueApc(a3, DbgkpLkmdEnumApcOrDpcDataCallback, a1, 0);
  return DbgkpLkmdLaunchSnapApc(a1, a2, a3, a4);
}
