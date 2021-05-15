// sub_514770 
 
void sub_514770(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  _DWORD *v8; // r5
  unsigned int v9; // r7
  unsigned int v10; // r3
  unsigned int v11; // r2
  _DWORD *v12; // r1
  _DWORD *v13; // r3
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  KeAcquireInStackQueuedSpinLock(v8 + 32, (unsigned int)va);
  v10 = v8[31];
  v11 = v10;
  if ( v10 > v9 )
    v11 = v9;
  if ( v11 )
  {
    v12 = (_DWORD *)v8[33];
    v9 -= v11;
    v8[31] = v10 - v11;
    do
    {
      v13 = v12;
      v12 = (_DWORD *)*v12;
      --v11;
    }
    while ( v11 );
    *v13 = 0;
    v8[33] = v12;
  }
  KeReleaseInStackQueuedSpinLock((int)va);
  if ( !v9 )
    JUMPOUT(0x431390);
  JUMPOUT(0x4312E2);
}
