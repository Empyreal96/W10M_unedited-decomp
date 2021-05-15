// sub_95935C 
 
int *__fastcall sub_95935C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28)
{
  int *result; // r0
  int v32; // r1
  int v33[32]; // [sp+0h] [bp-80h] BYREF

  v33[0] = ((int (*)(void))sub_959478)();
  v33[1] = sub_959478(a2);
  v33[2] = sub_959478(a3);
  v33[3] = sub_959478(a4);
  v33[4] = sub_959478(a5);
  v33[5] = sub_959478(a6);
  v33[6] = sub_959478(a7);
  v33[7] = sub_959478(a8);
  v33[8] = sub_959478(a9);
  v33[9] = sub_959478(a10);
  v33[10] = sub_959478(a11);
  v33[11] = sub_959478(a12);
  v33[12] = sub_959478(a13);
  v33[13] = sub_959478(a14);
  v33[14] = sub_959478(a15);
  v33[15] = sub_959478(a16);
  v33[16] = sub_959478(a17);
  v33[17] = sub_959478(a18);
  v33[18] = sub_959478(a19);
  v33[19] = sub_959478(a20);
  v33[20] = sub_959478(a21);
  v33[21] = sub_959478(a22);
  v33[22] = sub_959478(a23);
  v33[23] = sub_959478(a24);
  v33[24] = sub_959478(a25);
  v33[25] = sub_959478(a26);
  v33[26] = sub_959478(a27);
  v33[27] = sub_959478(a28);
  result = &KdDumpEnableOffset;
  v32 = 0;
  while ( v33[v32] == *(_DWORD *)((char *)sub_978BB0 + v32 * 4) )
  {
    if ( ++v32 >= 28 )
      return result;
  }
  return (int *)sub_96C1E8(&KdDumpEnableOffset);
}
