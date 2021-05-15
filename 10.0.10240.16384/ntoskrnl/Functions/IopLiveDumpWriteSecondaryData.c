// IopLiveDumpWriteSecondaryData 
 
int __fastcall IopLiveDumpWriteSecondaryData(int a1, int a2, _QWORD *a3, _QWORD *a4)
{
  unsigned int *v4; // r5
  __int64 v5; // r6
  int result; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r3
  int v14[2]; // [sp+0h] [bp-50h] BYREF
  int v15; // [sp+8h] [bp-48h]
  int v16; // [sp+Ch] [bp-44h]
  unsigned int v17[16]; // [sp+10h] [bp-40h] BYREF

  v4 = *(unsigned int **)(a2 + 8);
  v5 = 0i64;
  if ( v4 )
  {
    v15 = 16;
    v14[0] = 1886221636;
    v14[1] = 1651469378;
    v16 = -268425216;
    result = IopLiveDumpWriteBuffer(a1, (int)v14, 0x10u, a3);
    if ( result >= 0 )
    {
      v17[0] = 32;
      LODWORD(v5) = v15;
      v17[6] = 0;
      v17[7] = 0;
      do
      {
        v10 = v4[1];
        v11 = v4[2];
        v12 = v4[3];
        v17[1] = *v4;
        v17[2] = v10;
        v17[3] = v11;
        v17[4] = v12;
        v17[5] = v4[5];
        result = IopLiveDumpWriteBuffer(a1, (int)v17, v17[0], a3);
        if ( result < 0 )
          break;
        v5 += v17[0];
        result = IopLiveDumpWriteBuffer(a1, v4[4], v4[5], a3);
        if ( result < 0 )
          break;
        v13 = v4[5];
        v4 = (unsigned int *)v4[7];
        v5 += v13;
      }
      while ( v4 );
    }
  }
  else
  {
    result = 0;
  }
  if ( a4 )
    *a4 = v5;
  return result;
}
