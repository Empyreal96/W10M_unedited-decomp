// MiMarkSessionMasterProcess 
 
int __fastcall MiMarkSessionMasterProcess(int a1, int a2, int a3, int a4)
{
  int v6; // r2
  _DWORD *v7; // r0
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a1;
  v9[2] = a3;
  v9[3] = a4;
  MiSessionAddProcess();
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v9);
  v6 = a1 + 232;
  *(_BYTE *)(a1 + 605) |= 1u;
  v7 = *(_DWORD **)(a2 + 20);
  *(_DWORD *)(a1 + 232) = a2 + 16;
  *(_DWORD *)(a1 + 236) = v7;
  if ( *v7 != a2 + 16 )
    sub_50B828(v7);
  *v7 = v6;
  *(_DWORD *)(a2 + 20) = v6;
  KeReleaseInStackQueuedSpinLock((int)v9);
  return v9[0];
}
