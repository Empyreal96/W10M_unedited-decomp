// sub_524FEC 
 
void __fastcall sub_524FEC(__int64 a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int *a9, int **a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
  _DWORD *v17; // r4
  int v18; // r5
  int v19; // r6
  int v20; // r3

  if ( !v17[5] )
  {
    v20 = v17[7];
    if ( (v20 & 2) == 0 )
    {
      if ( (v20 & 1) != 0 )
      {
        a5 = 1;
        LOWORD(a7) = 263;
        BYTE2(a7) = 4;
        a8 = 0;
        a10 = &a9;
        a9 = (int *)&a9;
        a4 = v17[11];
        v17[11] = &a4;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v17 + 9, a17);
        }
        else
        {
          __dmb(0xBu);
          v17[9] = 0;
        }
        KfLowerIrql(v18);
        KeWaitForGate((int)&a7, 19);
      }
      else
      {
        LODWORD(a1) = v17;
        MiRemoveUnusedSegment(a1);
        v17[5] = 1;
        MiCleanSection(v17, v18, v19);
      }
      JUMPOUT(0x45E8E8);
    }
  }
  JUMPOUT(0x45E8C0);
}
