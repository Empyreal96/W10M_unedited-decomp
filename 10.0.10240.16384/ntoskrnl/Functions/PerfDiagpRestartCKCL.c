// PerfDiagpRestartCKCL 
 
int __fastcall PerfDiagpRestartCKCL(unsigned __int16 *a1)
{
  unsigned int v2; // r4
  int v3; // r5
  int v5; // [sp+0h] [bp-28h] BYREF
  int v6; // [sp+4h] [bp-24h] BYREF
  unsigned int v7[8]; // [sp+8h] [bp-20h] BYREF

  v2 = 0;
  while ( 1 )
  {
    ++v2;
    v7[0] = -500000 * v2;
    v7[1] = -500000 * v2;
    KeDelayExecutionThread(0, 0, v7);
    if ( !PerfDiagpIsTracingAllowed() )
      break;
    memmove((int)word_61CB48, (int)L"Circular Kernel Context Logger", 0x3Eu);
    PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, &v5);
    v3 = EtwpStartAutoLogger((char *)word_61CB48, a1, &v6, v5);
    PsDereferenceMonitorContextServerSilo(v5);
    if ( v3 != -1073741771 || v2 >= 0x14 )
      return v3;
  }
  return -1073741823;
}
