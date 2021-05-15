// KsepDbCacheQueryDeviceData 
 
int __fastcall KsepDbCacheQueryDeviceData(int a1, int a2, _DWORD *a3, unsigned int *a4, int a5)
{
  int v5; // r5
  _DWORD *v8; // r0
  unsigned int v9; // r3
  unsigned int v10; // r2

  v5 = -1073741275;
  if ( a1 )
  {
    v5 = 0;
    v8 = (_DWORD *)KsepCacheDeviceQueryData();
    if ( v8 )
    {
      *a3 = v8[5];
      v9 = v8[4];
      v10 = *a4;
      *a4 = v9;
      if ( v10 >= v9 )
        memmove(a5, v8[6], v8[4]);
      else
        v5 = -1073741789;
    }
    else
    {
      *a4 = 0;
    }
  }
  return v5;
}
