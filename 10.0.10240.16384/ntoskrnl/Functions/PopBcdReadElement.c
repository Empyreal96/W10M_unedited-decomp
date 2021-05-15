// PopBcdReadElement 
 
int __fastcall PopBcdReadElement(int a1, unsigned int a2, unsigned int *a3, int *a4)
{
  int v8; // r4
  int v9; // r0
  int v10; // r2
  unsigned int v11; // r5
  int v12; // r3
  int v14[8]; // [sp+8h] [bp-20h] BYREF

  v14[1] = (int)a4;
  v14[0] = 0;
  if ( BcdGetElementDataWithFlags(a1, a2, (int)a3, 0, v14) != -1073741789 )
    return -1073741275;
  v9 = ExAllocatePoolWithTag(1, v14[0], 1684226640);
  v11 = v9;
  if ( !v9 )
    return -1073741670;
  v8 = BcdGetElementDataWithFlags(a1, a2, v10, v9, v14);
  if ( v8 < 0 )
  {
    ExFreePoolWithTag(v11);
  }
  else
  {
    v8 = 0;
    v12 = v14[0];
    *a3 = v11;
    *a4 = v12;
  }
  return v8;
}
