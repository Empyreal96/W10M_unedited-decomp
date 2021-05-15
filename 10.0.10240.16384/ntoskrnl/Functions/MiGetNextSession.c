// MiGetNextSession 
 
int __fastcall MiGetNextSession(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r8
  int v7; // r4
  int *v8; // r4
  int v9; // r0
  _DWORD v11[10]; // [sp+0h] [bp-28h] BYREF

  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v5 = PsGetCurrentServerSilo();
  v6 = 0;
  if ( a1 )
    v7 = *(_DWORD *)(a1 + 324);
  else
    v7 = 0;
  KeAcquireInStackQueuedSpinLock(&dword_634980, v11);
  if ( v7 )
    v8 = *(int **)(v7 + 96);
  else
    v8 = (int *)dword_634D28;
  while ( v8 != &dword_634D28 )
  {
    v9 = MiSelectSessionAttachProcess(v8 - 24);
    v6 = v9;
    if ( v5 )
      return sub_515D34();
    if ( v9 )
      break;
    v8 = (int *)*v8;
  }
  KeReleaseInStackQueuedSpinLock(v11);
  if ( a1 )
    ObfDereferenceObjectWithTag(a1, 1953261124);
  if ( v5 )
    ObfDereferenceObjectWithTag(v5, 1953261124);
  return v6;
}
