// NormBuffer__SortBeforeSameClass 
 
int __fastcall NormBuffer__SortBeforeSameClass(int result, unsigned int a2, int a3, unsigned __int16 *a4)
{
  int *v4; // r4
  int v5; // r3
  int v6; // r5
  unsigned __int16 *v8; // r6
  unsigned __int16 *v9; // r5
  int v10; // r1
  int v11; // r7
  unsigned __int16 *v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v4 = (int *)result;
  v5 = *(_DWORD *)(result + 20);
  v6 = *(_DWORD *)(result + 44);
  *(_DWORD *)(result + 64) = v5;
  if ( v5 != v6 )
  {
    v12[0] = (unsigned __int16 *)(v5 - 2);
    result = NormBuffer__GetCurrentOutputChar(result, v12);
    v8 = (unsigned __int16 *)(v6 - 2);
    v9 = v12[0];
    if ( v4[12] > 0xFFFF )
      --v8;
    v10 = result;
    if ( v12[0] != v8 )
    {
      v11 = v4[17];
      do
      {
        Normalization__PageLookup(v11, v10);
        result = Normalization__TableLookup(v11);
        if ( (result & 0x3Fu) < a2 )
          break;
        v4[16] = (int)v9;
        v12[0] = v9 - 1;
        result = NormBuffer__GetCurrentOutputChar(result, v12);
        v9 = v12[0];
        v10 = result;
      }
      while ( v12[0] != v8 );
    }
  }
  return result;
}
