// HvpViewMapPrefetchFile 
 
int __fastcall HvpViewMapPrefetchFile(int a1, int a2)
{
  unsigned int v2; // r4
  _DWORD *v4; // r0
  unsigned int v5; // r5
  int v6; // r2
  _DWORD *v7; // r3
  int v8; // r4
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v2 = (unsigned int)(a2 + 4095) >> 12;
  v4 = (_DWORD *)ExAllocatePoolWithTag(1, 8 * (v2 + 2), 959794499);
  v5 = (unsigned int)v4;
  v10[0] = (int)v4;
  if ( !v4 )
    return -1073741670;
  *v4 = a1;
  v4[1] = v2;
  v6 = 0;
  v4[2] = 0;
  if ( v2 )
  {
    v7 = v4;
    do
    {
      v7[4] = v6;
      v7[5] = 0;
      v7 += 2;
      --v2;
      v6 += 4096;
    }
    while ( v2 );
  }
  v8 = MmPrefetchPagesEx(1, v10, 0);
  if ( v8 >= 0 )
    v8 = 0;
  ExFreePoolWithTag(v5);
  return v8;
}
