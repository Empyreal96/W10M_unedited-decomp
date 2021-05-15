// HvpGenerateLogMetadata 
 
int __fastcall HvpGenerateLogMetadata(_DWORD *a1, _DWORD *a2, unsigned int *a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r5
  int v9; // r6
  int v10; // r10
  _DWORD *v11; // r9
  int v12; // r0
  int v13; // r2
  int result; // r0
  _DWORD *v15; // r2
  int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = a4;
  v7 = HvpCountSetRangesInVector(a1);
  v8 = v7;
  if ( a2 && *a3 >= v7 )
  {
    v9 = 0;
    v10 = 0;
    if ( *a1 )
    {
      v11 = a2;
      while ( 1 )
      {
        v12 = RtlFindNextForwardRunClear((int)a1, v9, (int)v16);
        if ( !v12 )
          break;
        v13 = v16[0];
        if ( v16[0] != v9 )
        {
          *v11 = v9 << 9;
          v11[1] = (v13 - v9) << 9;
          v11 += 2;
          ++v10;
        }
        v9 = v13 + v12;
        if ( (unsigned int)(v13 + v12) >= *a1 )
          goto LABEL_9;
      }
      v15 = &a2[2 * v10];
      *v15 = v9 << 9;
      v15[1] = (*a1 - v9) << 9;
    }
LABEL_9:
    result = 0;
  }
  else
  {
    result = -1073741789;
  }
  *a3 = v8;
  return result;
}
