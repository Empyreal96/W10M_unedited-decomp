// MiEnableNewPfns 
 
int __fastcall MiEnableNewPfns(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r7
  unsigned int v3; // r4
  int v4; // r6
  unsigned int v5; // r5
  unsigned int *v6; // r6
  int result; // r0
  unsigned int *v8; // r9
  unsigned int v9; // r8
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  char v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // [sp+0h] [bp-30h]
  int v15; // [sp+4h] [bp-2Ch]
  int v17; // [sp+Ch] [bp-24h]

  v2 = a2;
  v3 = a1;
  v4 = a2 - a1;
  v5 = MmPfnDatabase + 24 * a1;
  v17 = a2 - a1;
  if ( a1 < a2 )
  {
    v6 = (unsigned int *)(v5 + 24564);
    v14 = v5 + 24564;
    do
    {
      if ( (v3 & 0x3FF) != 0 || v2 - v3 < 0x400 )
      {
        MiLockAndInsertPageInFreeList(v5);
        ++v3;
        v5 += 24;
        v6 += 6;
      }
      else
      {
        v8 = v6;
        v9 = v5 + 24552;
        do
        {
          v15 = KfRaiseIrql(2);
          v10 = (unsigned __int8 *)v8 + 3;
          do
            v11 = __ldrex(v10);
          while ( __strex(v11 | 0x80, v10) );
          __dmb(0xBu);
          if ( v11 >> 7 )
            return sub_54E4E0();
          v12 = *(_BYTE *)(v9 + 18);
          *(_DWORD *)(v9 + 20) = *(_DWORD *)(v9 + 20) & 0xFFF00000 | 0xFFFFE;
          *(_BYTE *)(v9 + 18) = v12 & 0xF8 | 1;
          if ( v9 == v5 )
            MiInsertLargePageInNodeList(v3, 1024, 1);
          __dmb(0xBu);
          do
            v13 = __ldrex(v8);
          while ( __strex(v13 & 0x7FFFFFFF, v8) );
          KfLowerIrql(v15);
          v9 -= 24;
          v8 -= 6;
        }
        while ( v9 >= v5 );
        v2 = a2;
        v5 += 24576;
        v6 = (unsigned int *)(v14 + 24576);
        v3 += 1024;
      }
      v14 = (unsigned int)v6;
    }
    while ( v3 < v2 );
    v4 = v17;
  }
  MiReturnResidentAvailable(v4);
  do
    result = __ldrex(&dword_634A2C[58]);
  while ( __strex(result + v4, &dword_634A2C[58]) );
  return result;
}
