// sub_54D36C 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_54D36C(int a1)
{
  int v1; // r4 OVERLAPPED
  int (__fastcall *v2)(_DWORD); // r3

  if ( (unsigned int)KeGetCurrentIrql(a1) >= 2 )
  {
    v2 = PspFreeMonitorContextServerSilo;
    *(_QWORD *)(v1 + 36) = *(_QWORD *)(&v1 - 1);
    *(_DWORD *)(v1 + 28) = 0;
    ExQueueWorkItem((_DWORD *)(v1 + 28), 1);
  }
  else
  {
    PspFreeMonitorContextServerSilo(v1);
  }
  JUMPOUT(0x4D7652);
}
