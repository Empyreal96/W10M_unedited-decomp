// sub_529F8C 
 
void sub_529F8C()
{
  _DWORD *v0; // r5

  ExFreeToNPagedLookasideList((int)&IopOplockFoExtLookasideList, v0);
  JUMPOUT(0x4691DA);
}
