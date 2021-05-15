// MmQuerySystemMemoryInformation 
 
int __fastcall MmQuerySystemMemoryInformation(int *a1)
{
  int v1; // r1
  int v2; // r4
  int v3; // r2
  int v4; // r3

  v1 = dword_634D4C;
  v2 = dword_632A90;
  __dmb(0xBu);
  v3 = dword_634D94;
  v4 = dword_640604;
  *a1 = v1;
  a1[1] = v2;
  a1[3] = v4;
  a1[2] = v3;
  return 0;
}
