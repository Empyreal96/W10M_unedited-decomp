// sub_5224B4 
 
void __fastcall sub_5224B4(int a1)
{
  int v1; // r5
  int v2; // r7
  _DWORD *v3; // r8

  ++*(_DWORD *)(v2 + 4);
  KeReleaseQueuedSpinLock(5, a1);
  ExFreePoolWithTag(v1, 1834378051);
  *v3 = v2;
  JUMPOUT(0x456ADC);
}
