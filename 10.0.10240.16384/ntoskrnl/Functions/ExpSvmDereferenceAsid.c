// ExpSvmDereferenceAsid 
 
void __fastcall __spoils<R2,R3,R12> ExpSvmDereferenceAsid(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r2
  int v6; // r3
  _DWORD v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[2] = a3;
  v7[3] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v7);
  v5 = (_DWORD *)(dword_619EEC + 8 * a1);
  v6 = v5[1] - 1;
  v5[1] = v6;
  if ( v6 < 0 && (v6 & 0x7FFFFFFF) == 0 )
  {
    *v5 = 0;
    ObfDereferenceObjectWithTag(0);
    --dword_619EE8;
  }
  KeReleaseInStackQueuedSpinLock((int)v7);
}
