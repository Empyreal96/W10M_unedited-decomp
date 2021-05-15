// sub_553E24 
 
void sub_553E24()
{
  _DWORD *v0; // r6
  int v1; // r7
  int v2; // r0

  if ( *(_DWORD *)(v1 + 20) < *v0 )
  {
    v2 = DbgPrint("(UCRBlock->Size >= *Size)");
    RtlpHeapHandleError(v2);
  }
  JUMPOUT(0x4F4BBC);
}
