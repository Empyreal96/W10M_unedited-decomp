// EtwpServerSiloTerminateNotify 
 
int __fastcall EtwpServerSiloTerminateNotify(int a1, int a2)
{
  int v4; // r4
  int result; // r0

  v4 = PsAttachSiloToCurrentThread(a1);
  EtwUnregister(*(_DWORD *)(a2 + 368));
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  EtwShutdown(0);
  result = PsDetachSiloFromCurrentThread(v4);
  if ( a1 )
    result = PspDereferenceSiloObject(a1);
  return result;
}
