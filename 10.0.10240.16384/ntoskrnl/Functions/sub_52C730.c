// sub_52C730 
 
void sub_52C730()
{
  int v0; // r8
  int v1; // [sp+0h] [bp-40h]

  IoSetOplockKeyContext(*(_DWORD *)(v0 + 28), v1, 2);
  ((void (__fastcall *)())FsRtlAcknowledgeEcp)();
  JUMPOUT(0x4736D2);
}
