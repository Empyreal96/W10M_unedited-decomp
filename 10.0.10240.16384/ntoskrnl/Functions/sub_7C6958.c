// sub_7C6958 
 
void sub_7C6958(int a1, int a2, int a3, int a4, ...)
{
  unsigned int v4; // r4
  unsigned int v5; // r0
  int v6; // r6
  int v7; // r5
  int v8; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  va_list va1; // [sp+4h] [bp+4h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v8 = va_arg(va1, _DWORD);
  v5 = *(_DWORD *)(v4 + 12);
  if ( v5 )
    ExFreePoolWithTag(v5);
  PiDmGetCacheKeys(*(_DWORD *)(v4 + 20), va1, (int *)va);
  v6 = v8;
  if ( v8 )
  {
    v7 = v4 + 64;
    do
    {
      PiDmCacheDataFree(v7);
      v7 += 20;
      --v6;
    }
    while ( v6 );
  }
  ExFreePoolWithTag(v4);
  JUMPOUT(0x6C8748);
}
