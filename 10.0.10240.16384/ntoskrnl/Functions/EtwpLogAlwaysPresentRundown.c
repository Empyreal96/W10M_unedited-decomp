// EtwpLogAlwaysPresentRundown 
 
int __fastcall EtwpLogAlwaysPresentRundown(int a1)
{
  if ( KdDebuggerEnabled )
    EtwpLogKernelEvent(0, a1, 0, 3898, 4200450);
  return EtwpLogKernelEvent(0, a1, 0, 8, 4200450);
}
