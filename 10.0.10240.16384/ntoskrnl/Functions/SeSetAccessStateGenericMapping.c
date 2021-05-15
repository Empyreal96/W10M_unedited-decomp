// SeSetAccessStateGenericMapping 
 
int __fastcall SeSetAccessStateGenericMapping(int a1, int *a2)
{
  int *v2; // r5
  int result; // r0
  int v4; // r2
  int v5; // r3
  int v6; // r4

  v2 = (int *)(*(_DWORD *)(a1 + 48) + 4);
  result = *a2;
  v4 = a2[1];
  v5 = a2[2];
  v6 = a2[3];
  *v2 = *a2;
  v2[1] = v4;
  v2[2] = v5;
  v2[3] = v6;
  return result;
}
