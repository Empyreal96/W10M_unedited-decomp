// sub_969D98 
 
void __fastcall sub_969D98(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  _DWORD *v15; // r6
  unsigned int v16; // r8
  int v17; // r9
  int v18; // r5
  unsigned int v19; // r2
  int v20; // r10
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r0

  v18 = *(_DWORD *)(v17 + 32);
  v19 = v15[5];
  v20 = 0;
  if ( v16 < v19 || v16 >= v15[6] + v19 )
  {
    v24 = RtlpxLookupFunctionTable(v16, &a11);
  }
  else
  {
    v21 = v15[5];
    v22 = v15[6];
    v23 = v15[7];
    a11 = v15[4];
    a12 = v21;
    a13 = v22;
    a14 = v23;
    v24 = a11;
  }
  if ( v24 )
  {
    a7 = a12;
    v20 = a14;
  }
  v15[4] = v24;
  v15[5] = a7;
  v15[6] = v18;
  v15[7] = v20;
  RtlRemoveInvertedFunctionTable(v16, v21, v22, v23);
  JUMPOUT(0x9535F8);
}
