// sub_7F695C 
 
int sub_7F695C(int a1, int a2, int a3, int a4, ...)
{
  unsigned int v4; // r4
  unsigned int *v5; // r0
  int v6; // r5
  int v7; // r3
  unsigned int v9; // r1
  int v10; // r5
  _BYTE *v11; // r7
  int v12; // r8
  unsigned __int8 *v13; // r9
  int v14; // r10
  int v15; // r6
  int v16; // r3
  int v17; // r0
  int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r3
  _DWORD v21[16]; // [sp-40h] [bp-40h] BYREF
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( v10 >= 0 || !(v10 + v14) || v10 == -1 )
  {
    v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 336);
  }
  else
  {
    v15 = ObpKernelHandleTable;
    v16 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v17 = *((_DWORD *)v13 + 294);
    if ( v16 != v17 )
    {
      KiStackAttachProcess(v17, 0, (int)va);
      v12 = 1;
    }
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = ExMapHandleToPointer(v15, v10);
  if ( v5 )
  {
    if ( !*v11
      || (*(_DWORD *)(*(_DWORD *)&v13[4
                                    * (*(unsigned __int8 *)((*v5 & 0xFFFFFFF8) + 12) ^ (unsigned __int8)((unsigned __int16)(*(_WORD *)v5 & 0xFFF8) >> 8) ^ *v13)
                                    + 4]
                    + 48) & v14) == 0 )
    {
      v18 = 0;
      if ( *v11 )
        v18 = 2;
      if ( v11[1] )
        v18 |= 1u;
      *v5 ^= (*v5 ^ v18) & v14;
      v19 = v5[1];
      if ( (v18 & 1) != 0 )
        v20 = v19 | 0x2000000;
      else
        v20 = v19 & 0xFDFFFFFF;
      v5[1] = v20;
    }
    __dmb(0xBu);
    do
      v9 = __ldrex(v5);
    while ( __strex(v9 + 1, v5) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(v15 + 32) )
      v5 = (unsigned int *)ExfUnblockPushLock(v15 + 32, 0);
    v6 = 0;
  }
  else
  {
    v6 = -1073741790;
  }
  v7 = (__int16)(*(_WORD *)(v4 + 308) + 1);
  *(_WORD *)(v4 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery((int)v5);
  if ( v12 )
    KiUnstackDetachProcess((unsigned int)v21, 0);
  return ((int (__fastcall *)(int))v21[15])(v6);
}
