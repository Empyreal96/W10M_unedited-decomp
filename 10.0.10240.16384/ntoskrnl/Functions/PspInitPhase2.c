// PspInitPhase2 
 
int PspInitPhase2()
{
  int v0; // r4
  __int64 v1; // r0
  int v2; // r1

  v0 = PsInitialSystemProcess;
  LODWORD(v1) = RtlGetSystemTimePrecise();
  *(_QWORD *)(v0 + 200) = v1;
  *(_DWORD *)(PsInitialSystemProcess + 824) = KeQueryInterruptTime();
  *(_DWORD *)(PsInitialSystemProcess + 828) = v2;
  return sub_96E638(MEMORY[0xFFFF93B0], MEMORY[0xFFFF93B4]);
}
