// SepRmServerSiloCreateNotify 
 
int __fastcall SepRmServerSiloCreateNotify(int a1, int a2, _BYTE *a3, _BYTE *a4)
{
  int v5; // r4
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = (int)a3;
  v7[1] = (int)a4;
  if ( PsAllocateMonitorContextServerSilo(SeRmSiloMonitor, 48, v7) < 0 )
    return -1073741801;
  memset((_BYTE *)v7[0], 0, 48);
  v5 = PsSetMonitorContextServerSilo(SeRmSiloMonitor, a1, 1, v7[0], 0);
  PsDereferenceMonitorContextServerSilo(v7[0]);
  return v5;
}
