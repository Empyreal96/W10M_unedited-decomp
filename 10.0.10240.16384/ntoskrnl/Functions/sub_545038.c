// sub_545038 
 
void __noreturn sub_545038()
{
  int v0; // r4

  KeBugCheckEx(26, 268177, v0, *(_DWORD *)(v0 + 4) | 0x80000000, *(_DWORD *)(v0 + 12) & 0x3FFFFFFF);
}
