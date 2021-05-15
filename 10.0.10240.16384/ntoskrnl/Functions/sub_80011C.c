// sub_80011C 
 
int sub_80011C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, ...)
{
  int v19; // r7
  unsigned int *v20; // r8
  unsigned int v21; // r1
  unsigned int v22; // r1
  __int16 v23; // r3
  int (__fastcall *v24)(int); // [sp-4h] [bp-4h]
  va_list va; // [sp+38h] [bp+38h] BYREF

  va_start(va, a18);
  __dmb(0xBu);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 + 1, v20) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(v19 + 32) )
    a1 = ExfUnblockPushLock(v19 + 32, 0);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(a1);
  if ( a10 )
    KiUnstackDetachProcess((unsigned int)va, 0);
  return v24(-1073741259);
}
