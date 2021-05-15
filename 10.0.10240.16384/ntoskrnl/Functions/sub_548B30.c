// sub_548B30 
 
void __fastcall sub_548B30(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, char a12)
{
  int *v12; // r7
  int *v13; // r8
  int v14; // r9
  int *v15; // r10
  int *v16; // r4
  int *v17; // r0
  int v18; // r1
  int v19; // r3
  int *v20; // r0

  if ( v14 )
  {
    v16 = (int *)v12[16];
    v17 = &a9;
    a9 = *v12;
    a10 = v16[2];
  }
  else
  {
    v16 = &a11;
    MiRefPageFileSpaceBitmaps(v12, &a11, a3, a4);
    v17 = (int *)&a12;
  }
  v18 = *v13;
  a7 = *v15;
  RtlFindLongestRunClearCapped(v17, v18, &a7);
  if ( !v14 )
  {
    v20 = MiDerefPageFileSpaceBitmaps((int)v12, (int **)v16, 0, v19);
    if ( v20 )
      ExFreePoolWithTag(v20, 0);
  }
  JUMPOUT(0x4C8E6C);
}
