// PnprGetStackLimits 
 
int __fastcall PnprGetStackLimits(int **a1, unsigned int *a2, int a3, int a4)
{
  int v5; // r3
  unsigned int v7; // [sp+0h] [bp-10h] BYREF
  int v8[3]; // [sp+4h] [bp-Ch] BYREF

  v8[0] = a4;
  *a1 = KeGetCurrentStackPointer((int)a1, (int)a2, a3, a4, a3);
  return KeQueryCurrentStackInformation(v8, &v7, a2, v5);
}
