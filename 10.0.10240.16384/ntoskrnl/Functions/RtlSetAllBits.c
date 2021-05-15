// RtlSetAllBits 
 
int __fastcall RtlSetAllBits(_DWORD *a1)
{
  return RtlFillMemoryUlong(a1[1], 4 * (((*a1 & 0x1F) != 0) + (*a1 >> 5)), -1);
}
