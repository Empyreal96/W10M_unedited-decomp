// sub_81AEF0 
 
void __fastcall sub_81AEF0(int a1)
{
  int v1; // r6
  int v2; // r0
  _DWORD *v3; // r5

  v2 = MiAllocateVad(a1, 2147418111);
  v3 = (_DWORD *)v2;
  if ( v2 )
  {
    MiInsertVadCharges(v2, v1);
    MiGetWsAndInsertVad(v3);
  }
  JUMPOUT(0x7B9034);
}
