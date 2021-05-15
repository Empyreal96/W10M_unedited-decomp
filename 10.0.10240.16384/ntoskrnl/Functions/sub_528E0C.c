// sub_528E0C 
 
void __fastcall sub_528E0C(int a1, int a2)
{
  int v2; // r5

  do
  {
    *(_DWORD *)(*(_DWORD *)(v2 + 176) + 16) &= ~a2;
    v2 = *(_DWORD *)(v2 + 12);
  }
  while ( v2 );
  KeReleaseQueuedSpinLock(10, a1);
  JUMPOUT(0x4DF28E);
}
