// sub_5410D4 
 
void __fastcall sub_5410D4(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, int a8, int *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r4
  __int64 *v17; // r5
  __int64 v18; // r6
  unsigned int v19; // r8
  unsigned int v20; // r2

  v19 = dword_681D78[0];
  while ( v19 )
  {
    v20 = __clz(__rbit(v19));
    v19 &= ~(1 << v20);
    a7 = v20;
    a9 = (int *)&a7;
    a10 = 0;
    a11 = 4;
    a12 = 0;
    a13 = (int)*(&KiProcessorBlock + v20) + 3272;
    a14 = 0;
    a15 = 4;
    a16 = 0;
    EtwWrite(v18, SHIDWORD(v18), v16, 0);
    v18 = *v17;
  }
  JUMPOUT(0x4AE6BA);
}
