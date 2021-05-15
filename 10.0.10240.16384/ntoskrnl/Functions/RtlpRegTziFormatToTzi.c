// RtlpRegTziFormatToTzi 
 
int __fastcall RtlpRegTziFormatToTzi(_DWORD *a1, _DWORD *a2)
{
  int v3; // r2

  *a1 = *a2;
  a1[21] = a2[1];
  a1[42] = a2[2];
  RtlpSystemTimeToTimeFields(a1 + 17, a2 + 3);
  return RtlpSystemTimeToTimeFields(a1 + 38, v3 + 28);
}
