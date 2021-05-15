// PiPnpRtlObjectEventCallback 
 
int __fastcall PiPnpRtlObjectEventCallback(int a1, int a2, int a3, int a4, int a5)
{
  return PiPnpRtlObjectEventWorker(a2, a3, a4, a5);
}
