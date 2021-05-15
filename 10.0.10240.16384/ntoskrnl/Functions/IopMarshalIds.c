// IopMarshalIds 
 
int __fastcall IopMarshalIds(_DWORD *a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int result; // r0

  *a1 = 0;
  a1[2] = 0;
  a1[2] = *a2;
  a1[3] = a2[1];
  a1[4] = a2[2];
  a1[5] = a2[3];
  a1[6] = a2[4];
  a1[7] = *a3;
  a1[8] = a3[1];
  a1[9] = a3[2];
  a1[10] = a3[3];
  result = memmove((int)(a1 + 11), a4 + 8, *(_DWORD *)(a4 + 4));
  a1[1] = *(_DWORD *)(a4 + 4) + 36;
  return result;
}
