// sub_5106B4 
 
void __fastcall sub_5106B4(int a1, int a2, unsigned int a3)
{
  int v3; // r5
  int v4; // r9
  int v5; // lr
  char v6; // [sp+10h] [bp-30h] BYREF

  if ( *(_DWORD *)(v3 + v5) + v4 > a3 )
  {
    ++*(_DWORD *)(v3 + 10204);
    KeReleaseInStackQueuedSpinLock((int)&v6);
    MiReclaimSystemVa(1);
    JUMPOUT(0x428112);
  }
  JUMPOUT(0x42803A);
}
