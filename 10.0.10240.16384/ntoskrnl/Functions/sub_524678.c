// sub_524678 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_524678(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19)
{
  int v19; // r6
  int v20; // r7
  int v21; // r8
  int v22; // r10
  int v23; // lr
  int v24; // r4
  int v25; // lr
  int v26; // r1 OVERLAPPED
  int v27; // r2 OVERLAPPED
  int v28; // r3
  int v29; // r3
  int *v30; // r2
  int v31; // r3
  int v32; // r1

  if ( v20 == 2 )
  {
    v25 = v21 + 44 * v19;
    *(_QWORD *)&v26 = *(_QWORD *)(v25 + 28);
    v28 = a19 & ~v26 | v27;
    *(_DWORD *)(v25 + 32) = v28;
    if ( v27 == v28 )
      JUMPOUT(0x45D0B0);
    v29 = ~v27;
    v30 = *(int **)(v25 + 40);
    v31 = v29 & ~v26;
    v32 = 1;
    if ( v30 )
    {
      while ( v32 )
      {
        if ( (v32 & v31 & a19) != 0 && !*v30 )
          *v30 = v22 | 0x20000;
        ++v30;
        v32 *= 2;
      }
    }
  }
  else
  {
    if ( v20 != 3 )
      JUMPOUT(0x45D084);
    v23 = v21 + 44 * v19;
    v24 = *(_DWORD *)(v23 + 28);
    *(_DWORD *)(v23 + 28) = v24 & a19;
    if ( v24 != (v24 & a19) )
      AuthzBasepSetAppContainerAccessReasons(v24 & a19, a2, v22, *(_DWORD *)(v23 + 40));
  }
  JUMPOUT(0x45D07E);
}
