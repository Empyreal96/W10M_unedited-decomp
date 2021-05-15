// RtlpCopyContext 
 
int __fastcall RtlpCopyContext(int *a1, _DWORD *a2)
{
  *a1 = *a2 & 0x20200007;
  a1[5] = a2[5];
  a1[6] = a2[6];
  a1[7] = a2[7];
  a1[8] = a2[8];
  a1[9] = a2[9];
  a1[10] = a2[10];
  a1[11] = a2[11];
  a1[12] = a2[12];
  a1[14] = a2[14];
  a1[15] = a2[15];
  a1[16] = a2[16];
  a1[17] = a2[17];
  a1[18] = a2[18];
  return memmove((int)(a1 + 36), (int)(a2 + 36), 0x40u);
}
