// PopDispatchSuperfetchNotification 
 
int __fastcall PopDispatchSuperfetchNotification(int a1, int a2)
{
  char v2; // r4

  v2 = 0;
  if ( a1 < 0 )
    v2 = 2;
  PopDiagTraceSuperfetchNotification(1);
  PfPowerActionNotify(1, v2, a2);
  return PopDiagTraceSuperfetchNotification(0);
}
