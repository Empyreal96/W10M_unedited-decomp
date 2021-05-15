// BgpFwReserveAllocate 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BgpFwReserveAllocate(int a1)
{
  unsigned int v1; // r4 OVERLAPPED
  unsigned int v2; // r0
  unsigned int v4; // r2
  int v5; // r3

  v1 = ((a1 + 15) & 0xFFFFFFF0) + 16;
  v2 = RtlFindClearBitsAndSet((unsigned int *)&dword_6416BC, v1, dword_6416C8);
  if ( v2 > dword_6416CC - 16 )
    return sub_50EEB0();
  dword_6416C8 = v2 + v1;
  v4 = dword_6416B8 + v2;
  v5 = 1262700354;
  *(_QWORD *)(v4 + 4) = *(_QWORD *)(&v1 - 1);
  *(_DWORD *)(v4 + 12) = 0;
  return v4 + 16;
}
