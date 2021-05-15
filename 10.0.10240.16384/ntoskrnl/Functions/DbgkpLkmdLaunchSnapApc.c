// DbgkpLkmdLaunchSnapApc 
 
int __fastcall DbgkpLkmdLaunchSnapApc(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // r0
  unsigned int v9; // r5
  int v10; // r4
  unsigned int *v11; // r7
  unsigned int v12; // r2
  int v13; // r0
  int v15[8]; // [sp+10h] [bp-20h] BYREF

  v8 = (_DWORD *)ExAllocatePoolWithTag(512, 80, 1884181323);
  v9 = (unsigned int)v8;
  if ( !v8 )
    return -1073741801;
  v8[12] = 0;
  v8[13] = a1;
  v8[14] = a2;
  v8[15] = a4;
  KeInitializeEvent((int)(v8 + 16), 0, 0);
  KeInitializeApc(v9, a3, 0, (int)DbgkpLkmdSnapThreadApc, 0, 0, 0, 0);
  v11 = (unsigned int *)(v9 + 48);
  if ( KeInsertQueueApc(v9, v9, v9 + 48, 2) )
  {
    v15[0] = -50000000;
    v15[1] = -1;
    while ( 1 )
    {
      v13 = KeWaitForSingleObject(v9 + 64, 0, 0, 0, v15);
      v10 = v13;
      if ( !v13 )
        break;
      if ( v13 == 258 )
        *(_DWORD *)(a4 + 4) |= 0x8000u;
      __dmb(0xBu);
      do
        v12 = __ldrex(v11);
      while ( !v12 && __strex(1u, v11) );
      __dmb(0xBu);
      if ( !v12 )
        return v10;
    }
    ExFreePoolWithTag(v9);
  }
  else
  {
    ExFreePoolWithTag(v9);
    v10 = -1073741823;
    *(_DWORD *)(a4 + 4) |= 0x4000u;
  }
  return v10;
}
