// EtwpThreadRundownApc 
 
int __fastcall EtwpThreadRundownApc(int a1, int a2, int a3, int *a4, int *a5)
{
  int v5; // r4

  v5 = *a4;
  EtwpTraceThreadRundown(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, *a5);
  return KeSetEvent(v5, 0, 0);
}
