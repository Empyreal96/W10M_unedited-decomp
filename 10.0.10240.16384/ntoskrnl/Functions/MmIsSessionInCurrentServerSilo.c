// MmIsSessionInCurrentServerSilo 
 
int __fastcall MmIsSessionInCurrentServerSilo(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r4
  int v7; // r5
  int *i; // r1
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  v5 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( v5 == -1 )
    v5 = 0;
  if ( v5 == a1 )
    return 1;
  v6 = 0;
  v7 = PsGetCurrentServerSilo();
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v10);
  for ( i = (int *)dword_634D28; i != &dword_634D28; i = (int *)*i )
  {
    if ( i[2079] == v7 && *(i - 22) == a1 )
    {
      if ( (*(i - 23) & 2) == 0 && (int *)*(i - 20) != i - 20 )
        v6 = 1;
      break;
    }
  }
  KeReleaseInStackQueuedSpinLock((int)v10);
  if ( v7 )
    ObfDereferenceObjectWithTag(v7);
  return v6;
}
