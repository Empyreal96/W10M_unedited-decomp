// sub_7BFF30 
 
void sub_7BFF30(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != v4 )
  {
    KiStackAttachProcess(v4, 0, (int)va);
    v5 = 1;
  }
  ExSweepHandleTable(v6);
  if ( v5 == 1 )
    KiUnstackDetachProcess((unsigned int)va, 0);
  v7 = (unsigned int *)(v4 + 172);
  __pld((void *)(v4 + 172));
  v8 = *(_DWORD *)(v4 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v9 = __ldrex(v7);
  while ( v9 == v8 && __strex(v8 - 2, v7) );
  if ( v9 != v8 )
    ExfReleaseRundownProtection((unsigned __int8 *)v7);
  JUMPOUT(0x6A5C7E);
}
