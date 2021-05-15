// sub_5507C8 
 
void __fastcall sub_5507C8(int a1)
{
  _DWORD *v1; // r7
  int v2; // r0

  v2 = InbvAcquireLock(a1);
  *v1 = 0;
  InbvReleaseLock(v2);
  JUMPOUT(0x4EC91E);
}
