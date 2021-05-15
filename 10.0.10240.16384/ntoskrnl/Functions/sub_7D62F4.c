// sub_7D62F4 
 
void __fastcall sub_7D62F4(int a1, int a2, int a3, int a4, int *a5, int a6, int *a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, _DWORD *a19)
{
  unsigned int v19; // r6
  unsigned int v20; // r8
  int v21; // r4
  int v22; // r10
  int v23; // r5
  _DWORD **v24; // r4
  _DWORD *v25; // t1

  v21 = RtlULongLongToULong(2 * v19, (unsigned __int64)v19 >> 31, &a6);
  v22 = a6;
  if ( v21 < 0 )
    v23 = 0;
  else
    v23 = ExAllocatePoolWithTag(1, 4 * a6, 1885957463);
  if ( v23 )
  {
    memmove(v23, v20, 4 * v19);
    *a5 = v23;
    *a7 = v22;
  }
  else
  {
    if ( v19 )
    {
      v24 = (_DWORD **)v20;
      do
      {
        v25 = *v24++;
        WmipUnreferenceEntry((int *)&WmipISChunkInfo, v25);
        --v19;
      }
      while ( v19 );
    }
    WmipUnreferenceEntry((int *)&WmipISChunkInfo, a19);
    v21 = -1073741670;
    *a5 = 0;
  }
  if ( v20 != a8 )
    ExFreePoolWithTag(v20);
  if ( v21 < 0 )
    JUMPOUT(0x6DBFDC);
  JUMPOUT(0x6DBFD2);
}
