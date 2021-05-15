// RtlCompressBufferLZNT1 
 
int __fastcall RtlCompressBufferLZNT1(int a1, unsigned int a2, int a3, _BYTE *a4, int a5, int a6, _DWORD *a7, unsigned int *a8)
{
  unsigned int v8; // r10
  _BYTE *v9; // r9
  int v10; // r7
  unsigned int v11; // r2
  unsigned int v12; // r5
  int (__fastcall *v13)(char *); // r8
  _BYTE *v14; // r4
  unsigned int *v15; // r3
  int result; // r0
  BOOL v17; // r3
  unsigned int v18; // [sp+10h] [bp-28h]
  int v19[9]; // [sp+14h] [bp-24h] BYREF

  v8 = a2 + a3;
  v9 = a4;
  v10 = 1;
  v11 = (unsigned int)&a4[a5];
  v18 = (unsigned int)&a4[a5];
  v12 = a2;
  if ( a1 )
  {
    if ( a1 != 256 )
      return -1073741637;
    v13 = (int (__fastcall *)(char *))LZNT1FindMatchMaximum;
  }
  else
  {
    v13 = (int (__fastcall *)(char *))LZNT1FindMatchStandard;
  }
  v14 = a4;
  if ( a2 >= v8 )
  {
LABEL_13:
    if ( (unsigned int)v14 <= v11 - 2 )
    {
      *v14 = 0;
      v14[1] = 0;
    }
    *a7 = v14 - v9;
    if ( v10 )
      result = 279;
    else
      result = 0;
  }
  else
  {
    v15 = a8;
    while ( 1 )
    {
      result = LZNT1CompressChunk(v13, v12, v8, v14, v11, v19, v15);
      if ( result < 0 )
        break;
      v17 = v10 && result == 279;
      v10 = v17;
      v11 = v18;
      v12 += 4096;
      v14 += v19[0];
      v15 = a8;
      if ( v12 >= v8 )
        goto LABEL_13;
    }
  }
  return result;
}
