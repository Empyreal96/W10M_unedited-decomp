// PsReleaseProcessWakeCounter 
 
unsigned int __fastcall PsReleaseProcessWakeCounter(int a1, int a2)
{
  int v2; // r2
  char v3; // r3

  v2 = a1 & 7;
  v3 = 1;
  if ( v2 == 5 )
  {
    v3 = 5;
    v2 = 0;
  }
  PspChargeJobWakeCounter((_DWORD *)(a1 & 0xFFFFFFF8), 0, v2, -1, 0xFFFFFFFF, 0xFFFFFFFF, v3, 0, a2);
  return ObDereferenceObjectDeferDeleteWithTag(a1 & 0xFFFFFFF8);
}
