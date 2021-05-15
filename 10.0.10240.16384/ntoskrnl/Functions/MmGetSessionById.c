// MmGetSessionById 
 
int __fastcall MmGetSessionById(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  int *i; // r2
  int *v8; // r0
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  v5 = PsGetCurrentServerSilo(a1, a2, a3, a4);
  v6 = 0;
  KeAcquireInStackQueuedSpinLock(&dword_634980, v10);
  for ( i = (int *)dword_634D28; i != &dword_634D28; i = (int *)*i )
  {
    v8 = i - 24;
    if ( v5 )
      return sub_517400(v8, 0x22A8u);
    if ( *(i - 22) == a1 )
    {
      v6 = MiSelectSessionAttachProcess(v8);
      break;
    }
  }
  KeReleaseInStackQueuedSpinLock(v10);
  if ( v5 )
    ObfDereferenceObjectWithTag(v5, 1953261124);
  return v6;
}
