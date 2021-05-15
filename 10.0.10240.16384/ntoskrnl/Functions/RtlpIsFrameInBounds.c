// RtlpIsFrameInBounds 
 
BOOL __fastcall RtlpIsFrameInBounds(unsigned int *a1, unsigned int a2, unsigned int *a3)
{
  return (a2 & 3) == 0 && a2 >= *a1 && a2 < *a3;
}
