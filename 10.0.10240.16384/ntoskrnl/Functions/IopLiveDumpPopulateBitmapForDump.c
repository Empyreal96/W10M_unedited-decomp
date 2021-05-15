// IopLiveDumpPopulateBitmapForDump 
 
unsigned int __fastcall IopLiveDumpPopulateBitmapForDump(_DWORD *a1)
{
  unsigned int v1; // r7
  unsigned int *v3; // r10
  unsigned int result; // r0
  unsigned int *v5; // r6
  unsigned int v6; // r5
  unsigned int v7; // r7
  int v8; // r1
  int v9; // r3
  unsigned int v10; // r8
  unsigned int v11; // r9
  int v12; // r3
  unsigned int v13; // [sp+0h] [bp-48h] BYREF
  int v14; // [sp+4h] [bp-44h] BYREF
  int v15; // [sp+8h] [bp-40h]
  unsigned int v16; // [sp+Ch] [bp-3Ch]
  int v17[2]; // [sp+10h] [bp-38h] BYREF
  int v18[12]; // [sp+18h] [bp-30h] BYREF

  v18[3] = 0;
  v18[0] = 0;
  v1 = a1[55];
  v18[1] = (int)IoFreeDumpRange;
  v3 = a1 + 62;
  v18[4] = 1;
  v16 = v1;
  v18[2] = (int)(a1 + 62);
  result = MmRemoveSystemCacheFromDump((int)v18);
  v5 = v3;
  while ( v5 )
  {
    result = RtlFindSetBits(v5, 1u, 0);
    v6 = result;
    if ( result != -1 )
    {
      do
      {
        v15 = RtlFindNextForwardRunClear((int)v5, v6, (int)&v14);
        if ( v15 )
          v7 = v14 - v6;
        else
          v7 = v1 - v6;
        v8 = v6;
        if ( (a1[12] & 1) != 0 )
        {
          result = (unsigned int)RtlSetBits((_BYTE *)a1 + 220, v6, v7);
        }
        else
        {
          v17[0] = v7 + v6;
          v9 = a1[56];
          v13 = v6;
          v17[1] = v9;
          do
          {
            result = RtlFindNextForwardRunClear((int)v17, v8, (int)&v13);
            v10 = result;
            if ( !result )
              break;
            if ( result > a1[69] )
            {
              v10 = a1[69];
              a1[12] |= 2u;
            }
            v11 = v13;
            if ( v10 )
            {
              result = (unsigned int)RtlSetBits(v17, v13, v10);
              a1[69] -= v10;
            }
            if ( (a1[12] & 2) != 0 )
              return result;
            v8 = v10 + v11;
            v13 = v10 + v11;
          }
          while ( v10 + v11 < v7 + v6 );
        }
        v12 = v15 + v7;
        v1 = v16;
        v6 += v12;
      }
      while ( v6 < v16 );
    }
    if ( v5 == v3 && (a1[5] & 4) != 0 )
      v5 = a1 + 65;
    else
      v5 = 0;
  }
  return result;
}
