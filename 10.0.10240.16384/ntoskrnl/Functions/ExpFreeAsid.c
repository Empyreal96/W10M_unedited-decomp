// ExpFreeAsid 
 
int __fastcall ExpFreeAsid(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  _DWORD *v6; // r2
  int v7; // r3
  int v8; // r4
  int result; // r0
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a3;
  v10[2] = a4;
  v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v10);
  v6 = (_DWORD *)(dword_619EEC + 8 * a1);
  v7 = v6[1] - 1;
  v6[1] = v7;
  if ( v7 )
  {
    v6[1] = v7 | 0x80000000;
    v8 = 0;
  }
  else
  {
    *v6 = 0;
    --dword_619EE8;
    v8 = 1;
  }
  result = KeReleaseInStackQueuedSpinLock((int)v10);
  if ( v8 == 1 )
    result = ObfDereferenceObjectWithTag(v5);
  return result;
}
