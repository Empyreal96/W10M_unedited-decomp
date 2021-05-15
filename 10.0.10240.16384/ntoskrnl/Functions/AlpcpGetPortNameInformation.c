// AlpcpGetPortNameInformation 
 
int __fastcall AlpcpGetPortNameInformation(int a1, unsigned int *a2, int *a3, int a4)
{
  unsigned int v6; // r4
  int v8; // r5
  int v9; // r1
  int v10; // r0
  unsigned int v11; // r4
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[1] = a4;
  v13[0] = 0;
  v6 = *a3;
  v8 = ObQueryNameStringMode(a1, 0, 0, v13, 0);
  if ( v8 == -1073741820 )
  {
    v9 = v13[0];
    if ( v13[0] <= v6 )
    {
      v10 = ExAllocatePoolWithTag(1, v13[0], 1129335873);
      v11 = v10;
      if ( v10 )
      {
        v8 = ObQueryNameStringMode(a1, v10, v13[0], v13, 0);
        if ( v8 < 0 )
          ExFreePoolWithTag(v11);
        else
          *a2 = v11;
      }
      else
      {
        v8 = -1073741801;
      }
      v9 = v13[0];
    }
    *a3 = v9;
  }
  return v8;
}
