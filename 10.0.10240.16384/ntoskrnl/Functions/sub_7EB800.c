// sub_7EB800 
 
void __fastcall sub_7EB800(int a1, int a2, int a3)
{
  int *v3; // r4
  int v4; // r3
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r3

  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = v4 & 0xFFFFFFC0;
  if ( (v4 & 0xFFFFFFC0) != 0 )
  {
    v4 = *(__int16 *)((v4 & 0xFFFFFFC0) + 0x136) - 1;
    *(_WORD *)(v5 + 310) = v4;
  }
  ExAcquireResourceExclusiveLite((int)(v3 + 8), 1, a3, v4);
  if ( v3[53] && (v3[107] & 0x1000) != 0 )
    PspSendReliableJobNotification(v3, 12);
  v6 = ExReleaseResourceLite((int)(v3 + 8));
  if ( v5 )
  {
    v7 = (__int16)(*(_WORD *)(v5 + 310) + 1);
    *(_WORD *)(v5 + 310) = v7;
    if ( !v7 && *(_DWORD *)(v5 + 100) != v5 + 100 )
      KiCheckForKernelApcDelivery(v6);
  }
  JUMPOUT(0x765936);
}
