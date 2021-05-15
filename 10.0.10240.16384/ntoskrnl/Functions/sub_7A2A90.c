// sub_7A2A90 
 
int __fastcall sub_7A2A90(int a1, int *a2, int *a3)
{
  unsigned int v5; // r5
  int v6; // r6
  int v7; // r4
  int v8; // r3
  int v10[2]; // [sp+10h] [bp-48h] BYREF
  int v11[16]; // [sp+18h] [bp-40h] BYREF

  v11[4] = 24;
  v11[5] = 0;
  v11[7] = 544;
  v11[6] = 0;
  v11[8] = 0;
  v11[9] = 0;
  v11[2] = a1;
  v11[3] = 0;
  v5 = 0;
  v10[0] = 0;
  v6 = ZwCreateSection();
  if ( v6 >= 0 )
  {
    v6 = ObReferenceObjectByHandle(v10[1], 0, 0, 0, (int)v11, 0);
    v7 = v11[0];
    ZwClose();
    if ( v6 >= 0 )
    {
      v11[0] = 0;
      v6 = MmMapViewInSystemSpace(v7, (int)v10, (int)v11);
      if ( v6 < 0 )
      {
        v5 = v10[0];
      }
      else
      {
        v8 = v10[0];
        *a2 = v7;
        v7 = 0;
        *a3 = v8;
      }
    }
    if ( v7 )
      return sub_811D70();
    if ( v5 )
      MmUnmapViewInSystemSpace(v5);
  }
  return v6;
}
