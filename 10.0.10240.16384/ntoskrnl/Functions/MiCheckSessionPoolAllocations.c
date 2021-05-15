// MiCheckSessionPoolAllocations 
 
int MiCheckSessionPoolAllocations()
{
  _DWORD *v0; // r5
  int *v1; // r0
  int v2; // r6
  int *v3; // r1
  int i; // r4
  int v5; // r2
  unsigned int v6; // r0
  int v8[2]; // [sp+0h] [bp-28h] BYREF
  unsigned int v9; // [sp+8h] [bp-20h]
  int v10; // [sp+Ch] [bp-1Ch]

  v8[0] = MmSessionSpace + 12288;
  v8[1] = 256;
  v0 = *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v1 = v8;
  v2 = 2;
  v9 = v0[2093];
  v10 = v0[2094];
  do
  {
    v3 = (int *)*v1;
    if ( *v1 )
    {
      for ( i = v1[1]; i; --i )
      {
        v5 = *v3;
        __dmb(0xBu);
        if ( v5 != 1801808973 )
          __dmb(0xBu);
        v3 += 7;
      }
    }
    v1 += 2;
    --v2;
  }
  while ( v2 );
  if ( v9 )
  {
    MiFreePoolPages(v9, 28 * v10);
    v0[2093] = 0;
    v0[2094] = 0;
  }
  v6 = v0[2095];
  if ( v6 )
  {
    ExFreePoolWithTag(v6);
    v0[2095] = 0;
  }
  return MiDeleteLeakedSessionPool();
}
