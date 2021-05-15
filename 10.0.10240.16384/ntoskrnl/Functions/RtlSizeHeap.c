// RtlSizeHeap 
 
int __fastcall RtlSizeHeap(int a1, int a2, int a3)
{
  return RtlpSizeHeapInternal(a1, a2, a3, (unsigned __int8)RtlpHpHeapFeatures);
}
